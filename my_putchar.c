/*
** my_putchar.c for my_putchar in /home/sauvau_m/rendu
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Wed Sep 30 11:23:30 2015 Mathieu Sauvau
** Last update Fri Nov 13 15:35:25 2015 Mathieu Sauvau
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
