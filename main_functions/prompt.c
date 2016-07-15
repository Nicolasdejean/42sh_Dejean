/*
** prompt.c for prompt in /home/dejean_n/PSU_2015_42sh/main_functions
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Tue May 17 16:17:44 2016 nicolas dejean
** Last update Sat Jun  4 05:57:22 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"
#include "get_next_line.h"

static char		*get_key_value(const t_env *list, char *cmp)
{
  const t_env		*tmp;

  tmp = list;
  while (tmp != NULL && my_strcmp(tmp->key, cmp) == 1)
    tmp = tmp->next;
  return (tmp == NULL ? DEFAULT_PROMPT : tmp->value);
}

static int		pwd_up_to_date(t_env *env_list)
{
  char		*pwd;

  pwd = get_key_value(env_list, "PWD");
  my_putstr(pwd);
  my_putstr(">");
  return (EXIT_SUCCESS);
}

char			*prompt(t_env *env_list)
{
  char		*line;

  pwd_up_to_date(env_list);
  if ((line = get_next_line(0)) == NULL)
    return (NULL);
  return (line);
}
