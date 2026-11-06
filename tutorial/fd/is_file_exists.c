#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

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

void	show_file_status(const char *file_name, int fd)
{
	if (file_name == NULL)
		return ;
	write(1, file_name, str_length(file_name));
	write(1, " is ", 4);
	if (fd == -1)
		write(1, "not ", 4);
	write(1, "exists.", 7);
	if (fd == -1)
		perror("\t");
	write(1, "\n", 1);
}

int	main(int len, char **str)
{
	int	fd;
	int	i;
	int	flag;

	if (len < 2)
	{
		write(2, "No file names to checks.\n", 25);
		return (1);
	}
	i = 1;
	while (i < len)
	{
		fd = open(str[i], O_RDONLY);
		// the fcntl(fd, F_GETFD) is used for checking that the file exists or not.
		flag = fcntl(fd, F_GETFD);
		show_file_status(str[i], flag);
		close(fd);
		i += 1;
	}
	return (0);
}

/*
cc -Wall -Wextra -Werror is_file_exists.c
*/
