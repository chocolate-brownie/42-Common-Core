/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:53:57 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/25 22:10:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	free_mlx(t_fractol *fractol)
{
	if (fractol->img && fractol->connection)
		mlx_destroy_image(fractol->connection, fractol->img);
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

int	clean_exit(t_fractol *fractol, char *message, int exit_code)
{
	if (fractol)
	{
		free_mlx(fractol);
		if (fractol->name)
			free(fractol->name);
		free(fractol);
	}
	print_message(message, exit_code);
	exit(exit_code);
	return (exit_code);
}
