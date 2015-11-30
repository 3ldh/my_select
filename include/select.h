/*
** select.h for my_select in /home/sauvau_m/rendu/PSU_2015_my_select
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Nov 30 13:59:35 2015 Mathieu Sauvau
** Last update Mon Nov 30 15:57:37 2015 Mathieu Sauvau
*/

#ifndef SELECT_H_

#define SELECT_H_

typedef enum {FALSE, TRUE} bool;

#include <curses.h>
#include <signal.h>
#include <stdlib.h>

typedef struct	s_elem
{
  char 		*data;
  bool		selected;
  bool		current;
  struct s_elem	*next;
  struct s_elem	*prev;
  
}	       	t_elem;

typedef struct	s_list
{
  int		size;
  t_elem	*first;
  t_elem	*last;
}		t_list;

t_list		*init_list(void);
int		add(t_list *, char *);
void		show_list(t_list);
void		add_end(t_list *list, char *data);
void		add_start(t_list *list, char *data);
void		clear_list(t_list *);
char		*pop_end(t_list *list);
char		*pop_start(t_list *list);
#endif	/* !SELECT_H_ */
