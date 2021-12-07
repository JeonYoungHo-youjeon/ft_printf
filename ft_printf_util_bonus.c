/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:29:33 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 13:30:17 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

char	*ft_strchr(const char *str, int c)
{
	char	*ptr_str;
	char	to_find;

	ptr_str = (char *)str;
	to_find = (char)c;
	while (*ptr_str)
	{
		if (*ptr_str == to_find)
			return (ptr_str);
		else
			ptr_str++;
	}
	if (to_find == '\0')
		return (ptr_str);
	return (NULL);
}

void	init_info(t_info *info)
{
	info->hash = -1;
	info->minus = -1;
	info->period = -1;
	info->plus = -1;
	info->space = -1;
	info->type = -1;
	info->zero = -1;
	info->width = 0;
	info->precision = 0;
}

int	info_get_zero(t_info *info, int index)
{
	if (info->period > -1)
		info->precision = info->precision * 10;
	else if (info->width)
		info->width = info->width * 10;
	else
		info->zero = index;
	return (1);
}

int	set_info(t_info *info, char *format, int index)
{
	if (ft_strchr("0", format[index]))
		return (info_get_zero(info, index));
	if (ft_strchr("-.# +", format[index]))
	{
		if (format[index] == '-')
			info->minus = index;
		else if (format[index] == '.')
			info->period = index;
		else if (format[index] == '#')
			info->hash = index;
		else if (format[index] == ' ')
			info->space = index;
		else if (format[index] == '+')
			info->plus = index;
		return (1);
	}
	if (ft_strchr("123456789", format[index]))
	{
		if (info->period > -1)
			info->precision = (info->precision * 10) + (format[index] - '0');
		else
			info->width = (info->width * 10) + (format[index] - '0');
		return (1);
	}
	return (0);
}
