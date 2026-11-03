#include "get_next_line.h"

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

size_t	index_of_a(char a, const char *src, bool include_last)
{
	size_t	i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == a && include_last == false)
			return (i);
		if (src[i] == a && include_last == true)
			return (i + 1);
		i += 1;
	}
	if (include_last == true)
		return (i);
	return (0);
}
