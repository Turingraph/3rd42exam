/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:32:57 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 14:41:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "permutation.h"

bool	is_unique_str(const char *str)
{
	size_t	i;
	size_t	j;

	if (str == NULL || str[0] == '\0')
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (false);
			j += 1;
		}
		i += 1;
	}
	return (true);
}

int	get_ith_char(const char *mark, const char *str,
	size_t index)
{
	size_t	i;
	int		y;

	if (mark == NULL || str == NULL || *str == '\0')
		return (-1);
	y = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_a_in_str(str[i], mark) == false)
			y += 1;
		if (y == (int)index)
			return ((int)i);
		i += 1;
	}
	return (-1);
}

void	write_permutations(const char *str, char *mark,
	size_t index, size_t length)
{
	int		current_note;
	size_t	i;

	if (str == NULL || mark == NULL || index >= length)
	{
		if (mark != NULL)
		{
			write(1, mark, str_length(mark));
			write(1, "\n", 1);
		}
	}
	i = 0;
	while (i < length - index)
	{
		current_note = get_ith_char(mark, str, i);
		if (current_note > -1)
		{
			mark[index] = str[current_note];
			write_permutations(str, mark, index + 1, length);
			mark[index] = '\0';
		}
		else
			i = length;
		i += 1;
	}
}
