/*
** my.h for my.h in /home/david_h/rendu/jour9Piscine_C_J09
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Thu Oct  9 11:09:05 2014 David Sullivan
** Last update Sun Nov 16 18:08:19 2014 david_h
*/

#ifndef MY_H_
#define MY_H_

#include        <stdarg.h>

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_sdtrcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
int     m_pt_str(va_list list);
int     m_pt_putchar(va_list list);
int     m_pt_num(va_list list);
int     m_pt_stroctal(va_list list);
int     m_ptunexa_min(va_list list);
int     m_pt_unexa_up(va_list list);
int     m_pt_bin(va_list list);
int     m_pt_octal(va_list list);
int     m_pt_dec(va_list list);
int     m_pt_point(va_list list);
void	my_printf(char *format, ...);

#endif
