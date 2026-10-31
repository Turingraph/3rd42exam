/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:19:23 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 16:34:59 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanf.h"

bool	is_continue(int cc)
{
	if (cc == '\n' || cc == EOF)
		return (false);
	return (true);
}

size_t	args_length(const char *str)
{
	size_t	i;
	size_t	y;

	if (str == NULL)
		return (0);
	y = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && (str[i] == 's' || str[i] == 'c'))
			y += 1;
		i += 1;
	}
	return (y);
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
			&& (str[i + 1] == 's' || str[i + 1] == 'c'))
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
			&& (str[i + 1] == 's' || str[i + 1] == 'c'))
			y += 1;
		if (y == (int)ith)
			return ((int)i);
		i += 1;
	}
	return (-1);
}
