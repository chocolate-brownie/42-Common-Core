/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:51:44 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/27 18:06:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_usage(void)
{
	ft_putendl_fd("\nError: Invalid Arguments", 2);
	ft_putendl_fd("Usage: ./fractol <type> <real> <imaginary>", 2);
	ft_putendl_fd("\nAvailable types:", 2);
	ft_putendl_fd("  1. Mandelbrot", 2);
	ft_putendl_fd("  2. Julia", 2);
	ft_putendl_fd("  3. Burning_Ship", 2);
	ft_putendl_fd("\nExample: ./fractol julia -0.4 0.6\n", 2);
	exit(0);
}

static int	is_valid_fractal(char *name)
{
	int	choice;

	choice = ft_atoi(name);
	if (choice == 1 || !ft_strncasecmp(name, "Mandelbrot", 10))
		return (MANDELBROT);
	if (choice == 2 || !ft_strncasecmp(name, "Julia", 10))
		return (JULIA);
	if (choice == 3 || !ft_strncasecmp(name, "Burning_Ship", 10))
		return (BURNING_SHIP);
	return (0);
}

static int	valid_value(char *str)
{
	int	i;
	int	dots;

	i = 0;
	dots = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.' && dots == 0)
			dots++;
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	*window_name(char **argv)
{
	if (argv[1][0] == '1' || !ft_strncasecmp(argv[1], "mandelbrot", 10))
		return ("fractol: Mandelbrot");
	if (argv[1][0] == '2' || !ft_strncasecmp(argv[1], "julia", 5))
		return ("fractol: Julia");
	if (argv[1][0] == '3' || !ft_strncasecmp(argv[1], "burning_ship", 12))
		return ("fractol: Burning Ship");
	return ("ERROR: Invalid window name!");
}

t_fractol	*control_args(char argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 4 || !valid_value(argv[2]) || !valid_value(argv[3]))
		print_usage();
	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (NULL);
	fractol->fractal_type = is_valid_fractal(argv[1]);
	if (!fractol->fractal_type)
	{
		free(fractol);
		print_usage();
	}
	fractol->name = window_name(argv);
	fractol->imag = ft_atof(argv[2]);
	fractol->real = ft_atof(argv[3]);
	fractol->img = NULL;
	fractol->addr = NULL;
	return (fractol);
}
