/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:35:37 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 17:08:36 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments(int argc, char **argv)
{
	char	**split_args;
	char	**args;

	printf("🚀 Starting argument check...\n");
	split_args = parse_arguments(argc, argv);
	if (argc == 2)
	{
		printf("📦 Arguments provided as a single string, splitting...\n");
		args = split_args;
	}
	else
	{
		printf("🗂️ Multiple arguments provided, using argv directly...\n");
		args = argv;
	}
	validate_arguments(args, split_args);
	if (split_args != NULL)
	{
		printf("🧹 Cleaning up split arguments...\n");
		free_arguments(split_args);
	}
	printf("✅ Argument check complete!\n");
}

/* Split arguments if argc == 2 */
char	**parse_arguments(int argc, char **argv)
{
	char	**split_args;

	split_args = NULL;
	if (argc == 2)
	{
		printf("🔍 Parsing single argument string: \"%s\"\n", argv[1]);
		split_args = ft_split(argv[1]);
		if (!split_args)
		{
			printf("❌ Error: Failed to split arguments!\n");
			handle_error_exit(split_args);
		}
		printf("✅ Successfully split arguments.\n");
	}
	else
	{
		printf("📂 Skipping argument splitting.\n");
	}
	return (split_args);
}

/* Validate that all arguments are integers and check for duplicates */
void	validate_arguments(char **args, char **split_args)
{
	int	i;

	printf("🔍 Validating arguments...\n");
	i = 0;
	while (args[i])
	{
		printf("📋 Checking argument %d: \"%s\"\n", i, args[i]);
		if (!is_valid_integer(args[i]))
		{
			printf("❌ Error: Argument \"%s\" is not a valid integer!\n",
				args[i]);
			if (split_args != NULL)
				free_arguments(split_args);
			handle_error_exit(args);
		}
		i++;
	}
	if (has_duplicates(args))
	{
		printf("❌ Error: Duplicate arguments found!\n");
		if (split_args != NULL)
			free_arguments(split_args);
		handle_error_exit(args);
	}
	printf("✅ All arguments validated successfully.\n");
}
