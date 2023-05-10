/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:09:14 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/21 22:09:14 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*d;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	d = malloc(end - start + 1);
	if (!d)
		return (0);
	ft_strlcpy(d, s1 + start, end - start + 1);
	return (d);
}

/*int main(void)
{
	char	*s1 = "Supercalifragilisticexpialegoric";
	char	*set = "abcdefghijklmnop";
	printf("%s\n", ft_strtrim(s1, set));
}*/