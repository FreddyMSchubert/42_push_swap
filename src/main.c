/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:52:27 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 23:04:14 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	execute_sorting_algos(t_stacks	*stacks)
{
	if (VERBOSE == 1)
	{
		ft_printf("\033[31mK SORT!\n");
		k_sort(stacks);
		ft_printf("\033[32mBUBBLE SORT!\n");
		bubble_sort(stacks);
		ft_printf("\033[33mINSERTION SORT!\n");
		insertion_sort(stacks);
		ft_printf("\033[0m");
	}
	else
	{
		bubble_sort(stacks);
		insertion_sort(stacks);
		k_sort(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (check_argument_validity(argv) == 0 || argc < 3)
		return (ft_printf(\
		"Input format: ./push_swap <signed integers seperated by space>\n"), 0);
	if (init_stacks(argv, &stacks) == 0)
		return (0);
	execute_sorting_algos(&stacks);
	print_best_result(&stacks);
	free_stacks(&stacks);
	return (1);
}
