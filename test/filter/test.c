#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct t_str_dynamic
{
	char	*arr;
	size_t	length;
	size_t	capacity;
}	t_str_dynamic;

t_str_dynamic	clone_str_dynamic(char *src, size_t max_length)
{
	size_t	i;
	t_str_dynamic	dst;

	dst.capacity = 0;
	dst.length = 0;
	dst.arr = NULL;
	if (max_length == 0)
		return (dst);
	dst.arr = malloc(sizeof(char) * (max_length + 1));
	if (dst.arr == NULL)
		return (dst);
	dst.capacity = max_length;
	i = 0;
	while (src != NULL && src[i] != '\0' && i < max_length)
	{
		dst.arr[i] = src[i];
		dst.length += 1;
		i += 1;
	}
	while (i <= max_length)
	{
		dst.arr[i] = '\0';
		i += 1;
	}
	return (dst);
}

bool	push_str_dynamic(t_str_dynamic *dst, char src)
{
	t_str_dynamic	dst2;

	if (dst == NULL || dst->capacity == 0)
		return (false);
	if (dst->length < dst->capacity && dst->arr != NULL)
	{
		dst->arr[dst->length] = src;
		dst->length += 1;
		return (true);
	}
	dst2 = clone_str_dynamic(dst->arr, dst->capacity * 2);
	if (dst2.arr == NULL)
		return (false);
	free(dst->arr);
	*dst = dst2;
	return (push_str_dynamic(dst, src));
}

void	concat_str_dynamic(t_str_dynamic *dst, const char *src)
{
	size_t	i;
	bool	is_loop;

	is_loop = true;
	i = 0;
	while (src != NULL && src[i] != '\0' && is_loop == true)
	{
		if (push_str_dynamic(dst, src[i]) == false)
			is_loop = false;
		i += 1;
	}
}

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

bool	is_match_filter(const char *str, const char *filter)
{
	size_t	i;

	if (filter == NULL || filter[0] == '\0')
		return (false);
	i = 0;
	while (filter[i] != '\0')
	{
		if (str[i] != filter[i])
			return (false);
		i += 1;
	}
	return (true);
}

void	write_repeat(char a, size_t len)
{
	while (len > 0)
	{
		write(1, &a, 1);
		len -= 1;
	}
}

void	write_filter(const char *str, const char *filter)
{
	size_t	i;
	size_t	filter_length;

	filter_length = str_length(filter);
	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		if (is_match_filter(str + i, filter) == false)
		{
			write(1, str + i, 1);
			i += 1;
		}
		else
		{
			write_repeat('*', filter_length);
			i += filter_length;
		}
	}
}

char	*get_all_line(int fd, size_t buffer_length)
{
	t_str_dynamic	buff;
	t_str_dynamic	dst;
	bool	is_loop;

	is_loop = true;
	if (fd < -1 || buffer_length == 0)
		return (NULL);
	dst = clone_str_dynamic(NULL, 1);
	if (dst.arr == NULL)
		return (NULL);
	while (is_loop == true)
	{
		buff = clone_str_dynamic(NULL, buffer_length);
		if (buff.arr == NULL)
			is_loop = false;
		else
		{
			read(fd, buff.arr, buffer_length);
			buff.length = str_length(buff.arr);
			concat_str_dynamic(&dst, buff.arr);
			if (buff.length < buffer_length)
				is_loop = false;
		}
		free(buff.arr);
	}
	close(fd);
	return (dst.arr);
}

int	main(int len, char **str)
{
	char	*answer;

	if (len != 2)
		return (1);
	answer = get_all_line(STDIN_FILENO, 100);
	if (answer == NULL)
		return (1);
	write_filter(answer, str[1]);
	free(answer);
	return (0);
}

/*
cc -Wall -Wextra -Werror test/filter/test.c -o test/filter/test.out
valgrind --leak-check=full --show-leak-kinds=all ./test/filter/test.out
*/
