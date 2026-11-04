/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:31:54 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 17:46:11 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	str_length(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

void	write_strargs(size_t length, ...)
{
	size_t	i;
	va_list	args;
	char	*output;

	if (length == 0)
		return ;
	va_start(args, length);
	i = 0;
	while (i < length)
	{
		output = va_arg(args, char *);
		if (output != NULL)
			write(1, output, str_length(output));
		write(1, "\n", 1);
		i += 1;
	}
	va_end(args);
}

void	set_str(char *dst, size_t length, char c)
{
	size_t	i;

	if (dst == NULL || length == 0)
		return ;
	i = 0;
	while (i < length)
	{
		dst[i] = c;
		i += 1;
	}
}

bool	is_a_in_str(char a, const char *str)
{
	size_t	i;

	if (str == NULL || *str == '\0')
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (true);
		i += 1;
	}
	return (false);
}

bool	is_a_in_int(int a, const int *str, size_t length)
{
	size_t	i;

	if (str == NULL || length == 0)
		return (false);
	i = 0;
	while (i < length)
	{
		if (str[i] == a)
			return (true);
		i += 1;
	}
	return (false);
}
