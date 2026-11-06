#include <fcntl.h>
#include <unistd.h>

int	str_length(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

int	main(int len, char **str)
{
	int	fd;
	int	i;
	int	write_state;

	if (len < 2)
	{
		write(1, "No valid inputs.\n", 17);
		return (1);
	}
	// The owner can do everything with this file.
	// the other user can only read this file.
	fd = open(str[1], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd == -1)
	{
		write(2, str[1], str_length(str[1]));
		write(2, " is not valid.\n", 15);
		return (1);
	}
	i = 2;
	while (i < len)
	{
		write_state = write(fd, str[i], str_length(str[i]));
		if (write_state != str_length(str[i]))
			close(fd);
		if (write_state != str_length(str[i]))
			return (1);
		write_state = write(fd, "\n", 1);
		if (write_state != 1)
			close(fd);
		if (write_state != 1)
			return (1);
		i += 1;
	}
	close(fd);
	return (0);
}

/*
cat myfile.txt | xxd
// this command show the Hexadecimal representation of string data.

cc -Wall -Wextra -Werror reinvent_wheel.c
valgrind --leak-check=full --show-leak-kinds=all ./a.out
// this 2 files are used for checking if the code works or not.
/dev/full // you cannot write anything because there is no empty space left.
/dev/null // you can write anything
*/
