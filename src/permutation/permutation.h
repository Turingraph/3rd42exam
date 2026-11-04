/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:36:07 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 14:37:58 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERMUTATION_H
# define PERMUTATION_H

# include "../libft/libft.h"

bool	is_unique_str(const char *str);
int		get_ith_char(const char *mark, const char *str,
			size_t index);
void	write_permutations(const char *str, char *mark,
			size_t index, size_t length);

#endif
