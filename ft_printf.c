/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:13:20 by marvin            #+#    #+#             */
/*   Updated: 2021/01/15 17:13:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *form, ...)
{
	va_list		ap;
	t_tool		*tool;
	void		(*tab[128])(t_tool *tool, va_list ap);
	int			r;

	if (!(tool = (struct s_tool *)malloc(sizeof(t_tool))))
		return (0);
	init_tool(tool, form);
	init_tab(tab);
	va_start(ap, form);
	while (form[tool->pos] && tool->secu > 0)
	{
		if (form[tool->pos] == '%')
			tag(tab, tool, ap);
		else if (tool->buff_i < BUFFER_SIZE)
			tool->buff[tool->buff_i++] = form[tool->pos++];
		else
			put_buff(tool);
	}
	put_buff(tool);
	r = tool->r;
	free(tool);
	return (r);
}
