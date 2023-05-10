/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:21:08 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/21 12:21:08 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] && nptr[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] > 47 && nptr[i] < 58)
		res = res * 10 + nptr[i++] - '0';
	return (sign * res);
}

/*int main()

{
	char	*a = "-1234 5+-";
	int i = ft_atoi(a);
	printf("%i\n", i);
	char	*b = "-1234 5+-";
	int j = atoi(b);
	printf("%i\n", j);
	return (0);
}*/