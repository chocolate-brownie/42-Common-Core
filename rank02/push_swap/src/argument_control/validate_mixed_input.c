/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mixed_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:23:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 17:28:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
is_space_separated_string:
	Checks if an argument contains spaces. Returns true if spaces are detected.
validate_mixed_input:
	Iterates through all arguments and keeps track of whether space-separated
	strings (has_space_separated) or standalone numbers (has_standalone_number)
	are present.
	If both are detected, it exits with an error message.
Integration into handle_arguments:
	The validate_mixed_input function is called before handling arguments to
	reject mixed input early.
*/
bool	is_space_separated_string(const char *arg)
{
	while (*arg)
	{
		if (*arg == ' ')
			return (true);
		arg++;
	}
	return (false);
}

void	validate_mixed_input(int argc, char **argv)
{
	bool has_space_separated = false;
	bool has_standalone_number = false;

	for (int i = 1; i < argc; i++)
	{
		if (is_space_separated_string(argv[i]))
			has_space_separated = true;
		else
			has_standalone_number = true;

		if (has_space_separated && has_standalone_number)
			error_exit("[ERROR] Mixed arguments are not allowed");
	}
}