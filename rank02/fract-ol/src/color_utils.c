/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:27:40 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:31:01 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Creates a 32-bit color from components
 */
int	create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/**
 * Gets single color component (t,r,g,b)
 */
int	get_color_component(int color, char component)
{
	if (component == 't')
		return ((color >> 24) & 0xFF);
	else if (component == 'r')
		return ((color >> 16) & 0xFF);
	else if (component == 'g')
		return ((color >> 8) & 0xFF);
	return (color & 0xFF);
}

/**
 * Darkens a color by a factor (0-1)
 */
int	add_shade(double factor, int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_color_component(color, 't');
	r = get_color_component(color, 'r') * (1 - factor);
	g = get_color_component(color, 'g') * (1 - factor);
	b = get_color_component(color, 'b') * (1 - factor);
	return (create_color(t, r, g, b));
}

/**
 * Gets complementary (opposite) color
 */
int	get_complementary_color(int color)
{
	int t = get_color_component(color, 't');
	int r = 255 - get_color_component(color, 'r');
	int g = 255 - get_color_component(color, 'g');
	int b = 255 - get_color_component(color, 'b');
	return (create_color(t, r, g, b));
}