/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:23:40 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 19:01:10 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANF_H
# define SCANF_H

# include "../libft/libft.h"
# include <ctype.h>

// count.c

bool	is_continue(int cc);
size_t	args_length(const char *str);
size_t	count_args(const char *str);
int 	type_from_args(const char *str, size_t ith);

// match.c

void	match_char(FILE *stream, int *cc, char *dst);
void	match_str(FILE *stream, int *cc, char *dst);
void	match_int(FILE *stream, int *cc, char *dst);
void	match_args(const char *str, size_t ith, va_list args, int *cc);

// scan.c

void	ft_scanf(const char *str, ...);
void	set_str(char *dst, size_t length, char c);

#endif
