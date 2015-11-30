/*
** my_strlen.c for strlen in /home/sauvau_m/rendu/Piscine_C_J04
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Thu Oct  1 13:35:21 2015 Mathieu Sauvau
** Last update Fri Nov 13 16:06:13 2015 Mathieu Sauvau
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (*(str + i) != '\0')
    {
      i = i + 1;
    }
  return (i);
}
