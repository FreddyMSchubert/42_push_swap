/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:58:40 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/22 07:38:18 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ----- SUBMODULES

#include "../submodules/42_ft_printf/ft_printf.h"
#include "../submodules/42_libft/libft.h"
#include "../submodules/42_get_next_line/get_next_line.h"

// ----- SETTINGS

// will output detailed logging if set to 1, and normal logging but with 
// operations count as last line if set to -1
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
int			ft_limits_atoi(const char *s, t_stacks	*stacks);
void		exit_error(char	*message, t_stacks	*stacks);

// --- Stacks

int			init_stacks(char	**argv, t_stacks	*stacks);
void		print_stacks(const t_stacks	*stacks);
void		free_stacks(t_stacks	*stacks);

// Functions

void		sa(t_stacks	*stacks, int print);
void		sb(t_stacks	*stacks, int print);
void		ss(t_stacks	*stacks, int print);

void		pa(t_stacks	*stacks, int print);
void		pb(t_stacks	*stacks, int print);

void		ra(t_stacks	*stacks, int print);
void		rb(t_stacks	*stacks, int print);
void		rr(t_stacks	*stacks, int print);

void		rra(t_stacks	*stacks, int print);
void		rrb(t_stacks	*stacks, int print);
void		rrr(t_stacks	*stacks, int print);

// Utils

int			ft_arraylen(const void **array);
void		turn_on_gravity(t_stacks	*stacks);
void		check_errors_in_input(t_stacks	*stacks);

// --- Sorting algos

void		bubble_sort(t_stacks	*stacks);
void		bubble_sort_desc(t_stacks	*stacks);
void		k_sort(t_stacks	*stacks);
void		cheap_quick_sort(t_stacks	*stacks);

// --- General Utils

int			check_correctly_sorted_asc(t_stack_item	*stack, int height);
int			check_correctly_sorted_des(t_stack_item	*stack, int height);
int			find_index_by_value(t_stack_item *stack, int value, \
										int search_distance);
void		swap_item_properties(t_stack_item	*item1, t_stack_item	*item2);
void		print_colored(const char *str, char color);
