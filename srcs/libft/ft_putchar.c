/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:00:30 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/02/28 21:19:48 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sup.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	l_ft_putchar(int c)
{
	int a;

	a = 0;
	if (c <= 127)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c < 2048)
	{
		a = ((c >> 6) | 0xC0);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
		return (2);
	}
	return (more_bytes_putchar(c));
}

int	more_bytes_putchar(int c)
{
	int a;

	a = 0;
	if (c < 65536)
	{
		a = ((c >> 12) | 0xE0);
		write(1, &a, 1);
		a = (((c >> 6) & 63) | 0x80);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
		return (3);
	}
	else if (c < 2097152)
	{
		a = ((c >> 18) | 0xF0);
		write(1, &a, 1);
		a = (((c >> 12) & 63) | 0x80);
		write(1, &a, 1);
		a = (((c >> 6) & 63) | 0x80);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
	}
	return ((c < 2097152) ? 4 : -1);
}

int	ft_putstr(char const *s)
{
	int count;
	int final;

	count = 0;
	final = 0;
	if (!s)
		return (0);
	while (*s)
	{
		count = ft_putchar((int)*s);
		s += count;
		final += count;
	}
	return (final);
}

int	l_ft_putstr(int *s, int i)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	while (*s && i--)
	{
		count += l_ft_putchar(*s);
		s++;
	}
	return (count);
}
