/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:52:27 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 08:39:30 by fschuber         ###   ########.fr       */
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

	if (check_argument_validity(argv) == 0 || argc < 3)
		return (ft_printf(\
		"Input format: ./push_swap <signed integers seperated by space>\n"), 0);
	if (init_stacks(argv, &stacks) == 0)
		return (0);
	start_sort_algo(&stacks);
	free_stacks(&stacks);
	ft_printf("%d\n", stacks.operations);
	return (1);
}
