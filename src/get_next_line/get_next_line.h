#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct t_str_dynamic
{
	char	*arr;
	size_t	length;
	size_t	capacity;
}	t_str_dynamic;

typedef struct t_gnl_tester
{
	const char	*file_name;
	const char	**content;
}	t_gnl_tester;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

// debug.c

bool	assert_next_line(const t_gnl_tester *src);

// get_next_line.c

char	*get_all_line(int fd, size_t buffer_length);
char	*get_next_line(int fd);

// utils.c

t_str_dynamic	clone_str_dynamic(char *src, size_t max_length);
bool	push_str_dynamic(t_str_dynamic *dst, char src);
void	concat_str_dynamic(t_str_dynamic *dst, const char *src);
size_t	index_of_a(char a, const char *src, bool include_last);

#endif
