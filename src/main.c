/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:52:27 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/15 10:12:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 3)
		return (ft_printf("Please input at least 2 numbers to sort!\n"), 0);
	if (init_stacks(argv, &stacks) == 0)
		return (0);
	print_stacks(&stacks);
	rra(&stacks);
	print_stacks(&stacks);
	rra(&stacks);
	print_stacks(&stacks);
	rra(&stacks);
	print_stacks(&stacks);
	return (1);
}
