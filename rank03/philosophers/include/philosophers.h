/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:09:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 04:57:48 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/gnl/get_next_line_bonus.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>

# define PNAME "fractol"
# define STEP 10.0
# define ZOOM_FACTOR 1.2
# define SIZE_W 960
# define SIZE_H 540

# define F1 "Mandelbrot"
# define F2 "Julia"
# define F3 "BurningShip"
# define F4 "Tricorn"

# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_MOVE 6
# define CLOSE_BUTTON 17

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_PLUS 61
# define KEY_NUM_PLUS 65451
# define KEY_MINUS 45
# define KEY_NUM_MINUS 65453
# define KEY_F1 65470
# define KEY_F2 65471
# define KEY_F3 65472

typedef struct s_image_data
{
	void			*image_ptr;
	char			*pixel_addr;
	int				bits_per_pixel;
	int				line_size;
	int				endianness;
}					t_image_data;

typedef struct s_fractal
{
	void			*mlx_ptr;
	void			*window_ptr;
	int				fractal_type;
	int				max_iterations;
	int				palette_number;
	t_image_data	image;
	double			center_x;
	double			center_y;
	double			complex_real;
	double			complex_imag;
	double			julia_real;
	double			julia_imag;
	double			zoom_level;
}					t_fractal;

void				error_print_usage(void);
char				*get_valid_input(char *prompt, t_fractal *fractal);
void				error_mlx(char *fractal_type);
void				my_mlx_pixel_put(t_image_data *data, int x, int y,
						int color);
int					key_hook(int keycode, t_fractal *vars);
int					btnclose_hook(t_fractal *vars);
int					fractal_type(char *argv);
int					destroy(t_fractal *vars);
int					rendering(t_fractal *vars);
int					create_trgb(int t, int r, int g, int b);
int					get_pallete(int i, int pal_no);
void				draw_mandelbrot(t_fractal *fractal, int pixel_x,
						int pixel_y);
void				draw_julia(t_fractal *vars, int x, int y);
void				draw_burning_ship(t_fractal *fractal, int x, int y);
void				draw_tricorn(t_fractal *fractal, int x, int y);
int					zoom(int button, int x, int y, t_fractal *vars);
int					expose(t_fractal *vars);
void				struct_init(t_fractal *fractal, char *type);
void				process_julia(t_fractal *fractal);
void				print_manual(void);

#endif