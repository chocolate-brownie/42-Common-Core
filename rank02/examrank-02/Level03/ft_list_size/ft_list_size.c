/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:01:25 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 15:08:32 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list	*curr;
	int		i;

	curr = begin_list;
	i = 0;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

t_list	*create_node(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		size;

	node1 = create_node("First");
	node2 = create_node("Second");
	node3 = create_node("Third");
	node1->next = node2;
	node2->next = node3;
	size = ft_list_size(node1);
	printf("List size: %d\n", size);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
