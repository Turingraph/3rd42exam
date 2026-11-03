#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test/get_next_line/input/alternate_line_nl_with_nl", 'r');
	if (fd < -1)
		return (1);
	line = get_all_line(fd, BUFFER_SIZE);
	write(1, ">>> ", 4);
	write(1, line, str_length(line));
	free(line);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/get_next_line/all_line.out
*/
