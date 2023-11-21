/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:06:53 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 16:04:46 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file contains all possible swap actions. */

#include "../../include/push_swap.h"

// @brief		sa (swap a) -> Swap the first two elements at the top of stack a
void	sa(t_stacks	*stacks, int print)
{
	if (stacks->a[0].slot_filled && stacks->a[1].slot_filled)
	{
		stacks->operations++;
		if (print == 1)
			print_colored("sa", 'g');
		swap_item_properties(&stacks->a[0], &stacks->a[1]);
		if (VERBOSE == 1)
			print_stacks(stacks);
	}
	else if (VERBOSE == 1)
		ft_printf("There was one or no elements to swap. Doing nothing.\n");
}

// @brief		sb (swap b) -> Swap the first two elements at the top of stack b
void	sb(t_stacks	*stacks, int print)
{
	if (stacks->b[0].slot_filled && stacks->b[1].slot_filled)
	{
		stacks->operations++;
		if (print == 1)
			print_colored("sb", 'g');
		swap_item_properties(&stacks->b[0], &stacks->b[1]);
		if (VERBOSE == 1)
			print_stacks(stacks);
	}
	else if (VERBOSE == 1)
		ft_printf("There was one or no elements to swap. Doing nothing.\n");
}

// @brief	ss (swap 2) -> Swap the first two elements at the top of both stacks
void	ss(t_stacks	*stacks, int print)
{
	sa(stacks, 0);
	sb(stacks, 0);
	stacks->operations--;
	if (print == 1)
		print_colored("ss", 'g');
	if (VERBOSE == 1)
		print_stacks(stacks);
}
