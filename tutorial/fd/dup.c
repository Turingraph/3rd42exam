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
	int	fd2;

	if (len != 3)
	{
		write(1, "No valid inputs.\n", 17);
		return (1);
	}
	// The owner can do everything with this file.
	// the other user can only read this file.
	fd = open(str[1], O_WRONLY | O_CREAT | O_APPEND, 0744);
	if (fd == -1)
	{
		write(2, str[1], str_length(str[1]));
		write(2, " is not valid.\n", 15);
		return (1);
	}
	// this will repeat the write operation 2 times.
	// fd2 = dup(fd);
	fd2 = dup2(fd, 67); // you can also specify the integer output using dup2.
	write(fd, str[2], str_length(str[2]));
	write(fd, "\n", 1);
	write(fd2, str[2], str_length(str[2]));
	write(fd2, "\n", 1);
	close(fd);
	close(fd2);
}
