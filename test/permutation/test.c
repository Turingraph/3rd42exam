/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:54:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 14:38:31 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/permutation/permutation.h"

int	main(int len, char **str)
{
	char	*mark;

	if (len != 2 || is_unique_str(str[1]) == false)
		return (1);
	mark = malloc(sizeof(char) * (str_length(str[1]) + 1));
	if (mark == NULL)
		return (1);
	mark[str_length(str[1])] = '\0';
	set_str(mark, str_length(str[1]), '0');
	write_permutations(str[1], mark, 0, str_length(str[1]));
	free(mark);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/permutation/test.out
*/
