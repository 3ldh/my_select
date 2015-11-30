/*
** my.h for my in /home/dhiver_b/work/projects/Bistromathique/Piscine_C_bistromathique/lib/my
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Fri Oct 23 10:55:37 2015 Bastien DHIVER
** Last update Fri Nov 13 15:13:57 2015 Mathieu Sauvau
*/

#ifndef MY_H_
# define MY_H_
# include <stdarg.h>

const char	*get_fct(const char *, va_list, int, int *);
int		my_putchar(char c);
int		my_strncmp(const char *, char *, int);
int		my_strlen(char *);
int		my_getnbr(const char *);
unsigned	nb_digits(unsigned);
int		my_putstr(char *);
long		my_put_nbr(long long);
int		my_put_float(double, unsigned int);
unsigned	my_put_nbr_ui(unsigned int);
void		my_putnbr_base2(unsigned int, char *, int *);
void		my_putnbr_base(unsigned int, char *);
void		my_putnbr_base_o(unsigned long, char *);
void		my_putnbr_base_x(unsigned long, char *);
void		my_putnbr_base_X(unsigned long, char *);
void		my_putnbr_base_b(unsigned long, char *);
void		my_putnbr_base_p(unsigned long, char *);
void		my_putnbr_base_l(unsigned long, char *);
void		my_putnbr_base_l2(unsigned long, char *, int *);

#endif /* !MY_H_ */
