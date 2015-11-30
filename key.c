/*
** key.c for select in /home/sauvau_m/rendu/PSU_2015_my_select
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Nov 30 19:29:54 2015 Mathieu Sauvau
** Last update Mon Nov 30 22:38:40 2015 Mathieu Sauvau
*/

#include "select.h"

void	key_down_up(t_list *list, t_elem *elem, t_utility *util)
{
  if (util->ch == KEY_DOWN)
    {
      elem = get_current(list);
      elem->current = FALSE;
      elem = go_down(list, util, elem->pos, elem->line);
      elem->current = TRUE;
      display(list, util);	  
    }
  else if (util->ch == KEY_UP)
    {
      elem = get_current(list);
      elem->current = FALSE;
      elem = go_up(list, util, elem->pos, elem->line);
      elem->current = TRUE;
      display(list, util);
    }
}

void	key_left_right(t_list *list, t_elem *elem, t_utility *util)
{
  if (util->ch == KEY_RIGHT)
    {
      elem = get_current(list);
      elem->current = FALSE;
      if (elem->next)
	elem->next->current = TRUE;
      else
	list->first->current = TRUE;
      display(list, util);
    }
  if (util->ch == KEY_LEFT)
    {
      elem = get_current(list);
      elem->current = FALSE;
      elem->prev->current = TRUE;
      display(list, util);
    }
}

void	key_select(t_list *list, t_elem *elem, t_utility *util)
{
  if (util->ch == ' ')
    {
      elem = get_current(list);
      elem->selected = (elem->selected == TRUE) ?
	(elem->selected = FALSE) : (elem->selected = TRUE);
      display(list, util);
    }
}
