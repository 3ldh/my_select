/*
** list_utility2.c for push_swap in /home/sauvau_m/rendu/CPE_2015_Pushswap
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Fri Nov  6 09:42:23 2015 Mathieu Sauvau
** Last update Mon Nov 30 15:57:02 2015 Mathieu Sauvau
*/

#include "select.h"

void		show_list(t_list list)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list.first;
  while (++i < list.size)
    {
      my_putstr(elem->data);
      if (i != list.size - 1)
	my_putchar(' ');
      elem = elem->next;
    }
  my_putchar('\n');
}

void		clear_list(t_list *list)
{
  t_elem	*tmp;
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      tmp = elem;
      elem = elem->next;
      free(tmp);
    }
  list->first = NULL;
  list->last = NULL;
}
