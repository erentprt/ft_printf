/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etepret <etepret@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:55:32 by etepret           #+#    #+#             */
/*   Updated: 2023/08/05 12:57:47 by etepret          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_point(unsigned long a, int sign)
{
	int	ret;
	int	tmp;

	ret = 0;
	if (sign == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		ret += 2;
		sign = 0;
	}
	if (a >= 16)
	{
		tmp = ft_point(a / 16, 0);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
		return (-1);
	return (ret + 1);
}
