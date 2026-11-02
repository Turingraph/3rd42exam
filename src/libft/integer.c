/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:45:31 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 19:21:38 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	skip_zero(size_t *index, const char *str,
	size_t max_digits, const char *base)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	while ((i < max_digits || max_digits == 0) && str[i] == *base)
		i += 1;
	if (i == max_digits && max_digits > 0)
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (is_a_in_str(str[i], "-+") == true)
		i += 1;
	*index = i;
	return (sign);
}

static int	int_to_int_output(long int y, const char *base, int sign, bool *is_int)
{
	y /= str_length(base);
	if ((y > 2147483647 && sign > 0) || *is_int == false
		|| (y < -2147483648 && sign < 0))
	{
		*is_int = false;
		return (-1);
	}
	return ((int)(y * sign));
}

int	str_to_int(const char *str, const char *base, bool *is_int,
		size_t max_digits)
{
	size_t		i;
	long int	y;
	int			sign;
	long int	coef;

	if (str == NULL || base == NULL || is_int == NULL
		|| *str == '\0' || *base == '\0')
	{
		if (is_int != NULL)
			*is_int = false;
		return (-1);
	}
	i = 0;
	y = 0;
	sign = skip_zero(&i, str, max_digits, base);
	while ((i < max_digits || max_digits == 0)
		&& str[i] != '\0' && *is_int == true)
	{

		coef = base_to_int(base, str[i]);
		if (coef >= 0)
		{
			y += coef;
			y *= str_length(base);
			if (y / str_length(base) > 2147483648)
				*is_int = false;
		}
		else
			*is_int = false;
		i += 1;
	}
	return (int_to_int_output(y, base, sign, is_int));
}

static size_t	write_int_helper(long int src_long, const char *base, int fd)
{
	long int	digits;
	long int	base_length;
	size_t		i;
	char		coef;

	base_length = str_length(base);
	i = 0;
	digits = 1;
	while (digits < src_long)
		digits *= base_length;
	if (digits > src_long)
		digits /= base_length;
	while (digits > 0)
	{
		coef = base[src_long / digits];
		write(fd, &coef, 1);
		src_long = src_long % digits;
		digits /= base_length;
		i += 1;
	}
	return (i);
}

size_t	write_int(int src, const char *base, int fd)
{
	long int	src_long;

	if (base == NULL || fd < -1)
		return (0);
	if (src == 0)
	{
		write(fd, base, 1);
		return (1);
	}
	src_long = (long int)src;
	if (src_long < 0)
	{
		write(fd, "-", 1);
		src_long *= -1;
	}
	return (write_int_helper(src_long, base, fd));
}

void	write_score(size_t score, size_t max_score)
{
	write(1, "score: ", 7);
	write_int(score, "0123456789", 1);
	write(1, " / ", 3);
	write_int(max_score, "0123456789", 1);
	write(1, "\n", 1);
}
