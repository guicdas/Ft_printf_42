/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tratamento.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:16:52 by gcatarin          #+#    #+#             */
/*   Updated: 2023/07/11 18:06:05 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	get_precision(char *s)
{
	while (*s && (*s >= '0' && *s <= '9'))
	{
		data()->precision *= 10;
		data()->precision += *s - 48;
		(*s)++;
	}
	data()->dot = 1;
}

 int	set_token(char *s)
{
	if (*s == '-') //Left-justify within the given field width;
		data()->minus = 1;
	else if (*s == ' ')
		data()->space = 1;
	else if (*s == '.')
		get_precision(++s);
	else if (*s == '0')
		data()->character = '0';
	else if (*s == '#')
		data()->hash = 1;
	else if (*s == '+')
		data()->plus = 1;
	else
		return (0);
	data()->has_flags = 1;
	return (1);
}

 int	is_specifier(char *s, va_list *ap)
{
	if (*s == 'd' || *s == 'i')
		ft_int(ap);
	else if (*s == 's')
		ft_str(ap, 0);
	else if (*s == '%' && data()->has_flags == 0)
		data()->ret += write(1, "%", 1);
	else if (*s == 'p')
		ft_pointer(ap);
	else if (*s == 'c')
		ft_char(ap);
	else if (*s == 'u')
		data()->ret += put_b_nbr(va_arg(*ap, unsigned int), DEX, 10);
	else if (*s == 'x')
		f_uns(ap, HEXAL, 'x');
	else if (*s == 'X')
		f_uns(ap, HEXAU, 'X');
	else
		return (0);
	return (1);
}

static void	token(char **s, va_list *ap)
{
	while (*s && set_token(*s))
		(*s)++;
	if (is_specifier(*s, ap))
		(*s)++;
}

void	token_loop(char *s, va_list *ap)
{
	while (*s)
	{
		if (*s == '%')
			token(&s, ap);
		else
		{
			data()->ret += write(1, s, 1);
			(*s)++;
		}
	}
}