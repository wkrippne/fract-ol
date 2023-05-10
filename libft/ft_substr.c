/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:51:42 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/21 20:51:42 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (0);
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*int main(void)
{
	char *str = strdup("0123456789");
	printf("9: %s\n", ft_substr(str, 9, 10));
	return (0);
}*/