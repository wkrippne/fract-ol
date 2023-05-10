/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:28:17 by wkrippne          #+#    #+#             */
/*   Updated: 2023/01/02 19:28:17 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;
	t_list	*tmp;

	a = *lst;
	if (!lst || !del)
		return ;
	while (a)
	{
		tmp = a->next;
		ft_lstdelone(a, del);
		a = tmp;
	}
	*lst = NULL;
}
