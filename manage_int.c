#include "ft_printf.h"

int		how_long(int num)
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
	return(size);
}

char		*ft_itoa_printf(int n)
{
	char			*tab;
	int				len;
	unsigned int	m;

	if (n < 0)
		m = -n;
	else
		m = n;
	len = how_long(m);
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

void	put_int(t_tool *tool, int num, char space)
{
	int			size;
	char		*number;

	size = how_long(num);
	number = ft_itoa_printf(num);
	if (tool->if_preci && !tool->preci && num == 0)
	{
		size = 0;
		number[0] = 0;
	}
	if (!tool->minus)
	{
		if (space == '0')
			put_added(tool, num);
		put_width(tool, tool->width, space);
	}
	if (tool->minus || space != '0')
		put_added(tool, num);
	put_preci(tool, size);
	str_to_buff(tool, number, size);
	free(number);
	if (tool->minus)
		put_width(tool, tool->width, space);
}

void	manage_int(t_tool *tool, va_list ap)
{
	long int	num;
	char		space;
	int			size;
	int			added;

	space = ' ';
	if (tool->zero && !tool->minus && !tool->if_preci)
		space = '0';
	num = va_arg(ap, int);
	size = how_long(num);
	if (tool->if_preci && !tool->preci && num == 0)
		size = 0;
	added = 0;
	if (num < 0 || tool->plus || tool->space)
		added++;
	tool->width = width_int(added, size, tool->preci, tool->width);
	put_int(tool, num, space);
	tool->secu = 0;		
}