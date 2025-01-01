/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:53:57 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/01 17:31:39 by milan-god        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	free_mlx(t_fractol *fractol)
{
	if (fractol->image.ptr_img && fractol->connection)
		mlx_destroy_image(fractol->connection, fractol->image.ptr_img);
	if (fractol->window && fractol->connection)
		mlx_destroy_window(fractol->connection, fractol->window);
	if (fractol->connection)
	{
		mlx_destroy_display(fractol->connection);
		free(fractol->connection);
	}
}

static void	print_message(char *message, int exit_code)
{
	if (message)
	{
		if (exit_code == 0)
			ft_putendl_fd(message, 1);
		else
			ft_putendl_fd(message, 2);
	}
}
/**
 * Performs clean program exit with proper resource cleanup
 * 1. Frees all MLX resources if fractol exists
 * 2. Prints exit message
 * 3. Exits program with provided exit code
 */
int	clean_exit(t_fractol *fractol, char *message, int exit_code)
{
	if (fractol)
	{
		free_mlx(fractol);
		free(fractol);
	}
	print_message(message, exit_code);
	exit(exit_code);
	return (exit_code);
}
