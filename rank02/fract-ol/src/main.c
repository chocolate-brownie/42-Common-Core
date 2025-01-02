/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:09:53 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 22:53:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	control_arguments(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		return (0);
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		if (is_valid_number(argv[2] && is_valid_number(argv[3])))
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_fractal	*fractal;
}
