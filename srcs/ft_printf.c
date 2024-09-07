/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:19:44 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/19 13:54:44 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_data *data(void){
	static t_data d;

	return (&d);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;

	va_start(ap, s);
	token_loop((char *)s, ap);
	va_end(ap);

	return (data()->ret);
}

int main(void)
{
	int	i;

	i = ft_printf("%c %d", 'p', 10);
	printf("return ->%d\n--------------------\n", i);
	i = printf("%c %d", 'p', 10);
	printf("return ->%d\n", i);
}

// (".%d .mk %cei%+ . %%\n", 10, 'p');
// (%sotokens %)
// %token%
// ("%.%%");