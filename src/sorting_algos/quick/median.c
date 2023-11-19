/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:33 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/19 07:21:50 by fschuber         ###   ########.fr       */
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
	ft_printf("Successfully copied over values! len = %d\n", length);
	while (array && check_correctly_sorted_asc(array, length) == 0)
	{
		if (array[counter].value < array[counter - 1].value)
		{
			// ft_printf("Swapping values %d and %d!\n", array[counter].value, array[counter - 1].value);
			temp = array[counter].value;
			array[counter].value = array[counter - 1].value;
			array[counter - 1].value = temp;
		}
		counter++;
		if (counter >= length)
			counter = 1;
		ft_printf("%d ", counter);
	}
	ft_printf("\n");
	for (int k = 0; k < length; k++)
	 	ft_printf("%d ", array[k].value);
	ft_printf("\n");
	if (array)
		temp = array[length / 2 - 1].value;
	free (array);
	return (temp);
}

/*
	@brief		Pushes over all elements larger than median from p_s to s_s
	@brief		Will always rotate p_s len / 2 times. (with int rounddown)
	@returns	number of elements pushed.
*/
int	push_numbers_after_median(t_stack_item *p_s, t_stacks *stacks, int len)
{
	int		ra_count;
	int		pushed_count;
	int		median;
	int		counter;

	ra_count = 0;
	pushed_count = 0;
	median = get_median(p_s, len);
	ft_printf("Median is %d for length %d\n", median, len);
	counter = 0;
	ft_printf("Pushing values larger or equal to median.\n");
	while (counter < len - ra_count - pushed_count)
	{
		if (p_s[0].value <= median)
		{
			push_to_other_stack(p_s, stacks);
			pushed_count++;
		}
		if (p_s[0].value > median)
		{
			rotate_stack(p_s, stacks);
			ra_count++;
		}
	}
	while (ra_count > 0)
	{
		reverse_rotate_stack(p_s, stacks);
		ra_count--;
	}
	return (pushed_count);
}
