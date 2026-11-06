#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int len, char **str)
{
	int	fd;

	if (len != 3)
		return (1);
	fd = open(str[1], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	dup2(fd, 1);
	printf("Write: %s\n", str[2]);
	close(fd);
}
