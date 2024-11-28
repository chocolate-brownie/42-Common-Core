/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:06:17 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 17:30:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Controls argument parsing, validation, and populates stack_a.
*/
void	control_arguments(int argc, char **argv, t_stack *stack_a)
{
	char	**split_args;
	int		i;
	long	nbr;

	if (argc == 2)
		split_args = ft_split(argv[1], ' ');
	else if (argc > 2)
		split_args = argv + 1;
	else
		return ;
	i = 0;
	while (split_args[i])
	{
		nbr = ft_atol(split_args[i]);
		validate_argument(split_args, argc, nbr, stack_a);
		push_to_stack(stack_a, (int)nbr);
		i++;
	}
	if (argc == 2)
		free_split(split_args);
}

/*
** Validates an individual argument.
** Checks for integer range and duplicates, exits on failure.
*/
void	validate_argument(char **split_args, int argc, long nbr,
		t_stack *stack_a)
{
	if (!is_valid_integer(nbr) || is_duplicate(stack_a, (int)nbr))
	{
		if (argc == 2)
			free_split(split_args);
		free_stack(stack_a);
		error_exit();
	}
}

int	is_valid_integer(long nbr)
{
	return (nbr >= INT_MIN && nbr <= INT_MAX);
}

int	is_duplicate(t_stack *stack, int nbr)
{
	t_stack_node	*current;

	current = stack->head;
	while (current)
	{
		if (current->nbr == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}
