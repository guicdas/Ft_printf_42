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

	i = ft_printf("%s", "");
	printf("return ->%d\n--------------------\n", i);
	i = printf("%s", "");
	printf("return ->%d\n", i);
}

// (".%d .mk %cei%+ . %%\n", 10, 'p');
// (%sotokens %)
// %token%
// ("%.%%");
/*category: c
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 
category: s
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK ==8819== Invalid read of size 1
==8819==    at 0x10F55B: ft_strlen (in /home/virtualgui/Documents/code/ft_printf/printfTester/s_test)
==8819==    by 0x10F2E5: ft_str (in /home/virtualgui/Documents/code/ft_printf/printfTester/s_test)
==8819==    by 0x10EC61: is_specifier (in /home/virtualgui/Documents/code/ft_printf/printfTester/s_test)
==8819==    by 0x10EF32: token (in /home/virtualgui/Documents/code/ft_printf/printfTester/s_test)
==8819==    by 0x10EF85: token_loop (in /home/virtualgui/Documents/code/ft_printf/printfTester/s_test)
==8819==    by 0x10EB26: ft_printf (in /home/virtualgui/Documents/code/ft_printf/printfTester/s_test)
==8819==    by 0x10E7AA: void print<long>(char const*, long) (print.hpp:66)
==8819==    by 0x10CE64: main (s_test.cpp:37)
==8819==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==8819== 
10.SIGSEGV 
category: p
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.KO 
category: d
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 18.OK 19.OK 20.OK 21.OK 22.OK 23.OK 24.OK 25.OK 26.OK 27.OK 28.OK 29.OK 
category: i
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 18.OK 19.OK 20.OK 21.OK 22.OK 23.OK 24.OK 25.OK 26.OK 27.OK 28.OK 29.OK 
category: u
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 18.OK 19.OK 20.OK 21.OK 22.OK 23.OK 24.OK 25.OK 26.OK 27.OK 28.OK 29.OK 
category: x
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 18.OK 19.OK 20.OK 21.OK 22.OK 23.OK 24.OK 25.OK 26.OK 27.OK 28.OK 29.OK 30.OK 31.OK 
category: X
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 18.OK 19.OK 20.OK 21.OK 22.OK 23.OK 24.OK 25.OK 26.OK 27.OK 28.OK 29.OK 30.OK 31.OK 
category: %
1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 
category: mix
1.OK */