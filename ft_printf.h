/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:11:15 by gcatarin          #+#    #+#             */
/*   Updated: 2023/01/07 23:28:59 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define DEX "0123456789"
# define HEXAL "0123456789abcdef"
# define HEXAU "0123456789ABCDEF"

typedef struct s_data{
	int	ret;

	int	minus;
	int	space;
	int	character;
	int	hash;
	int	plus;
	int	precision;
	int	zero;
	int	dot;

	int	has_flags;
}t_data;

t_data *data(void);

//-----	PRINTF	-----//
int		ft_printf(const char *c, ...);
void	token_loop(char *s, va_list *ap);
void	manage_tokens(void);
int		count_number_length(long long num);
void	print_precision(int num);

//-----	TYPES	-----//
int		put_b_nbr(unsigned long long nbr, char *b, size_t bs);
void	ft_pointer(va_list *ap);
void	ft_char(va_list *ap);
void	ft_str(va_list *ap, char m);
void	ft_int(va_list *ap);
void	f_uns(va_list *ap, char *s, char c);

//-----	UTILS	-----//
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t len);
void	*ft_memset(char *dest, int c, size_t len);
size_t	ft_strlen(char *str);
