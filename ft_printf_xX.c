/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:34:48 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 16:03:26 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_xX_putstr(t_info *info, unsigned long long arg_int)
{
	int	count;

	count = get_hexa_len(info, arg_int);
	while (info->precision > count)
	{
		write(1, "0", 1);
		count++;
	}
	if (arg_int == 0 && info->period > -1)
	{
		if (info->precision)
			write(1, "0", 1);
	}
	else
		ft_puthexa(arg_int, info->type);
	return (count);
}

int	print_xX_putzero(t_info *info, long arg_int)
{
	int	count;
	int	arg_size;

	count = 0;
	arg_size = get_hexa_len(info, arg_int);
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

int	print_xX_putspace(t_info *info, long arg_int)
{
	int	count;
	int	arg_size;

	count = 1;
	arg_size = get_hexa_len(info, arg_int);
	if (info->precision > arg_size)
		arg_size = info->precision;
	if (info->hash > -1 || info->type == 'p')
		arg_size = arg_size + 2;
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

int	print_xX_puthash(t_info *info, long arg_int)
{
	int	count;

	count = 0;
	if ((arg_int != 0 && info->hash > -1) || info->type == 'p')
	{
		if (info->type == 'x' || info->type == 'p')
		{
			write(1, "0x", 2);
			count = 2;
		}
		else if (info->type == 'X')
		{
			write(1, "0X", 2);
			count = 2;
		}
	}
	return (count);
}

int	print_xX(t_info *info, va_list ap)
{
	int					tmp_count;
	unsigned long long	arg_int;

	tmp_count = 0;
	if (info->type == 'p')
		arg_int = (unsigned long long)va_arg(ap, void *);
	else
		arg_int = va_arg(ap, unsigned int);
	if (info->minus > -1)
	{
		tmp_count += print_xX_puthash(info, arg_int);
		tmp_count += print_xX_putstr(info, arg_int);
		tmp_count += print_xX_putspace(info, arg_int);
	}
	else
	{
		tmp_count += print_xX_putspace(info, arg_int);
		tmp_count += print_xX_puthash(info, arg_int);
		tmp_count += print_xX_putzero(info, arg_int);
		tmp_count += print_xX_putstr(info, arg_int);
	}
	return (tmp_count);
}
