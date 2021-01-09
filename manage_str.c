#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i++);
}

void	manage_str(t_tool *tool, va_list ap)
{
	char	*str;
	int		size;

	str = va_arg(ap, char *);
	if (str == NULL || str == 0)
		str = "(null)";
	size = ft_strlen(str);
	if (tool->if_preci && tool->preci < size)
		size = tool->preci;
	if (!tool->minus)
		put_width(tool, tool->width - size, ' ');
	str_to_buff(tool, str, size);
	if (tool->minus)
		put_width(tool, tool->width - size, ' ');
	tool->secu = 0;
}
	
	