/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:50:35 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 19:55:05 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file contains some helpful utils for the other stack files. */

#include "../../include/push_swap.h"

// @brief	Counts elements in a NULL - terminated array of any type
int	ft_arraylen(const void **array)
{
	int		count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}

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

void	free_results(t_result_line	*line)
{
	int		counter;

	counter = 0;
	while (counter < line->result_len)
		free(line->line[counter]);
	free(line->line);
}
