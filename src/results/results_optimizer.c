/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   results_optimizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:17:24 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 18:40:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// used to remove redundanices and improve efficiency for a result string

#include "../../include/push_swap.h"

// @brief	If function find wanted1 and wanted2 after each other, wanted2
// @brief	gets freed + turned to NULL, wanted1 gets replaced with double actio
// @brief	index replindex of wanted1 gets replaced with char at [0].
// @brief	e.g. sa sb -> ss (null)
static void	merge_items(t_result_line *result, char *wanted1, \
						char *wanted2, int replindex)
{
	int		counter;

	counter = 0;
	while (counter < result->result_len)
	{
		if ((result->line[counter] == wanted1 && \
			result->line[counter + 1] == wanted2) || \
			(result->line[counter] == wanted2 && \
			result->line[counter + 1] == wanted1))
		{
			ft_printf("found a merge redundancy!\n");
			result->line[counter][replindex] = result->line[counter][0];
			free(result->line[counter + 1]);
			result->line[counter + 1] = NULL;
		}
		counter++;
	}
}

static void	remove_redundant_items(t_result_line *result, char *wanted1, \
										char *wanted2)
{
	int		counter;

	counter = 0;
	while (counter < result->result_len)
	{
		if ((result->line[counter] == wanted1 && \
			result->line[counter + 1] == wanted2) || \
			(result->line[counter] == wanted2 && \
			result->line[counter + 1] == wanted1))
		{
			ft_printf("found a redundancy!\n");
			free(result->line[counter]);
			free(result->line[counter + 1]);
			result->line[counter] = NULL;
			result->line[counter + 1] = NULL;
		}
		counter++;
	}
}

void	remove_redundancies_in_result(t_result_line	*result)
{
	merge_items(result, "sa", "sb", 1);
	merge_items(result, "ra", "rb", 1);
	merge_items(result, "rra", "rrb", 2);
	remove_redundant_items(result, "pa", "pb");
	remove_redundant_items(result, "sa", "sa");
	remove_redundant_items(result, "sb", "sb");
	remove_redundant_items(result, "ss", "ss");
	remove_redundant_items(result, "ra", "rra");
	remove_redundant_items(result, "rb", "rrb");
	remove_redundant_items(result, "rr", "rrr");
}
