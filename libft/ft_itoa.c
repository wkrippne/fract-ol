/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:38:29 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/22 22:38:29 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_estim(long n)
{
	size_t	estim;

	estim = 0;
	if (n < 0)
	{
		estim++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char	*ft_gen(char *rtn, long nbr, int len)
{
	int	isneg;

	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*rtn;
	long	nbr;

	nbr = n;
	len = ft_estim(nbr);
	rtn = 0;
	rtn = ft_gen(rtn, nbr, len);
	if (!rtn)
		return (0);
	return (rtn);
}

/*int main(void)
{
	char *s = ft_itoa(2147483647);
	printf("1: %s\n", s);
	free(s);
	char *str = ft_itoa(-2147483648);
	printf("3: %s\n", str);
	free(s);
	return 0;
}*/