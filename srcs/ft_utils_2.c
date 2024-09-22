/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:32:06 by gcatarin          #+#    #+#             */
/*   Updated: 2022/12/23 19:58:17 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	f_uns(va_list *ap, char *s, char c)
{
	unsigned long long	t;

	t = va_arg(*ap, unsigned int);
	if (t != 0)
	{
		if (c == 'x')
			data()->ret += write (1, "0x", 2);
		if (c == 'X')
			data()->ret += write (1, "0X", 2);
	}
	data()->ret += put_b_nbr(t, s, 16);
}

int	spaceflag(char **str, va_list *ap)
{
	(void)str;
	(void)ap;
	/*
	int	nums;
	int	i;

	i = 0;
	(*str)++;
	//nums = numcond(*str);
	i = nums;
	if (i == -1)
		nums = 1;
	while (nums > 0)
	{
		nums = nums / 10;
		(*str)++;
	}
	if (**str == 's')
		ftstr(argptr, ' ', i);
	if (**str == 'd' || **str == 'i')
		ftint(argptr, ' ');*/
	return (0);
}
