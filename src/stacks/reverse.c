/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:35:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/15 09:59:53 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stacks	*stacks)
{
	int		temp_val;
	int		temp_fill;
	int		i;

	print_colored("rra\n", 'g');
	i = stacks->height - 2;
	temp_val = stacks->a[stacks->height - 1].value;
	temp_fill = stacks->a[stacks->height - 1].slot_filled;
	while (i >= 0)
	{
		stacks->a[i + 1].slot_filled = stacks->a[i].slot_filled;
		stacks->a[i + 1].value = stacks->a[i].value;
		i--;
	}
	stacks->a[0].slot_filled = temp_fill;
	stacks->a[0].value = temp_val;
}

void	rrb(t_stacks	*stacks)
{
	int		temp_val;
	int		temp_fill;
	int		i;

	print_colored("rrb\n", 'g');
	i = stacks->height - 2;
	temp_val = stacks->b[stacks->height - 1].value;
	temp_fill = stacks->b[stacks->height - 1].slot_filled;
	while (i >= 0)
	{
		stacks->b[i + 1].slot_filled = stacks->b[i].slot_filled;
		stacks->b[i + 1].value = stacks->b[i].value;
		i--;
	}
	stacks->b[0].slot_filled = temp_fill;
	stacks->b[0].value = temp_val;
}

void	rrr(t_stacks	*stacks)
{
	print_colored("rrr\n", 'g');
	rra(stacks);
	rrb(stacks);
}
