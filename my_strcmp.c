/*
** my_strcmp.c for strcmp in /home/sauvau_m/rendu/Piscine_C_J06/ex_06
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Oct  5 18:02:59 2015 Mathieu Sauvau
** Last update Tue Oct  6 09:57:21 2015 Mathieu Sauvau
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s2[i] != s1[i])
	break;
      i++;
    }
  return (s1[i] - s2[i]);
}
