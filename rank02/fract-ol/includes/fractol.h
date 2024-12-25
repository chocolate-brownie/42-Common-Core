/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:55:12 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/25 20:57:10 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>

# define WIDTH 960
# define HEIGHT 540
# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

typedef struct s_vars
{
	void	*mlx_conn;
	void	*mlx_win;
}			t_vars;

t_vars		*open_window(char *program_name);
void		close_window(t_vars *vars);

#endif
