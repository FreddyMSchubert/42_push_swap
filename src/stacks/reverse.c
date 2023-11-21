/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:35:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 06:55:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/*
	@brief		rra (reverse rotate a) -> Shift down all elements of stack a 
				by 1. The last becomes the first.
*/
void	rra(t_stacks	*stacks, int print)
{
	int		temp_val;
	int		temp_fill;
	int		temp_sort;
	int		i;

	if (stacks->a[0].slot_filled != 0)
	{
		stacks->operations++;
		if (print == 1)
			print_colored("rra", 'b');
		i = stacks->a_height - 1;
		temp_val = stacks->a[stacks->a_height - 1].value;
		temp_fill = stacks->a[stacks->a_height - 1].slot_filled;
		temp_sort = stacks->a[stacks->a_height - 1].sorted_index;
		while (--i >= 0)
			swap_item_properties(&stacks->a[i + 1], &stacks->a[i]);
		stacks->a[0].slot_filled = temp_fill;
		stacks->a[0].value = temp_val;
		stacks->a[0].value = temp_sort;
		turn_on_gravity(stacks);
		if (VERBOSE == 1 && print == 1)
			print_stacks(stacks);
	}
}

/*
	@brief		rrb (reverse rotate b) -> Shift down all elements of stack b 
				by 1. The last becomes the first.
*/
void	rrb(t_stacks	*stacks, int print)
{
	int		temp_val;
	int		temp_fill;
	int		temp_sort;
	int		i;

	if (stacks->b[0].slot_filled != 0)
	{
		stacks->operations++;
		if (print == 1)
			print_colored("rrb", 'b');
		i = stacks->b_height - 1;
		temp_val = stacks->b[stacks->b_height - 1].value;
		temp_fill = stacks->b[stacks->b_height - 1].slot_filled;
		temp_sort = stacks->b[stacks->b_height - 1].sorted_index;
		while (--i >= 0)
			swap_item_properties(&stacks->b[i + 1], &stacks->b[i]);
		stacks->b[0].slot_filled = temp_fill;
		stacks->b[0].value = temp_val;
		stacks->b[0].sorted_index = temp_sort;
		turn_on_gravity(stacks);
		if (VERBOSE == 1 && print == 1)
			print_stacks(stacks);
	}
}

/*
	@brief		rrr (reverse rotate 2) -> Shift down all elements of both stacks
				by 1. The last becomes the first.
*/
void	rrr(t_stacks	*stacks)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	stacks->operations--;
	print_colored("rrr", 'b');
	if (VERBOSE == 1)
		print_stacks(stacks);
}
