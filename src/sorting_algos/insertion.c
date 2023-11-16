/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:33:14 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 10:54:57 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief	Finds the first element with certain value in stack
// @returns	Index of that element
static int	find_index_by_value(t_stack_item	*stack, int value)
{
	int	counter;

	counter = -1;
	while (stack[++counter].value)
		if (stack[counter].value == value)
			return (counter);
	return (-1);
}

static int	find_index_to_rotate_to(t_stacks	*stacks)
{
	int		subtraction_amount;
	int		sorted_index_of_pot_insert_point;

	subtraction_amount = 0;
	sorted_index_of_pot_insert_point = find_index_by_value \
		(stacks->sorted, stacks->a[0].value) + subtraction_amount;
	if (stacks->b[stacks->height - 1].slot_filled == 1)
		sorted_index_of_pot_insert_point = stacks->height - 1;
	if (sorted_index_of_pot_insert_point < 0)
		return (0);
	while (sorted_index_of_pot_insert_point >= 0 && \
				stacks->a[0].slot_filled != 0)
	{
		if (find_index_by_value(stacks->b, stacks-> \
						sorted[sorted_index_of_pot_insert_point].value) == -1)
			subtraction_amount--;
		else
			return (find_index_by_value(stacks->b, stacks-> \
						sorted[sorted_index_of_pot_insert_point].value));
		sorted_index_of_pot_insert_point = find_index_by_value \
			(stacks->sorted, stacks->a[0].value) + subtraction_amount;
	}
	return (0);
}

// @brief	rotates b so when pb is executed, the pushed element is sorted.
static void	rotate_b_to_perfectly_receive_slot(t_stacks	*stacks)
{
	t_stack_item		nbr_to_be_top;
	int					index_to_be_top;
	int					counter;

	counter = -1;

	index_to_be_top = find_index_to_rotate_to(stacks);
	nbr_to_be_top = stacks->b[index_to_be_top];
	while (stacks->b[0].value != nbr_to_be_top.value)
	{
		if (index_to_be_top - 0 < ft_tile_arraylen(stacks->b) \
							- index_to_be_top + 1)
		{
			rb(stacks, 1);
		}
		else
		{
			rrb(stacks, 1);
		}
		// make a descending check. if wrong, alarm!
	}
}

void	insertion_sort(t_stacks	*stacks)
{
	while (stacks->a[0].slot_filled != 0)
	{
		pb(stacks);
		rotate_b_to_perfectly_receive_slot(stacks);
	}
	// rotate correctly
	while (stacks->b[0].slot_filled != 0)
	{
		pa(stacks);
	}
	// push over one element.
	// now, move b until the element at top of a can be pushed again and will be in order
	// find the highest number and rotate it to top
	// push everything back over
}
