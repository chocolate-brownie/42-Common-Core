/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:55:12 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/23 15:22:42 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>

# define WIDTH 960
# define HEIGHT 540

typedef struct s_vars
{
	void	*mlx_conn;
	void	*mlx_win;

}			t_vars;

#endif