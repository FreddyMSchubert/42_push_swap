/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:33 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/18 07:27:58 by fschuber         ###   ########.fr       */
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
	while (array && check_correctly_sorted(array, length) == 0)
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
		temp = array[length / 2].value;
	free (array);
	return (temp);
}

// @brief	Checks whether there are numbers above nbr in stack in range 0 - len
// static int	numbers_above_int_in_stack(t_stack_item	*stack, int len,
//									int nbr)
// {
// 	int		counter;

// 	counter = 0;
// 	while (counter < len && stack[counter].value < nbr)
// 		counter++;
// 	return (counter);
// }

/*
	@brief		Pushes over all elements larger than median from p_s to s_s
	@brief		Will always rotate p_s len / 2 times. (with int rounddown)
	@returns	number of elements pushed.
*/
int	push_numbers_after_median(t_stack_item *p_s, \
									t_stacks *stacks, \
									int len)
{
	int		ra_count;
	int		pushed_count;
	int		median;
	int		counter;

	ra_count = 0;
	pushed_count = 0;
	median = get_median(p_s, len);
	counter = 0;
	while (counter < len - ra_count - pushed_count)
	{
		if (p_s[0].value > median)
		{
			push_to_other_stack(p_s, stacks);
			pushed_count++;
		}
		if (p_s[0].value <= median)
		{
			rotate_stack(p_s, stacks);
			ra_count++;
		}
	}
	return (pushed_count);
}
