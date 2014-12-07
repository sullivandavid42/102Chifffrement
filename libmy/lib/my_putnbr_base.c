/*
** my_putnbr_base.c for my_putnbr_base in /home/david_h/rendu/PSU_2014_my_printf/libmy/lib
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Nov 16 13:16:44 2014 david_h
** Last update Sun Nov 16 13:16:49 2014 david_h
*/

#include        "my.h"

void    my_putnbr_base(int nb, char *base)
{
  int   result;
  int   diviseur;
  int   size_base;

  size_base = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % size_base;
      my_putchar(base[result]);
      diviseur = diviseur / size_base;
    }
}
