/*
** my_strncmp.c for strncmp in /home/sauvau_m/rendu/Piscine_C_J06/ex_07
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Oct  5 18:05:24 2015 Mathieu Sauvau
** Last update Mon Dec  7 14:20:16 2015 Mathieu Sauvau
*/

#include <stdio.h>
#include "my.h"

int	my_strncmp(const char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n - 1 && s1[i] != '\0')
    {
      if (s2[i] != s1[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}
