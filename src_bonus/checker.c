/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:08:34 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 16:22:45 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ex_line(t_stacks	*stacks, char	*line)
{
	if (ft_strncmp(line, "Error\n", 5) == 0)
		exit(EXIT_FAILURE);
	if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		pa(stacks, 0);
	if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		pb(stacks, 0);
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		sa(stacks, 0);
	if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		sb(stacks, 0);
	if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(stacks, 0);
	if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ra(stacks, 0);
	if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rb(stacks, 0);
	if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(stacks, 0);
	if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		rra(stacks, 0);
	if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		rrb(stacks, 0);
	if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(stacks, 0);
}

int	read_input_loop(t_stacks	*stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		ex_line(stacks, line);
		line = get_next_line(0);
	}
	if (check_correctly_sorted_asc(stacks->a, stacks->height) == 1)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			sort_result;

	if (argc > 1)
	{
		if (check_argument_validity(argv) == 0)
			exit_error("Format: ./checker <signed ints sep by ' '>\n", NULL);
		if (init_stacks(argv, &stacks) == 0)
			exit_error("Stack initialization failed.\n"\
						, NULL);
		sort_result = read_input_loop(&stacks);
		if (sort_result == 0 || stacks.b[0].slot_filled == 1)
			ft_printf("KO\n");
		else if (sort_result == 1 && stacks.b[0].slot_filled == 0)
			ft_printf("OK\n");
		free_stacks(&stacks);
	}
	return (1);
}
