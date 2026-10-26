/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:08:53 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/26 18:30:20 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool	subslop_matching(const char *src, const char *abc)
{
	size_t	i;

	if (src == NULL || abc == NULL)
		return (false);
	i = 0;
	while (src[i] != '\0' && src[i] == abc[i])
		i += 1;
	if (abc[i] == '\0')
		return (true);
	return (false);
}

// time : O(n)
// space: O(1)
size_t	str_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str != NULL && *str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}

void	slop_matching(const char *src, const char *abc, size_t length)
{
	size_t	i;
	size_t	j;

	if (src == NULL || abc == NULL)
		return ;
	i = 0;
	while (src[i] != '\0' && i < length)
	{
		if (subslop_matching(src + i, abc) == true)
		{
			j = str_length(abc);
			while (j > 0)
			{
				write(1, "*", 1);
				j -= 1;
			}
			i += str_length(abc);
		}
		else
		{
			write(1, src + i, 1);
			i += 1;
		}
	}
}

char	*concat_str(const char *str1, const char *str2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (str_length(str1) == 0 && 0 == str_length(str2))
		return (NULL);
	dst = malloc(sizeof(char) * (str_length(str1) + str_length(str2) + 1));
	if (dst == NULL)
		return (NULL);
	dst[str_length(str1) + str_length(str2)] = '\0';
	i = 0;
	while (str1[i] != '\0')
	{
		dst[i] = str1[i];
		i += 1;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		dst[i + j] = str2[j];
		j += 1;
	}
	return (dst);
}

/**
 * Allocate and initialize a memory block with zero values.
 * Print a message to stdout if allocation fails and comment is provided.
 *
 * time/space: O(n) / O(n)
 *
 * status: internal helper
 * 
 * @param elem_size size of the memory block in bytes
 * @param comment message to print when allocation fails
 *
 * @return pointer to the initialized memory block, or NULL on failure
 */
void	*malloc_talk(size_t elem_size, const char *comment)
{
	size_t			i;
	unsigned char	*d;
	void			*dst;

	if (elem_size == 0)
		return (NULL);
	dst = (void *)malloc(elem_size);
	if (dst == NULL)
	{
		if (comment != NULL && *comment != '\0')
		{
			write(1, "Malloc Fail: ", 14);
			write(1, comment, str_length(comment));
		}
		return (NULL);
	}
	d = (unsigned char *)dst;
	i = 0;
	while (i < elem_size)
	{
		*d = 0;
		d += 1;
		i += 1;
	}
	return (dst);
}

char	*read_loop()
{
	char	*concat_dst;
	char	*dst;
	char	*temp;

	dst = malloc_talk(sizeof(char) * (42), "read_loop\n");
	if (dst == NULL)
		return (NULL);
	read(STDIN_FILENO, dst, 42);
	if (str_length(dst) < 42)
		return (dst);
	while (str_length(dst) == 42)
	{
		concat_dst = dst;
		dst = malloc_talk(sizeof(char) * (42), "read_loop\n");
		if (dst == NULL)
			return (concat_dst);
		read(STDIN_FILENO, dst, 42);
		temp = concat_str(concat_dst, dst);
		free(concat_dst);
		concat_dst = temp;
	}
	free(dst);
	return (concat_dst);
}

size_t	find_last_new(const char *str, size_t maxx)
{
	if (str == NULL)
		return (0);
	while (maxx > 0)
	{
		if (str[maxx - 1] == '\n')
			return (maxx - 1);
		maxx -= 1;
	}
	return (0);
}

int	main(int len, char **arg)
{
	char	*input2;
	size_t	length;

	if (len != 2)
		return (1);
	input2 = read_loop();
	length = str_length(input2);
	slop_matching(input2, arg[1], length);
	free(input2);
	return (0);
}
