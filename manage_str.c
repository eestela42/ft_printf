/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:12:55 by marvin            #+#    #+#             */
/*   Updated: 2021/01/15 17:12:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i++);
}

void	manage_str(t_tool *tool, va_list ap)
{
	char	*str;
	int		size;
	char	space;

	space = ' ';
	if (tool->zero && !tool->minus)
		space = '0';
	str = va_arg(ap, char *);
	if (str == NULL || str == 0)
		str = "(null)";
	size = ft_strlen_str(str);
	if (tool->if_preci && tool->preci >= 0 && tool->preci < size)
		size = tool->preci;
	if (!tool->minus)
		put_width(tool, tool->width - size, space);
	str_to_buff(tool, str, size);
	if (tool->minus)
		put_width(tool, tool->width - size, space);
	tool->secu = 0;
}
