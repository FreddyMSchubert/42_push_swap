/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:31:18 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/18 07:28:55 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// quick sort utilities

#include "../../../include/push_swap.h"

// @brief		pushes first element from primary to secondary stack
// @brief		To use it you dont need to know which one of the stacks (a/b)
// @brief		you are pushing from, thats why its helpful
void	push_to_other_stack(t_stack_item	*p_s, t_stacks	*stacks)
{
	if (stacks->a[0].value == p_s[0].value)
		pb(stacks);
	else if (stacks->b[0].value == p_s[0].value)
		pa(stacks);
}

// @brief		swaps first two elements of primary stack
// @brief		To use it you dont need to know which one of the stacks (a/b)
// @brief		you are swapping, thats why its helpful
void	swap_stack(t_stack_item	*p_s, t_stacks	*stacks)
{
	if (stacks->a[0].value == p_s[0].value)
		sa(stacks, 1);
	else if (stacks->b[0].value == p_s[0].value)
		sb(stacks, 1);
}

// @brief		rotates specified stack
// @brief		To use it you dont need to know which one of the stacks (a/b)
// @brief		you are rotating, thats why its helpful
void	rotate_stack(t_stack_item	*p_s, t_stacks	*stacks)
{
	if (stacks->a[0].value == p_s[0].value)
		ra(stacks, 1);
	else if (stacks->b[0].value == p_s[0].value)
		rb(stacks, 1);
}

// @brief		reverse rotates specified stack
// @brief		To use it you dont need to know which one of the stacks (a/b)
// @brief		you are reverse rotating, thats why its helpful
void	reverse_rotate_stack(t_stack_item	*p_s, t_stacks	*stacks)
{
	if (stacks->a[0].value == p_s[0].value)
		rra(stacks, 1);
	else if (stacks->b[0].value == p_s[0].value)
		rrb(stacks, 1);
}
