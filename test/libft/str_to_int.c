/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:05:39 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 19:18:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int	expected_answer[] = {10101, -2, 2147483647, -2147483648, 0, 404, 1, 2, -1, 84237, 67};
	char	*arr[] = {
		"Yoasobi", "Yorushika", "Zutomayo", "Yonezu", "Radiohead", "2147483648",
        "-2147483649", "", "          ", "1010dog", "sixseven"
	};
	char	*arr2[] = {
		"10101", "-2", "2147483647", "-2147483648", "0", "404", "1", "2", "-1",
        "84237", "67"
	};
	size_t	maxx = 11;
	size_t	i = 0;
	size_t	score = 0;
    bool    is_bool;

	while (i < maxx)
	{
        is_bool = true;
		if (str_to_int(arr[i], "0123456789", &is_bool, 0) == -1 && is_bool == false)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			write_int(i, "0123456789", 1);
			write(1, "\t", 1);
			write_int(str_to_int(arr2[i], "0123456789", &is_bool, 0), "0123456789", 1);
            write(1, "\n", 1);
		}
		i += 1;
	}
    i = 0;
	while (i < maxx)
	{
        is_bool = true;
		if (str_to_int(arr2[i], "0123456789", &is_bool, 0) == expected_answer[i] && is_bool == true)
			score += 1;
		else
		{
			write(1, "<<< ", 4);
			write_int(i, "0123456789", 1);
			write(1, "\t", 1);
			write_int(str_to_int(arr2[i], "0123456789", &is_bool, 0), "0123456789", 1);
            write(1, "\n", 1);
		}
		i += 1;
	}
	write(1, "score: ", 7);
	write_int(score, "0123456789", 1);
	write(1, " / ", 3);
	write_int(maxx * 2, "0123456789", 1);
	write(1, "\n", 1);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/libft/str_to_int.out
*/
