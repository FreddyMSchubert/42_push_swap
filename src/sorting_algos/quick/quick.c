/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:27:14 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/19 09:23:28 by fschuber         ###   ########.fr       */
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

// @brief		Applies bubble sort to stack b ascendingly
static void	bubble_sort_stack_ascending(t_stack_item	*stack,
								t_stacks	*stacks,
								int len)
{
	int	last_index_val;
	int	counter;
	int	rotations;

	ft_printf("Applying ascending bubble sort with length %d!\n", len);
	counter = 0;
	rotations = 0;
	last_index_val = stack[0].value;
	while (counter < len)
	{
		if (stack[counter].value > last_index_val)
			last_index_val = stack[counter].value;
		ft_printf("loop %d, curr highest num is %d.\n", counter, last_index_val);
		counter++;
	}
	ft_printf("last index val: %d\n", last_index_val);
	while (check_correctly_sorted_asc(stack, len - rotations) == 0)
	{
		print_stacks(stacks);
		if (stack[0].value > stack[1].value)
			swap_stack(stack, stacks);
		else
		{
			rotate_stack(stack, stacks);
			rotations++;
		}
	}
	while (stack[len - 1].value != last_index_val)
	{
		reverse_rotate_stack(stack, stacks);
		rotations--;
	}
}

// @brief		Applies bubble sort to stack b descendingly
static void	bubble_sort_stack_descending(t_stack_item	*stack,
								t_stacks	*stacks,
								int len)
{
	int	last_index_val;
	int	counter;

	ft_printf("Applying descending bubble sort with length %d!\n", len);
	counter = 0;
	last_index_val = stack[0].value;
	while (counter < len)
	{
		if (stack[counter].value < last_index_val)
			last_index_val = stack[counter].value;
		ft_printf("loop %d, curr lowest num is %d.\n", counter, last_index_val);
		counter++;
	}
	ft_printf("last index val: %d\n", last_index_val);
	while (check_correctly_sorted_desc(stack, len) == 0)
	{
		if (stack[0].value < stack[1].value && \
				stack[0].value != last_index_val)
			swap_stack(stack, stacks);
		else
			rotate_stack(stack, stacks);
	}
	ft_printf("idk man i guess thats sorted correctly now who knows.\n");
	while (stack[len - 1].value != last_index_val)
		reverse_rotate_stack(stack, stacks);
	for (int k = 0; k < len; k++)
		ft_printf("%d ", stack[k]);
}

// selection is including start and including end.
// ascending is either 1 or -1, 1 if ascending, -1 is decending
static void	set_pivot_rec(t_stack_item	*p_s, \
							t_stack_item	*s_s, \
							t_stacks	*stacks, \
							int len, \
							int ascending)
{
	int		numbers_pushed_over;
	int		counter;

	print_stacks(stacks);
	ft_printf("pivot rec was called for %d -> %d. ascending is %d.\n", p_s[0].value, p_s[len - 1].value, ascending);
	counter = 0;
	if (len > PIVOT_THRESH)
	{
		ft_printf("Len larger than Pivot! After pushing numbers after median:\n");
		numbers_pushed_over = push_numbers_after_median(p_s, stacks, len);
		print_stacks(stacks);
		ft_printf("Recalling self for first half (lower than median, in secondary stack).\n");
		set_pivot_rec(s_s, p_s, stacks, numbers_pushed_over, -ascending);
		counter = 0;
		print_stacks(stacks);
		ft_printf("Recalling self for second half (higher than median, in primary stack)\n");
		set_pivot_rec(p_s, s_s, stacks, len - numbers_pushed_over, ascending);
		print_stacks(stacks);
		counter = 0;
		while (counter++ < numbers_pushed_over)
			push_to_other_stack(s_s, stacks);
	}
	if (len <= PIVOT_THRESH && ascending == 1)
		bubble_sort_stack_ascending(p_s, stacks, len);
	if (len <= PIVOT_THRESH && ascending == -1)
		bubble_sort_stack_descending(p_s, stacks, len);
	print_stacks(stacks);
	ft_printf("pivot rec is done with %d -> %d.\n", p_s[0].value, p_s[len - 1].value);
}

void	quick_sort(t_stacks	*stacks)
{
	set_pivot_rec(stacks->a, stacks->b, stacks, stacks->height, 1);
}
