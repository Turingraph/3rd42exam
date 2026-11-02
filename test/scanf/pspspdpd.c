#include "scanf.h"

int	main(void)
{
	size_t	length_of_str = 2;
	size_t	length_of_int = 5;
	size_t	y = 0;
	int		*int_input = clone_intarr(length_of_int, -404, -404, -404, -404, -404);
	int		*int_expect = clone_intarr(length_of_int, -6498,	-121073,	56,	3940,	0);
	char	**str_input = clone_strarr(100,  length_of_str, NULL, NULL);
	char	**str_expect = clone_strarr(100, length_of_str, "Mumu", "Tata");

	ft_scanf("%s %s %d %d %d %d %d", str_input[0], str_input[1],
		int_input, int_input + 1, int_input + 2, int_input + 3, int_input + 4);
	y = assert_strarr((const char **)str_expect, (const char **)str_input, length_of_str);
	y += assert_int((const int *)int_input, (const int *)int_expect, length_of_int);
	write_score(y, length_of_str + length_of_int);
	free_strarr(str_input, length_of_str);
	free_strarr(str_expect, length_of_str);
	free(int_expect);
	free(int_input);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/scanf/pspspdpd.out
*/
