/*
** my_putstr.c for  in /home/girard_z/PSU/PSU_2015_42sh/tools
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue May 17 12:54:31 2016 benjamin girard
** Last update Fri May 27 21:28:17 2016 girard_z
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

int			my_putstr(const char *str)
{
  int			i;

  i = -1;
  if (str == NULL)
    return (EXIT_SUCCESS);
  while (str[++i])
    write(1, &str[i], 1);
  return (EXIT_SUCCESS);
}
