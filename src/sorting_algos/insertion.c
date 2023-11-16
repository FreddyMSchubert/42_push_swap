/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:33:14 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 18:53:21 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief	Finds the first element with certain value in stack
// @returns	Index of that element
static int	find_index_by_value(t_stack_item	*stack, int value)
{
	int	counter;

	counter = -1;
	while (stack[++counter].value)
		if (stack[counter].value == value)
			return (ft_printf("found value %d at index %d!\n", value, counter), counter);
	return (-1);
}

static int	find_index_to_rotate_to(t_stacks	*stacks)
{
	int		subtraction_amount;
	int		sorted_index_of_pot_insert_point;

	ft_printf("Time to find the perfect position for %d!\n", stacks->a[0].value);
	subtraction_amount = 1;
	sorted_index_of_pot_insert_point = find_index_by_value \
		(stacks->sorted, stacks->a[0].value) - subtraction_amount;
	// if (stacks->b[stacks->height - 1].slot_filled == 1)
	// 	sorted_index_of_pot_insert_point = stacks->height - 1;
	if (sorted_index_of_pot_insert_point < 0)
	{
		ft_printf("updated sorted index cause were at the beginning!\n");
		// this handles the case when the lowest number comes in. should handle highest case afterwards.
		// heres the problem with this, we look for 34567 in b, but that dont work. we gotta look for the highest that is avialable in b. fck
		// should maybe make a function that gets the stacks and a number and a char and gets either the next lower available in the char specified stack or the next higher available
		return find_index_by_value(stacks->b, stacks->sorted[stacks->height - 1].value);
	}
	ft_printf("pot insert point is %d, the sorted value is %d.\n", sorted_index_of_pot_insert_point, stacks->sorted[sorted_index_of_pot_insert_point].value);
	while (sorted_index_of_pot_insert_point >= 0 && \
				stacks->a[0].slot_filled != 0)
	{
		if (find_index_by_value(stacks->b, stacks-> \
						sorted[sorted_index_of_pot_insert_point].value) == -1)
		{
			subtraction_amount++;
			ft_printf("subtraction amount++; (is now %d).\n", subtraction_amount);
		}
		else
		{
			ft_printf("Found %d at sorted index %d in b! returning.\n", stacks->sorted[sorted_index_of_pot_insert_point].value, sorted_index_of_pot_insert_point);
			return (find_index_by_value(stacks->b, stacks-> \
						sorted[sorted_index_of_pot_insert_point].value));
		}
		sorted_index_of_pot_insert_point = find_index_by_value \
			(stacks->sorted, stacks->a[0].value) - subtraction_amount;
	}
	ft_printf("returning 0, whyyyyyyyyy\n");
	return (ft_tile_arraylen(stacks->b) - 1);
}

// @brief	rotates b so when pb is executed, the pushed element is sorted.
static void	rotate_b_to_perfectly_receive_slot(t_stacks	*stacks)
{
	t_stack_item		nbr_to_be_top;
	int					index_to_be_top;
	int					counter;

	counter = -1;
	index_to_be_top = find_index_to_rotate_to(stacks);
	nbr_to_be_top = stacks->b[index_to_be_top];
	ft_printf("Index in b thats supposed to be at top is %d. (thats what the function to get the index returned).\n", index_to_be_top);
	while (stacks->b[0].value != nbr_to_be_top.value)
	{
		if (index_to_be_top - 0 < ft_tile_arraylen(stacks->b) \
							- index_to_be_top + 1)
			rb(stacks, 1);
		else
			rrb(stacks, 1);
	}
	ft_printf("rotated correctly! time to push a!\n");
}

void	insertion_sort(t_stacks	*stacks)
{
	while (stacks->a[0].slot_filled != 0)
	{
		ft_printf("Ready for pushing. Pushing now!\n");
		pb(stacks);
		ft_printf("Rotating b to perfect position now..\n");
		rotate_b_to_perfectly_receive_slot(stacks);
	}
	// rotate correctly
	while (stacks->b[0].slot_filled != 0)
	{
		pa(stacks);
	}
	// push over one element.
	// now, move b until the element at top of a can be pushed again and will be in order
	// find the highest number and rotate it to top
	// push everything back over
}
