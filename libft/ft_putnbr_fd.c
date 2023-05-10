/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:15:58 by wkrippne          #+#    #+#             */
/*   Updated: 2022/12/28 23:15:58 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			ft_putnbr_fd(n, fd);
		}
		else if (n < 10)
		{
			a = n + '0';
			write(fd, &a, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			a = (n % 10) + '0';
			write(fd, &a, 1);
		}
	}
}
