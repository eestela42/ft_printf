#include "ft_printf.h"

int		hexa_size(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return(1);
	while (num)
	{
		num /= 16;
		i++;
	}
	return(i);
}

char	*reversed_hexa(unsigned int num, char *tab, int size, t_tool *tool)
{
	char	*hexa;

	if (!(hexa = malloc(sizeof(char) * (size + 1))))
	{
		return(NULL);
		tool->secu = -1;
	}
	hexa[size] = 0;;
	while (num)
	{
		hexa[--size] = tab[num % 16];
		num /= 16;
	}
	return(hexa);
}

void	manage_hex(t_tool *tool, va_list ap)
{
	char			*tab;
	unsigned int	num;
	char			space;

	tab = "0123456789abcdef";
	if (tool->form[tool->pos] == 'X')
		tab = "0123456789ABCDEF";
	num = va_arg(ap, unsigned int);
	space = ' ';
	if (tool->zero && !tool->if_preci)
		space = '0';
	tool->width = width_int(0, hexa_size(num), tool->preci, tool->width);
	if (!tool->minus)
		put_width(tool, tool->width, space);
	if (tool->if_preci)
		put_preci(tool, hexa_size(num));
	tab = reversed_hexa(num, tab, hexa_size(num), tool);
	if (num == 0)
		char_to_buff(tool, '0');
	else if (tab && tool->secu != -1)
		str_to_buff(tool, tab, 100);
	if (tab && tool->secu != -1)
		free(tab);
	if (tool->minus)
		put_width(tool, tool->width, space);
	tool->secu--;
}