/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:44:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 06:36:20 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_sqrt(int num)
{
	int	sqrt;

	sqrt = 1;
	if (num < 0)
		return (0);
	while (sqrt * sqrt <= num)
		sqrt++;
	return (sqrt - 1);
}

static void	push_elements_back_efficiently(t_stacks	*stacks)
{
	int		curr_highest_element;
	int		highest_element_b_index;

	ft_printf("\033[31mNow pushing elements back!\n");
	curr_highest_element = stacks->height - 1;
	while (stacks->b[0].slot_filled != 0)
	{
		while (stacks->b[0].value != stacks->sorted[curr_highest_element].value)
		{
			highest_element_b_index = find_index_by_value(stacks->b, \
						stacks->sorted[curr_highest_element].value, \
														stacks->height);
			ft_printf("%d < %d ???\n", highest_element_b_index, \
									stacks->b_height - highest_element_b_index);
			ft_printf("if true, shift up, if false, shift down.\n");
			if (highest_element_b_index - 0 < \
								stacks->b_height - highest_element_b_index)
				rb(stacks, 1);
			else
				rrb(stacks, 1);
		}
		pa(stacks);
		curr_highest_element--;
	}
	ft_printf("Done pushing! \033[0m\n");
}

void	k_sort(t_stacks	*stacks)
{
	int		i;
	double	range;

	ft_printf("\033[31mNow pushing elements over!\n");
	i = 0;
	range = ft_sqrt(stacks->height) * 1.6;
	while (stacks->a[0].slot_filled == 1)
	{
		if (stacks->a[0].sorted_index < i)
		{
			pb(stacks);
			rb(stacks, 1);
		}
		else if (stacks->a[0].sorted_index <= i + range)
		{
			pb(stacks);
		}
		else
		{
			ra(stacks, 1);
		}
		i++;
	}
	ft_printf("Done pushing! \033[0m\n");
	push_elements_back_efficiently(stacks);
}
