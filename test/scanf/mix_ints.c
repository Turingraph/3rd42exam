#include "scanf.h"

int	main(void)
{
	size_t	length_of_int = 5;
	size_t	y = 0;
	int		*int_input = clone_intarr(length_of_int, -404, -404, -404, -404, -404);
	int		*int_expect = clone_intarr(length_of_int, 0, -12, 13, -404, -404);
	int		result_input;
	int		result_expect = 3;

	result_input = ft_scanf("%d %d %d %d %d", int_input, int_input + 1, int_input + 2, int_input + 3, int_input + 4);
	y += assert_intarr((const int *)int_input, (const int *)int_expect, length_of_int);
	write_score(y, length_of_int);
	if (assert_int(result_expect, result_input, 0))
		write(1, "Output is correct\n", 18);
	free(int_expect);
	free(int_input);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/scanf/mix_ints.out

*/