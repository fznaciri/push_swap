#include "../include/stack.h"

void	rotate_ra(t_stack **a)
{
	int		t;
	int		c;
	t_stack	*tmp;
	t_stack	*p;
	t_stack	*new;

	if (stack_count(*a) > 1)
	{
		tmp = *a;
		while (tmp)
		{
			if (!tmp->next)
			{
				t = tmp->value;
				c = tmp->chunk;
				p->next = NULL;
				free(tmp);
				break ;
			}
			p = tmp;
			tmp = tmp->next;
		}
		push(a, t, c);
	}
}

void	rotate_rb(t_stack **a)
{
	int		t;
	int		c;
	t_stack	*tmp;
	t_stack	*p;
	t_stack	*new;

	if (stack_count(*a) > 1)
	{
		tmp = *a;
		while (tmp)
		{
			if (!tmp->next)
			{
				t = tmp->value;
				c = tmp->chunk;
				p->next = NULL;
				free(tmp);
				break ;
			}
			p = tmp;
			tmp = tmp->next;
		}
		push(a, t, c);
	}
}

void	rotate_rab(t_stack **a, t_stack **b)
{
	rotate_ra(a);
	rotate_rb(b);
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);
}

void	swap(t_stack **s)
{
	int	t1;
	int	t2;
	int	c1;
	int	c2;

	if (stack_count(*s) > 1)
	{
		c1 = (*s)->chunk;
		t1 = pop(s);
		c2 = (*s)->chunk;
		t2 = pop(s);
		push(s, t1, c1);
		push(s, t2, c2);
	}
}
