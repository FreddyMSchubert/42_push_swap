/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:35:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 11:09:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file is here to initialize stacks and free them again. */

#include "../../include/push_swap.h"

// @brief	Prints out all the data in a stacks struct
void	print_stacks(const t_stacks	*stacks)
{
	int		counter;

	counter = -1;
	if (VERBOSE == 1)
		ft_printf("\n");
	while (++counter < stacks->height && VERBOSE == 1)
	{
		if (stacks->a[counter].slot_filled == 1)
			ft_printf(" [%d]%d \t", stacks->a[counter].value, \
							stacks->a[counter].sorted_index);
		else
			ft_printf(" \t \t");
		if (stacks->b[counter].slot_filled == 1)
			ft_printf(" [%d]%d \t", stacks->b[counter].value, \
							stacks->b[counter].sorted_index);
		else
			ft_printf(" \t \t");
		ft_printf(" [%d] \n", stacks->sorted[counter].value);
	}
	if (VERBOSE == 1)
	{
		ft_printf("  a    b    s - aH: %d, bH: %d, #: %d\n", stacks->a_height, \
								stacks->b_height, stacks->operations);
		ft_printf("\n");
	}
}

// @brief	Frees everything allocated inside t_stacks
void	free_stacks(t_stacks	*stacks)
{
	free(stacks->a);
	free(stacks->b);
	if (VERBOSE == 1)
		ft_printf("Freed stacks!\n");
}
