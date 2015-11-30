/*
** select_utility.c for my_select in /home/sauvau_m/rendu/PSU_2015_my_select
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Nov 30 21:00:08 2015 Mathieu Sauvau
** Last update Mon Nov 30 21:01:21 2015 Mathieu Sauvau
*/

#include "select.h"

int		get_best_col_size(t_list list)
{
  int		size;
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list.first;
  size = my_strlen(elem->data);
  while (++i < list.size)
    {
      if (size < my_strlen(elem->data))
	size = my_strlen(elem->data);
      elem = elem->next;
    }
  return (size + 5);
}

t_elem		*get_current(t_list *list)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      if (elem->current == TRUE)
	return (elem);
      elem = elem->next;
    }
  return (NULL);
}
