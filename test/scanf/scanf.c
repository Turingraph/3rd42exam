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
	char	mumu[100];
	char	cheche[100];
	char	tata[100];

	set_str(mumu, 100, '\0');
	set_str(cheche, 100, '\0');
	set_str(tata, 100, '\0');
	scanf("%s %c %s", mumu, cheche, tata);
	ft_printf(3, mumu, cheche, tata);
	if (assert_str("mumu", mumu) == true)
		write(1, "01: YES\n", 8);
	else
		write(1, "01: NO\n", 7);
	if (assert_str("c", cheche) == true)
		write(1, "02: YES\n", 8);
	else
		write(1, "02: NO\n", 7);
	if (assert_str("tata", tata) == true)
		write(1, "03: YES\n", 8);
	else
		write(1, "03: NO\n", 7);
	return (0);
}
