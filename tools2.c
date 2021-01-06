#include "ft_printf.h"

void	put_width(t_tool *tool, int spaces, char space)
{
	int	i;

	i = 0;
	while (i++ < spaces)
	{
		tool->buff[tool->buff_i++] = space;
		if (tool->buff_i == BUFFER_SIZE)
			put_buff(tool);
	}
}

void	put_preci(t_tool *tool, int size)
{
	int		number;
	int		i;

	number = tool->preci - size;
	i = 0;
	if (number > 0)
	{
		while (i++ < number)
		{
			tool->buff[tool->buff_i++] = '0';
			if (tool->buff_i == BUFFER_SIZE)
				put_buff(tool);
		}
	}
}

void	str_to_buff(t_tool *tool, char *str, int size)
{
	int	i;

	i = 0;
	while (i < size && str[i])
	{
		tool->buff[tool->buff_i++] = str[i++];
		if (tool->buff_i == BUFFER_SIZE)
			put_buff(tool);
	}
}

void	char_to_buff(t_tool *tool, char c)
{
	tool->buff[tool->buff_i++] = c;
	if (tool->buff_i == BUFFER_SIZE)
		put_buff(tool);
}

int		width_int(int added, int size, int preci, int width)
{
	if (preci > size)
		return(width - (preci + added));
	return(width - (size + added));
}