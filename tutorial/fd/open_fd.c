#include <unistd.h>

/*
cc -Wall -Wextra -Werror open_fd.c
exec 42>&1
./a.out
exec 42>&-
*/

int	main(void)
{
	write(42, "Open: 42\n", 9);
	write(43, "Open: 43\n", 9);
	write(44, "Open: 44\n", 9);
	write(45, "Open: 45\n", 9);
	return (0);
}