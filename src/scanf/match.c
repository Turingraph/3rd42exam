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

void	match_args(const char *str, size_t ith, va_list args, int *cc)
{
	int		y;
	char	*dst;

	y = type_from_args(str, ith);
	if (y == -1)
		return ;
	dst = va_arg(args, char *);
	if (str[y + 1] == 's')
		match_str(stdin, cc, dst);
	else
		match_char(stdin, cc, dst);
}
