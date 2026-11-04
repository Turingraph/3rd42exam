/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:54:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 18:00:44 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/permutation/permutation.h"

int	main(int len, char **input)
{
	int	*str;
	int	number_queens;
	int	*mark;
	bool	is_int = true;

	if (len != 2 || is_unique_str(input[1]) == false)
		return (1);
	number_queens = str_to_int(input[1], "0123456789", &is_int, 0);
	if (is_int == false || number_queens < 0)
		return (1);
	mark = create_intarr((size_t)number_queens);
	set_intarr(mark, (size_t)number_queens, -1);
	str = create_intarr((size_t)number_queens);
	if (str == NULL || mark == NULL)
		return (1);
	write_n_queens(str, mark, 0, (size_t)number_queens);
	free(str);
	free(mark);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/permutation/n_queen.out abc
*/
