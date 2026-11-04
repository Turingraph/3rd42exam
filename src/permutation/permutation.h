/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:36:07 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 17:58:44 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERMUTATION_H
# define PERMUTATION_H

# include "../libft/libft.h"

// n_queens.c

void	write_n_int(const int *src, size_t length);
void	write_n_queens(const int *str, int *mark,
			size_t index, size_t length);

// permutation.c

bool	is_unique_str(const char *str);
void	write_permutations(const char *str, char *mark,
			size_t index, size_t length);

// utils.c

int		*create_intarr(size_t length);
void	set_intarr(int *dst, size_t length, int a);

#endif
