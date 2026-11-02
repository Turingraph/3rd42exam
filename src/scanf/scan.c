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
	while (cc != EOF && i < length)
	{
		while (cc == ' ' || cc == '\n')
			cc = fgetc(stdin);
		match_args(str, i, args, &cc);
		i += 1;
	}
	va_end(args);
}

void	write_userinput(void)
{
	char	cc;
	char	index;

	index = 'a';
	cc = fgetc(stdin);
	while (cc != EOF)
	{
		while (cc == ' ')
			cc = fgetc(stdin);
		if (cc != EOF)
		{
			write(1, &index, 1);
			write(1, ".", 1);
			index += 1;
		}
		while (cc != EOF && cc != ' ')
		{
			write(1, &cc, 1);
			cc = fgetc(stdin);
		}
		write(1, " ", 1);
	}
}
