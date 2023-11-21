/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:11:47 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 08:16:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the remains of once was a glorious quick sort algorithm

#include "../../include/push_swap.h"

// @brief		splits the inputted stack in half and applies bubble sort
void	cheap_quick_sort(t_stacks	*stacks)
{
	int		counter;

	counter = 0;
	while (counter < stacks->height)
	{
		if (stacks->a[0].sorted_index < stacks->height / 2)
			pb(stacks);
		else
			ra(stacks, 1);
		counter++;
	}
	bubble_sort(stacks);
	bubble_sort_desc(stacks);
	while (stacks->b[0].slot_filled == 1)
		pa(stacks);
}
