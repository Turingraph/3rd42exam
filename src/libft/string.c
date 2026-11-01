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

char	*clone_str(const char *src, size_t max_length)
{
	char	*dst;
	size_t	i;

	dst = malloc(sizeof(char) * (max_length + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (src != NULL && src[i] != '\0' && i < max_length)
	{
		dst[i] = src[i];
		i += 1;
	}
	while (i < max_length)
	{
		dst[i] = '\0';
		i += 1;
	}
	return (dst);
}

void	free_strarr(char **dst, size_t length)
{
	size_t	i;

	if (dst == NULL)
		return ;
	i = 0;
	while (i < length)
	{
		free(dst[i]);
		i += 1;
	}
	free(dst);
}

char	**clone_strarr(size_t max_length, size_t arr_length, ...)
{
	char	*src;
	char	**dst;
	va_list	args;
	size_t	i;

	if (arr_length == 0)
		return (NULL);
	dst = malloc(sizeof(char *) * (arr_length + 1));
	if (dst == NULL)
		return (NULL);
	dst[arr_length] = NULL;
	va_start(args, arr_length);
	i = 0;
	while (i < arr_length)
	{
		src = va_arg(args, char *);
		dst[i] = clone_str((const char *)src, max_length);
		if (dst[i] == NULL)
		{
			free_strarr(dst, i);
			return (NULL);
		}
		i += 1;
	}
	va_end(args);
	return (dst);
}
