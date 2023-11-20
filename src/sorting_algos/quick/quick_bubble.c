/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_bubble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:24:36 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 07:12:29 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bubble sorting specifically optimized for the circumstances in the
// base case of quick sort

#include "../../../include/push_swap.h"

// @brief			Applies bubble sort to stack b ascendingly
// @param mode 0	it goes through to end swapping out of order items
// @param mode 1	it goes back from end to start switching to 0 if something
// 				is out of order.
void	bubble_sort_stack_ascending(t_stack_item	*stack, \
								t_stacks	*stacks, \
								int len)
{
	int	rotations;

	rotations = 0;
	while (check_correctly_sorted_asc(stack, len - rotations) == 0)
	{
		if (stack[0].value > stack[1].value)
			swap_stack(stack, stacks);
		else
		{
			rotate_stack(stack, stacks);
			rotations++;
		}
		while (check_correctly_sorted_asc(stack, len - rotations) == 1 && \
							rotations > 0)
		{
			reverse_rotate_stack(stack, stacks);
			rotations--;
			if (check_correctly_sorted_asc(stack, len - rotations) == 0)
				break ;
		}
	}
}

// @brief		Applies bubble sort to stack b descendingly
void	bubble_sort_stack_descending(t_stack_item	*stack, \
								t_stacks	*stacks, \
								int len)
{
	int	rotations;

	rotations = 0;
	while (check_correctly_sorted_des(stack, len - rotations) == 0)
	{
		if (stack[0].value < stack[1].value)
			swap_stack(stack, stacks);
		else
		{
			rotate_stack(stack, stacks);
			rotations++;
		}
		while (check_correctly_sorted_des(stack, len - rotations) == 1 && \
							rotations > 0)
		{
			reverse_rotate_stack(stack, stacks);
			rotations--;
			if (check_correctly_sorted_des(stack, len - rotations) == 0)
				break ;
		}
	}
}
