/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:09:53 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 04:24:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	parsing(int argc, char **argv, t_fractal *ptr)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
	{
		ptr->param.is_mandel = true;
		ptr->param.program_name = "MANDELBROT";
		return (0);
	}
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		if (is_valid_number(argv[2]) && is_valid_number(argv[3]))
		{
			ptr->param.is_julia = true;
			ptr->param.program_name = "JULIA";
			ptr->param.julia_x = ft_atof(argv[2]);
			ptr->param.julia_y = ft_atof(argv[3]);
			return (0);
		}
	}
	return (1);
}

static void	exit_message(t_fractal *ptr)
{
	ft_putendl_fd("Invalid parameters", STDERR_FILENO);
	ft_putendl_fd("Usage:", STDERR_FILENO);
	ft_putendl_fd("[1] ./fractol mandelbrot", STDERR_FILENO);
	ft_putendl_fd("[2] ./fractol julia <x> <y>", STDERR_FILENO);
	if (ptr && ptr->conn)
		mlx_destroy_display(ptr->conn);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	ft_memset(&fractal, 0, sizeof(t_fractal));
	if (parsing(argc, argv, &fractal) == 1)
		exit_message(&fractal);
	init_mlx(&fractal);
	init_events(&fractal);
	mlx_loop(fractal.conn);
}
