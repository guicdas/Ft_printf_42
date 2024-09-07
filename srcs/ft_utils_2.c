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

int	put_b_nbr(unsigned long long nbr, char *b, size_t bs)
{
	int	i;

	i = 0;
	if (nbr >= bs)
		i = put_b_nbr((nbr / bs), b, bs);
	return (i + write(1, &b[nbr % bs], 1));
}
