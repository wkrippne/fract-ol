/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:59:08 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/19 11:59:08 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	d = (char *)dest;
	s = (const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main()
{
	char dest[100];
	const char src[] = "Guten Tag";
	memcpy(dest, src, 5*sizeof(char));
	printf("eins%s\n", dest);
	char dst[100];
	const char sr[] = "Guten Tag";
	ft_memcpy(dst, sr, 5*sizeof(char));
	printf("zwei%s\n", dst);
}*/