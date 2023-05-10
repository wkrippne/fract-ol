/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:13:22 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/21 21:13:22 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (0);
	ft_memmove(join, s1, len1);
	ft_memmove(join + len1, s2, len2);
	join[len1 + len2] = '\0';
	return (join);
}
