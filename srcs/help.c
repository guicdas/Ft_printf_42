/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:17:48 by gcatarin          #+#    #+#             */
/*   Updated: 2023/01/07 23:18:35 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	verif(char **c, int nums)
{
	int	i;

	i = nums;
	while (nums > 0)
	{
		nums = nums / 10;
		(*c)++;
	}
	if (nums == -1)
	{
		(*c)++;
		i = 0;
	}
	return (i);
}

int	is_specifier(char c, va_list argptr)
{
	if (c == 'd' || c == 'i')
		ft_int(argptr);
	else if (c == 's')
		ft_str(argptr, 0, -2);
	else if (c == '%')
		data()->ret += write(1, "%", 1);
	else if (c == 'p')
		ft_pointer(argptr);
	else if (c == 'c')
		ft_char(argptr);
	else if (c == 'u')
		data()->ret += put_b_nbr(va_arg(argptr, unsigned int), DEX, 10);
	else if (c == 'x')
		data()->ret += put_b_nbr(va_arg(argptr, unsigned int), HEXAL, 16);
	else if (c == 'X')
		data()->ret += put_b_nbr(va_arg(argptr, unsigned int), HEXAU, 16);
	else
		return (0);
	return (1);
}

/*if (data()->hash && **str == 'x')
		return (fun(argptr, HEXAL, **str));
	if (**str == 'X')
		return (fun(argptr, HEXAU, **str));*/