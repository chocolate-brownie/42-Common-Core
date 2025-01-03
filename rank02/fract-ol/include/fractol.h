/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:09:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 04:01:20 by mgodawat         ###   ########.fr       */
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

# define ERR_MLX_INIT "[ERROR]: MLX initialization failed"
# define ERR_WIN_INIT "[ERROR]: Window creation failed"
# define ERR_IMG_INIT "[ERROR]: Image creation failed"
# define ERR_ADDR_INIT "[ERROR]: Image address retrieval failed"

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
	int		shift_y;
	double	zoom;
	int		iterations;
	double	hypotenuse;
}			t_math;

typedef struct s_param
{
	bool	is_mandel;
	bool	is_julia;
	double	julia_x;
	double	julia_y;
	char	*program_name;
}			t_param;

typedef struct s_fractal
{
	void	*conn;
	void	*win;

	t_param	param;
	t_math	math;
	t_img	img;

}			t_fractal;

void		error_exit(char *msg);
bool		is_valid_number(char *str);
void		init_mlx(t_fractal *fractal);

#endif