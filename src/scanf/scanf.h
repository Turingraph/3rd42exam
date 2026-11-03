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

size_t	count_args(const char *str);
int 	type_from_args(const char *str, size_t ith);

// match.c

bool	match_args(const char *str, size_t ith, va_list args, int *cc);

// scan.c

int		ft_scanf(const char *str, ...);
void	write_userinput(void);

#endif
