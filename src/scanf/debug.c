/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:19:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 16:35:46 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanf.h"




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
