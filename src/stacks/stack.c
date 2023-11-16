/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:35:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 10:40:19 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file is here to initialize stacks and free them again. */

#include "../../include/push_swap.h"

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
	while (check_correctly_sorted(sorted, stacks->height) == 0)
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
	return (NULL);
}

// @brief		Turns a string array in input format into desired stacks format
// @param[in]	argv string array in input format, e.g. ./push_swap 2 1 3 6 5 8
// @param[in]	non-allocated t_stacks passed by reference
// @param[out]	0 on failure, 1 on success
int	init_stacks(char	**argv, t_stacks	*stacks)
{
	t_stack_item	*a;
	t_stack_item	*b;
	int				counter;
	int				height;

	height = ft_arraylen((const void **)argv) - 1;
	a = malloc (sizeof(t_stack_item *) * height);
	b = malloc (sizeof(t_stack_item *) * height);
	if (!a || !b)
		return (free(a), free(b), 0);
	stacks->height = height;
	stacks->operations = 0;
	counter = 0;
	while (counter < stacks->height)
	{
		a[counter].value = ft_atoi(argv[counter + 1]);
		a[counter].slot_filled = 1;
		b[counter].value = 0;
		b[counter].slot_filled = 0;
		counter++;
	}
	stacks->a = a;
	stacks->b = b;
	normal_bubble_sort(stacks);
	return (1);
}

// @brief	Prints out all the data in a stacks struct
void	print_stacks(const t_stacks	*stacks)
{
	int		counter;

	counter = 0;
	while (counter < stacks->height && VERBOSE == 1)
	{
		if (stacks->a[counter].slot_filled == 1)
			ft_printf(" [%d] ", stacks->a[counter]);
		else
			ft_printf(" [ ] ");
		if (stacks->b[counter].slot_filled == 1)
			ft_printf(" [%d] \n", stacks->b[counter]);
		else
			ft_printf(" [ ] \n");
		counter++;
	}
	if (VERBOSE == 1)
		ft_printf("  a    b - H: %d, #: %d\n", stacks->height, \
												stacks->operations);
}

// @brief	Frees everything allocated inside t_stacks
void	free_stacks(t_stacks	*stacks)
{
	free(stacks->a);
	free(stacks->b);
	if (VERBOSE == 1)
		ft_printf("Freed stacks!");
}
