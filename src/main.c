/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:52:27 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/06 11:26:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	start_sort_algo(t_stacks	*stacks)
{
	if (stacks->height < 5)
	{
		bubble_sort(stacks);
		if (VERBOSE == 1)
			ft_printf("did bubble sort!\n");
	}
	else if (stacks->height < 10)
	{
		cheap_quick_sort(stacks);
		if (VERBOSE == 1)
			ft_printf("did cheap quick sort!\n");
	}
	else
	{
		k_sort(stacks);
		if (VERBOSE == 1)
			ft_printf("did k sort!\n");
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc > 1)
	{
		if (check_argument_validity(argv) == 0)
			exit_error("Format: ./push_swap <signed ints sep by ' '>\n", NULL);
		if (init_stacks(argv, &stacks) == 0)
			exit_error("Stack initialization failed.\n"\
						, NULL);
		print_stacks(&stacks);
		if (check_correctly_sorted_asc(stacks.a, stacks.height) == 0)
			start_sort_algo(&stacks);
		if (check_correctly_sorted_asc(stacks.a, stacks.height) == 0)
			return (free_stacks(&stacks), 1);
		else
			return (free_stacks(&stacks), 0);
	}
}
