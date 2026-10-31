/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:40:45 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 18:43:21 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>

// integer.c

int		str_to_int(const char *str, const char *base, bool *is_int,
			size_t max_digits);
size_t	write_int(int src, const char *base, int fd);

// string.c

size_t	str_length(const char *str);
void	write_strarr(size_t length, ...);
bool	assert_str(const char *str1, const char *str2);

#endif
