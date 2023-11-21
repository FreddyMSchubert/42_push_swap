/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:35:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 08:24:16 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	@brief		ra (rotate a) -> Shift up all elements of stack a by 1. 
				The first becomes the last.
*/
void	ra(t_stacks	*stacks, int print)
{
	int		temp_val;
	int		temp_fill;
	int		temp_sort;
	int		i;

	i = 0;
	stacks->operations++;
	if (print == 1)
		print_colored("ra", 'y');
	temp_val = stacks->a[0].value;
	temp_fill = stacks->a[0].slot_filled;
	temp_sort = stacks->a[0].sorted_index;
	while (++i < stacks->height)
		swap_item_properties(&stacks->a[i - 1], &stacks->a[i]);
	i--;
	stacks->a[i].slot_filled = temp_fill;
	stacks->a[i].value = temp_val;
	stacks->a[i].sorted_index = temp_sort;
	turn_on_gravity(stacks);
	if (VERBOSE == 1)
		print_stacks(stacks);
}

/*
	@brief		rb (rotate b) -> Shift up all elements of stack b by 1. 
				The first becomes the last.
*/
void	rb(t_stacks	*stacks, int print)
{
	int		temp_val;
	int		temp_fill;
	int		temp_sort;
	int		i;

	i = 0;
	stacks->operations++;
	if (print == 1)
		print_colored("rb", 'y');
	temp_val = stacks->b[0].value;
	temp_fill = stacks->b[0].slot_filled;
	temp_sort = stacks->b[0].sorted_index;
	while (++i < stacks->height)
		swap_item_properties(&stacks->b[i - 1], &stacks->b[i]);
	i--;
	stacks->b[i].slot_filled = temp_fill;
	stacks->b[i].value = temp_val;
	stacks->b[i].sorted_index = temp_sort;
	turn_on_gravity(stacks);
	if (VERBOSE == 1)
		print_stacks(stacks);
}

/*
	@brief		rr (rotate 2) -> Shift up all elements of both stacks by 1. 
				The first becomes the last.
*/
void	rr(t_stacks	*stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	stacks->operations--;
	print_colored("rr", 'y');
	if (VERBOSE == 1)
		print_stacks(stacks);
}
