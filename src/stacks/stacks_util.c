/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:50:35 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 06:46:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file contains some helpful utils for the other stack files. */

#include "../../include/push_swap.h"

// @brief	Counts elements in a NULL - terminated array of any type
int	ft_arraylen(const void **array)
{
	int		count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}

void	print_colored(const char *str, char color)
{
	const char	*color_code;

	color_code = "\033[0m";
	if (color == 'r')
		color_code = "\033[31m";
	if (color == 'g')
		color_code = "\033[32m";
	if (color == 'y')
		color_code = "\033[33m";
	if (color == 'b')
		color_code = "\033[34m";
	if (color == 'm')
		color_code = "\033[35m";
	if (color == 'c')
		color_code = "\033[36m";
	if (VERBOSE == 1)
		ft_printf("%s%s\033[0m", color_code, str);
	else
		ft_printf("%s", str);
}

static void	gravitize_stack(t_stack_item *stack, int height)
{
	int		counter;
	int		counter2;

	counter = 0;
	while (counter < height)
	{
		if (stack[counter].slot_filled == 0)
		{
			counter2 = counter;
			while (counter2 < height && \
					stack[counter2].slot_filled == 0)
				counter2++;
			if (counter2 == height)
				break ;
			stack[counter].value = stack[counter2].value;
			stack[counter].slot_filled = 1;
			stack[counter2].slot_filled = 0;
		}
		counter++;
	}
}

// @brief	Deletes empty spaces in stacks
void	turn_on_gravity(t_stacks	*stacks)
{
	gravitize_stack(stacks->a, stacks->height);
	gravitize_stack(stacks->b, stacks->height);
}
