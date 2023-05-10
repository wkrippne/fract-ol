/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:36:05 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/19 16:36:05 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (src == dest || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	s = (const char *)src;
	d = (char *)dest;
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (dest);
	}
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*int main()
{
	const char a[] = "geeks";
	char b[100];
	memmove(b, a, 5*sizeof(char));
	printf("Min%s\n", b);
	const char c[] = "geeks";
	char d[100];
	ft_memmove(d, c, 5*sizeof(char));
	printf("std%s\n", d);
}*/