/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:35:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 09:37:46 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stacks	*stacks, int print_stack)
{
	int		temp_val;
	int		temp_fill;
	int		i;

	stacks->operations++;
	print_colored("ra\n", 'b');
	i = 1;
	temp_val = stacks->a[0].value;
	temp_fill = stacks->a[0].slot_filled;
	while (i < stacks->height)
	{
		stacks->a[i - 1].slot_filled = stacks->a[i].slot_filled;
		stacks->a[i - 1].value = stacks->a[i].value;
		i++;
	}
	i--;
	stacks->a[i].slot_filled = temp_fill;
	stacks->a[i].value = temp_val;
	turn_on_gravity(stacks);
	if (VERBOSE == 1 && print_stack == 1)
		print_stacks(stacks);
}

void	rb(t_stacks	*stacks, int print_stack)
{
	int		temp_val;
	int		temp_fill;
	int		i;

	stacks->operations++;
	print_colored("rb\n", 'b');
	i = 1;
	temp_val = stacks->b[0].value;
	temp_fill = stacks->b[0].slot_filled;
	while (i < stacks->height)
	{
		stacks->b[i - 1].slot_filled = stacks->b[i].slot_filled;
		stacks->b[i - 1].value = stacks->b[i].value;
		i++;
	}
	i--;
	stacks->b[i].slot_filled = temp_fill;
	stacks->b[i].value = temp_val;
	turn_on_gravity(stacks);
	if (VERBOSE == 1 && print_stack == 1)
		print_stacks(stacks);
}

void	rr(t_stacks	*stacks)
{
	stacks->operations--;
	print_colored("rr\n", 'b');
	ra(stacks, 0);
	rb(stacks, 0);
	if (VERBOSE == 1)
		print_stacks(stacks);
}
