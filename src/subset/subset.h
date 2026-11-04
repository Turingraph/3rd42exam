/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:13:29 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 19:04:44 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSET_H
# define SUBSET_H

# include "../libft/libft.h"

// utils.c

size_t	lasttruth(const bool *src, size_t length);
bool	*create_bool(size_t length);
void	add_bool(bool *dst, size_t length);
bool	isalltrue(const bool *src, size_t length);
int		*strarr_to_int(size_t length, const char **str);

// subset.c

void	write_powerset(const int *src, size_t length, int target);

#endif
