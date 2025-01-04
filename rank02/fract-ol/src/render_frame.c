/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:11:20 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/04 21:15:21 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../include/fractol.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}

static void	map_coordinates(int x, int y, t_complex *c, t_fractal *fractal)
{
	fractal->param.unscaled_num = x;
	fractal->param.new_min = -2;
	fractal->param.new_max = +2;
	fractal->param.old_min = 0;
	fractal->param.old_max = WIDTH;
	c->x_real = map(fractal);
	fractal->param.unscaled_num = y;
	fractal->param.new_min = +2;
	fractal->param.new_max = -2;
	fractal->param.old_min = 0;
	fractal->param.old_max = HEIGHT;
	c->y_imaginary = map(fractal);
}

static int	map_colors(int i, t_fractal *fractal)
{
	fractal->param.unscaled_num = i;
	fractal->param.new_min = COLOR_BLACK;
	fractal->param.new_max = COLOR_WHITE;
	fractal->param.old_min = 0;
	fractal->param.old_max = fractal->max_iteration;
	return (int)map(fractal);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		magnitude_squared;
	int			i;
	int			color;

	i = 0;
	z.x_real = 0.0;
	z.y_imaginary = 0.0;
	map_coordinates(x, y, &c, fractal);
	while (i < fractal->max_iteration)
	{
		z = sum_complex(square_complex(z), c);
		magnitude_squared = z.x_real * z.x_real + z.y_imaginary * z.y_imaginary;
		if (magnitude_squared > fractal->escape_value)
		{
			color = map_colors(i, fractal);
			put_pixel(&fractal->img[fractal->curr_img], x, y, color);
			return ;
		}
		++i;
	}
	put_pixel(&fractal->img[fractal->curr_img], x, y, COLOR_WHITE);
}

void    render_frame(t_fractal *fractal)
{
    int x;
    int y;
    int back_buffer;

    printf("Starting render with double buffering...\n");

    back_buffer = (fractal->curr_img + 1) % 2;
    printf("Current buffer: %d, Back buffer: %d\n", fractal->curr_img, back_buffer);

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
			handle_pixel(x, y, fractal);
            x++;
        }
        y++;
    }

    printf("Drawing complete, swapping buffers...\n");
    swap_buffers(fractal, back_buffer);
    printf("Render complete\n");
} */

#include "../include/fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	printf("Running mypixelput ...\n");

	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)(img->pix_ptr + offset) = color;
	}

	printf("ENDING mypixelput ...\n");

}

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    // Debug the inputs
    printf("map function inputs: unscaled=%f, new_min=%f, new_max=%f, old_min=%f, old_max=%f\n",
           unscaled_num, new_min, new_max, old_min, old_max);

    double result = (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
    printf("map function output: %f\n", result);
    return result;
}

/* static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (fractal->param.is_julia == true)
	{
		c->x_real = fractal->param.julia_x;
		c->y_imaginary = fractal->param.julia_x;
	}
	else
	{
		c->x_real = z->x_real;
		c->y_imaginary = z->y_imaginary;
	}
} */

static void    handle_pixel(int x, int y, t_fractal *fractal)
{
    printf("Running handle pixel...\n");

    double      magnitude_squared;
    int         iteration = 0;
    int         color;

	t_complex z;
    t_complex c;

    z.x_real = 0.0;
    z.y_imaginary = 0.0;

    // Debug the inputs to map function
    printf("Mapping x: input=%d, WIDTH=%d\n", x, WIDTH);
    printf("Mapping y: input=%d, HEIGHT=%d\n", y, HEIGHT);

    c.x_real = map(x, -2, +2, 0, WIDTH);
    c.y_imaginary = map(y, 2, -2, 0, HEIGHT);

    // Debug the mapped values
    printf("Mapped to: c=(%f, %f)\n", c.x_real, c.y_imaginary);

    printf("Initial values - c: (%f, %f), max_iteration: %d, escape_value: %f\n",
           c.x_real, c.y_imaginary, fractal->max_iteration, fractal->escape_value);

    while (iteration < fractal->max_iteration)
    {
        z = sum_complex(square_complex(z), c);
        magnitude_squared = (z.x_real * z.x_real) + (z.y_imaginary * z.y_imaginary);

        printf("Iteration %d: z=(%f, %f), magnitude_squared=%f\n",
               iteration, z.x_real, z.y_imaginary, magnitude_squared);

        if (magnitude_squared > fractal->escape_value)
        {
            color = map(iteration, COLOR_BLACK, COLOR_WHITE, 0, fractal->max_iteration);
            my_pixel_put(x, y, &fractal->img[fractal->curr_img], color);
            return;
        }
        ++iteration;
    }
    my_pixel_put(x, y, &fractal->img[fractal->curr_img], COLOR_BLACK);
    printf("ENDING handle pixel...\n");
}

void	render_frame(t_fractal *fractal)
{
    int	back_buffer;
    int	y;
    int	x;

    printf("\nStarting Mandelbrot render...\n");
    printf("max_iteration: %d, escape_value: %f\n",
           fractal->max_iteration, fractal->escape_value);

    back_buffer = (fractal->curr_img + 1) % 2;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
            handle_pixel(x, y, fractal);
    }

    printf("Frame complete, swapping buffers...\n");
    printf("Current buffer: %d, Back buffer: %d\n", fractal->curr_img, back_buffer);

    swap_buffers(fractal, back_buffer);
}
