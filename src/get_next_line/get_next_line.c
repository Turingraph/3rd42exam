#include "get_next_line.h"

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

bool	assert_next_line(const t_gnl_tester *src)
{
	char	*line;
	int		fd;
	size_t	i;

	if (src == NULL || src->content == NULL || src->file_name == NULL)
		return (false);
	fd = open(src->file_name, 'r');
	if (fd < -1)
		return (false);
	i = 0;
	if (src->content[i] == NULL)
	{
		line = get_next_line(fd);
		if (assert_str(src->content[i], line) == false)
		{
			free(line);
			return (false);
		}
		return (true);
	}
	while (src->content[i] != NULL)
	{
		line = get_next_line(fd);
		if (assert_str(src->content[i], line) == false)
		{
			free(line);
			return (false);
		}
		i += 1;
		free(line);
	}
	return (true);
}
