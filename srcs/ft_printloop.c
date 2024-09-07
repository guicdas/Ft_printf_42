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

static int	is_token(char *s)
{
	if (*s == '-') //Left-justify within the given field width;
		data()->minus = 1;
	else if (*s == ' ')
		data()->space = 1;
	else if (*s == '.')
		data()->dot = 1;
	else if (*s == '0')
		data()->zero = 1;
	else if (*s == '#')
		data()->hash = 1;
	else if (*s == '+')
		data()->plus = 1;
	else
		return (0);
	data()->has_flags = 1;
	return (1);
}

static int	is_specifier(char *s, va_list argptr)
{
	if (*s == 'd' || *s == 'i')
		ft_int(argptr);
	else if (*s == 's')
		ft_str(argptr, 0);
	else if (*s == '%' && data()->has_flags == 0)
		data()->ret += write(1, "%", 1);
	else if (*s == 'p')
		ft_pointer(argptr);
	else if (*s == 'c')
		ft_char(argptr);
	else if (*s == 'u')
		data()->ret += put_b_nbr(va_arg(argptr, unsigned int), DEX, 10);
	else if (*s == 'x')
		data()->ret += put_b_nbr(va_arg(argptr, unsigned int), HEXAL, 16);
	else if (*s == 'X')
		data()->ret += put_b_nbr(va_arg(argptr, unsigned int), HEXAU, 16);
	else
		return (0);
	return (1);
}

/*
if (data()->hash && **str == 'x')
		return (fun(argptr, HEXAL, **str));
if (**str == 'X')
	return (fun(argptr, HEXAU, **str));
*/

int	write_string(char **s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i += write(1, &s, 1);
		(*s)++;
	}
	return (i);
}

void	token(char **s, va_list ap)
{
	size_t	i;

	i = 0;
	(*s)++;
	while (*s && is_token(*s))
	{
		i++;
		(*s)++;
	}
	if (is_specifier(*s, ap))
	{
		i++;
		(*s)++;
	}
	
}

void	token_loop(char *s, va_list ap)
{
	while (*s)
	{
		if (*s == '%')
			token(&s, ap);
		else
		{
			data()->ret += write(1, s, 1);
			s++;
		}
	}
}