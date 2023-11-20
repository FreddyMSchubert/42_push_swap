/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   results.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:45:20 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 23:03:56 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	*init_results(t_stacks	*stacks)
{
	stacks->bubble_result.line = malloc(sizeof(char *) * (1));
	stacks->insert_result.line = malloc(sizeof(char *) * (1));
	stacks->k_result.line = malloc(sizeof(char *) * (1));
	if (!stacks->bubble_result.line || !stacks->insert_result.line || \
										!stacks->k_result.line)
		return (NULL);
	stacks->bubble_result.line[0] = NULL;
	stacks->insert_result.line[0] = NULL;
	stacks->k_result.line[0] = NULL;
	stacks->bubble_result.result_len = 1;
	stacks->insert_result.result_len = 1;
	stacks->k_result.result_len = 1;
	return (NULL);
}

void	*add_result(t_result_line *result_line, char	*val)
{
	int		counter2;

	ft_printf("Trying to add     %s operation.\n", val);
	result_line->result_len++;
	result_line->line = realloc(result_line->line, sizeof(char *) * \
								(result_line->result_len));
	if (!result_line->line)
		return (NULL);
	result_line->line[result_line->result_len - 2] = malloc(sizeof(char) * \
													(ft_strlen(val) + 1));
	if (!result_line->line[result_line->result_len - 2])
		return (NULL);
	counter2 = 0;
	while (val[counter2] != '\0')
	{
		result_line->line[result_line->result_len - 2][counter2] \
													= val[counter2];
		counter2++;
	}
	result_line->line[result_line->result_len - 2][counter2] = '\0';
	result_line->line[result_line->result_len - 1] = NULL;
	ft_printf("Added             %s operation.\n", result_line->line[result_line->result_len - 2]);
	return (NULL);
}

static void	print_result(t_result_line	*result)
{
	int		counter;

	if (VERBOSE != -1)
	{
		counter = 0;
		while (result->line[counter] != NULL)
		{
			ft_printf("%d: ", counter);
			if (result->line[counter] && result->line[counter][0] != '0')
				ft_printf("%s\n", result->line[counter]);
			counter++;
		}
		ft_printf("%d\n", result->result_len);
	}
}

void	print_best_result(t_stacks	*stacks)
{
	print_result(&stacks->insert_result);
	// if (stacks->bubble_result.result_len < stacks->insert_result.result_len && \
	// 	stacks->bubble_result.result_len < stacks->k_result.result_len)
	// {
	// 	if (VERBOSE == 1)
	// 		ft_printf("Used BUBBLE SORT!\n");
	// 	print_result(&stacks->bubble_result);
	// }
	// else if (stacks->insert_result.result_len < stacks->k_result.result_len)
	// {
	// 	if (VERBOSE == 1)
	// 		ft_printf("Used INSERTION SORT!\n");
	// 	print_result(&stacks->insert_result);
	// }
	// else
	// {
	// 	if (VERBOSE == 1)
	// 		ft_printf("Used K SORT!\n");
	// 	print_result(&stacks->k_result);
	// }
}
