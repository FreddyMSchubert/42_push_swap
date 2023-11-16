/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:58:40 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 10:30:12 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ----- SUBMODULES

#include "../submodules/42_ft_printf/ft_printf.h"
#include "../submodules/42_libft/libft.h"

// ----- SETTINGS

#define VERBOSE 1		// will output detailed logging if set to 1

// ----- STRUCTS

/*
	@param value		Actual value of the item
	@param slot_filled	1 if value is in slot, 0 if slot is empty
*/
typedef struct s_stack_item {
	int		value;
	int		slot_filled;
}				t_stack_item;
/*
	@brief				Contains two stacks a and b of height height;
	@param **a			Stack a. (length = height) (Pointer array)
	@param **b			Stack b. (length = height) (Pointer array)
	@param height		Height of both stacks. Stacks will always be same height
	@param operations	gets iterated for every operation. determines efficiency
*/
typedef struct s_stacks {
	t_stack_item	*a;
	t_stack_item	*b;
	t_stack_item	*sorted;
	int				height;
	int				operations;
}				t_stacks;

// ----- FILES

// --- Stacks

int			init_stacks(char	**argv, t_stacks	*stacks);
void		print_stacks(const t_stacks	*stacks);
void		free_stacks(t_stacks	*stacks);

// Functions

void		sa(t_stacks	*stacks, int print_stack);
void		sb(t_stacks	*stacks, int print_stack);
void		ss(t_stacks	*stacks);

void		pa(t_stacks	*stacks);
void		pb(t_stacks	*stacks);

void		ra(t_stacks	*stacks, int print_stack);
void		rb(t_stacks	*stacks, int print_stack);
void		rr(t_stacks	*stacks);

void		rra(t_stacks	*stacks, int print_stack);
void		rrb(t_stacks	*stacks, int print_stack);
void		rrr(t_stacks	*stacks);

// Utils

int			ft_arraylen(const void **array);
int			ft_tile_arraylen(t_stack_item	*array);
void		print_colored(const char *str, char color);
void		turn_on_gravity(t_stacks	*stacks);

// --- Sorting algos

void		bubble_sort(t_stacks	*stacks);
void		insertion_sort(t_stacks	*stacks);

// Utils

int			check_correctly_sorted(t_stack_item	*stack, int height);