/*
** init_term.c for my_select in /home/sauvau_m/rendu/PSU_2015_my_select
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Dec  7 18:53:23 2015 Mathieu Sauvau
** Last update Wed Dec  9 14:54:54 2015 Mathieu Sauvau
*/

#include "select.h"

char		*get_term(char **ae)
{
  int		n;
  int		i;
  int		j;
  char		*term;

  if ((term = malloc(100)) == NULL)
    return (NULL);
  n = 0;
  while (ae[n])
    {
      if (my_strncmp(ae[n], "TERM=", 5) == 0)
	{
	  i = 5;
	  j = 0;
	  while (ae[n][i])
	    term[j++] = ae[n][i++];
	  term[j] = '\0';
	  return (term);
	}
      n++;
    }
  return (NULL);
}

void		free_all(t_list *list)
{
  clear_list(list);
  free(list);
}
