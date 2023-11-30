/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:54:15 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/30 15:52:32 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stacks init stuff

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
	check_errors_in_input(stacks);
	return (NULL);
}

// normal bubble sort without special operations
// used to create "sorted" stack at start of program
static void	*normal_bubble_sort(t_stacks	*stacks)
{
	int				counter;
	int				temp;

	counter = -1;
	stacks->sorted = malloc(sizeof(t_stack_item) * stacks->height);
	if (!stacks->sorted)
		return (NULL);
	while (++counter < stacks->height)
		stacks->sorted[counter].value = stacks->a[counter].value;
	counter = 0;
	while (check_correctly_sorted_asc(stacks->sorted, stacks->height) == 0)
	{
		if (stacks->sorted[counter].value > stacks->sorted[counter + 1].value)
		{
			temp = stacks->sorted[counter].value;
			stacks->sorted[counter].value = stacks->sorted[counter + 1].value;
			stacks->sorted[counter + 1].value = temp;
		}
		counter++;
		if (counter > stacks->height - 2)
			counter = 0;
	}
	return (set_sorted_indices(stacks));
}

int	init_stacks_seperated(char	**argv, t_stacks	*stacks)
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
		stacks->a[stacks->a_height].value = \
							ft_limits_atoi(argv[stacks->a_height + 1], stacks);
		stacks->a[stacks->a_height].slot_filled = 1;
		stacks->b[stacks->a_height].value = 0;
		stacks->b[stacks->a_height].slot_filled = 0;
		stacks->b[stacks->a_height].sorted_index = 0;
		stacks->a_height++;
	}
	normal_bubble_sort(stacks);
	return (1);
}

int	init_stacks_string(char	**argv, t_stacks	*stacks)
{
	char	**split_argv;

	split_argv = ft_split(argv[1], ' ');
	stacks->height = ft_arraylen((const void **)split_argv);
	stacks->a = malloc (sizeof(t_stack_item) * stacks->height);
	stacks->b = malloc (sizeof(t_stack_item) * stacks->height);
	stacks->operations = 0;
	if (!stacks->a || !stacks->b)
		return (free(stacks->a), free(stacks->b), 0);
	stacks->a_height = 0;
	stacks->b_height = 0;
	while (stacks->a_height < stacks->height)
	{
		stacks->a[stacks->a_height].value = \
						ft_limits_atoi(split_argv[stacks->a_height], stacks);
		stacks->a[stacks->a_height].slot_filled = 1;
		stacks->b[stacks->a_height].slot_filled = 0;
		stacks->b[stacks->a_height].sorted_index = 0;
		stacks->a_height++;
	}
	normal_bubble_sort(stacks);
	ft_free_rec((void **)split_argv);
	return (1);
}

// @brief		Turns a string array in input format into desired stacks format
// @param[in]	argv string array in input format, e.g. ./push_swap 2 1 3 6 5 8
// @param[in]	non-allocated t_stacks passed by reference
// @param[out]	0 on failure, 1 on success
int	init_stacks(char	**argv, t_stacks	*stacks)
{
	if (ft_arraylen((const void **)argv) == 2)
		return (init_stacks_string(argv, stacks));
	else
		return (init_stacks_seperated(argv, stacks));
}
