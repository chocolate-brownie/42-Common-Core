/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:09:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 03:39:53 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include <stdbool.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_ptr;

	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_math
{
	int		shift_x;
	int		shit_y;
	double	zoom;
	int		iterations;
}			t_math;

typedef struct s_param
{
	bool	is_mandel;
	bool	is_julia;
	char	*program_name;
}			t_param;

typedef struct s_fractal
{
	void	*conn;
	void	*win;
	double	julia_x;
	double	julia_y;
	t_param	param;
	t_math	math;
	t_img	img;

}			t_fractal;

void		error_exit(char *msg);
bool		is_valid_number(char *str);

#endif