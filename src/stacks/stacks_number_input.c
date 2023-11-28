/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_number_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:22:47 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/28 06:04:20 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

#include <limits.h>

static int	ft_limits_isspace(const char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || s == '\v')
		return (1);
	if (s == '\f' || s == '\r')
		return (1);
	return (0);
}

void	check_valid_range(long value, t_stacks	*stacks)
{
	if (value > INT_MAX || value < INT_MIN)
		exit_error("A number was outside of valid int range.\n", stacks);
}

int	ft_limits_atoi(const char *s, t_stacks	*stacks)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	sign = 1;
	value = 0;
	while (ft_limits_isspace(s[i]))
		i++;
	if (!ft_isdigit(s[i]))
	{
		if (s[i] == '-')
			sign = -sign;
		if (s[i] == '-' || s[i] == '+')
			i++;
		else
			return (0);
	}
	while (ft_isdigit(s[i]))
	{
		value = (value * 10) + s[i] - 48;
		check_valid_range(value * sign, stacks);
		i++;
	}
	return ((int)value * sign);
}
