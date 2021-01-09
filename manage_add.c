#include "ft_printf.h"

int		size_add(uintptr_t num)
{
	int		i;

	i = 0;
	if (num == 0)
		return(3);
	while (num)
	{
		num /= 16;
		i++;
	}
	return(i + 2);
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
	hexa[0] = '0';
	hexa[1] = 'x';
	if (num == 0)
		hexa[2] = '0';
	while (num)
	{
		hexa[i--] = tab[num % 16];
		num /= 16;
	}
	return(hexa);
}

void	manage_add(t_tool *tool, va_list ap)
{
	char			*tab;
	uintptr_t		num;
	int				size;

	tab = "0123456789abcdef";
	num = va_arg(ap, uintptr_t);
	size = size_add(num);
	tab = add_to_str(tool, tab, num, size);
	if (!tab)
	{
		tool->secu = -1;
		return ;
	}
	tool->width = tool->width - size;
	if (!tool->minus)
		put_width(tool, tool->width, ' ');
	str_to_buff(tool, tab, size);
	if (tool->minus)
		put_width(tool, tool->width, ' ');
	free(tab);
	tool->secu = 0;
}