/*
** select.h for my_select in /home/sauvau_m/rendu/PSU_2015_my_select
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Nov 30 13:59:35 2015 Mathieu Sauvau
** Last update Wed Dec  9 15:27:50 2015 Mathieu Sauvau
*/

#ifndef SELECT_H_

#define SELECT_H_

//typedef enum {FALSE, TRUE} bool;

# define  KEY_BUFF (10)
# include <curses.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct	s_elem
{
  char 		*data;
  bool		selected;
  bool		current;
  int		col;
  int		line;
  struct s_elem	*next;
  struct s_elem	*prev;

}	       	t_elem;

typedef struct	s_list
{
  int		size;
  t_elem	*first;
  t_elem	*last;
}		t_list;

typedef struct	s_utility
{
  char		*term;
  SCREEN	*screen;
  int		col_max;
  int		row_max;
  int		col_width;
  int		ch;
  int		x;
  int		y;
}		t_utility;

t_list		*init_list(void);
int		add(t_list *, char *);
int		get_best_col_size(t_list list);
int		my_strlen(char *);
void		show_list(t_list *);
void		add_end(t_list *list, char *data);
void		add_start(t_list *list, char *data);
void		clear_list(t_list *);
char		*pop_end(t_list *list);
char		*pop_start(t_list *list);
char		*pop_middle(t_list *list, t_elem *elem);
t_elem		*go_left(t_list *list, t_utility *util, int col, int line);
t_elem		*go_right(t_list *list, t_utility *util, int col, int line);
t_elem		*get_current(t_list *list);
void		add_start(t_list *list, char *data);
void		add_end(t_list *list, char *data);
void		my_putchar(char c);
void		my_putstr(char *);
void		display(t_list *list, t_utility *util);
void		key_down_up(t_list *list, t_elem *elem, t_utility *);
void		calc_display_pos(t_utility *util);
void		real_display(t_elem *elem, t_utility *util);
void		key_left_right(t_list *list, t_elem *elem, t_utility *);
void		key_select(t_list *list, t_elem *elem, t_utility *);
void		key_delete(t_list *list, t_elem *elem, t_utility *util);
void		detect_key(t_list *list, t_utility *util);
t_utility	get_util(t_list *list);
int		my_strncmp(const char *s1, char *s2, int n);
void		change_term(t_utility *util, char *term);
char		*get_term(char **ae);
void		free_all(t_list *list, char *term);

#endif	/* !SELECT_H_ */
