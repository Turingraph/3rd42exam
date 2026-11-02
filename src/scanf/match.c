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

void	match_char(FILE *stream, int *cc, char *dst)
{
	if (is_continue(*cc) == false)
		return ;
	if (dst == NULL)
		return ;
	dst[0] = (char)(*cc);
	*cc = fgetc(stream);
}

void	match_str(FILE *stream, int *cc, char *dst)
{
	size_t	j;

	if (is_continue(*cc) == false)
		return ;
	if (dst == NULL)
		return ;
	j = 0;
	while (is_continue(*cc) && *cc != ' ')
	{
		dst[j] = (char)(*cc);
		*cc = fgetc(stream);
		j += 1;
	}
}

void	match_int(FILE *stream, int *cc, int *dst)
{
	bool		is_int;
	long int	y;
	int			coef;

	is_int = true;
	y = 0;
	if (is_continue(*cc) == false
		|| dst == NULL)
		return ;
	while (is_continue(*cc) && *cc != ' ' && y < 21474836480
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
	if (y < 21474836480)
		*dst = (int)y;
}

void	match_args(const char *str, size_t ith, va_list args, int *cc)
{
	int		y;
	char	*dst;
	int		*dst_int;

	y = type_from_args(str, ith);
	if (y == -1)
		return ;
	if (str[y + 1] == 's')
	{
		dst = va_arg(args, char *);
		match_str(stdin, cc, dst);
	}
	else if (str[y + 1] == 'c')
	{
		dst = va_arg(args, char *);
		match_char(stdin, cc, dst);
	}
	else if (str[y + 1] == 'd')
	{
		dst_int = va_arg(args, int *);
		match_int(stdin, cc, dst_int);
	}
}
