/*
** decrypt.c for 102chiffrement in /home/david_h/rendu/102chiffrement
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Nov 23 21:11:18 2014 david_h
** Last update Thu Nov 27 11:49:02 2014 carle_s
*/

#include "include/crypt.h"

void	aff_decrypt(int **matr, int c_msg)
{
  int	i;

  i = 0;
  while (i < c_msg * 2 + 2 * (c_msg % 2 == 0))
    {
      my_putnbr_base(matr[i / 2][i % 2], " abcdefghijklmnopqrstuvwxyz");
      i = i + 1;
    }
}

int	get_base(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i] != c && base[i] != 0)
    {
      i = i + 1;
    }
  if (base[i] != '\0')
    return (i);
  return (-1);
}

int	my_get_nbr_base(char *nbr, char *base, int *n)
{
  int	i;

  i = 0;
  *n = 0;
  while (get_base(nbr[i], base) == -1  && nbr[i] != '\0')
    i = i + 1;
  if (nbr[i] == '\0')
    {
      *n = -1;
      return (0);
    }
  while (get_base(nbr[i], base) != -1 && nbr[i] != '\0')
    {
      *n = *n * my_strlen(base) + get_base(nbr[i], base);
      i = i + 1;
    }
  return (i);
}

int	**get_msg_matr(char *msg, char *base, int **rev_key, int *c_msg)
{
  int	**matr;
  int	n;
  int	i;
  int	ad;

  matr = createTable(2, my_strlen(msg));
  n = 0;
  i = 0;
  ad = 0;
  while (n != -1)
    {
      ad = ad + my_get_nbr_base(msg + ad, base, &n);
      matr[i % 2][i / 2] = n;
      i = i + 1;
    }
  *c_msg = i / 2;
  return (mult_decrypt(rev_key, matr, i / 2));
}

int	decrypt(char *msg, char *nb1, char *nb2, char *nb3, char * nb4, char *base, char *flag)
{
  int	**key;
  int	**rev_key;
  int	**res;
  int	c_msg;

  key = create_key(nb1, nb2, nb3, nb4);
  rev_key = create_rev_key(key);
  res = get_msg_matr(msg, base, rev_key, &c_msg);
  aff_decrypt(res, c_msg);
  return (0);
}
