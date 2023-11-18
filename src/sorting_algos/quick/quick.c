/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:27:14 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/18 07:51:36 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	recursive function that...
	1. if it has more then x (e.g. 5) numbers, creates a pivot at the median 
		of its numbers and calls itself with those areas selected
	2. if it has x or less, it moves over the selected numbers to b
	3. b sorts them using bubble (if i come up with a better algo
		with push swap rules in 1 stack, use that)
	4. order them back into a.
*/

#include "../../../include/push_swap.h"

// @brief		Applies bubble sort to stack b
static void	bubble_sort_stack(t_stack_item	*stack,
								t_stacks	*stacks,
								int len)
{
	int	last_index_val;

	last_index_val = stack[len - 1].value;
	while (check_correctly_sorted(stack, len) == 0)
	{
		if (stack[0].value > stack[1].value && \
				stack[0].value != last_index_val)
			swap_stack(stack, stacks);
		else
			rotate_stack(stack, stacks);
	}
}

// selection is including start and including end.
static void	set_pivot_rec(t_stack_item	*p_s, \
							t_stack_item	*s_s, \
							t_stacks	*stacks, \
							int len)
{
	int		numbers_pushed_over;
	int		counter;

	counter = 0;
	if (len > PIVOT_THRESH)
	{
		numbers_pushed_over = push_numbers_after_median(p_s, stacks, len);
		set_pivot_rec(s_s, p_s, stacks, numbers_pushed_over);
		while (counter++ < numbers_pushed_over)
			push_to_other_stack(s_s, stacks);
		counter = 0;
		while (counter++ < len / 2)
			reverse_rotate_stack(p_s, stacks);
		set_pivot_rec(s_s, p_s, stacks, len / 2);
	}
	if (len <= PIVOT_THRESH)
	{
		bubble_sort_stack(p_s, stacks, len);
	}
}

void	quick_sort(t_stacks	*stacks)
{
	set_pivot_rec(stacks->a, stacks->b, stacks, stacks->height);
}
