/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:09:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/04 20:38:44 by mgodawat         ###   ########.fr       */
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

# define COLOR_BLACK 0xFF000000
# define COLOR_WHITE 0xFFFFFFFF
# define COLOR_ELECTRIC_PURPLE 0xFF9932CC
# define COLOR_HOT_PINK 0xFFFF69B4
# define COLOR_NEON_GREEN 0xFF39FF14
# define COLOR_ACID_GREEN 0xFFB8E62E
# define COLOR_ELECTRIC_BLUE 0xFF7DF9FF
# define COLOR_PLASMA_PURPLE 0xFF8A2BE2
# define COLOR_NEON_ORANGE 0xFFFF6700
# define COLOR_CYBER_YELLOW 0xFFFFD300
# define COLOR_MAGENTA_BURST 0xFFFF00FF
# define COLOR_TOXIC_GREEN 0xFF00FF00
# define COLOR_LAVA_RED 0xFFFF3300
# define COLOR_LASER_BLUE 0xFF0033FF
# define COLOR_FUSION_PINK 0xFFFF1493
# define COLOR_VOID_PURPLE 0xFF9400D3
# define COLOR_QUANTUM_TURQUOISE 0xFF40E0D0

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

typedef struct s_complex
{
	double	x_real;
	double	y_imaginary;
}			t_complex;

typedef struct s_param
{
	char	*program_name;
	bool	is_mandel;
	bool	is_julia;
	double	julia_x;
	double	julia_y;
/* 	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max; */
}			t_param;

typedef struct s_fractal
{
	void	*conn;
	void	*win;
	t_param	param;
	t_img	img[2];
	int		curr_img;
	double	escape_value;
	int		max_iteration;
}			t_fractal;

/** @brief Utilities
 *  Error management,argument validation and math stuff
 */
void		error_exit(char *msg, t_fractal *fractal, int error_stage);
bool		is_valid_number(char *str);
// double		map(t_fractal *ptr);
double 		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

/** @brief Init process
 * Setting up the mlx connection and window
 * Setting up hooks for keyboard and mouse events
 */
void		init_mlx(t_fractal *fractal);
void		init_events(t_fractal *fractal);

/** @brief Rendering */
void		render_frame(t_fractal *fractal);

/** @brief Double image buffer management
 * Initiating two image structure to avoid screen tearing and handle pushing
 * image to the window process smoothly
 */
int			init_image_buffers(t_fractal *fractal);
void		swap_buffers(t_fractal *fractal, int back_buffer);

#endif