/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:35:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/15 11:06:57 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file is here to initializie stacks and free them again. */

#include "../../include/push_swap.h"

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
	return (1);
}

// @brief	Prints out all the data in a stacks struct
void	print_stacks(const t_stacks	*stacks)
{
	int		counter;

	counter = 0;
	while (counter < stacks->height)
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
	ft_printf("  -    - \n  a    b \n");
	ft_printf("Height: %d\n", stacks->height);
}

// @brief	Frees everything allocated inside t_stacks
void	free_stacks(t_stacks	*stacks)
{
	free(stacks->a);
	free(stacks->b);
	ft_printf("Freed stacks!");
}
