/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:11:33 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 17:58:38 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "permutation.h"

int	*create_intarr(size_t length)
{
	size_t	i;
	int		*dst;

	if (length == 0)
		return (NULL);
	dst = malloc(sizeof(int) * length);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dst[i] = (int)i;
		i += 1;
	}
	return (dst);
}

void	set_intarr(int *dst, size_t length, int a)
{
	size_t	i;

	if (length == 0 || dst == NULL)
		return ;
	i = 0;
	while (i < length)
	{
		dst[i] = a;
		i += 1;
	}
}
