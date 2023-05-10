/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:37:59 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/21 10:37:59 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ll;

	i = 0;
	ll = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (j < ll)
			{
				if (big[i + j] != little[j] || len == (i + j))
					break ;
				j++;
			}
			if (j == ll)
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}

/*int main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char * empty = (char*)"";
	printf("1%s\n", ft_strnstr(haystack, needle, 0)); // == 0)
	printf("2%s\n", ft_strnstr(haystack, needle, -1)); //== haystack + 1)
	printf("3%s\n", ft_strnstr(haystack, "a", -1)); // == haystack)
	printf("4%s\n", ft_strnstr(haystack, "c", -1)); //== haystack + 4)
	printf("5%s\n", ft_strnstr(empty, "", -1)); //== empty)
	printf("6%s\n", ft_strnstr(empty, "", 0)); //== empty)
	printf("7%s\n", ft_strnstr(empty, "coucou", -1)); // == 0)
	printf("8%s\n", ft_strnstr(haystack, "aaabc", 5)); // == haystack)
	printf("9%s\n", ft_strnstr(empty, "12345", 5)); // == 0)
	printf("10%s\n", ft_strnstr(haystack, "abcd", 9)); // == haystack + 5)
	printf("11%s\n", ft_strnstr(haystack, "cd", 8)); // == NULL)
	printf("12%s\n", ft_strnstr(haystack, "a", 1)); // == haystack)
	printf("13%s\n", ft_strnstr("1", "a", 1)); // == NULL)
	printf("14%s\n", ft_strnstr("22", "b", 2)); // == NULL)
	return (0);
}*/