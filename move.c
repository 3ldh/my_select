/*
** move.c for select in /home/sauvau_m/rendu/PSU_2015_my_select
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Nov 30 19:31:29 2015 Mathieu Sauvau
** Last update Mon Nov 30 22:44:38 2015 Mathieu Sauvau
*/

#include "select.h"

t_elem		*go_down(t_list *list, t_utility *util, int col, int line)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      if (line + 1 <= util->y)
	{
	  if (elem->pos == col && elem->line == line + 1)
	    return (elem);
	}
      else
	{
	  if (elem->pos == col && elem->line == 0)
	    return (elem);
	}
      elem = elem->next;
    }
  return (NULL);
}

t_elem		*go_up(t_list *list, t_utility *util, int col, int line)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      if (line - 1 >= 0)
	{
	  if (elem->pos == col && elem->line == line - 1)
	    return (elem);
	}
      else
	{
	  if (elem->pos == col && elem->line == util->y)
	    return (elem);
	}
      elem = elem->next;
    }
  return (NULL);
}

void		detect_key(t_list *list, t_utility *util)
{
  int		i;
  t_elem	*elem;
  
  raw();  
  i = -1;
  elem = list->first;
  while (42)
    {
      util->ch = getch();
      key_down_up(list, elem, util);
      key_left_right(list, elem, util);
      key_select(list, elem, util);
      if (util->ch == 'q' || util->ch == '\n')
	{
	  endwin();
	  break ;
	}
    }
}
