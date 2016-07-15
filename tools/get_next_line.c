/*
** get_next_line.c for get_next_line in /home/girard_z/get_next_line
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue Mar  1 14:07:08 2016 benjamin girard
** Last update Fri May 27 21:15:39 2016 girard_z
*/

#include "get_next_line.h"

int		my_realloc(t_struct *get, int size)
{
  int		i;
  char		*tmp;

  i = -1;
  if ((tmp = malloc(sizeof(char) * size)) == NULL)
    return (1);
  while (++i < size)
    tmp[i] = '\0';
  i = -1;
  while (get->reader[++i] != '\0')
    tmp[i] = get->reader[i];
  free(get->reader);
  if ((get->reader = malloc(sizeof(char) * size)) == NULL)
    return (1);
  i = -1;
  while (++i < size)
    get->reader[i] = '\0';
  i = -1;
  while (tmp[++i] != '\0')
    get->reader[i] = tmp[i];
  get->reader[i] = '\0';
  free(tmp);
  return (0);
}

int		check_back_n(t_struct *get)
{
  int		i;

  i = 0;
  while (get->reader[i] != '\0')
    {
      if (get->reader[i] == '\n')
	return (i);
      i = i + 1;
    }
  return (-1);
}

int		process(t_struct *get, const int fd)
{
  int		i;

  get->read_return = -2;
  while (check_back_n(get) < 0)
    {
      i = 0;
      while (get->reader[i] != '\0')
	i = i + 1;
      if ((get->read_return = read(fd, &get->reader[i], READ_SIZE))
	  == -1)
	return (1);
      if (check_back_n(get) < 0 && get->read_return == 0)
	return (0);
      get->mult = get->mult + 1;
      if (my_realloc(get, ((READ_SIZE * get->mult) + 1)) == 1)
	return (1);
    }
  return (0);
}

int		put_in_tmp(t_struct *get)
{
  int		i;
  int		r;

  r = 0;
  i = -1;
  if (get->reader[0] == '\n' && get->reader[1] == '\0')
    {
      get->reader[0] = '\0';
      return (1);
    }
  if ((get->tmp = malloc(sizeof(char) * (READ_SIZE * get->mult) + 1)) == NULL)
    return (1);
  while (++i < ((READ_SIZE * get->mult) + 1))
    get->tmp[i] = '\0';
  i = 0;
  while (get->reader[i] != '\n' && get->reader[i] != '\0')
    i = i + 1;
  if (get->reader[i] == '\n')
    get->reader[i] = '\0';
  while (get->reader[i] != '\0')
    {
      get->tmp[r++] = get->reader[i];
      get->reader[i++] = '\0';
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	save[READ_SIZE];
  t_struct	get;

  if (set_up(&get) == 1)
    return (NULL);
  while (save[++(get.i)] != '\0')
    get.reader[get.i] = save[get.i];
  get.i = get.i - 1;
  while (++(get.i) < ((READ_SIZE * 2) + 1))
    get.reader[get.i] = '\0';
  get.i = -1;
  while (++(get.i) < READ_SIZE)
    save[get.i] = '\0';
  if (process(&get, fd) == 1)
    return (NULL);
  if (put_in_tmp(&get) == 1)
    return (get.reader);
  get.i = -1;
  while (get.tmp[++(get.i)] != '\0')
    save[get.i] = get.tmp[get.i];
  free(get.tmp);
  if (get.reader[0] == '\0')
    return (NULL);
  return (get.reader);
}
