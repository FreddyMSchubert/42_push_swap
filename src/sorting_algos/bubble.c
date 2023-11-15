/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:50:36 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/15 11:59:01 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief		Simple bubble sort implementation.
// @brief		125 operations for 9 8 7 6 5 4 3 2 1 0
void	bubble_sort(t_stacks	*stacks)
{
	int		wraparound_index;

	wraparound_index = stacks->height - 1;
	while (check_correctly_sorted(stacks) == 0)
	{
		if (stacks->a[0].value > stacks->a[1].value && \
				wraparound_index != 0)
			sa(stacks);
		if (check_correctly_sorted(stacks) == 0)
		{
			ra(stacks);
			wraparound_index--;
			if (wraparound_index == -1)
				wraparound_index = stacks->height - 1;
		}
	}
}
