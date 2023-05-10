/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:22:11 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/08 17:00:04 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return (c);
	else
		return (0);
}
