/*
** push_swap_utility.c for push swap in /home/sauvau_m/rendu/CPE_2015_Pushswap
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Thu Nov  5 09:15:08 2015 Mathieu Sauvau
** Last update Mon Nov 30 18:43:34 2015 Mathieu Sauvau
*/

#include "select.h"

t_list		*init_list()
{
  t_list	*list;

  if((list = malloc(sizeof(t_list))) == NULL)
     return (NULL);
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
  return (list);
}

void		add_end(t_list *list, char *data)
{
  t_elem	*n_elem;

  if ((n_elem = malloc(sizeof(t_elem))) == NULL)
    exit (1);
  list->size++;
  n_elem->data = data;
  n_elem->selected = FALSE;
  n_elem->current = FALSE;
  n_elem->prev = list->last;
  n_elem->next = list->first;
  if (list->last)
    list->last->next = n_elem;
  else
    list->first = n_elem;
  list->last = n_elem;
}

void		add_start(t_list *list, char *data)
{
  t_elem	*n_elem;

  if ((n_elem = malloc(sizeof(t_elem))) == NULL)
    exit (1);
  list->size++;
  n_elem->data = data;
  n_elem->selected = FALSE;
  n_elem->current = FALSE;
  n_elem->line = 0;
  n_elem->pos = 0;
  n_elem->next = list->first;
  n_elem->prev = list->last;
  if (list->first)
    list->first->prev = n_elem;
  else
    list->last = n_elem;
  list->first = n_elem;
}

char		*pop_end(t_list *list)
{
  char		*data;
  t_elem	*tmp;

  tmp = list->last;
  if (!tmp)
    return (NULL);
  list->size--;
  data = tmp->data;
  list->last = tmp->prev;
  list->first->prev = list->last;
  if (list->last)
    list->last->next = list->first;
  else
    list->first = NULL;
  free(tmp);
  return (data);
}

char		*pop_start(t_list *list)
{
  char		*data;
  t_elem	*tmp;

  tmp = list->first;
  if (!tmp)
    return (NULL);
  list->size--;
  data = tmp->data;
  list->first = tmp->next;
  list->last->next = list->first;
  if (list->first)
    list->first->prev = list->last;
  else
    list->last = NULL;
  free(tmp);
  return (data);
}
