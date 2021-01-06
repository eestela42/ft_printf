#include "ft_printf.h"

int		how_long(int num)
{
	int	size;

	size = 0;
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
	while (--len >= 0)
	{
		tab[len] = (m % 10) + '0';
		m = m / 10;
	}
	return (tab);
}

void	put_int(t_tool *tool, int num, char space, int added)
{
	char		sign;
	int			size;
	char		*number;
	size = how_long(num);
	if (num < 0)
	{
		sign = '-';
		tool->plus = 0;
	}
	number = ft_itoa_printf(num);
	if (tool->space && !tool->plus && ++added)
		char_to_buff(tool, ' ');
	if (!tool->minus)
		put_width(tool, tool->width, space);
	if (num < 0)
		char_to_buff(tool, sign);
	put_preci(tool, size + added);
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
	added = 0;
	if (num < 0 || (tool->plus && num >= 0) || tool->space)
		added++;
	tool->width = width_int(added, size, tool->preci, tool->width);
	put_int(tool, num, space, added);
	tool->secu = 0;		
}

/*int	int_reversed(int num)
{
	int tab[10];
	int	i;
	int	y;
	
	i = 0;
	y = 0;
	if (num < 0)
		num = -num;
	else if (num == 0)
		return(0);
	tab[0] = 0;
	while (num)
	{
		tab[i++] = num % 10;
		num = num / 10;
	}
	while (y < i)
		num = num * 10 + tab[y++];
	return(num);
}

void	int_to_buff(t_tool *tool, int num, int size)
{
	char	str[10];
	int		i;

	i = 0;
	if (tool->plus && num >= 0)
		char_to_buff(tool, '+');
	else if (num < 0)
		char_to_buff(tool, '-');
	put_preci(tool, size);
	num = int_reversed(num);
	while(size)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	str[i] = 0;
	str_to_buff(tool, str, 999);
}
*/