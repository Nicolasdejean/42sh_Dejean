/*
** my_strcat.c for  in /home/girard_z/PSU/PSU_2015_42sh
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Sun May 29 22:27:41 2016 girard_z
** Last update Sun May 29 23:28:07 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

char			*my_strcat(const char *src, const char *dest,
				   const int equal)
{
  char			*res;
  int			src_i;
  int			dest_i;

  dest_i = -1;
  src_i = -1;
  if ((res = malloc(sizeof(char)
		    * (my_strlen(src) + my_strlen(dest) + 2))) == NULL)
    return (NULL);
  while (src != NULL && ++src_i < my_strlen(src))
    res[src_i] = src[src_i];
  if (equal == 1)
    res[src_i++] = '=';
  else
    res[src_i++] = '/';
  while (dest != NULL && ++dest_i < my_strlen(dest))
    res[src_i++] = dest[dest_i];
  res[src_i] = '\0';
  return (res);
}
