/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:02:09 by wkrippne          #+#    #+#             */
/*   Updated: 2023/01/01 23:02:09 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*c;

	c = (t_list *)malloc(sizeof(t_list));
	if (!c)
		return (c = 0);
	c->content = content;
	c->next = NULL;
	return (c);
}
