/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:44:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 16:36:30 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief		Returns sqrt of num with 2 decimal point precision
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
		pa(stacks);
		curr_highest_element--;
	}
}

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
			pb(stacks);
			rb(stacks, 1);
			i++;
		}
		else if (stacks->a[0].sorted_index <= i + range)
		{
			pb(stacks);
			i++;
		}
		else
		{
			ra(stacks, 1);
		}
	}
	push_elements_back_efficiently(stacks);
}
