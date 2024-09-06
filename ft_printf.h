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
	int	dot;
	int	zero;
	int	hash;
	int	plus;
}t_data;

t_data *data(void);

//-----	HELPER FUNCTIONS	-----//
int		spaceflag(char **str, va_list argptr);
int		verif(char **c, int nums);

//-----	FTS	-----//
int		put_b_nbr(unsigned long long nbr, char *b, size_t bs);
void	ft_pointer(va_list argptr);
void	ft_char(va_list argptr);
void	ft_str(va_list argptr, char m, int max);
void	ft_int(va_list argptr);
int		f_uns(va_list argptr, char *s, char c);

//----------ACTION-------------//
void	minusaction(char **c, va_list argptr);
int		zeroaction(char **c, int ret, va_list argptr);
int		pointaction(char **c, int ret, va_list argptr, int maxtudo);
char	*spaceaction(int mfw, char *arg, char k, int max);

//-----	FUNCTIONS	-----//
int		ft_printf(const char *c, ...);

char	**ft_split(char const *s, char c, int index_split);
void	token_loop(char *s, va_list argptr);
int		is_specifier(char c, va_list argptr);

//-----	UTILS	-----//
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t len);
void	*ft_memset(char *dest, int c, size_t len);
size_t	ft_strlen(char *str);

//--//
char	*ft_itoa(long long n, int bs, char *b);