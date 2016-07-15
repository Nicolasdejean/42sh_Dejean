/*
** my_strlen.c for  in /home/girard_z/PSU/PSU_2015_42sh/tools
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Mon May 16 07:26:10 2016 benjamin girard
** Last update Sun May 29 23:22:45 2016 girard_z
*/

#include <stdlib.h>

int		my_strlen(const char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i += 1;
  return (i);
}
