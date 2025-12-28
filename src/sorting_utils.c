
#include "push_swap.h"

int	ascending(t_list *list)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		if (lst->next != NULL && lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	descending(t_list *list)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		if (lst->next != NULL && lst->content < lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}