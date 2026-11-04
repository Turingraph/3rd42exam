/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:13:54 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 19:12:20 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subset.h"

void	write_subset_int(const int *src, size_t length, const bool *boolarr)
{
	size_t	i;
	size_t	last;

	if (src == NULL || length == 0)
		return ;
	last = lasttruth(boolarr, length);
	i = 0;
	while (i < length)
	{
		if (boolarr == NULL || boolarr[i] == true)
		{
			write_int(src[i], "0123456789", 1);
			if (i < last)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
		}
		i += 1;
	}
}

int	f_sigma(const int *src, size_t length, const bool *boolarr)
{
	size_t	i;
	int		y;

	if (src == NULL || length == 0)
		return (0);
	y = 0;
	i = 0;
	while (i < length)
	{
		if (boolarr == NULL || boolarr[i] == true)
			y += src[i];
		i += 1;
	}
	return (y);
}

void	write_powerset(const int *src, size_t length, int target)
{
	bool	*mark;

	if (src == NULL || length == 0)
		return ;
	mark = create_bool(length);
	if (mark == NULL)
		return ;
	mark[0] = true;
	while (isalltrue(mark, length) == false)
	{
		if (f_sigma(src, length, mark) == target)
			write_subset_int(src, length, mark);
		add_bool(mark, length);
	}
	if (f_sigma(src, length, mark) == target)
		write_subset_int(src, length, mark);
	free(mark);
}
