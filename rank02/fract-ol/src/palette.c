/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:17:41 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 10:13:41 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int	hellfire(int i)
{
	if (i % 12 == 0)
		return (create_trgb(0, 128, 0, 0));
	else if (i % 12 == 1)
		return (create_trgb(0, 205, 0, 0));
	else if (i % 12 == 2)
		return (create_trgb(0, 255, 36, 0));
	else if (i % 12 == 3)
		return (create_trgb(0, 255, 69, 0));
	else if (i % 12 == 4)
		return (create_trgb(0, 255, 104, 31));
	else if (i % 12 == 5)
		return (create_trgb(0, 255, 140, 0));
	else if (i % 12 == 6)
		return (create_trgb(0, 255, 165, 0));
	else if (i % 12 == 7)
		return (create_trgb(0, 255, 69, 0));
	else if (i % 12 == 8)
		return (create_trgb(0, 255, 55, 0));
	else if (i % 12 == 9)
		return (create_trgb(0, 255, 0, 0));
	else if (i % 12 == 10)
		return (create_trgb(0, 139, 0, 0));
	else
		return (create_trgb(0, 178, 34, 34));
}

static int	classic_mandel(int i)
{
	if (i % 6 == 0)
		return (create_trgb(0, 0, 0, 139));
	else if (i % 6 == 1)
		return (create_trgb(0, 255, 215, 0));
	else if (i % 6 == 2)
		return (create_trgb(0, 0, 0, 205));
	else if (i % 6 == 3)
		return (create_trgb(0, 255, 255, 0));
	else if (i % 6 == 4)
		return (create_trgb(0, 0, 0, 255));
	else
		return (create_trgb(0, 218, 165, 32));
}

static int	classic_rainbow(int i)
{
	if (i % 6 == 0)
		return (create_trgb(0, 148, 0, 211));
	else if (i % 6 == 1)
		return (create_trgb(0, 0, 0, 255));
	else if (i % 6 == 2)
		return (create_trgb(0, 0, 255, 0));
	else if (i % 6 == 3)
		return (create_trgb(0, 255, 255, 0));
	else if (i % 6 == 4)
		return (create_trgb(0, 255, 127, 0));
	else
		return (create_trgb(0, 255, 0, 0));
}

int	get_pallete(int i, int pal_no)
{
	if (pal_no == 2)
		return (classic_mandel(i));
	else if (pal_no == 3)
		return (classic_rainbow(i));
	return (hellfire(i));
}
