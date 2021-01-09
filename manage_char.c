#include "ft_printf.h"

/*void	manage_str(t_tool *tool, va_list ap)
{
	char	*str;
	int		size;
	int		spaces;
	int		i;

	str = va_arg(ap, char *);
	spaces = 0;
	size = 0;
	while (str[++size]);
	if (tool->if_preci && tool->preci < size)
		size = tool->preci;
	if (tool->if_width && tool->width > size)
		spaces = tool->width - size;
	i = 0;
	if (!tool->minus)
		put_width(tool, spaces, ' ');
	str_to_buff(tool, str, size);
	if (tool->minus)
		put_width(tool, spaces, ' ');
	tool->secu = 0;
}
*/
void	manage_char(t_tool *tool, va_list ap)
{
	char	c;

	c = (char) va_arg(ap, int);
	if (!tool->minus)
		put_width(tool, tool->width - 1, ' ');
	char_to_buff(tool, c);
	if (tool->minus)
		put_width(tool, tool->width - 1, ' ');
	tool->secu = 0;
}

void	manage_per(t_tool *tool, va_list ap)
{
	char	space;

	(void)ap;
	space = ' ';
	if (tool->zero && !tool->minus)
		space = '0';
	
	if (!tool->minus)
		put_width(tool, tool->width - 1, space);
	char_to_buff(tool, '%');
	if (tool->minus)
		put_width(tool, tool->width - 1, space);
	tool->secu = 0;
}