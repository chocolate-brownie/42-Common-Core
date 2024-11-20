/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:04 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/20 13:38:52 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_SIZE_H
#define FT_LIST_SIZE_H

typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

#endif