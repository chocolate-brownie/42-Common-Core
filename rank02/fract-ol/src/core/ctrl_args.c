/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:51:44 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/25 22:07:40 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_usage(void)
{
	ft_putendl_fd("Usage: ./fractol <type>", 1);
	ft_putendl_fd("Available types:", 1);
	ft_putendl_fd("  1. Mandelbrot", 1);
	ft_putendl_fd("  2. Julia", 1);
	ft_putendl_fd("  2. Burning Ship", 1);
	ft_putendl_fd("\nJulia set usage: ./fractol julia <real> <imaginary>", 1);
	ft_putendl_fd("Example: ./fractol julia -0.4 0.6", 1);
	exit(0);
}
