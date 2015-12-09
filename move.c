/*
** move.c for select in /home/sauvau_m/rendu/PSU_2015_my_select
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Nov 30 19:31:29 2015 Mathieu Sauvau
** Last update Wed Dec  9 15:19:05 2015 Mathieu Sauvau
*/

#include "select.h"

t_elem		*find_elem(t_list *list, int col, int line)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      if (elem->col == col && elem->line == line)
	return (elem);
      elem = elem->next;
    }
  return (NULL);
}

t_elem		*go_right(t_list *list, t_utility *util, int col, int line)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      if (elem->line == line && col + util->col_width + 2 <= util->x)
	{
	  if (elem->line == line && elem->col == col + util->col_width + 2)
	    return (elem);
	}
      else
	{
	  if (elem->line == line && elem->col == 0)
	    return (elem);
	}
      elem = elem->next;
    }
  return (find_elem(list, 0, line));
}

t_elem		*go_left(t_list *list, t_utility *util, int col, int line)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      if (col - (util->col_width + 2) >= 0)
	{
	  if (elem->line == line && elem->col == col - (util->col_width + 2))
	    return (elem);
	}
      else
	{
	  if (elem->line == line && elem->col == util->x)
	    return (elem);
	}
      elem = elem->next;
    }
  return (find_elem(list, util->x - (util->col_width + 2), line));
}

void		detect_key(t_list *list, t_utility *util)
{
  t_elem	*elem;

  raw();
  elem = list->first;
  while (util->ch != 27 && util->ch != '\n' && list->size != 0)
    {
      display(list, util);
      util->ch = getch();
      key_down_up(list, elem, util);
      key_left_right(list, elem, util);
      key_select(list, elem, util);
      key_delete(list, elem, util);
    }
  clear();
  endwin();
}
