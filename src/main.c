/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:52:27 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/19 20:31:32 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	ft_printf("a");
	if (check_argument_validity(argv) == 0 || argc < 3)
		return (ft_printf(\
		"Input format: ./push_swap <signed integers seperated by space>\n"), 0);
	if (init_stacks(argv, &stacks) == 0)
		return (0);
	print_stacks(&stacks);
	k_sort(&stacks);
	ft_printf("%d\n", stacks.operations);
	print_stacks(&stacks);
	if (VERBOSE == 1)
	{
		if (check_correctly_sorted_asc(stacks.a, stacks.height) == 1)
			ft_printf("\033[0;32mInput was correctly sorted in %d operations! \
						Yaay!\033[0m\n", stacks.operations);
		else
			ft_printf("\033[0;31mThat was not correctly sorted. \
						It took %d operations. \033[0m\n", stacks.operations);
	}
	free_stacks(&stacks);
	return (1);
}
