/*
** mult_matrice.c for 102chiffrement in /home/david_h/rendu/102chiffrement
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Fri Nov 21 14:12:10 2014 david_h
** Last update Fri Dec  5 10:23:36 2014 david_h
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/crypt.h"

int     **mult_matrice(int **key, int **msg, char *str, int c_msg)
{
  int   **res;
  int   l_key = 2;
  int   c_key = 2;
  int   l_msg = 2;
  int   i;
  int   k;
  int   j;

  res = createTable(10 * my_strlen(str), (my_strlen(str) * 10));
  i = 0;
  j = 0;
  k = 0;
  while (i <= c_msg)
    {
      j = 0;
      while (j < l_msg)
        {
          res[i][j] = 0;
          k = 0;
          while (k < l_msg)
            {
              res[i][j] += key[k][i] * msg[k][j];
              k += 1;
            }
	  //          printf("%d |", res[i][j]);
          j += 1;
	}
      i += 1;
    }
  return (res);
}

int	**mult_decrypt(int **key, int **msg, int c_msg)
{
  int	**res;
  int	i;
  int	j;
  int	k;

  i = 0;
  res = createTable(c_msg * 2, c_msg * 2);
  while (i < c_msg)
    {
      j = 0;
      while (j < 2)
	{
	  k = 0;
	  res[i][j] = 0;
	  while (k < 2)
	    {
	      res[i][j] += key[k][j] * msg[k][i];
	      k = k + 1;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (res);
}
