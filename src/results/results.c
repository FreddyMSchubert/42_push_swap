/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   results.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:45:20 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 20:47:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	*init_results(t_stacks	*stacks)
{
	stacks->bubble_result.line = malloc(sizeof(char *) * (stacks->height + 1));
	stacks->insert_result.line = malloc(sizeof(char *) * (stacks->height + 1));
	stacks->k_result.line = malloc(sizeof(char *) * (stacks->height + 1));
	if (!stacks->bubble_result.line || !stacks->insert_result.line || \
										!stacks->k_result.line)
		return (NULL);
	stacks->bubble_result.line[0] = NULL;
	stacks->insert_result.line[0] = NULL;
	stacks->k_result.line[0] = NULL;
	stacks->bubble_result.result_len = stacks->height;
	stacks->insert_result.result_len = stacks->height;
	stacks->k_result.result_len = stacks->height;
	return (NULL);
}

void	*add_result(t_result_line *result_line, char	*val)
{
	int		counter;
	int		counter2;

	counter = 0;
	while (result_line->line[counter] != NULL)
		counter++;
	if (counter == result_line->result_len - 1)
		result_line->result_len++;
	result_line->line = realloc(result_line->line, sizeof(char *) * \
								(result_line->result_len + 1));
	if (!result_line->line)
		return (NULL);
	result_line->line[result_line->result_len] = NULL;
	result_line->line[counter] = malloc(sizeof(char) * (ft_strlen(val) + 1));
	if (!result_line->line[counter])
		return (NULL);
	counter2 = 0;
	while (val[counter2] != '\0')
	{
		result_line->line[counter][counter2] = val[counter2];
		counter2++;
	}
	result_line->line[counter][counter2] = '\0';
	result_line->line[counter + 1] = NULL;
	return (NULL);
}

static void	print_result(t_result_line	*result)
{
	int		counter;

	if (VERBOSE != -1)
	{
		counter = 0;
		while (counter < result->result_len - 1)
		{
			ft_printf("Printing index %d.\n", counter);
			if (result->line[counter] && result->line[counter] != NULL)
				ft_printf("%s\n", result->line[counter]);
			else
				ft_printf("was null\n");
			counter++;
		}
	}
}

void	print_best_result(t_stacks	*stacks)
{
	remove_redundancies_in_result(&stacks->bubble_result);
	remove_redundancies_in_result(&stacks->k_result);
	remove_redundancies_in_result(&stacks->insert_result);
	if (stacks->bubble_result.result_len < stacks->insert_result.result_len && \
		stacks->bubble_result.result_len < stacks->k_result.result_len)
		print_result(&stacks->bubble_result);
	else if (stacks->insert_result.result_len < stacks->k_result.result_len)
		print_result(&stacks->insert_result);
	else
		print_result(&stacks->k_result);
}
