/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:35:51 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 15:19:08 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hexa_len(t_info *info, unsigned long long n)
{
	int		len;

	len = 0;
	if (n == 0 && info->period > -1 && !(info->precision))
		return (0);
	else if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_puthexa(unsigned long long n, char type)
{
	char	c;

	if (n >= 16)
	{
		ft_puthexa((n / 16), type);
		if ((n % 16) >= 10 && (type == 'x' || type == 'p'))
			c = 'a' + (n % 16) - 10;
		else if ((n % 16) >= 10 && type == 'X')
			c = 'A' + (n % 16) - 10;
		else
			c = '0' + (n % 16);
		write(1, &c, 1);
	}
	else
	{
		if ((n % 16) >= 10 && (type == 'x' || type == 'p'))
			c = 'a' + (n % 16) - 10;
		else if ((n % 16) >= 10 && type == 'X')
			c = 'A' + (n % 16) - 10;
		else
			c = '0' + (n % 16);
		write(1, &c, 1);
	}
}
