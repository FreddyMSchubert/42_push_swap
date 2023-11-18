/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:58:40 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/18 08:05:17 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ----- SUBMODULES

#include "../submodules/42_ft_printf/ft_printf.h"
#include "../submodules/42_libft/libft.h"

// ----- SETTINGS

// will output detailed logging if set to 1
#define VERBOSE 1

// defines at what length of substack to stop splitting and start sorting
// (in quick sort)
#define PIVOT_THRESH 5

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
	int				a_height;
	int				b_height;
	int				height;
	int				operations;
}				t_stacks;

// ----- FILES

// --- General

// Util

int			check_argument_validity(char	**argv);
void		exit_error(char	*message, t_stacks	*stacks);

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
void		print_colored(const char *str, char color);
void		turn_on_gravity(t_stacks	*stacks);

// --- Sorting algos

// - Bubble Sort

void		bubble_sort(t_stacks	*stacks);

// Bubble Utils

// - Insertion Sort

void		insertion_sort(t_stacks	*stacks);

// Insertion Utils

// - Quick sort

void		quick_sort(t_stacks	*stacks);

// Median / Pivot Stuff

int			push_numbers_after_median(t_stack_item *p_s, \
										t_stacks *stacks, int len);

// Quick utils

void		push_to_other_stack(t_stack_item	*p_s, t_stacks	*stacks);
void		swap_stack(t_stack_item	*p_s, t_stacks	*stacks);
void		rotate_stack(t_stack_item	*p_s, t_stacks	*stacks);
void		reverse_rotate_stack(t_stack_item	*p_s, t_stacks	*stacks);

// --- General Utils

int			check_correctly_sorted(t_stack_item	*stack, int height);