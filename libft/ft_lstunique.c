
#include "libft.h"

int	ft_lstunique(t_list **list)
{
	t_list	*lst;

	lst = *list;
	while (lst)
	{
		if (ft_lstcontains(list, lst))
			return (0);
		lst = lst->next;
	}
	return (1);
} 