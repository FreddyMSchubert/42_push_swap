/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:50:35 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 13:35:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file contains some helpful utils for the other stack files. */

#include "../../include/push_swap.h"

#include <limits.h>	// for int limits

// @brief	Counts elements in a NULL - terminated array of any type
int	ft_arraylen(const void **array)
{
	int		count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}

// @brief		Swaps all item properties of two stack items
void	swap_item_properties(t_stack_item	*item1, t_stack_item	*item2)
{
	int		tval;
	int		tfilled;
	int		tsorted;

	tval = item1->value;
	tfilled = item1->slot_filled;
	tsorted = item1->sorted_index;
	item1->value = item2->value;
	item1->slot_filled = item2->slot_filled;
	item1->sorted_index = item2->sorted_index;
	item2->value = tval;
	item2->slot_filled = tfilled;
	item2->sorted_index = tsorted;
}

// @brief	Moves all elements in a stack to begging, removing empty spaces
static void	gravitize_stack(t_stack_item *stack, int height)
{
	int		counter;
	int		counter2;

	counter = 0;
	while (counter < height)
	{
		if (stack[counter].slot_filled == 0)
		{
			counter2 = counter;
			while (counter2 < height && \
					stack[counter2].slot_filled == 0)
				counter2++;
			if (counter2 == height)
				break ;
			swap_item_properties(&stack[counter], &stack[counter2]);
			stack[counter].slot_filled = 1;
			stack[counter2].slot_filled = 0;
		}
		counter++;
	}
}

// @brief	Deletes empty spaces in stacks
void	turn_on_gravity(t_stacks	*stacks)
{
	gravitize_stack(stacks->a, stacks->height);
	gravitize_stack(stacks->b, stacks->height);
}

void	check_errors_in_input(t_stacks	*stacks)
{
	int		counter;
	int		counter2;

	counter = 0;
	while (counter < stacks->height)
	{
		counter2 = 0;
		while (counter2 < stacks->height)
		{
			if (stacks->a[counter].value == stacks->a[counter2].value && \
				counter != counter2)
				exit_error("Duplicate value inputted!\n", stacks);
			counter2++;
		}
		counter++;
	}
}
