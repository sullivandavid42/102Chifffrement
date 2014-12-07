/*
** create_matrice.c for 102chiffrement in /home/david_h/rendu/102chiffrement
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Fri Nov 21 14:17:51 2014 david_h
** Last update Fri Dec  5 10:22:13 2014 david_h
*/

#include "./include/crypt.h"

int     **create_key(char *c1, char *c2, char *c3, char *c4)
{
  int   nb_temp;
  int   **key_matrice;

  key_matrice = createTable(2, 2);
  nb_temp = my_getnbr(c1);
  key_matrice[0][0] = nb_temp;
  nb_temp = my_getnbr(c2);
  key_matrice[0][1] = nb_temp;
  nb_temp = my_getnbr(c3);
  key_matrice[1][0] = nb_temp;
  nb_temp = my_getnbr(c4);
  key_matrice[1][1] = nb_temp;
  return (key_matrice);
}

int	**create_rev_key(int **key)
{
  int	**reverse_key;
  
  reverse_key = createTable(2, 2);
  reverse_key[0][0] = key[1][1];
  reverse_key[0][1] = key[0][1] * -1;
  reverse_key[1][0] = key[1][0] * -1;
  reverse_key[1][1] = key[0][0];
  return (reverse_key);
}

int     **createTable(int nbLin, int nbCol)
{
  int   **tableau;
  int   *tableau2;
  int   i;

  tableau = (int **)malloc(sizeof(int*)*nbLin);
  tableau2 = (int *)malloc(sizeof(int)*nbCol*nbLin);
  i = 0;
  while (i < nbLin)
    {
      tableau[i] = &tableau2[i*nbCol];
      i = i + 1;
    }
  return (tableau);
}

int	**create_matr_alpha(char *str, int **dest, int **key)
{
  int   x;
  int   y;
  int   i;

  x = 0;
  y = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
        dest[y][x] = 0;
      else
        dest[y][x] =  (int)str[i] - 96;
      x = x + 1;
      i = i + 1;
      if (y == 0)
        {
          x = x - 1;
          y = 1;
        }
      else
        y = 0;
    }
  if (my_strlen(str) % 2 == 1)
    {
      dest[1][x] = 0;
    }
  return (mult_matrice(dest, key, str, x));
}

int     **create_revmatr_alpha(char *str, int **dest, int **key)
{
  int   x;
  int   y;
  int   i;

  x = 0;
  y = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
        dest[y][x] = 0;
      else
        dest[y][x] =  (int)str[i] + 96;
      x = x + 1;
      i = i + 1;
      if (y == 0)
        {
          x = x - 1;
          y = 1;
        }
      else
        y = 0;
    }
  if (my_strlen(str) % 2 == 1)
    {
      dest[1][x] = 0;
    }
  return (mult_matrice(dest, key, str, x));
}
