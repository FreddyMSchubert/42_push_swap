/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:33 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 09:36:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// median / pivot settings & sorting around pivot related quick sort operations

#include "../../../include/push_swap.h"

/*
	@brief		Returns median value between 0 and length on stack
	@returns	-1 if allocation failed, a 
*/
static int	get_median(t_stack_item	*stack, int length)
{
	t_stack_item		*array;
	int					counter;
	int					temp;

	array = malloc(sizeof(t_stack_item) * length);
	counter = -1;
	while (array && ++counter < length)
		array[counter].value = stack[counter].value;
	counter = 1;
	while (array && check_correctly_sorted_asc(array, length) == 0)
	{
		if (array[counter].value < array[counter - 1].value)
		{
			temp = array[counter].value;
			array[counter].value = array[counter - 1].value;
			array[counter - 1].value = temp;
		}
		counter++;
		if (counter >= length)
			counter = 1;
	}
	if (array)
		temp = array[length / 2 - 1].value;
	free (array);
	return (temp);
}

/*
	@brief		Pushes over all elements larger than median from p_s to s_s
	@brief		and returns p_s back to same position
	@returns	number of elements pushed.
*/
int	push_numbers_after_median(t_stack_item *p_s, t_stacks *stacks, int len)
{
	int		pushed_count;
	int		median;
	int		counter;

	pushed_count = 0;
	median = get_median(p_s, len);
	counter = 0;
	while (counter < len)
	{
		if (p_s[0].value > median)
			rotate_stack(p_s, stacks);
		else if (p_s[0].value <= median)
		{
			push_to_other_stack(p_s, stacks);
			pushed_count++;
		}
		counter++;
	}
	return (pushed_count);
}
