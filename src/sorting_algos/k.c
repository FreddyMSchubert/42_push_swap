/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:44:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 16:05:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief		Returns sqrt of num with no decimal point precision
int	ft_sqrt(int num)
{
	double	sqrt;

	sqrt = 1;
	if (num < 0)
		return (0);
	while (sqrt * sqrt < num)
		sqrt += 1;
	return (sqrt);
}

/*
	@brief	pushes all elements from b to a in the most efficient order that
	@brief	results in a being sorted.
*/
static void	push_elements_back_efficiently(t_stacks	*stacks)
{
	int		curr_highest_element;
	int		highest_element_b_index;

	curr_highest_element = stacks->height - 1;
	while (stacks->b[0].slot_filled != 0)
	{
		while (stacks->b[0].value != stacks->sorted[curr_highest_element].value)
		{
			highest_element_b_index = find_index_by_value(stacks->b, \
						stacks->sorted[curr_highest_element].value, \
														stacks->height);
			if (highest_element_b_index - 0 < \
								stacks->b_height - highest_element_b_index)
				rb(stacks, 1);
			else
				rrb(stacks, 1);
		}
		pa(stacks, 1);
		curr_highest_element--;
	}
}

/*
	@brief	Sorts by first pushing over the elements in a strategically
			so they can later be more easily pulled back in 
			push_elements_back_efficiently
*/
void	k_sort(t_stacks	*stacks)
{
	int		i;
	int		range;

	i = 0;
	range = ft_sqrt(stacks->height) * 16 / 10;
	while (stacks->a[0].slot_filled == 1)
	{
		if (stacks->a[0].sorted_index <= i)
		{
			pb(stacks, 1);
			rb(stacks, 1);
			i++;
		}
		else if (stacks->a[0].sorted_index <= i + range)
		{
			pb(stacks, 1);
			i++;
		}
		else
		{
			ra(stacks, 1);
		}
	}
	push_elements_back_efficiently(stacks);
}
