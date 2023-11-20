/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:33:14 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 22:43:10 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief		returns the next lower available value in b.
// @brief		if unavailable, it starts at top again.
// @brief		if looped once, it returns index 0 (though that shouldnt happen)
// @returns		index in b to found value
static int	find_index_to_rotate_to(t_stacks	*stacks)
{
	int		selected_index_in_sorted;

	selected_index_in_sorted = \
		find_index_by_value(stacks->sorted, stacks->a[0].value, stacks->height);
	while (find_index_by_value(stacks->b, \
			stacks->sorted[selected_index_in_sorted].value, \
									stacks->b_height) == -1)
	{
		selected_index_in_sorted--;
		if (selected_index_in_sorted < 0)
			selected_index_in_sorted = stacks->height - 1;
	}
	return (find_index_by_value(stacks->b, \
						stacks->sorted[selected_index_in_sorted].value, \
						stacks->b_height));
}

// @brief	rotates b so when pb is executed, the pushed element is sorted.
static void	rotate_b_to_perfectly_receive_slot(t_stacks	*stacks)
{
	t_stack_item		nbr_to_be_top;
	int					index_to_be_top;

	if (stacks->a[0].slot_filled == 0)
		index_to_be_top = find_index_by_value(stacks->b, \
					stacks->sorted[stacks->height - 1].value, stacks->height);
	else
		index_to_be_top = find_index_to_rotate_to(stacks);
	nbr_to_be_top = stacks->b[index_to_be_top];
	while (stacks->b[0].value != nbr_to_be_top.value)
	{
		if (index_to_be_top - 0 < stacks->b_height - index_to_be_top + 1)
			do_operation(stacks, &stacks->insert_result, "rb");
		else
			do_operation(stacks, &stacks->insert_result, "rrb");
	}
}

void	insertion_sort(t_stacks	*stacks)
{
	while (stacks->a[0].slot_filled != 0)
		do_operation(stacks, &stacks->insert_result, "pb");
	while (stacks->b[0].value != stacks->sorted[stacks->height - 1].value)
		rotate_b_to_perfectly_receive_slot(stacks);
	while (stacks->b[0].slot_filled != 0)
		do_operation(stacks, &stacks->insert_result, "pa");
}
