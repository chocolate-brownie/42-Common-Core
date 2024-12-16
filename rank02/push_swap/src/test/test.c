#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int	stack_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*curr;

	len = 0;
	curr = stack;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;
	int				len;

	len = stack_len(*head);
	if (!*head || !head || len == 1)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

// Helper function to create a new node
t_stack_node	*create_node(int value)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// Helper function to print list
void	print_list(t_stack_node *head)
{
	t_stack_node	*current;

	current = head;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack_node *stack = NULL;

	// Create a simple list: 1 -> 2 -> 3
	stack = create_node(1);
	stack->next = create_node(2);
	stack->next->prev = stack;
	stack->next->next = create_node(3);
	stack->next->next->prev = stack->next;

	printf("Original list: ");
	print_list(stack);

	swap(&stack);

	printf("After swap: ");
	print_list(stack);

	return (0);
}