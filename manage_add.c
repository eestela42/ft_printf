#include "ft_printf.h"

int		size_add(uintptr_t num, t_tool *tool)
{
	int		i;

	i = 0;
	if (!num && tool->if_preci && !tool->preci)
		return(0);
	else if (!num)
		return(1);
	while (num)
	{
		num /= 16;
		i++;
	}
	return(i);
}

char	*add_to_str(t_tool *tool, char *tab, uintptr_t num, int size)
{
	char	*hexa;
	int		i;

	if (!(hexa = malloc(sizeof(char) * (size + 1))))
	{
		tool->secu = -1;
		return(NULL);
	}
	i = size - 1;
	if (!num)
		hexa[0] = '0';
	while (num)
	{
		hexa[i--] = tab[num % 16];
		num /= 16;
	}
	return(hexa);
}

void		add_width(t_tool *tool, int size)
	{
		if (tool->preci > size)
			tool->width += -(tool->preci + 2);
		else
			tool->width += -(size + 2);
	}

void	manage_add(t_tool *tool, va_list ap)
{
	char			*tab;
	uintptr_t		num;
	int				size;
	char			space;

	space = ' ';
	if (tool->zero && !tool->minus && (!tool->if_preci || tool->preci < 0))
		space = '0';
	tab = "0123456789abcdef";
	num = va_arg(ap, uintptr_t);
	size = size_add(num, tool);
	tab = add_to_str(tool, tab, num, size);
	if (!tab)
	{
		tool->secu = -1;
		return ;
	}
	add_width(tool, size);
	if (!tool->minus && space != '0')
		put_width(tool, tool->width, space);
	str_to_buff(tool, "0x", 2);
	if (!tool->minus && space == '0')
		put_width(tool, tool->width, space);
	put_preci(tool, size);
	str_to_buff(tool, tab, size);
	if (tool->minus)
		put_width(tool, tool->width, space);
	free(tab);
	tool->secu = 0;
}