
#include "push_swap.h"

void	rr(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rev_rotate(list_a);
	rev_rotate(list_b);
	ft_printf("rrr\n");
}

void	ss(t_list **list_a, t_list **list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}