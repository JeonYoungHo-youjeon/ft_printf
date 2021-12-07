/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:36:26 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 15:24:48 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ft_strlen(t_info *info, const char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		str++;
		length++;
	}
	if (info->period > -1 && info->precision == 0)
		length = 0;
	else if (info->precision && length > info->precision)
		length = info->precision;
	return (length);
}

int	print_s_putzero(t_info *info, char *arg_char)
{
	int	count;
	int	arg_size;

	count = 0;
	arg_size = print_ft_strlen(info, arg_char);
	if (info->zero > -1 && !(info->period > -1 || info->minus > -1))
	{
		while (info->width > arg_size++)
		{
			write(1, "0", 1);
			count++;
		}
	}
	return (count);
}

int	print_s_putspace(t_info *info, char *arg_char)
{
	int	count;
	int	arg_size;

	count = 1;
	arg_size = print_ft_strlen(info, arg_char);
	if (info->zero > -1 && info->minus > -1)
	{
		while (info->width > arg_size++ && count++)
			write(1, " ", 1);
	}
	else if (info->zero == -1)
	{
		while (info->width > arg_size++ && count++)
			write(1, " ", 1);
	}
	return (count - 1);
}

int	ft_putstr(char *s, int size)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (size > count)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count - 1);
}

int	print_s(t_info *info, va_list ap)
{
	int		tmp_count;
	char	*arg_char;

	tmp_count = 0;
	arg_char = va_arg(ap, char *);
	if (arg_char == NULL)
		arg_char = "(null)";
	if (info->minus > -1)
	{
		tmp_count += ft_putstr(arg_char, print_ft_strlen(info, arg_char));
		tmp_count += print_s_putspace(info, arg_char);
	}
	else
	{
		tmp_count += print_s_putspace(info, arg_char);
		tmp_count += print_s_putzero(info, arg_char);
		tmp_count += ft_putstr(arg_char, print_ft_strlen(info, arg_char));
	}
	tmp_count++;
	return (tmp_count);
}
