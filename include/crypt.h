/*
** crypt.h for 102chiffrement in /home/david_h/rendu/102chiffrement/include
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Fri Nov 21 15:24:30 2014 david_h
** Last update Wed Nov 26 16:42:54 2014 carle_s
*/

#ifndef _CRYPT_H
#define _CRYPT_H

#include <stdio.h>
#include <stdlib.h>

int	**create_key(char *c1, char *c2, char *c3, char *c4);
int	**create_rev_key(int **key);
int	**createTable(int nbLin, int  nbCol);
int     **create_matr_alpha(char *str, int **dest, int **key);
int	**mult_matrice(int **key, int **msg, char *str, int c_msg);
int	**mult_decrypt(int **key, int **msg, int c_msg);
void	my_putnbr_base(int nbr, char *base);
void	aff_base_res(int **key, char *base, int c_msg);
int    crypt(char *msg, char *nb1, char *nb2, char *nb3, char *nb4, char *base, char *flag);

#endif /* _CRYPT_H_ */
