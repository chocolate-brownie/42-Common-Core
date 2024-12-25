/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:58:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/25 21:12:48 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	control_arguments(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fractol <type>\nTypes: mandelbrot, julia\n",
			STDERR_FILENO);
		return (1);
	}
	len = ft_strlen(argv[1]);
	if ((len != 10 || ft_strncmp(argv[1], "mandelbrot", 10) != 0) && (len != 5
			|| ft_strncmp(argv[1], "julia", 5) != 0))
	{
		ft_putstr_fd("Invalid fractal type\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;
	char	*program_name;

	program_name = ft_strjoin(argv[0], "-");
	vars = NULL;
	if (control_arguments(argc, argv) == 1)
		exit(EXIT_FAILURE);
	vars = open_window(ft_strjoin(program_name, argv[1]));
	close_window(vars);
	return (0);
}
