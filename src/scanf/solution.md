

```
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool	is_a_in_str(char a, const char *str)
{
	size_t	i;

	if (str == NULL || *str == '\0')
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (true);
		i += 1;
	}
	return (false);
}

size_t	str_length(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

int	base_to_int(const char *base, char coef)
{
	size_t	i;

	if (base == NULL || coef == '\0' || is_a_in_str(coef, "-+") == true)
		return (-1);
	i = 0;
	while (base[i] != '\0' && base[i] != coef)
		i += 1;
	if (base[i] != coef)
		return (-1);
	return (i);
}

size_t	count_args(const char *str)
{
	size_t	i;
	size_t	y;

	if (str == NULL)
		return (0);
	y = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%'
			&& is_a_in_str(str[i + 1], "scd") == true)
			y += 1;
		i += 1;
	}
	return (y);
}

int	type_from_args(const char *str, size_t ith)
{
	size_t	i;
	int		y;

	if (str == NULL)
		return (-1);
	y = -1;
	i = 0;
	while (str[i] != '\0' && y < (int)ith)
	{
		if (str[i] == '%'
			&& is_a_in_str(str[i + 1], "scd") == true)
			y += 1;
		if (y == (int)ith)
			return ((int)i);
		i += 1;
	}
	return (-1);
}


bool	match_char(FILE *stream, int *cc, char *dst)
{
	if (*cc == EOF || is_a_in_str(*cc, " \n") == true || dst == NULL)
		return (false);
	dst[0] = (char)(*cc);
	*cc = fgetc(stream);
	return (true);
}

bool	match_str(FILE *stream, int *cc, char *dst)
{
	size_t	j;

	if (*cc == EOF || is_a_in_str(*cc, " \n") == true || dst == NULL)
		return (false);
	j = 0;
	while (*cc != EOF && is_a_in_str(*cc, " \n") == false)
	{
		dst[j] = (char)(*cc);
		*cc = fgetc(stream);
		j += 1;
	}
	return (true);
}

bool	match_int(FILE *stream, int *cc, int *dst)
{
	bool		is_int;
	long int	y;
	int			coef;
	long int	sign;

	sign = 1;
	is_int = true;
	y = 0;
	if (*cc == EOF
		|| is_a_in_str(*cc, "0123456789+-") == false
		|| dst == NULL)
		return (false);
	if (*cc == '-')
		sign = -1;
	if (*cc == '-' || *cc == '+')
		*cc = fgetc(stream);
	while (*cc != EOF && *cc != ' ' && y < 21474836480
		&& is_int == true)
	{
		coef = base_to_int("0123456789", *cc);
		if (coef < 0)
			is_int = false;
		else
		{
			y += coef;
			y *= str_length("0123456789");
			*cc = fgetc(stream);
		}
	}
	y /= str_length("0123456789");
	if (sign * y > -2147483648 && sign * y < 2147483647)
		*dst = (int)(y * sign);
	return (true);
}

bool	match_args(const char *str, size_t ith, va_list args, int *cc)
{
	int		y;
	char	*dst;
	int		*dst_int;
	bool	success;

	success = false;
	y = type_from_args(str, ith);
	if (y == -1)
		return (success);
	if (str[y + 1] == 's')
	{
		dst = va_arg(args, char *);
		success = match_str(stdin, cc, dst);
	}
	else if (str[y + 1] == 'c')
	{
		dst = va_arg(args, char *);
		success = match_char(stdin, cc, dst);
	}
	else if (str[y + 1] == 'd')
	{
		dst_int = va_arg(args, int *);
		success = match_int(stdin, cc, dst_int);
	}
	return (success);
}

int	ft_scanf(const char *str, ...)
{
	int		cc;
	va_list	args;
	size_t	i;
	size_t	length;
	bool	status;

	length = count_args(str);
	if (length == 0)
		return (0);
	i = 0;
	va_start(args, str);
	cc = fgetc(stdin);
	status = true;
	while (cc != EOF && i < length && status == true)
	{
		while (cc == ' ' || cc == '\n')
			cc = fgetc(stdin);
		status = match_args(str, i, args, &cc);
		if (status == true)
			i += 1;
	}
	va_end(args);
	if (ferror(stdin) != 0 || (i == 0 && cc == EOF))
		return (EOF);
	return ((int)i);
}
```

Things to be considered
1.	Do not deal with Integer-Overflow and other undefined behavior.

```
bool	match_int(FILE *stream, int *cc, int *dst)
{
...
long int	y;
...
while (y < 21474836480 && ...)
...
y /= str_length("0123456789");
if (sign * y > -2147483648 && sign * y < 2147483647)
	*dst = (int)(y * sign);
return (true);
}
```

2.	You don't have to deal with `scanf("Subscript_to_my_channel %d");`
3.	You have to deal with negative and positive sign `"-+"` as separatator of `%d` format.
4.	You have to skips the `\n` (new line) as same as ` ` (space)

```
while (cc == ' ' || cc == '\n')
	cc = fgetc(stdin);
```

5.	The when user type the last `\n` then `(cc = fget(stdin)) == EOF` is true.
6.	`ft_scanf` return the number of all successful matching and it will stop working once it match all of the input and/or it fail to matching the input.

ChatGPT recommendation
1.	`fgets(FILE *stream)` return `int`
2.	pass `func(va_list *)` instead of `func(va_list)` for the sake of compatibility.
3.	%c does not skip whitespace, the %c get whitespace, newline, and every other char. The whitespace-skipping behavior belongs to %s and %d, not %c.
4.	%s must terminate, you forget `dst[i] = '\0'`
5.	Your integer parser accepts a sign without digits
6.	don't exclude excludes INT_MIN and INT_MAX for %d.
7.	Use isspace() instead of checking only space and newline
