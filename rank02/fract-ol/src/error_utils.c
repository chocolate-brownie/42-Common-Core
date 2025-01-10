/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:08:18 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 04:12:03 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_print_usage(void)
{
	ft_printf("%s has invalid input\n", PNAME);
	ft_printf("Please choose one of the following\n");
	ft_printf("\t1:%s\n\t2:%s\n\t3:%s\n\t4:%s\n", F1, F2, F3, F4);
	exit(1);
}

void	error_mlx(char *fractal_type)
{
	ft_printf("%s: %s: Failed to init mlx\n", PNAME, fractal_type);
	exit(2);
}

int	expose(t_fractal *vars)
{
	rendering(vars);
	return (0);
}
