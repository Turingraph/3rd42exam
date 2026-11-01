#include "libft.h"

bool	assert_str(const char *str1, const char *str2)
{
	size_t	i;

	if (str1 == NULL && str2 == NULL)
		return (true);
	if (str1 == NULL || str2 == NULL)
		return (false);
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str2[i] == str1[i])
		i += 1;
	if (str1[i] != str2[i])
		return (false);
	return (true);
}

size_t	assert_strarr(const char **str1, const char **str2, size_t length)
{
	size_t	i;
	size_t	y;

	if (str1 == NULL || str2 == NULL)
		return (0);
	y = 0;
	i = 0;
	while (i < length)
	{
		if (assert_str(str1[i], str2[i]))
			y += 1;
		else
		{
			write(1, ">>> ", 4);
			write_int(i, "0123456789", 1);
			write(1, "\t", 1);
			if (str1[i] != NULL && str1[i][0] != '\0')
				write(1, str1[i], str_length(str1[i]));
			write(1, " != ", 5);
			if (str2[i] != NULL && str2[i][0] != '\0')
				write(1, str2[i], str_length(str2[i]));
			write(1, "\n", 1);
		}
		i += 1;
	}
	return (y);
}

bool	assert_int(const int *int1, const int *int2, size_t length)
{
	size_t	i;

	if (int1 == NULL && int2 == NULL)
		return (true);
	if (int1 == NULL || int2 == NULL)
		return (false);
	i = 0;
	while (i < length)
	{
		if (int1[i] != int2[i])
			return (false);
		i += 1;
	}
	return (true);
}
