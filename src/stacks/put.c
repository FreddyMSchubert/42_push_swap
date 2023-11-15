/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:34:48 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/15 11:57:34 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stacks	*stacks)
{
	print_colored("pa\n", 'y');
	if (stacks->b[0].slot_filled == 1)
	{
		stacks->operations++;
		if (stacks->a[0].slot_filled == 1)
			ft_printf("There was an item in [0] of a. Overwriting in pa!\n");
		stacks->a[0].value = stacks->b[0].value;
		stacks->a[0].slot_filled = 1;
		stacks->b[0].slot_filled = 0;
	}
	else
		ft_printf("First slot of b was empty. Doing nothing.\n");
}

void	pb(t_stacks	*stacks)
{
	print_colored("pb\n", 'y');
	if (stacks->a[0].slot_filled == 1)
	{
		stacks->operations++;
		if (stacks->b[0].slot_filled == 1)
			ft_printf("There was an item in [0] of b. Overwriting in pb!\n");
		stacks->b[0].value = stacks->a[0].value;
		stacks->b[0].slot_filled = 1;
		stacks->a[0].slot_filled = 0;
	}
	else
		ft_printf("First slot of a was empty. Doing nothing.\n");
}
