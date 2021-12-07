/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:16:19 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 15:39:41 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_info
{
	char		type;
	int			minus;
	int			zero;
	int			period;
	int			hash;
	int			space;
	int			plus;
	int			width;
	int			precision;
}				t_info;

void	*ft_free(void *ptr);
char	*ft_strchr(const char *str, int c);
void	init_info(t_info *info);
int		info_get_zero(t_info *info, int index);
int		set_info(t_info *info, char *format, int index);

int		print_di_putnbr(t_info *info, long arg_int);
int		print_di_putstr(t_info *info, long arg_int);
int		print_di_putspace(t_info *info, long arg_int);
int		print_di_putzero(t_info *info, long arg_int);
int		print_di_putminus(long arg_int);

int		get_nbrlen(long n);
void	ft_putnbr(long n);
int		print_di(t_info *info, va_list ap);
int		print_u(t_info *info, va_list ap);

int		get_hexa_len(t_info *info, unsigned long long n);
void	ft_puthexa(unsigned long long n, char type);

int		print_xX_putstr(t_info *info, unsigned long long arg_int);
int		print_xX_putzero(t_info *info, long arg_int);
int		print_xX_putspace(t_info *info, long arg_int);
int		print_xX_puthash(t_info *info, long arg_int);
int		print_xX(t_info *info, va_list ap);

int		print_c_putzero(t_info *info);
int		print_c_putspace(t_info *info);
int		print_c(t_info *info, va_list ap);
int		print_percent_put_spacezero(t_info *info);
int		print_percent(t_info *info);

int		print_ft_strlen(t_info *info, const char *str);
int		print_s_putzero(t_info *info, char *arg_char);
int		print_s_putspace(t_info *info, char *arg_char);
int		ft_putstr(char *s, int size);
int		print_s(t_info *info, va_list ap);

int		print_argument(t_info *info, va_list ap);
int		init_parsing(char *format, int *index, va_list ap);
int		parse_format(char *format, va_list ap);
int		ft_printf(const char *format, ...);

#endif
