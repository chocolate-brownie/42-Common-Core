/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:35:37 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 17:01:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Wrapper function for parsing and validating arguments */
void	check_arguments(int argc, char **argv)
{
	char	**split_args;
	char	**args;

	split_args = parse_arguments(argc, argv);
	if (argc == 2)
		args = split_args;
	else
		args = argv;
	validate_arguments(args, split_args);
	if (split_args != NULL)
		free_arguments(split_args);
}

/* Split arguments if argc == 2 */
char	**parse_arguments(int argc, char **argv)
{
	char	**split_args;

	split_args = NULL;
	if (argc == 2)
	{
		split_args = ft_split(argv[1]);
		if (!split_args)
			handle_error_exit(split_args);
	}
	return (split_args);
}

/* Validate that all arguments are integers and check for duplicates */
void	validate_arguments(char **args, char **split_args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_integer(args[i]))
		{
			if (split_args != NULL)
				free_arguments(split_args);
			handle_error_exit(args);
		}
		i++;
	}
	if (has_duplicates(args))
	{
		if (split_args != NULL)
			free_arguments(split_args);
		handle_error_exit(args);
	}
}
