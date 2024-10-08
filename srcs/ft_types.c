/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:48:18 by gcatarin          #+#    #+#             */
/*   Updated: 2022/12/23 20:20:47 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_int(va_list *ap)
{
	long long	t;

	t = va_arg(*ap, int);
	if (t < 0)
	{
		data()->ret += write(1, "-", 1);
		t *= -1;
	}
	else
		manage_tokens();
	if (data()->dot)
		print_precision(count_number_length(t));
	put_b_nbr(t, DEX, 10);
}

void	ft_char(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	data()->ret += write(1, &c, 1);
}

void	ft_str(va_list *ap, char m)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(*ap, char *);
	if (!s)
		data()->ret += write(1, "(null)", 6);
	//data()->ret += write(1, 0, 0);
	if (m == ' ')
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != '-' && i != 0)
			data()->ret += write(1, "+", 1);
	}
	data()->ret += write(1, s, ft_strlen(s));
}

void	ft_pointer(va_list *ap)
{
	unsigned long	s;

	s = va_arg(*ap, unsigned long);
	if (!s)
		data()->ret += write(1, "(nil)", 5);
	data()->ret += write (1, "0x", 2);
	put_b_nbr(s, HEXAL, 16);
}

void	put_b_nbr(unsigned long long nbr, char *b, size_t bs)
{
	if (data()->dot)
		print_precision(count_number_length(nbr));
	if (nbr >= bs)
		put_b_nbr((nbr / bs), b, bs);
	data()->ret += write(1, &b[nbr % bs], 1);
}
