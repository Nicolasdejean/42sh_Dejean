/*
** my_perror.c for  in /home/girard_z/PSU/PSU_2015_42sh/tools
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Mon May 16 07:25:03 2016 benjamin girard
** Last update Wed Jun  1 20:26:47 2016 girard_z
*/

#include <stdlib.h>
#include <unistd.h>
#include "sh.h"

int		my_perror(char *str, int ret_val)
{
  write(2, str, my_strlen(str));
  return (ret_val);
}
