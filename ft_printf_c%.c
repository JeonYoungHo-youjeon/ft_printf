/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c%.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:33:33 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 13:42:38 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent_put_spacezero(t_info *info)
{
	int	count;

	count = 1;
	if (info->zero > -1 && !(info->minus > -1))
	{
		while (info->width > count++)
		{
			write(1, "0", 1);
		}
	}
	else
	{
		while (info->width > count++)
			write(1, " ", 1);
	}
	return (count - 1);
}

int	print_percent(t_info *info)
{
	int	tmp_count;

	tmp_count = 0;
	if (info->minus > -1)
	{
		write(1, "%", 1);
		tmp_count += print_percent_put_spacezero(info);
	}
	else
	{
		tmp_count += print_percent_put_spacezero(info);
		write(1, "%", 1);
	}
	return (tmp_count);
}

int	print_c_putzero(t_info *info)
{
	int	count;
	int	arg_size;

	count = 0;
	arg_size = 1;
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

int	print_c_putspace(t_info *info)
{
	int	count;
	int	arg_size;

	count = 1;
	arg_size = 1;
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

int	print_c(t_info *info, va_list ap)
{
	int				tmp_count;
	unsigned char	arg_char;

	tmp_count = 0;
	arg_char = (unsigned char)va_arg(ap, int);
	if (info->minus > -1)
	{
		write(1, &arg_char, 1);
		tmp_count += print_c_putspace(info);
	}
	else
	{
		tmp_count += print_c_putspace(info);
		tmp_count += print_c_putzero(info);
		write(1, &arg_char, 1);
	}
	tmp_count++;
	return (tmp_count);
}
