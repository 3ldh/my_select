/*
** key.c for select in /home/sauvau_m/rendu/PSU_2015_my_select
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Nov 30 19:29:54 2015 Mathieu Sauvau
** Last update Thu Dec 10 10:33:07 2015 Mathieu Sauvau
*/

#include "select.h"

void	key_left_right(t_list *list, t_elem *elem, t_utility *util)
{
  if (util->ch == KEY_LEFT)
    {
      elem = get_current(list);
      elem->current = FALSE;
      elem = go_left(list, util, elem->col, elem->line);
      elem->current = TRUE;
    }
  else if (util->ch == KEY_RIGHT)
    {
      elem = get_current(list);
      elem->current = FALSE;
      elem = go_right(list, util, elem->col, elem->line);
      elem->current = TRUE;
    }
}

void	key_down_up(t_list *list, t_elem *elem, t_utility *util)
{
  if (util->ch == KEY_DOWN)
    {
      elem = get_current(list);
      elem->current = FALSE;
      elem->next->current = TRUE;
    }
  if (util->ch == KEY_UP)
    {
      elem = get_current(list);
      elem->current = FALSE;
      if (elem->prev)
	elem->prev->current = TRUE;
      else
	list->last->current = TRUE;
    }
}

void	key_select(t_list *list, t_elem *elem, t_utility *util)
{
  if (util->ch == ' ')
    {
      elem = get_current(list);
      (elem->selected == TRUE) ?
	(elem->selected = FALSE) : (elem->selected = TRUE);
      elem->current = FALSE;
      if (elem->next)
	elem->next->current = TRUE;
      else
	list->first->current = TRUE;
    }
}

void	key_delete(t_list *list, t_elem *elem, t_utility *util)
{
  if (util->ch == KEY_BACKSPACE || util->ch == KEY_DC)
    {
      elem = get_current(list);
      if (elem->next && elem->next != list->first)
	elem->next->current = TRUE;
      else
	elem->prev->current = TRUE;
      pop_middle(list, elem);
    }
}
