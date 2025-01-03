/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:09:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 04:47:58 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include <stdbool.h>
# include <stdlib.h>

# define WIDTH 700
# define HEIGHT 700

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5
# define DESTROY_NOTIFY 17

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_R 114
# define KEY_PLUS 61
# define KEY_MINUS 45

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

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

void		error_exit(char *msg, t_fractal *fractal, int error_stage);
bool		is_valid_number(char *str);
void		init_mlx(t_fractal *fractal);
void		init_events(t_fractal *fractal);
void		data_init(t_fractal *fractal);

#endif