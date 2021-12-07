/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:46:24 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 13:44:58 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_argument(t_info *info, va_list ap)
{
	int	tmp_count;

	tmp_count = 0;
	if (info->type == '%')
		tmp_count = print_percent(info);
	else if (info->type == 'd' || info->type == 'i')
		tmp_count = print_di(info, ap);
	else if (info->type == 'u')
		tmp_count = print_u(info, ap);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		tmp_count = print_xX(info, ap);
	else if (info->type == 'c')
		tmp_count = print_c(info, ap);
	else if (info->type == 's')
		tmp_count = print_s(info, ap);
	return (tmp_count);
}

int	init_parsing(char *format, int *index, va_list ap)
{
	t_info	*info;
	int		tmp_count;

	tmp_count = 0;
	(*index)++;
	info = malloc(sizeof(t_info));
	init_info(info);
	while (ft_strchr("-0.# +123456789", format[*index]))
	{
		set_info(info, format, *index);
		(*index)++;
	}
	if (ft_strchr("cspdiuxX%", format[*index]))
	{
		info->type = format[*index];
		tmp_count += print_argument(info, ap);
	}
	ft_free(info);
	return (tmp_count);
}

int	parse_format(char *format, va_list ap)
{
	int		return_size;
	int		index;
	int		*index_ptr;

	return_size = 0;
	index = 0;
	index_ptr = &index;
	while (format[index])
	{
		if (format[index] == '%')
		{
			return_size += init_parsing(format, index_ptr, ap);
		}
		else
		{
			write(1, &format[index], 1);
			return_size++;
		}
		index++;
	}
	return (return_size);
}

int	ft_printf(const char *format, ...)
{
	int		return_size;
	va_list	ap;

	va_start(ap, format);
	return_size = parse_format((char *)format, ap);
	va_end(ap);
	return (return_size);
}
