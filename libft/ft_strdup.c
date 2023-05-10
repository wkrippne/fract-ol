/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:22:37 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/21 16:22:37 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;

	d = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!d)
		return (0);
	d = ft_memcpy(d, s, ft_strlen(s) + 1);
	return (d);
}
