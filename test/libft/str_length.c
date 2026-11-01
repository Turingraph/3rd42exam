/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:24:57 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 18:39:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	size_t	expected_answer[] = {7, 9, 8, 6, 9, 7};
	char	*arr[] = {
		"Yoasobi", "Yorushika", "Zutomayo", "Yonezu", "Radiohead", "Nujabes"
	};
	size_t	length = 6;
	size_t	i = 0;
	size_t	score = 0;

	while (i < length)
	{
		if (str_length(arr[i]) == expected_answer[i])
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			write_int(i, "0123456789", 1);
			write(1, " is wrong\n", 10);
		}
		i += 1;
	}
	write_score(score, length);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/libft/str_length.out
*/
