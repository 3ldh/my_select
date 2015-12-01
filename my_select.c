/*
** my_select.c for my_select in /home/sauvau_m/rendu/PSU_2015_my_select
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Nov 30 09:54:00 2015 Mathieu Sauvau
** Last update Tue Dec  1 12:40:17 2015 Mathieu Sauvau
*/

#include "select.h"

void		real_display(t_list *list, t_elem *elem, t_utility *util)
{
  if (elem->current == TRUE)
    attron(A_UNDERLINE);
  if (elem->selected == TRUE)
    attron(A_REVERSE);
  elem->pos = util->x;
  elem->line = util->y;
  mvprintw(util->y, util->x, "%s\n", elem->data);
  attroff(A_REVERSE | A_UNDERLINE);
}

void		calc_display_pos(t_list *list, t_elem *elem, t_utility *util)
{
  if (list->size > util->row_max)
    {
      if (elem && (util->x = util->n * util->col_width)
	  > util->col_max - my_strlen(elem->data))
	{
	  util->y++;
	  util->x = 0;
	  util->n = 0;
	}
    }
  else
    util->y++;
}

void		display(t_list *list, t_utility *util)
{
  t_elem	*elem;

  util->n = 0;
  util->x = 0;
  util->y = 0;
  util->i = -1;
  elem = list->first;
  clear();
  echo();
  while (++util->i < list->size)
    {
      real_display(list, elem, util);
      util->n++;
      elem = elem->next;
      calc_display_pos(list, elem, util);
    }
  refresh();
  noecho();
}

t_utility	get_util(t_list *list)
{
  t_utility	util;

  getmaxyx(stdscr, util.row_max, util.col_max);
  util.col_width = get_best_col_size(*list);
  return (util);
}

int		main(int ac, char **av)
{
  t_list	*list;
  t_utility	util;
  int		i;

  i = 0;
  initscr();
  curs_set(0);
  list = init_list();
  if (ac < 2)
    return (1);
  while (++i < ac)
    add_start(list, av[i]);
  list->first->current = TRUE;
  util = get_util(list);
  keypad(stdscr, TRUE);
  display(list, &util);
  detect_key(list, &util);
  show_list(list);
  clear_list(list);
  free(list);
  return (0);
}
