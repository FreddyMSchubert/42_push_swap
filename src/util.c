/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:45:09 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/21 11:17:11 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File contains general util functions

#include "../include/push_swap.h"

int	check_argument_validity_string(char	**argv)
{
	int	counter;

	counter = 0;
	while (argv[1][counter])
	{
		if (!ft_isdigit(argv[1][counter]) && !(argv[1][counter] == '-') && \
				!(argv[1][counter] == ' '))
			return (0);
		counter++;
	}
	return (1);
}

// @brief	Used to check validity of inputted arguments
int	check_argument_validity(char	**argv)
{
	int		word_selector;
	int		char_selector;

	if (ft_arraylen((const void **)argv) == 2)
		return (check_argument_validity_string(argv));
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

// @brief	exits program after freeing stacks and logging an error message
void	exit_error(char	*message, t_stacks	*stacks)
{
	if (VERBOSE == 1)
		ft_printf(message);
	else
		write(2, "Error\n", 6);
	if (stacks != NULL)
		free_stacks(stacks);
	exit(EXIT_FAILURE);
}

// @brief		Prints stuff, but with colors! No colors if verbose is off
// @brief		Also adds a terminating new line
void	print_colored(const char *str, char color)
{
	const char	*color_code;

	color_code = "\033[0m";
	if (color == 'r')
		color_code = "\033[31m";
	if (color == 'g')
		color_code = "\033[32m";
	if (color == 'y')
		color_code = "\033[33m";
	if (color == 'b')
		color_code = "\033[34m";
	if (color == 'm')
		color_code = "\033[35m";
	if (color == 'c')
		color_code = "\033[36m";
	if (VERBOSE == 1)
		ft_printf("%s%s\033[0m", color_code, str);
	else
		ft_printf("%s", str);
	ft_printf("\n");
}
