/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:02:28 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 19:19:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanf.h"

int	main(void)
{
	size_t	length = 3;
	size_t	y = 0;
	char	**str_input = clone_strarr(100,  length, NULL, NULL, NULL);
	char	**str_expect = clone_strarr(100, length, "Mumu", "Cheche", "Tata");

	ft_scanf("%s %s %s", str_input[0], str_input[1], str_input[2]);
	write_strargs(length, str_input[0], str_input[1], str_input[2]);
	y = assert_strarr((const char **)str_expect, (const char **)str_input, length);
	write_score(y, length);
	free_strarr(str_input, length);
	free_strarr(str_expect, length);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/scanf/strs.out

*/