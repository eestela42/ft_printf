/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:13:01 by marvin            #+#    #+#             */
/*   Updated: 2021/01/15 17:13:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			how_long_uns(unsigned int num)
{
	int	size;

	size = 0;
	if (!num)
		size = 1;
	while (num)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa_printf_uns(unsigned int m, int len)
{
	char			*tab;

	if (!(tab = malloc((len + 1) * sizeof(char))))
		return (NULL);
	tab[len] = 0;
	tab[0] = '0';
	while (--len >= 0)
	{
		tab[len] = (m % 10) + '0';
		m = m / 10;
	}
	return (tab);
}

void		put_uns(t_tool *tool, unsigned int num, char space, int size)
{
	char		*number;

	number = ft_itoa_printf_uns(num, size);
	if (tool->if_preci && !tool->preci && num == 0)
	{
		size = 0;
		number[0] = 0;
	}
	if (!tool->minus)
	{
		if (space == '0' && tool->plus)
			char_to_buff(tool, '+');
		else if (space == '0' && tool->space)
			char_to_buff(tool, ' ');
		put_width(tool, tool->width, space);
	}
	if ((tool->minus || space != '0') && tool->plus)
		char_to_buff(tool, '+');
	else if ((tool->minus || space != '0') && tool->space)
		char_to_buff(tool, ' ');
	put_preci(tool, size);
	str_to_buff(tool, number, size);
	free(number);
	if (tool->minus)
		put_width(tool, tool->width, space);
}

void		manage_uns(t_tool *tool, va_list ap)
{
	unsigned int	num;
	char			space;
	int				size;
	int				added;

	space = ' ';
	if (tool->zero && !tool->minus && (!tool->if_preci || tool->preci < 0))
		space = '0';
	num = va_arg(ap, unsigned int);
	size = how_long_uns(num);
	if (tool->if_preci && !tool->preci && num == 0)
		size = 0;
	added = 0;
	if (tool->plus || tool->space)
		added++;
	tool->width = width_int(added, size, tool->preci, tool->width);
	put_uns(tool, num, space, size);
	tool->secu = 0;
}
