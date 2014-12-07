/*
** main.c for main in /home/david_h/labo/102chiffremenet
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Wed Nov 19 23:53:48 2014 david_h
** Last update Sun Dec  7 13:10:46 2014 carle_s
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/crypt.h"

int	is_char_in(int c, char *base)
{
  while (base != NULL && base[0] != '\0')
    {
      if (c == base[0])
	return (1);
      base = base + 1;
    }
  return (0);
}

int	test_decrypt(char *src, char *base)
{
  while (src != NULL && src[0] != '\0')
    {
      if (src[0] != ' ' && is_char_in(src[0], base) == 0)
	return (0);
      src = src + 1;
    }
  return (1);
}

int	main(int argc, char **argv)
{
  if (argc != 8 || (argv[7][0] != '0' && argv[7][0] != '1'))
    {
      my_printf("Dechiffrement Usage : \"MES_TO_CRYPT\" KEY \"BASE\" 0 \n\n");
      my_printf("Dechiffrement Usage : \"MES_TO_CRYPT\" KEY \"BASE\" 1 \n\n");
      return (0);
    }
  if (argv[7][0] == '0')
    {
      printf("Chiffrement de \"%s\" avec la clef %s %s %s %s en base \"%s\"\n\n : ", 
		argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
      crypt(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
    }
  else
    {
      printf("Déchiffrement de \"%s\" avec la clef %s %s %s %s en base \"%s\"\n\n : ",
	     argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
      if (test_decrypt(argv[1], argv[6]) != 1)
	return (printf("Un ou plusieurs caractere de la source ne sont pas present dans la base.\n"));
      decrypt(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
    }  
  return (0);
}
