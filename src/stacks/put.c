/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:34:48 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/17 07:43:05 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stacks	*stacks)
{
	int		counter;

	print_colored("pa\n", 'y');
	if (stacks->b[0].slot_filled == 1)
	{
		stacks->operations++;
		if (stacks->a[0].slot_filled == 1)
		{
			counter = stacks->height - 1;
			while (--counter >= 0)
			{
				stacks->a[counter + 1].value = stacks->a[counter].value;
				stacks->a[counter + 1].slot_filled = \
						stacks->a[counter].slot_filled;
			}
		}
		stacks->a[0].value = stacks->b[0].value;
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

	print_colored("pb\n", 'y');
	if (stacks->a[0].slot_filled == 1)
	{
		stacks->operations++;
		if (stacks->b[0].slot_filled == 1)
		{
			counter = stacks->height - 1;
			while (--counter >= 0)
			{
				stacks->b[counter + 1].value = stacks->b[counter].value;
				stacks->b[counter + 1].slot_filled = \
						stacks->b[counter].slot_filled;
			}
		}
		stacks->b[0].value = stacks->a[0].value;
		stacks->b[0].slot_filled = 1;
		stacks->a[0].slot_filled = 0;
		stacks->b_height++;
		stacks->a_height--;
		turn_on_gravity(stacks);
	}
	if (VERBOSE == 1)
		print_stacks(stacks);
}
