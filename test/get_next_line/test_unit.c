#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test/get_next_line/input/multiple_line_with_nl", 'r');
	if (fd < -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		write(1, ">>> ", 4);
		write(1, line, str_length(line));
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/get_next_line/test_unit.out
*/
