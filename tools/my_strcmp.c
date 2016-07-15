/*
** my_strcmp.h for  in /home/girard_z/PSU/PSU_2015_42sh/tools
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue May 17 17:03:03 2016 benjamin girard
** Last update Sun May 29 17:38:16 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

int		my_strcmp(char *str, char *cmp)
{
  int		i;

  i = -1;
  if (str == NULL || cmp == NULL)
    return (10);
  while (str[++i] != '\0')
    if (str[i] != cmp[i])
      return (1);
  if (str[i] != cmp[i])
    return (1);
  return (0);
}
