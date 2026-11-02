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
# include <stdlib.h>

// assert.c

bool	assert_str(const char *str1, const char *str2);
size_t	assert_strarr(const char **str1, const char **str2, size_t length);
size_t	assert_int(const int *int1, const int *int2, size_t length);

// clone.c

char	*clone_str(const char *src, size_t max_length);
void	free_strarr(char **dst, size_t length);
char	**clone_strarr(size_t max_length, size_t arr_length, ...);
int		*clone_intarr(size_t arr_length, ...);

// integer.c

int		base_to_int(const char *base, char coef);
int		str_to_int(const char *str, const char *base, bool *is_int,
			size_t max_digits);
size_t	write_int(int src, const char *base, int fd);
void	write_score(size_t score, size_t max_score);

// string.c

size_t	str_length(const char *str);
void	write_strargs(size_t length, ...);
void	set_str(char *dst, size_t length, char c);
bool	is_a_in_str(char a, const char *str);

#endif
