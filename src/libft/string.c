/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:31:54 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 16:33:56 by phsottat         ###   ########.fr       */
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

void	write_strarr(size_t length, ...)
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

bool	assert_str(const char *str1, const char *str2)
{
	size_t	i;

	if (str1 == NULL || str2 == NULL)
		return (false);
	i = 0;
	while (str1[i] != '\0' && str2[i] == str1[i])
		i += 1;
	if (str1[i] != str2[i])
		return (false);
	return (true);
}

