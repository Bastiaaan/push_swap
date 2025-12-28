
#include "libft.h"

int	ft_lstcontains(t_list **list, t_list *item)
{
	t_list	*lst;

	lst = *list;
	while (lst)
	{
		if (lst->content == item->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}