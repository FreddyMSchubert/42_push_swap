/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:02:06 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/15 11:04:02 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_correctly_sorted(t_stacks	*stacks)
{
	int	i;

	i = 1;
	while (i < stacks->height)
	{
		if (stacks->a[i].value < stacks->a[i - 1].value)
			return (0);
		i++;
	}
	return (1);
}
