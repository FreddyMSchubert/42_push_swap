/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:52:27 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 11:18:03 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	start_sort_algo(t_stacks	*stacks)
{
	if (stacks->height < 5)
	{
		bubble_sort(stacks);
		if (VERBOSE == 1)
			ft_printf("did bubble sort!\n");
	}
	else if (stacks->height < 10)
	{
		cheap_quick_sort(stacks);
		if (VERBOSE == 1)
			ft_printf("did cheap quick sort!\n");
	}
	else
	{
		k_sort(stacks);
		if (VERBOSE == 1)
			ft_printf("did k sort!\n");
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (check_argument_validity(argv) == 0 || argc < 2)
		exit_error("Format: ./push_swap <signed integers seperated by space>\n"\
					, NULL);
	if (init_stacks(argv, &stacks) == 0)
		exit_error("Stack initialization failed.\n"\
					, NULL);
	start_sort_algo(&stacks);
	free_stacks(&stacks);
	if (VERBOSE == -1)
		ft_printf("%d\n", stacks.operations);
	return (1);
}
