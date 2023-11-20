/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:06:53 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 16:15:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file contains all possible swap actions. */

#include "../../include/push_swap.h"

void	sa(t_stacks	*stacks, int print_stack)
{
	stacks->operations++;
	print_colored("sa\n", 'r');
	if (stacks->a[0].slot_filled && stacks->a[1].slot_filled)
	{
		swap_item_properties(&stacks->a[0], &stacks->a[1]);
		if (VERBOSE == 1 && print_stack == 1)
			print_stacks(stacks);
	}
	else if (VERBOSE == 1)
		ft_printf("There was one or no elements to swap. Doing nothing.\n");
}

void	sb(t_stacks	*stacks, int print_stack)
{
	stacks->operations++;
	print_colored("sb\n", 'r');
	if (stacks->b[0].slot_filled && stacks->b[1].slot_filled)
	{
		swap_item_properties(&stacks->b[0], &stacks->b[1]);
		if (VERBOSE == 1 && print_stack == 1)
			print_stacks(stacks);
	}
	else if (VERBOSE == 1)
		ft_printf("There was one or no elements to swap. Doing nothing.\n");
}

void	ss(t_stacks	*stacks)
{
	stacks->operations--;
	print_colored("ss\n", 'r');
	sa(stacks, 0);
	sb(stacks, 0);
	if (VERBOSE == 1)
		print_stacks(stacks);
}
