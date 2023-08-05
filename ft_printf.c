/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etepret <etepret@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:55:48 by etepret           #+#    #+#             */
/*   Updated: 2023/08/05 12:54:50 by etepret          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (c == 's')
		return (ft_putstr(va_arg((*args), char *)));
	else if (c == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg((*args), int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((*args), unsigned int), c));
	else if (c == '%')
		return (ft_putstr("%"));
	else
		return (0);
}

int	is_valid_format(const char *str, int i)
{
	char	next_char;

	if (str[i] == '%' && str[i + 1] != '\0')
	{
		next_char = str[i + 1];
		if (next_char == 'c' || next_char == 's' 
			|| next_char == 'p' || next_char == 'd' 
			|| next_char == 'i' || next_char == 'u' 
			|| next_char == 'x' || next_char == 'X' 
			|| next_char == '%')
			return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		rtn;
	int		tmp;

	i = 0;
	rtn = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && is_valid_format(str, i))
		{
			tmp = ft_format(&args, str[++i]);
			if (tmp == -1)
				return (-1);
			rtn += tmp - 1;
		}
		else if (ft_putchar(str[i]) == -1)
			return (-1);
		rtn++;
		i++;
	}
	va_end(args);
	return (rtn);
}
