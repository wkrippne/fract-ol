/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:31:24 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/21 15:31:24 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	if (!nmemb || !size)
	{
		size = 1;
		nmemb = 1;
	}
	a = malloc(nmemb * size);
	if (!a)
		return (0);
	ft_memset(a, 0, nmemb * size);
	return (a);
}

/*int main()
{
    size_t nmemb = 5;
    size_t size = 0;
    void *ptr = calloc(nmemb, size);
    if (!ptr)
    {
        printf("Test 1 failed: Returned NULL\n");
    }
    else
    {
        unsigned char reference[1];
        ft_memset(reference, 0, 1);
        if (ft_memcmp(ptr, reference, 1) != 0)
        {
            printf("Test 1 failed: Memory not zeroed\n");
        }
        else
        {
            printf("Test 1 passed\n");
        }
        free(ptr);
    }
}*/