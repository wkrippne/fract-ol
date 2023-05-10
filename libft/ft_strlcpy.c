/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:55:55 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/19 20:55:55 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sl;

	i = 0;
	sl = 0;
	while (src[sl])
		sl++;
	if (!size)
		return (sl);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (size < sl)
		dst[size - 1] = '\0';
	else if (size != 0)
		dst[i] = '\0';
	return (sl);
}

/*int main()
{
	char src[] = "coucou";
	char dest[10];
	ft_memset(dest, 'A', 10);
	printf("42:%zu\n", ft_strlcpy(dest, src, 0));
	printf("42:%zu\n", ft_strlcpy(dest, src, 1));
	printf("42:%zu\n", ft_strlcpy(dest, src, 2));
	printf("42:%zu\n", ft_strlcpy(dest, src, -1));

	printf("42:%zu\n", ft_strlcpy(dest, src, 6));

	printf("42:%zu\n", ft_strlcpy(dest, src, 7));
	printf("42:%zu\n", ft_strlcpy(dest, src, 8));
	printf("42:%zu\n", ft_strlcpy(dest, "", 42));
	printf("42:%zu\n", ft_strlcpy(dest, "1", 0));
}
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
	check(ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A'); 
	check(ft_strlcpy(dest, src, 1) == strlen(src)
	 && dest[0] == 0 && dest[1] == 'A'); 
	check(ft_strlcpy(dest, src, 2) == strlen(src) 
	&& dest[0] == 'c' && dest[1] == 0  && dest[2] == 'A'); 
	check(ft_strlcpy(dest, src, -1) == strlen(src) 
	&& !strcmp(src, dest) && dest[strlen(src) + 1] == 'A');
	check(ft_strlcpy(dest, src, 6) == strlen(src) 
	&& !memcmp(src, dest, 5) && dest[5] == 0);
	check(ft_strlcpy(dest, src, 7) == strlen(src) && !memcmp(src, dest, 7));
	check(ft_strlcpy(dest, src, 8) == strlen(src) && !memcmp(src, dest, 7)); 
	check(ft_strlcpy(dest, "", 42) == 0 && !memcmp("", dest, 1)); 
	check(ft_strlcpy(dest, "1", 0) == 1 && dest[0] == 0);*/