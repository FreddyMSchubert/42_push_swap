/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:50:36 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 19:05:17 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief		Simple bubble sort implementation.
// @brief		107 operations for 9 8 7 6 5 4 3 2 1 0
void	bubble_sort(t_stacks	*stacks)
{
	while (check_correctly_sorted_asc(stacks->a, stacks->a_height) == 0)
	{
		if (stacks->a[0].value > stacks->a[1].value && \
				stacks->a[0].value != stacks->sorted[stacks->height - 1].value)
		{
			do_operation(stacks, &stacks->bubble_result, "sa");
		}
		else
		{
			do_operation(stacks, &stacks->bubble_result, "ra");
		}
	}
}
