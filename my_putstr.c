/*
** my_putstr.c for putstr in /home/sauvau_m/rendu/Piscine_C_J04
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Thu Oct  1 11:28:08 2015 Mathieu Sauvau
** Last update Fri Nov 13 15:58:04 2015 Mathieu Sauvau
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (!str)
    {
      write(2, "String empty\n", 12);
      return (1);
    }
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      i = i + 1;
    }
  return (0);
}
