/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:45:09 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 19:52:57 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File contains general util functions

#include "../include/push_swap.h"

int	check_argument_validity(char	**argv)
{
	int		word_selector;
	int		char_selector;

	argv++;
	word_selector = 0;
	while (argv[word_selector] != NULL)
	{
		char_selector = 0;
		while (argv[word_selector][char_selector] != '\0')
		{
			if (!ft_isdigit(argv[word_selector][char_selector]) && \
				!(argv[word_selector][char_selector] == '-'))
				return (0);
			char_selector++;
		}
		word_selector++;
	}
	return (1);
}

void	exit_error(char	*message, t_stacks	*stacks)
{
	ft_printf(message);
	free_stacks(stacks);
	exit(EXIT_FAILURE);
}
