/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:36:55 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:37:18 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/gnl/get_next_line_bonus.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/include/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

/* Window and rendering constants */
# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 540
# define MOVEMENT_STEP 10.0
# define ZOOM_FACTOR 1.2
# define PROGRAM_NAME "fractol"

/* File descriptors */
# define FD_STDOUT STDOUT_FILENO
# define FD_STDIN STDIN_FILENO
# define FD_STDERR STDERR_FILENO

/* MLX event codes */
# define EVENT_KEY_PRESS 2
# define EVENT_MOUSE_PRESS 4
# define EVENT_MOUSE_MOVE 6
# define EVENT_WINDOW_CLOSE 17

/* Fractal types */
# define FRACTAL_MANDELBROT "Mandelbrot"
# define FRACTAL_JULIA "Julia"
# define FRACTAL_BURNING_SHIP "Burning_Ship"
# define FRACTAL_MANDELBROT3 "Mandelbrot3"
# define FRACTAL_MANDELBROT4 "Mandelbrot4"

typedef struct s_image
{
	void	*img_ptr;
	char	*pixel_data;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_image;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fractal_type;
	int		max_iterations;
	int		color_palette;
	t_image	img;
	double	center_x;
	double	center_y;
	double	julia_real;
	double	julia_imag;
	double	complex_real;
	double	complex_imag;
	double	zoom_level;
}			t_fractal;

/* Error handling */
void		print_usage_error(void);
void		print_mlx_error(char *message);
int			is_valid_fractal(char *name);

/* Color management */
int			create_color(int transparency, int red, int green, int blue);
int			get_color_component(int color, char component);
int			add_shade(double intensity, int base_color);
int			get_complementary_color(int color);

/* Color palettes */
int			get_color_palette(int iteration, int palette_id);
int			get_fire_palette(int iteration);
int			get_warm_palette(int iteration);
int			get_ocean_palette(int iteration);

/* Window controls */
int			cleanup_and_exit(t_fractal *fractal);
int			handle_keypress(int key, t_fractal *fractal);
int			handle_zoom(int button, int x, int y, t_fractal *fractal);
int			handle_window_close(t_fractal *fractal);
int			handle_expose(t_fractal *fractal);
int			render_frame(t_fractal *fractal);
void		set_pixel(t_image *img, int x, int y, int color);
static void	handle_extra_keys(int key, t_fractal *fractal);

/* Fractal renderers */
void		render_mandelbrot(t_fractal *fractal, int x, int y);
void		render_julia(t_fractal *fractal, int x, int y);
void		render_burning_ship(t_fractal *fractal, int x, int y);
void		render_mandelbrot3(t_fractal *fractal, int x, int y);
void		render_mandelbrot4(t_fractal *fractal, int x, int y);
static void	calc_quartic(t_fractal *fractal, double cx, double cy);
static void	set_pixel_color(t_fractal *fractal, int x, int y, int iterations);

#endif