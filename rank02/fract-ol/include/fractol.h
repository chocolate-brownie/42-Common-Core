/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:09:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 23:04:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_ptr;

	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_param
{
	bool	is_julia;
	bool	is_mandel;
}			t_param;

typedef struct s_fractal
{
	void	*conn;
	void	*win;
	t_img	img;
	t_param	param;
}			t_fractal;

bool		is_valid_number(char *str);

#endif