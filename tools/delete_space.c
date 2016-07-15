/*
** delete_space.c for  in /home/girard_z/PSU/PSU_2015_42sh/tools
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Fri May 20 20:40:09 2016 girard_z
** Last update Sun May 22 22:15:33 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

void		delete_space(char *str, int *i)
{
  while (str[*i] == ' ' || str[*i] == '\t')
    ++(*i);
}
