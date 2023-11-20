/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:27:14 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 10:00:47 by fschuber         ###   ########.fr       */
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
	if (VERBOSE == 1)
		ft_printf("pivot rec was called for %d -> %d. ascending is %d.\n", p_s[0].value, p_s[len - 1].value, ascending);
	counter = 0;
	if (len > PIVOT_THRESH)
	{
		if (VERBOSE == 1)
			ft_printf("Len larger than Pivot! After pushing numbers after median:\n");
		numbers_pushed_over = push_numbers_after_median(p_s, stacks, len);
		if (VERBOSE == 1)
			ft_printf("Recalling self for first half (lower than median, in secondary stack).\n");
		set_pivot_rec(s_s, p_s, stacks, numbers_pushed_over, -ascending);
		counter = 0;
		if (VERBOSE == 1)
			ft_printf("Recalling self for second half (higher than median, in primary stack)\n");
		set_pivot_rec(p_s, s_s, stacks, len - numbers_pushed_over, ascending);
		counter = 0;
		while (counter++ < numbers_pushed_over)
			push_to_other_stack(s_s, stacks);
	}
	if (len <= PIVOT_THRESH && ascending == 1)
		bubble_sort_stack_ascending(p_s, stacks, len);
	if (len <= PIVOT_THRESH && ascending == -1)
		bubble_sort_stack_descending(p_s, stacks, len);
	if (VERBOSE == 1)
		ft_printf("pivot rec is done with %d -> %d.\n", p_s[0].value, p_s[len - 1].value);
}

void	quick_sort(t_stacks	*stacks)
{
	set_pivot_rec(stacks->a, stacks->b, stacks, stacks->height, 1);
}
