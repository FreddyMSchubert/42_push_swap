/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:58:40 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/20 17:50:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ----- SUBMODULES

#include "../submodules/42_ft_printf/ft_printf.h"
#include "../submodules/42_libft/libft.h"

// ----- SETTINGS

// will output detailed logging if set to 1, no logging if -1
#define VERBOSE 0

// defines at what length of substack to stop splitting and start sorting
// (in quick sort)
#define PIVOT_THRESH 5

// ----- STRUCTS

/*
	@param value		Actual value of the item
	@param slot_filled	1 if value is in slot, 0 if slot is empty
	@param sorted_index	Index that value has in sorted stack / result
*/
typedef struct s_stack_item {
	int		value;
	int		slot_filled;
	int		sorted_index;
}				t_stack_item;
/*
	@brief				Keeps track of one result line
	@param line			The actual line itself
	@param result_len	allocated length including NULL
*/
typedef struct s_result_line {
	char	**line;
	int		result_len;
}				t_result_line;
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
	t_result_line	k_result;
	t_result_line	bubble_result;
	t_result_line	insert_result;
}				t_stacks;

// ----- FILES

// --- General

// Util

int			check_argument_validity(char	**argv);
void		exit_error(char	*message, t_stacks	*stacks);

// Results

void		*init_results(t_stacks	*stacks);
void		*add_result(t_result_line *result_line, char	*val);
void		print_best_result(t_stacks	*stacks);

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

// - Basic Sorts

void		bubble_sort(t_stacks	*stacks);
void		insertion_sort(t_stacks	*stacks);
void		k_sort(t_stacks	*stacks);

// - Quick sort

void		quick_sort(t_stacks	*stacks);

// Median / Pivot Stuff

int			push_numbers_after_median(t_stack_item *p_s, \
										t_stacks *stacks, int len);

// Bubble Stuff

void		bubble_sort_stack_ascending(t_stack_item	*stack, \
								t_stacks	*stacks, \
								int len);
void		bubble_sort_stack_descending(t_stack_item	*stack, \
								t_stacks	*stacks, \
								int len);

// Quick utils

void		push_to_other_stack(t_stack_item	*p_s, t_stacks	*stacks);
void		swap_stack(t_stack_item	*p_s, t_stacks	*stacks);
void		rotate_stack(t_stack_item	*p_s, t_stacks	*stacks);
void		reverse_rotate_stack(t_stack_item	*p_s, t_stacks	*stacks);

// --- General Utils

int			check_correctly_sorted_asc(t_stack_item	*stack, int height);
int			check_correctly_sorted_des(t_stack_item	*stack, int height);
int			find_index_by_value(t_stack_item *stack, int value, \
										int search_distance);
void		swap_item_properties(t_stack_item	*item1, t_stack_item	*item2);