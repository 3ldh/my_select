/*
** my_select.c for my_select in /home/sauvau_m/rendu/PSU_2015_my_select
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Nov 30 09:54:00 2015 Mathieu Sauvau
** Last update Mon Nov 30 19:18:46 2015 Mathieu Sauvau
*/

#include "select.h"

void		do_resize(t_list *list)
{

}

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

void		display(t_list *list)
{
  t_elem	*elem;
  int		i;
  int		col;
  int		row;
  int		x;
  int		y;
  int		n;
  int		col_width;

  col_width = get_best_col_size(*list);
  n = 0;
  x = 0;
  y = 0;
  getmaxyx(stdscr, row, col);
  i = -1;
  elem = list->first;
  clear();
  echo();
  while (++i < list->size)
    {
      if (elem->current == TRUE)
	attron(A_UNDERLINE);
      if (elem->selected == TRUE)
	attron(A_REVERSE);
      elem->pos = x;
      elem->line = y;
      mvprintw(y, x, "%s\n", elem->data);
      attroff(A_REVERSE);
      attroff(A_UNDERLINE);
      n++;
      elem = elem->next;
      if (elem && (x = n * col_width) > col - my_strlen(elem->data))
	{
	  y++;
	  x = 0;
	  n = 0;
	}
    }
  refresh();
  noecho();
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

t_elem		*go_down(t_list *list, int col, int line)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      if (elem->pos == col && elem->line == line + 1)
	return (elem);
      elem = elem->next;
    }
  return (NULL);
}

t_elem		*go_up(t_list *list, int col, int line)
{
  t_elem	*elem;
  int		i;

  i = -1;
  elem = list->first;
  while (++i < list->size)
    {
      if (elem->pos == col && elem->line == line - 1)
	return (elem);
      elem = elem->next;
    }
  return (NULL);
}

void		detect_key(t_list *list)
{
  int		ch;
  int		i;
  t_elem	*elem;
  
  raw();  
  i = -1;
  elem = list->first;
  while (42)
    {
      signal(SIGWINCH, do_resize);
      ch = getch();
      if (ch == KEY_DOWN)
	{
	  elem = get_current(list);
	  elem->current = FALSE;
	  elem = go_down(list, elem->pos, elem->line);
	  elem->current = TRUE;
	  display(list);	  
	}
      if (ch == KEY_UP)
	{
	  elem = get_current(list);
	  elem->current = FALSE;
	  elem = go_up(list, elem->pos, elem->line);
	  elem->current = TRUE;
	  display(list);
	}
      if (ch == KEY_RIGHT)
	{
	  elem = get_current(list);
	  elem->current = FALSE;
	  if (elem->next)
	    elem->next->current = TRUE;
	  else
	    list->first->current = TRUE;
	  display(list);
	}
      if (ch == KEY_LEFT)
	{
	  elem = get_current(list);
	  elem->current = FALSE;
	  elem->prev->current = TRUE;
	  display(list);
	}

      if (ch == ' ')
	{
	  elem = get_current(list);
	  elem->selected = (elem->selected == TRUE) ?
	    (elem->selected = FALSE) : (elem->selected = TRUE);
	  display(list);
	}
      if (ch == 'q' || ch == '\n')
	{
	  endwin();
	  break ;
	}
    }
}

int		main(int ac, char **av)
{
  t_list	*list;
  int		ch;
  int		row;
  int		col;
  int		i;

  i = 0;
  list = init_list();
  if (ac < 2)
    return (1);
  while (++i < ac)
    add_start(list, av[i]);
  list->first->current = TRUE;
  initscr();
  keypad(stdscr, TRUE);
  display(list);
  noecho();
  detect_key(list);
  getmaxyx(stdscr, row, col);
  return (0);
}
