/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:20:31 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 16:34:59 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanf.h"

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
