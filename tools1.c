#include "ft_printf.h"

void	init_tool(t_tool *tool, char *form)
{
	tool->form = form;
	tool->pos = 0;
	tool->buff_i = 0;
	tool->secu = 1;
	tool->r = 0;
	tool->if_preci = 0;
	tool->preci = 0;
	tool->if_width = 0;
	tool->width = 0;
	tool->plus = 0;
	tool->minus = 0;
	tool->zero = 0;
}

void	init_tab(void (*tab[128])(t_tool *tool, va_list ap))
{
	int i;

	i = 0;
	while (i <= 128)
		tab[i++] = skip;
	tab['+'] = plus;
	tab['-'] = minus;
	tab['0'] = zero;
	tab['*'] = asterisk;
	tab['.'] = preci;
	tab[' '] = space;
	i = '1';
	while (i <= '9')
		tab[i++] = width;
	tab['c'] = manage_char;
	tab['%'] = manage_per;
	tab['s'] = manage_str;
	tab['d'] = manage_int;
	tab['i'] = manage_int;
	tab['p'] = manage_add;
	tab['x'] = manage_hex;
	tab['X'] = manage_hex;
}

void	put_buff(t_tool *tool)
{
	if (tool->buff_i > 0)
	{
		write(1, tool->buff, tool->buff_i);
		tool->r = tool->r + tool->buff_i;
		tool->buff_i = 0;
	}
}

void	reset_tool(t_tool *tool)
{
	tool->secu = 1;
	tool->if_preci = 0;
	tool->preci = 0;
	tool->if_width = 0;
	tool->width = 0;
	tool->plus = 0;
	tool->minus = 0;
	tool->zero = 0;
}

void	tag(void (*tab[128])(t_tool *tool, va_list ap), t_tool *tool, va_list ap)
{
	//printf("pre pos = %i", tool->pos);
	tool->pos++;
	//printf("post pos = %i", tool->pos);
	while(tool->secu == 1)
	{
		//printf("\nform[] = %c", tool->form[tool->pos]);
		tab[(int)tool->form[tool->pos]](tool, ap);
		tool->pos++;

		//printf("\nsecu = %i\n", tool->secu);
	}
	//printf("\n\nif_preci = %i\npreci = %i\nif_width = %i\nwidth = %i\nplus = %i\nminus = %i\nzero = %i\nspace = %i\nsecu = %i\n", tool->if_preci, tool->preci, tool->if_width, tool->width, tool->plus, tool->minus, tool->zero, tool->space, tool->secu);
	if (tool->secu == 0)
		reset_tool(tool);
}