/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:58:56 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 04:54:36 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	exit_with_error(t_fractal *fractal, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (fractal->mlx_ptr)
	{
		if (fractal->image.image_ptr)
			mlx_destroy_image(fractal->mlx_ptr, fractal->image.image_ptr);
		if (fractal->window_ptr)
			mlx_destroy_window(fractal->mlx_ptr, fractal->window_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
	exit(1);
}

static int	is_valid_double(char *str)
{
	int	i;
	int	has_decimal;

	i = 0;
	has_decimal = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '.')
		{
			if (has_decimal)
				return (0);
			has_decimal = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (has_decimal);
}

char	*get_valid_input(char *prompt, t_fractal *fractal)
{
	char	*input;

	ft_printf("%s", prompt);
	input = get_next_line(STDIN_FILENO);
	if (!input || !is_valid_double(input))
	{
		free(input);
		ft_printf("\nInvalid input. Enter a decimal number (e.g., 1.0)\n");
		ft_printf("\nAvailable parameters examples:\n\n");
		ft_printf(" * julia_x = -0.70176, julia_y = -0.3842\n");
		ft_printf(" * julia_x = 0.285, julia_y = 0.01\n");
		ft_printf(" * julia_x = -0.8, julia_y = 0.156\n");
		ft_printf(" * julia_x = 0.355, julia_y = 0.355\n");
		ft_printf(" * julia_x = -0.4, julia_y = 0.6\n");
		ft_printf(" * julia_x = -0.54, julia_y = 0.54\n");
		ft_printf(" * julia_x = -0.7269, julia_y = 0.1889\n");
		ft_printf(" * julia_x = 0.279, julia_y = 0.008\n");
		ft_printf(" * julia_x = -0.835, julia_y = -0.2321\n\n");
		exit_with_error(fractal, "\n-----Error-----\n");
	}
	return (input);
}
