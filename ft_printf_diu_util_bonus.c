/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:32:28 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 15:34:03 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_di_putnbr(t_info *info, long arg_int)
{
	int	count;

	count = get_nbrlen(arg_int);
	if (arg_int < 0)
	{
		count--;
	}
	while (info->precision > count)
	{
		write(1, "0", 1);
		count++;
	}
	if (arg_int == 0 && info->period > -1)
	{
		if (!info->precision && info->width)
			write(1, " ", 1);
		else if (info->precision)
			write(1, "0", 1);
		else
			count--;
	}
	else
		ft_putnbr(arg_int);
	return (count);
}

int	print_di_putstr(t_info *info, long arg_int)
{
	int	count;

	count = 0;
	if (info->plus > -1 && arg_int > -1 && info->type != 'u')
	{
		write(1, "+", 1);
		count++;
	}
	else if (info->space > -1 && arg_int > -1 && info->type != 'u')
	{
		write(1, " ", 1);
		count++;
	}
	count += print_di_putnbr(info, arg_int);
	return (count);
}

int	print_di_putspace(t_info *info, long arg_int)
{
	int	count;
	int	arg_size;

	count = 1;
	arg_size = get_nbrlen(arg_int);
	if (info->precision >= arg_size)
	{
		arg_size = info->precision;
		if (arg_int < 0)
			arg_size++;
	}
	if ((arg_int > 0) && (info->space > -1 || info->plus > -1))
		arg_size++;
	if (info->zero > -1 && (info->minus > -1 || info->period > -1))
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

int	print_di_putzero(t_info *info, long arg_int)
{
	int	count;
	int	arg_size;

	count = 0;
	arg_size = get_nbrlen(arg_int);
	if (info->precision > arg_size)
		arg_size = info->precision;
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

int	print_di_putminus(long arg_int)
{
	int	count;

	count = 0;
	if (arg_int < 0)
	{
		write(1, "-", 1);
		count++;
	}
	return (count);
}
