/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etepret <etepret@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:55:19 by etepret           #+#    #+#             */
/*   Updated: 2023/08/05 12:53:40 by etepret          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	rtn;
	int	tmp;

	rtn = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		rtn += 1;
		n *= -1;
	}
	if (n >= 10)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		rtn += tmp;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (rtn + 1);
}

int	ft_unsigned(unsigned int n)
{
	int	rtn;
	int	tmp;

	rtn = 0;
	if (n >= 10)
	{
		tmp = ft_unsigned(n / 10);
		if (tmp == -1)
			return (-1);
		rtn += tmp;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (rtn + 1);
}

int	ft_hex(unsigned int a, char c)
{
	int	rtn;
	int	tmp;

	rtn = 0;
	if (a >= 16)
	{
		tmp = ft_hex(a / 16, c);
		if (tmp == -1)
			return (-1);
		rtn += tmp;
	}
	if (c == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[a % 16], 1) == -1)
			return (-1);
	}
	else if (c == 'x')
		if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
			return (-1);
	return (rtn + 1);
}
