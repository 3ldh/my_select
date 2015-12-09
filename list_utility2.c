/*
** list_utility2.c for push_swap in /home/sauvau_m/rendu/CPE_2015_Pushswap
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov  6 09:42:23 2015 Mathieu Sauvau
** Last update Tue Dec  8 18:02:23 2015 Mathieu Sauvau
*/

#include "select.h"

int		get_nb_selected(t_list *list)
{
  t_elem	*elem;
  int		i;
  int		n;

  i = -1;
  n = 0;
  elem = list->first;
  while (++i < list->size)
    {
      if (elem->selected == TRUE)
	n++;
      elem = elem->next;
    }
  return (n);
}

void		show_list(t_list *list)
{
  t_elem	*elem;
  int		i;
  int		nb_selected;

  i = -1;
  nb_selected = get_nb_selected(list);
  elem = list->first;
  while (++i < list->size)
    {
      if (elem->selected == TRUE)
	{
	  my_putstr(elem->data);
	  nb_selected--;
	  if (nb_selected != 0)
	    my_putchar(' ');
	}
      elem = elem->next;
    }
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

t_list		*init_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
     return (NULL);
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
  return (list);
}
