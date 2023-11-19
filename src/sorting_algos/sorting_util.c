/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:02:06 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/19 09:20:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	@return		1 if specified stack is ascending up to index height or 0.
*/
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

/*
	@return		1 if specified stack is descending up to index height or 0.
*/
int	check_correctly_sorted_desc(t_stack_item	*stack, int height)
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
