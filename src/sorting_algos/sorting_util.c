/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:02:06 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 22:45:31 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// @brief					Finds the first element with certain value in stack
// @param search_distance	how long to search for starting from 0
// @returns					Index of that element
int	find_index_by_value(t_stack_item *stack, \
								int value, \
								int search_distance)
{
	int	counter;

	counter = -1;
	while (++counter < search_distance)
		if (stack[counter].value == value)
			return (counter);
	return (-1);
}

/*
	@return		1 if specified stack is ascending up to index height or 0.
*/
int	check_correctly_sorted_asc(t_stack_item	*stack, int height)
{
	int	i;

	i = 1;
	while (i < height)
	{
		if (stack[i].value < stack[i - 1].value)
			return (0);
		i++;
	}
	return (1);
}

/*
	@return		1 if specified stack is descending up to index height or 0.
*/
int	check_correctly_sorted_des(t_stack_item	*stack, int height)
{
	int	i;

	i = 1;
	while (i < height)
	{
		if (stack[i].value > stack[i - 1].value)
			return (0);
		i++;
	}
	return (1);
}

static void	perform_operation(t_stacks	*stacks, char	*operation)
{
	ft_printf("Trying to perform %s operation.\n", operation);
	if (ft_strncmp(operation, "sa", 2) == 0)
		sa(stacks);
	else if (ft_strncmp(operation, "sb", 2) == 0)
		sb(stacks);
	else if (ft_strncmp(operation, "ss", 2) == 0)
		ss(stacks);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		pa(stacks);
	else if (ft_strncmp(operation, "pb", 2) == 0)
		pb(stacks);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		ra(stacks);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rb(stacks);
	else if (ft_strncmp(operation, "rr", 2) == 0)
		rr(stacks);
	else if (ft_strncmp(operation, "rra", 3) == 0)
		rra(stacks);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		rrb(stacks);
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		rrr(stacks);
}

// @brief	not only executes an operation but adds it to results
void	do_operation(t_stacks	*stacks, t_result_line	*line, char	*operation)
{
	stacks->operations++;
	if (VERBOSE == 1)
		ft_printf("%s\n", operation);
	perform_operation(stacks, operation);
	add_result(line, operation);
}
