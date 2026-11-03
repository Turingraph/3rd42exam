```
#include "get_next_line.h"

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

/*
1st Mistake I made in 3rd Nov 2026

```
size_t	index_of_a(...)
...
	// This line is problematic because you will forget the '\n' for 
	// the last output of get_next_line (in case the file end with '\n')
	if (src[i] == a && (include_last == false || src[i + 1] == '\0))
		return (i);
	if (src[i] == a && include_last == true)
		return (i + 1);
...
```
*/

size_t	index_of_a(char a, const char *src, bool include_last)
{
	size_t	i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == a && (include_last == false || src[i + 1] == '\0'))
			return (i);
		if (src[i] == a && include_last == true)
			return (i + 1);
		i += 1;
	}
	if (include_last == true)
		return (i);
	return (0);
}


/*
2nd Mistake I made in 3rd Nov 2026

```
char	*get_all_line(...)
...
	read(fd, buff.arr, buffer_length);
	concat_str_dynamic(&dst, buff.arr);
	// buff.length is 0, so you will get only one line and forget every other lines.
	if (buff.length < buffer_length)
		is_loop = false;
...
```
*/

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

char	*get_next_line(int fd)
{
	static char		*all_str = NULL;
	static size_t	index = 0;
	char			*dst;
	size_t			length;

	if (fd < -1)
		return (NULL);
	if (all_str == NULL)
		all_str = get_all_line(fd, BUFFER_SIZE);
	if (all_str == NULL)
		return (NULL);
	length = index_of_a('\n', all_str + index, true);
	dst = clone_str_dynamic(all_str + index, length).arr;
	if (all_str[index + length] == '\0')
	{
		free(all_str);
		all_str = NULL;
		index = 0;
	}
	else
		index += length;
	return (dst);
}
```

Things to consider
1.	static strall = NULL, index = 0;
2.	implement get_all_line with dynamic array
3.	length = index_of_a('\n', strall + index, include_char = true)
4.	dst = clone_str(dst + index, length)
5.	if (dst[index + length] == '\0'), then reset dst and index
6.	if (dst[index + length] != NULL), then index += length
7.	be careful about index_of_a and clone_str
