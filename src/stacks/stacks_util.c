/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:50:35 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/15 09:57:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file contains some helpful utils for the other stack files. */

#include "../../include/push_swap.h"

// @brief	Counts elements in a NULL - terminated array of any type
int	ft_arraylen(const void **array)
{
	int		count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}

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
	ft_printf("%s%s\033[0m", color_code, str);
}
