/*
** my_show_list.c for  in /home/girard_z/PSU/PSU_2015_42sh/tools
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue May 17 12:35:19 2016 benjamin girard
** Last update Sat Jun  4 05:55:55 2016 girard_z
*/

#include <stdlib.h>
#include <unistd.h>
#include "sh.h"

void			show_line_env(t_env *env, char *line)
{
  t_env			*tmp;

  tmp = env;
  while (tmp != NULL && my_strcmp(line, tmp->key) != 0)
    tmp = tmp->next;
  if (tmp == NULL || tmp->value == NULL)
    return ;
  my_putstr(tmp->value);
}

int			my_show_env_list(t_tree *tree, t_env **env_list)
{
  t_env			*tmp;

  (void)tree;
  tmp = *env_list;
  while (tmp != NULL)
    {
      my_putstr(tmp->key);
      write(1, "=", 1);
      my_putstr(tmp->value);
      write(1, "\n", 1);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
