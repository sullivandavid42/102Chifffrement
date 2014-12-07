/*
** crypt.c for 102chiffrement in /home/david_h/rendu/102chiffrement
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Fri Nov 21 14:23:20 2014 david_h
** Last update Wed Dec  3 19:00:34 2014 carle_s
*/

#include "./include/crypt.h"

void    my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  if (nbr / my_strlen(base) != 0)
    my_putnbr_base(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
}

void    aff_base_res(int **key, char *base, int c_msg)
{
  int   i;

  i = 0;
  while (i < c_msg * 2 + 2 * (c_msg % 2 == 1))
    {
      my_putnbr_base(key[i / 2][i % 2 == 1], base);
      my_putchar(' ');
      i = i + 1;
    }
}

int	crypt(char *msg, char *nb1, char *nb2, char *nb3, char *nb4, char *base, char *flag)
{
  int	**key;
  int	**res;

  key = create_key(nb1, nb2, nb3, nb4);
  res = create_matr_alpha(msg, (createTable(2, my_strlen(msg))), key);
  my_putchar('\n');
  aff_base_res((int**)res, base, my_strlen(msg) /2);
  my_putchar('\n');
  return (0);
}
