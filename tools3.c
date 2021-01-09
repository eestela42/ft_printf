#include "ft_printf.h"

void	put_added(t_tool *tool, int num)
{
	if (num < 0)
		char_to_buff(tool, '-');
	else if (tool->plus && num >= 0)
		char_to_buff(tool, '+');
	else if (tool->space)
		char_to_buff(tool, ' ');
}