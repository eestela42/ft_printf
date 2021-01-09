#include "ft_printf.h"

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