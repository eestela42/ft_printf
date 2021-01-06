#include "ft_printf.h"

void		skip(t_tool *tool, va_list ap)
{
	(void)ap;
	tool->secu = -1;
}

void	plus(t_tool *tool, va_list ap)
{
	(void)ap;
    tool->plus = 1;
}

void	minus(t_tool *tool, va_list ap)
{
	(void)ap;
    tool->minus = 1;
}

void	zero(t_tool *tool, va_list ap)
{
	(void)ap;
    tool->zero = 1;
}

void	asterisk(t_tool *tool, va_list ap)
{
	int	i;

	if (tool->if_width)
	{
		tool->secu = -1;
		return;
	}
	i = va_arg(ap, int);
	if (i < 0)
	{
		tool->minus = 1;
		tool->if_width = 1;
		tool->width = -i;
	}
	else if (i == 0)
		tool->zero = 1;
	else
	{
		tool->if_width = 1;
		tool->width = i;
	}
}