#include "../include/stack.h"

void	sswap(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	push_a(t_stack **a, t_stack **b, int chunk)
{
	int	t;

	if (stack_count(*b) >= 1)
	{
		t = pop(b);
		push(a, t, chunk);
	}
}

void	push_b(t_stack **a, t_stack **b, int chunk)
{
	int	t;

	if (*a)
	{
		t = pop(a);
		push(b, t, chunk);
	}
}

void	rotate_a(t_stack **a)
{
	int		t;
	int		c;
	t_stack	*tmp;
	t_stack	*new;

	if (stack_count(*a) > 1)
	{
		c = (*a)->chunk;
		t = pop(a);
		tmp = *a;
		while (tmp)
		{
			if (!tmp->next)
			{
				new = malloc(sizeof(t_stack));
				new->value = t;
				new->chunk = c;
				new->next = NULL;
				tmp->next = new;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

void	rotate_b(t_stack **a)
{
	int		t;
	int		c;
	t_stack	*tmp;
	t_stack	*new;

	if (stack_count(*a) > 1)
	{
		c = (*a)->chunk;
		t = pop(a);
		tmp = *a;
		while (tmp)
		{
			if (!tmp->next)
			{
				new = malloc(sizeof(t_stack));
				new->value = t;
				new->chunk = c;
				new->next = NULL;
				tmp->next = new;
				break ;
			}
			tmp = tmp->next;
		}
	}
}
