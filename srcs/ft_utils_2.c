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

int	count_number_length(long long num)
{
	int counter = 0;
	while (num)
	{
		num /= 10;
		counter++;
			printf("num: %lld\n", num);
	}
	printf("counter: %d\n", counter);
	return (counter);
}

void	print_precision(int num)
{
	while (data()->precision - num > 0)
	{
		if (data()->space)
			data()->ret += write(1, " ", 1);
		else
			data()->ret += write(1, "0", 1);
	}
}

void	manage_tokens(void)
{
	if (data()->plus)
		data()->ret += write(1, "+", 1);
	if (data()->space && !data()->plus)
		data()->ret += write(1, " ", 1);
}
