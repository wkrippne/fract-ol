/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:09:21 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/20 17:09:21 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	p = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			p = (char *)(s + i);
		i++;
	}
	if ((char)c == '\0')
		p = (char *)(s + i);
	return (p);
}

/*int main(void)
{
	char s[] = "tripouille";
	printf("1: %s\n", ft_strrchr(s, 't'));
	printf("1: %s\n", strrchr(s, 't'));
	printf("2: %s\n", ft_strrchr(s, 'l'));
	printf("2: %s\n", strrchr(s, 'l'));
	printf("4: %s\n", ft_strrchr(s, 'z'));
	printf("4: %s\n", strrchr(s, 'z'));
	printf("5: %s\n", ft_strrchr(s, 0));
	printf("5: %s\n", strrchr(s, 0));
	printf("6: %s\n", ft_strrchr(s, 't' + 256));
	printf("6: %s\n", strrchr(s, 't' + 256));
	return (0);
}*/