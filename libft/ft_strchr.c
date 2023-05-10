/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:51:15 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/20 14:51:15 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (0);
}

/*int main(void)
{
	char s[] = "tripouille";
	printf("%s\n", ft_strchr(s, 't'));
	printf("%s\n", ft_strchr(s, 'l') );
	printf("%s\n", ft_strchr(s, 'z'));
	printf("%s\n", ft_strchr(s, 0)) ;
	printf("%s\n", ft_strchr(s, 't' + 256));
	return (0);
}*/