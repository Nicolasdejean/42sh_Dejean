/*
** get_next_line2.c for  in /home/girard_z/PSU_2015_minishell2
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Sat Apr  9 03:56:22 2016 benjamin girard
** Last update Sat Jun  4 05:52:43 2016 girard_z
*/

#include "get_next_line.h"

int		set_up(t_struct *get)
{
  get->mult = 2;
  get->i = -1;
  if ((get->reader = malloc(sizeof(char) * ((READ_SIZE * 2) + 1))) == NULL)
    return (1);
  return (0);
}
