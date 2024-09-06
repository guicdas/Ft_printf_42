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

int	ft_printf(const char *s, ...)
{
	va_list	argptr;

	va_start(argptr, s);
	token_loop((char *)s, argptr);
	va_end(argptr);

	return (data()->ret);
}

int main(void)
{
	int	i;

	i = ft_printf("%d %c .%d+2. \n", 10, 'p', 15);
	printf("return ->%d\n", i);
	i = printf("%d %c .%d+2. \n", 10, 'p', 15);
	printf("return ->%d\n", 25);
}

// i = ft_printf(".%d.%%. .%s+2. \n");
// i = ft_printf("%.%");
// (%sotokens %)
