/*
** my_printf.c for my_printf in /home/david_h/rendu/PSU_2014_my_printf
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Nov 16 12:21:30 2014 david_h
** Last update Sun Nov 16 18:13:29 2014 david_h
*/

#include        <stdlib.h>
#include        <stdarg.h>
#include        "../include/my.h"

typedef int	(*flag)(va_list);

int	chk_fl(char *fmt, char *flag_t, flag *func_t, int i, va_list ap)
{
  int	j;

  j = 0;
  while ((fmt[i] != flag_t[j]) && (flag_t[j] != '\0'))
    j++;
  if (flag_t[j] == '\0')
    {
      my_putchar('%');
      my_putchar(fmt[i]);
    }
  else
    func_t[j](ap);
  return (i);
}

char	*tabfct(char *tab)
{
  if ((tab = malloc(sizeof(char) * 11)) == NULL)
    return (0);

  tab[0] = 'd';
  tab[1] = 's';
  tab[2] = 'c';
  tab[3] = 'i';
  tab[4] = 'o';
  tab[5] = 'b';
  tab[6] = 'x';
  tab[7] = 'X';
  tab[8] = 'S';
  tab[9] = 'u';
  tab[10] = 'p';
  return (tab);
}

flag	*tab_func(flag *tab_func)
{
  tab_func = malloc(sizeof(flag) * 11);

  tab_func[0] = m_pt_num;
  tab_func[1] = m_pt_str;
  tab_func[2] = m_pt_putchar;
  tab_func[3] = m_pt_num;
  tab_func[4] = m_pt_octal;
  tab_func[5] = m_pt_bin;
  tab_func[6] = m_ptunexa_min;
  tab_func[7] = m_pt_unexa_up;
  tab_func[8] = m_pt_stroctal;
  tab_func[9] = m_pt_dec;
  tab_func[10] = m_pt_point;
  return (tab_func);
}

void		my_printf(char *fmt, ...)
{
  va_list	ap;
  flag		*func_tab;
  char		*flag_tab;
  int		i;

  va_start(ap, fmt);
  func_tab = tab_func(func_tab);
  flag_tab = tabfct(flag_tab);
  i = 0;
  while (fmt[i])
    {
      if (fmt[i] == '%')
	{
	  i++;
	  if (fmt[i] == '%')
	    my_putchar('%');
	  else
	    chk_fl(fmt, flag_tab, func_tab, i, ap);
        }
      else
	my_putchar(fmt[i]);
      i++;
    }
}
