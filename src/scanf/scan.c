/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:20:10 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 16:36:10 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanf.h"

void	ft_scanf(const char *str, ...)
{
	int		cc;
	va_list	args;
	size_t	i;
	size_t	length;

	length = count_args(str);
	if (length == 0)
		return ;
	i = 0;
	va_start(args, str);
	cc = fgetc(stdin);
	while (is_continue(cc) && i < length)
	{
		while (cc == ' ')
			cc = fgetc(stdin);
		match_args(str, i, args, &cc);
		i += 1;
	}
	va_end(args);
}

void	set_str(char *dst, size_t length, char c)
{
	size_t	i;

	if (dst == NULL || length == 0)
		return ;
	i = 0;
	while (i < length)
	{
		dst[i] = c;
		i += 1;
	}
}
