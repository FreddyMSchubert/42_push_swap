/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:50:36 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 07:55:29 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief		Simple bubble sort implementation.
// @brief		117 operations for 9 8 7 6 5 4 3 2 1 0
void	bubble_sort(t_stacks	*stacks)
{
	int		last_index;

	last_index = 0;
	while (stacks->a[last_index].slot_filled == 1)
		last_index++;
	last_index--;
	while (check_correctly_sorted(stacks->a, stacks->height) == 0)
	{
		if (stacks->a[0].value > stacks->a[1].value)
			sa(stacks, 1);
		if (stacks->a[0].value < stacks->a[last_index].value && \
					check_correctly_sorted(stacks->a, stacks->height) == 0)
			rra(stacks, 1);
		else if (check_correctly_sorted(stacks->a, stacks->height) == 0)
			ra(stacks, 1);
	}
}
