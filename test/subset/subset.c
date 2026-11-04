/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:46:37 by phsottat          #+#    #+#             */
/*   Updated: 2026/11/04 19:00:55 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/subset/subset.h"

int	main(int len, char **str)
{
	int		*set;
	int		target;
	bool	is_int;

	is_int = true;
	if (len < 3)
		return (1);
	target = str_to_int(str[1], "0123456789", &is_int, 0);
	if (is_int == false)
		return (1);
	set = strarr_to_int(len - 2, (const char **)(str + 2));
	if (set == NULL)
		return (1);
	write_powerset((const int *)set, len - 2, target);
	free(set);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/subset/subset.out
*/
