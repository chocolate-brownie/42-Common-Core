/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:55:12 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/25 22:19:49 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>

# define WIDTH 960
# define HEIGHT 540
# define MANDELBROT 1
# define JULIA 2

typedef struct s_fractol
{
	void	*connection;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*name;
	int		fractal_type;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	julia_real;
	double	julia_imag;
	double	zoom;
	int		max_iter;
	int		color_shift;
}			t_fractol;

int			clean_exit(t_fractol *fractol, char *message, int exit_code);

#endif
