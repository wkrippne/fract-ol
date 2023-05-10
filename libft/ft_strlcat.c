/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:33:05 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/20 09:33:05 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	size_t	i;
	size_t	j;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (sl);
	j = dl;
	if (size < dl)
		return (size + sl);
	else
	{
		while (src[i] && (dl + i) < size)
			dst[j++] = src[i++];
		if ((dl + i) == size && dl < size)
			dst[--j] = '\0';
		else
			dst[j] = '\0';
		return (dl + sl);
	}
}

/*int main(void)
{
	char a[] = "abcdefg";
	char b[] = "uvwxyz";
	ft_strlcat(a, b, 5);
	printf("mine: %s\n", a);	
}*/