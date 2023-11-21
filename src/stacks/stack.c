/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:35:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 06:57:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file is here to initialize stacks and free them again. */

#include "../../include/push_swap.h"

/*
	@brief		Loops through stack a, finding every value on sorted stack.
				Saves the sorted index.
*/
static void	*set_sorted_indices(t_stacks	*stacks)
{
	int		i;
	int		k;

	i = 0;
	while (i < stacks->a_height)
	{
		k = 0;
		while (k < stacks->height)
		{
			if (stacks->sorted[k].value == stacks->a[i].value)
				stacks->a[i].sorted_index = k;
			k++;
		}
		i++;
	}
	return (NULL);
}

// normal bubble sort without special operations
// used to create "sorted" stack at start of program
static void	*normal_bubble_sort(t_stacks	*stacks)
{
	int				counter;
	t_stack_item	*sorted;
	int				temp;

	counter = -1;
	sorted = malloc(sizeof(t_stack_item) * stacks->height);
	if (!sorted)
		return (NULL);
	while (++counter < stacks->height)
		sorted[counter].value = stacks->a[counter].value;
	counter = 0;
	while (check_correctly_sorted_asc(sorted, stacks->height) == 0)
	{
		if (sorted[counter].value > sorted[counter + 1].value)
		{
			temp = sorted[counter].value;
			sorted[counter].value = sorted[counter + 1].value;
			sorted[counter + 1].value = temp;
		}
		counter++;
		if (counter > stacks->height - 2)
			counter = 0;
	}
	stacks->sorted = sorted;
	return (set_sorted_indices(stacks));
}

// @brief		Turns a string array in input format into desired stacks format
// @param[in]	argv string array in input format, e.g. ./push_swap 2 1 3 6 5 8
// @param[in]	non-allocated t_stacks passed by reference
// @param[out]	0 on failure, 1 on success
int	init_stacks(char	**argv, t_stacks	*stacks)
{
	int				height;

	height = ft_arraylen((const void **)argv) - 1;
	stacks->a = malloc (sizeof(t_stack_item) * height);
	stacks->b = malloc (sizeof(t_stack_item) * height);
	if (!stacks->a || !stacks->b)
		return (free(stacks->a), free(stacks->b), 0);
	stacks->height = height;
	stacks->operations = 0;
	stacks->a_height = 0;
	stacks->b_height = 0;
	while (stacks->a_height < stacks->height)
	{
		stacks->a[stacks->a_height].value = ft_atoi(argv[stacks->a_height + 1]);
		stacks->a[stacks->a_height].slot_filled = 1;
		stacks->a[stacks->a_height].sorted_index = 0;
		stacks->b[stacks->a_height].value = 0;
		stacks->b[stacks->a_height].slot_filled = 0;
		stacks->b[stacks->a_height].sorted_index = 0;
		stacks->a_height++;
	}
	normal_bubble_sort(stacks);
	return (1);
}

// @brief	Prints out all the data in a stacks struct
void	print_stacks(const t_stacks	*stacks)
{
	int		counter;

	counter = -1;
	if (VERBOSE == 1)
		ft_printf("\n");
	while (++counter < stacks->height && VERBOSE == 1)
	{
		if (stacks->a[counter].slot_filled == 1)
			ft_printf(" [%d]%d \t", stacks->a[counter].value, \
							stacks->a[counter].sorted_index);
		else
			ft_printf(" \t \t");
		if (stacks->b[counter].slot_filled == 1)
			ft_printf(" [%d]%d \t", stacks->b[counter].value, \
							stacks->b[counter].sorted_index);
		else
			ft_printf(" \t \t");
		ft_printf(" [%d] \n", stacks->sorted[counter].value);
	}
	if (VERBOSE == 1)
	{
		ft_printf("  a    b    s - aH: %d, bH: %d, #: %d\n", stacks->a_height, \
								stacks->b_height, stacks->operations);
		ft_printf("\n");
	}
}

// @brief	Frees everything allocated inside t_stacks
void	free_stacks(t_stacks	*stacks)
{
	free(stacks->a);
	free(stacks->b);
	if (VERBOSE == 1)
		ft_printf("Freed stacks!\n");
}
