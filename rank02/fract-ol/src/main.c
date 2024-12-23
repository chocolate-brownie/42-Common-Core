/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:58:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/23 17:35:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	control_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fractol <type>\nTypes: mandelbrot, julia\n",
			STDERR_FILENO);
		return (1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1]))
		&& ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
	{
		ft_putstr_fd("Invalid fractal type\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	*vars;
	t_vars	*fractol;

	if (control_arguments(argc, argv))
		return (1);
	vars = open_window(argv[0]);
	close_window(vars);
	return (0);
}
