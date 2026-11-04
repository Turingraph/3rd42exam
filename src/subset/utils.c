/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:36:27 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 19:04:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subset.h"

size_t	lasttruth(const bool *src, size_t length)
{
	size_t	i;
	size_t	y;

	if (src == NULL || length == 0)
		return (false);
	i = 0;
	while (i < length)
	{
		if (src[i] == true)
			y = i;
		i += 1;
	}
	return (y);
}

bool	*create_bool(size_t length)
{
	bool	*dst;
	size_t	i;

	if (length == 0)
		return (NULL);
	dst = malloc(sizeof(bool) * length);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dst[i] = false;
		i += 1;
	}
	return (dst);
}

void	add_bool(bool *dst, size_t length)
{
	size_t	i;

	if (dst == NULL || length == 0)
		return ;
	i = 0;
	while (i < length && dst[i] == true)
	{
		dst[i] = false;
		i += 1;
	}
	if (i < length)
		dst[i] = true;
}

bool	isalltrue(const bool *src, size_t length)
{
	size_t	i;

	if (src == NULL || length == 0)
		return (false);
	i = 0;
	while (i < length)
	{
		if (src[i] == false)
			return (false);
		i += 1;
	}
	return (true);
}

int	*strarr_to_int(size_t length, const char **str)
{
	int		*dst;
	size_t	i;
	bool	is_int;

	is_int = true;
	if (str == NULL || length == 0)
		return (NULL);
	dst = malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dst[i] = str_to_int(str[i], "0123456789", &is_int, 0);
		if (is_int == false)
		{
			free(dst);
			return (NULL);
		}
		i += 1;
	}
	return (dst);
}
