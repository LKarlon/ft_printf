/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:07:47 by chermist          #+#    #+#             */
/*   Updated: 2019/02/28 13:21:15 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sup.h"

void	clean_mods(t_mdfrs *m)
{
	int i;

	i = -1;
	while (++i < 7)
		m->flag[i] = '|';
	m->c_num = 0;
	m->modifier = 0;
	m->width = 0;
	m->pr = -1;
	m->spec = 0;
}

int		count_num(long long i)
{
	static int	count = 0;

	count = 0;
	if (i == INT64_MIN)
		return (20);
	if ((i < 0) && (i = -i))
		count++;
	while (i / 10 > 0)
	{
		++count;
		i /= 10;
	}
	return (++count);
}

int		u_count_num(unsigned long long i)
{
	static int	count = 0;

	count = 0;
	while (i / 10 > 0)
	{
		++count;
		i /= 10;
	}
	return (++count);
}

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

double	ft_pow(double d, int pow)
{
	return (pow ? (d * ft_pow(d, pow - 1)) : 1);
}
