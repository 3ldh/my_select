/*
** my_select.c for my_select in /home/sauvau_m/rendu/PSU_2015_my_select
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Nov 30 09:54:00 2015 Mathieu Sauvau
** Last update Wed Dec  9 15:19:38 2015 Mathieu Sauvau
*/

#include "select.h"

void		real_display(t_elem *elem, t_utility *util)
{
  if (elem->current == TRUE)
    attron(A_UNDERLINE);
  if (elem->selected == TRUE)
    attron(A_REVERSE);
  elem->col = util->x;
  elem->line = util->y;
  mvprintw(util->y, util->x, "%s\n", elem->data);
  attroff(A_REVERSE | A_UNDERLINE);
}

void		calc_display_pos(t_utility *util)
{
  getmaxyx(stdscr, util->row_max, util->col_max);
  if (util->y >= util->row_max - 1)
    {
      util->y = 0;
      util->x += util->col_width + 2;
    }
  else
    util->y++;
  if (util->x > util->col_max - util->col_width)
    {
      clear();
      endwin();
      exit(-1);
    }
}

void		display(t_list *list, t_utility *util)
{
  t_elem	*elem;
  int		i;

  util->x = 0;
  util->y = 0;
  i = -1;
  elem = list->first;
  clear();
  echo();
  while (++i < list->size)
    {
      real_display(elem, util);
      elem = elem->next;
      calc_display_pos( util);
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

int		main(int ac, char **av, char **ae)
{
  char		*term;
  SCREEN	*screen;
  t_list	*list;
  t_utility	util;
  int		i;

  if (ac < 2)
    return (1);
  term = get_term(ae);
  screen = newterm(term, stderr, stdin);
  set_term(screen);
  i = 0;
  curs_set(0);
  set_escdelay(0);
  list = init_list();
  while (++i < ac)
    add_end(list, av[i]);
  list->first->current = TRUE;
  util = get_util(list);
  util.ch = 0;
  keypad(stdscr, TRUE);
  detect_key(list, &util);
  if (util.ch == '\n')
    show_list(list);
    free(term);
   free_all(list);
  return (0);
}
