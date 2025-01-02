/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:19:24 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:26:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Picks color palette based on user choice
 * Each palette has different color patterns
 */
int	get_color_palette(int iteration, int palette_id)
{
	if (palette_id == 2)
		return (get_warm_palette(iteration));
	else if (palette_id == 3)
		return (get_ocean_palette(iteration));
	return (get_fire_palette(iteration));
}

/**
 * Fire-themed colors (orange, red, yellow)
 */
int	get_fire_palette(int iteration)
{
	if (iteration % 8 == 0)
		return (create_color(0, 133, 50, 33));
	else if (iteration % 8 == 1)
		return (create_color(0, 254, 94, 65));
	else if (iteration % 8 == 2)
		return (create_color(0, 249, 144, 93));
	else if (iteration % 8 == 3)
		return (create_color(0, 243, 193, 120));
	else if (iteration % 8 == 4)
		return (create_color(0, 230, 217, 140));
	else if (iteration % 8 == 5)
		return (create_color(0, 216, 241, 160));
	else if (iteration % 8 == 6)
		return (create_color(0, 108, 205, 140));
	return (create_color(0, 0, 168, 120));
}

/**
 * Warm pastel colors (pink, white, green)
 */
int	get_warm_palette(int iteration)
{
	if (iteration % 4 == 0)
		return (create_color(0, 250, 112, 112));
	else if (iteration % 4 == 1)
		return (create_color(0, 254, 253, 237));
	else if (iteration % 4 == 2)
		return (create_color(0, 198, 235, 197));
	return (create_color(0, 161, 195, 152));
}

/**
 * Ocean-themed colors (turquoise, yellow, white)
 */
int	get_ocean_palette(int iteration)
{
	if (iteration % 5 == 0)
		return (create_color(0, 229, 61, 0));
	else if (iteration % 5 == 1)
		return (create_color(0, 255, 233, 0));
	else if (iteration % 5 == 2)
		return (create_color(0, 252, 255, 247));
	else if (iteration % 5 == 3)
		return (create_color(0, 33, 160, 160));
	return (create_color(0, 4, 104, 101));
}
