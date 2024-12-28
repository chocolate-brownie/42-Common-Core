/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:55:12 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/28 18:46:23 by mgodawat         ###   ########.fr       */
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
# define BURNING_SHIP 3

/**
 * @brief struct for the math stuff
 */

typedef struct s_math
{
	double		real;
	double		imaginary;
}				t_math;

/**
 * Structure for some basic varibles
 * @param name is the fractol type ex: julia mandelbrot
 * @param id for the fractol types mandelbrot[1] julia[2] burningship[3]
 */
typedef struct s_params
{
	char		*name;
	int			id;
}				t_params;

/**
 * We will have to buffer all of our pixels to a image, which we will
 * then push to the window, the structure for the pixel buffer control
 * @note values from mlx_get_data_addr();
 */
typedef struct s_image
{
	void		*ptr_img;
	char		*ptr_pixels;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

/**
 * @brief Main structure combining all the necessary sub structures
 * @param connection --> mlx_init()
 * @param window --> mlx_new_window()
 */
typedef struct s_fractol
{
	void		*connection;
	void		*window;
	t_image		image;
	t_params	params;
	t_math		math;
}				t_fractol;

int				clean_exit(t_fractol *fractol, char *message, int exit_code);
double			ft_atof(const char *str);
t_fractol		*control_args(char argc, char **argv);

#endif
