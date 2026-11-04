/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:10:01 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 18:00:09 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "permutation.h"

static bool	check_n_capture(const int *src, size_t length)
{
	int	i;

	if (length < 2 || src == NULL)
		return (true);
	i = 1;
	while (i < (int)length)
	{
		if (src[0] + i == src[i] || src[0] - i == src[i])
			return (false);
		i += 1;
	}
	return (true);
}

bool	check_n_queens(const int *src, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		if (check_n_capture(src + i, length - i) == false)
			return (false);
		i += 1;
	}
	return (true);
}

void	write_n_int(const int *src, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		write_int(src[i], "0123456789", 1);
		if (i < length - 1)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		i += 1;
	}
}

static int	get_ith_int(const int *mark, const int *str,
	size_t index, size_t length)
{
	size_t	i;
	int		y;

	if (mark == NULL || str == NULL || length == 0)
		return (-1);
	y = -1;
	i = 0;
	while (i < length)
	{
		if (is_a_in_int(str[i], mark, length) == false)
			y += 1;
		if (y == (int)index)
			return ((int)i);
		i += 1;
	}
	return (-1);
}

void	write_n_queens(const int *str, int *mark,
	size_t index, size_t length)
{
	int		current_note;
	size_t	i;

	if (str == NULL || mark == NULL || index >= length)
	{
		if (check_n_queens(mark, length) == true)
			write_n_int(mark, length);
		return ;
	}
	i = 0;
	while (i < length - index)
	{
		current_note = get_ith_int(mark, str, i, length);
		if (current_note > -1)
		{
			mark[index] = str[current_note];
			write_n_queens(str, mark, index + 1, length);
			mark[index] = -1;
		}
		else
			i = length;
		i += 1;
	}
}
