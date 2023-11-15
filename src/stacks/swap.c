/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:06:53 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/15 10:09:35 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file contains all possible swap actions. */

#include "../../include/push_swap.h"

void	sa(t_stacks	*stacks)
{
	int		temp;

	print_colored("sa\n", 'r');
	if (stacks->a[0].slot_filled && stacks->a[1].slot_filled)
	{
		temp = stacks->a[0].value;
		stacks->a[0].value = stacks->a[1].value;
		stacks->a[1].value = temp;
	}
	else
		ft_printf("There was one or no elements to swap. Doing nothing.\n");
}

void	sb(t_stacks	*stacks)
{
	int		temp;

	print_colored("sb\n", 'r');
	if (stacks->b[0].slot_filled && stacks->b[1].slot_filled)
	{
		temp = stacks->b[0].value;
		stacks->b[0].value = stacks->b[1].value;
		stacks->b[1].value = temp;
	}
	else
		ft_printf("There was one or no elements to swap. Doing nothing.\n");
}

void	ss(t_stacks	*stacks)
{
	print_colored("ss\n", 'r');
	sa(stacks);
	sb(stacks);
}
