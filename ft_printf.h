/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etepret <etepret@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:56:10 by etepret           #+#    #+#             */
/*   Updated: 2023/08/05 11:43:54 by etepret          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_point(unsigned long a, int sign);

int	ft_putnbr(int a);
int	ft_hex(unsigned int a, char c);
int	ft_unsigned(unsigned int a);

int	ft_format(va_list *args, char c);
int	ft_printf(const char *str, ...);
int	is_valid_format(const char *str, int i);

#endif
