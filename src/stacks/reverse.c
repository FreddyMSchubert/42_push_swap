/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:35:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 09:42:33 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stacks	*stacks, int print_stack)
{
	int		temp_val;
	int		temp_fill;
	int		i;

	stacks->operations++;
	print_colored("rra\n", 'g');
	i = ft_tile_arraylen(stacks->a) - 2;
	temp_val = stacks->a[ft_tile_arraylen(stacks->a) - 1].value;
	temp_fill = stacks->a[ft_tile_arraylen(stacks->a) - 1].slot_filled;
	while (i >= 0)
	{
		stacks->a[i + 1].slot_filled = stacks->a[i].slot_filled;
		stacks->a[i + 1].value = stacks->a[i].value;
		i--;
	}
	stacks->a[0].slot_filled = temp_fill;
	stacks->a[0].value = temp_val;
	turn_on_gravity(stacks);
	if (VERBOSE == 1 && print_stack == 1)
		print_stacks(stacks);
}

void	rrb(t_stacks	*stacks, int print_stack)
{
	int		temp_val;
	int		temp_fill;
	int		i;

	stacks->operations++;
	print_colored("rrb\n", 'g');
	i = ft_tile_arraylen(stacks->b) - 2;
	temp_val = stacks->b[ft_tile_arraylen(stacks->b) - 1].value;
	temp_fill = stacks->b[ft_tile_arraylen(stacks->b) - 1].slot_filled;
	while (i >= 0)
	{
		stacks->b[i + 1].slot_filled = stacks->b[i].slot_filled;
		stacks->b[i + 1].value = stacks->b[i].value;
		i--;
	}
	stacks->b[0].slot_filled = temp_fill;
	stacks->b[0].value = temp_val;
	turn_on_gravity(stacks);
	if (VERBOSE == 1 && print_stack == 1)
		print_stacks(stacks);
}

void	rrr(t_stacks	*stacks)
{
	print_colored("rrr\n", 'g');
	stacks->operations--;
	rra(stacks, 0);
	rrb(stacks, 0);
	if (VERBOSE == 1)
		print_stacks(stacks);
}
