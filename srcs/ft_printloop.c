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

t_data *data(void){
	static t_data d;

	return (&d);
}

static char	*line_treat(char *str, char *new, size_t *index)
{
	size_t	i;
	size_t	j;

	i = (str[0] == '%');
	//i += (i && (str[1] == '%'));
	if (i)
	{
		j = *index;
		new[j++] = '\2';
		//if (i == 2)
		//	new[j++] = str[1];
		index[0] = j;
	}
	return (str + i);
}

static char	*line_dup(char *str, char *new)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str = line_treat(str, new, &i);
		new[i++] = *str;
		str++;
	}
	return (new);
}

static int	is_token(char c)
{
	if (c == '-') //Left-justify within the given field width;
		data()->minus = 1;
	else if (c == ' ')
		data()->space = 1;
	else if (c == '.')
		data()->dot = 1;
	else if (c == '0')
		data()->zero = 1;
	else if (c == '#')
		data()->hash = 1;
	else if (c == '+')
		data()->plus = 1;
	else
		return (0);
	return (1);
}

static void	token(char *s, va_list argptr)
{
	size_t	i;

	i = 0;
	printf("\nTOKEN ->%s\n", s);
	while (s[i] && is_token(s[i]))
	{
		//printf("found token.\n");
		i++;
	}
	if (is_specifier(s[i], argptr))
	{
		//printf("\nfound specifier.\n");
		i++;
	}
	else
		data()->ret += write(1, s, ft_strlen(s));
	if (i < ft_strlen(s))
	{
		while (s[i])
			data()->ret += write(1, &s[i++], 1);
	}
}

void	token_loop(char *s, va_list argptr)
{
	char	**tokens;
	char	*dup_array;
	size_t	i;

	dup_array = line_dup(s, ft_calloc(2, ft_strlen(s)));
	tokens = ft_split(dup_array, '\2', 0);
	i = -1;
	while (tokens[++i])
		token(tokens[i], argptr);
}
