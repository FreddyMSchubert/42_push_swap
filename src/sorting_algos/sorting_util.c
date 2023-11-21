/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:02:06 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 08:28:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief					Finds the first element with certain value in stack
// @param search_distance	how long to search for starting from 0
// @returns					Index of that element
int	find_index_by_value(t_stack_item *stack, \
								int value, \
								int search_distance)
{
	int	counter;

	counter = -1;
	while (++counter < search_distance)
		if (stack[counter].value == value)
			return (counter);
	return (-1);
}


// @return		1 if specified stack is ascending up to index height or 0.
int	check_correctly_sorted_asc(t_stack_item	*stack, int height)
{
	int	i;

	i = 1;
	while (i < height)
	{
		if (stack[i].value < stack[i - 1].value)
			return (0);
		i++;
	}
	return (1);
}

// @return		1 if specified stack is descending up to index height or 0.
int	check_correctly_sorted_des(t_stack_item	*stack, int height)
{
	int	i;

	i = 1;
	while (i < height)
	{
		if (stack[i].value > stack[i - 1].value)
			return (0);
		i++;
	}
	return (1);
}
