/*
** get_next_line.h for get_next_line.h in /home/girard_z/get_next_line
** 
** Made by benjamin girard
** Login   <girard_z@epitech.net>
** 
** Started on  Tue Mar  1 14:07:44 2016 benjamin girard
** Last update Sat Apr  9 03:58:47 2016 benjamin girard
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (128)
#endif /* !READ_SIZE */

#include <stdlib.h>
#include <unistd.h>

typedef struct		s_struct
{
  int			mult;
  char			*reader;
  char			*tmp;
  int			read_return;
  int			i;
}			t_struct;

char			*get_next_line(const int);
int			set_up(t_struct *);

#endif /* !GET_NEXT_LINE_H_ */
