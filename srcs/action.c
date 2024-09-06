/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:30:32 by gcatarin          #+#    #+#             */
/*   Updated: 2023/04/01 15:27:28 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	minusaction(char **c)
{
	int	nums = 0;

	//nums = numcond(*c);
	if (nums != 0)
	{
		if (verif(c, nums))
		{
			//tmfw = compare(c, argptr);
			//ret = tmfw + numaction(ret, nums - tmfw);
		}
	}
	//else
		//data()->ret += compare(c, argptr);
}


int	zeroaction(char **c, int ret)
{
	int		nums = 0;
	int		i;
	char	*arg;

	arg = NULL;
	(*c)++;
	//	nums = numcond(*c);
	if (nums != 0)
	{
		if (verif(c, nums))
		{
			//arg = precompare(c, argptr);
			i = ft_strlen(arg);
			if (i != 0)
				arg = spaceaction((nums - i), arg, '0', 1000);
		}
		return (ret + (write(1, arg, ft_strlen(arg))));
	}
	return (ret);
}

int	pointaction(char **c, int ret, int maxtudo)
{
	int		nums = 0;
	char	*arg;
	int		i;

	arg = NULL;
	(*c)++;
//nums = numcond(*c);
	if (nums != 0)
	{
		if (verif(c, nums))
		{
			//arg = precompare(c, argptr);
			i = ft_strlen(arg);
			if (maxtudo > 0)
				arg = spaceaction((maxtudo - i), arg, ' ', nums);
			else if (nums > i)
				arg = spaceaction(0, arg, ' ', 1000);
			else
				arg = spaceaction((nums - i), arg, ' ', nums);
		}
		return (ret + (write(1, arg, ft_strlen(arg))));
	}
	return (ret);
}

char	*spaceaction(int mfw, char *arg, char k, int max)
{
	int			i;
	static char	s[100];

	s[0] = 0;
	i = 0;
	if (!ft_strlen(arg))
		i = mfw;
	if (*arg == '-' && ft_strlen(arg) > 1)
	{
		arg++;
		s[i++] = '-';
		mfw = mfw + 1;
	}
	while (i < mfw)
		s[i++] = k;
	while (*arg && max-- > 0)
		s[i++] = *arg++;
	s[i] = 0;
	return (s);
}
