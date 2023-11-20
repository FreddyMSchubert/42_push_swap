/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:34:48 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 18:53:42 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stacks	*stacks)
{
	int		counter;

	if (stacks->b[0].slot_filled == 1)
	{
		if (stacks->a[0].slot_filled == 1)
		{
			counter = stacks->height - 1;
			while (--counter >= 0)
				swap_item_properties \
						(&stacks->a[counter + 1], &stacks->a[counter]);
		}
		swap_item_properties(&stacks->a[0], &stacks->b[0]);
		stacks->a[0].slot_filled = 1;
		stacks->b[0].slot_filled = 0;
		stacks->a_height++;
		stacks->b_height--;
		turn_on_gravity(stacks);
	}
	if (VERBOSE == 1)
		print_stacks(stacks);
}

void	pb(t_stacks	*stacks)
{
	int		counter;

	if (stacks->a[0].slot_filled == 1)
	{
		if (stacks->b[0].slot_filled == 1)
		{
			counter = stacks->height - 1;
			while (--counter >= 0)
				swap_item_properties \
						(&stacks->b[counter + 1], &stacks->b[counter]);
		}
		swap_item_properties(&stacks->b[0], &stacks->a[0]);
		stacks->b[0].slot_filled = 1;
		stacks->a[0].slot_filled = 0;
		stacks->b_height++;
		stacks->a_height--;
		turn_on_gravity(stacks);
	}
	if (VERBOSE == 1)
		print_stacks(stacks);
}
