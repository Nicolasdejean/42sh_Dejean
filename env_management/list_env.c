/*
** list_env.c for  in /home/girard_z/PSU/PSU_2015_42sh
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue May 17 09:53:58 2016 benjamin girard
** Last update Sat Jun  4 04:12:05 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

static char		*take_envline_key(char *env_line)
{
  int			i;
  char			*key;

  i = 0;
  while (env_line[i] != '\0' && env_line[i] != '=')
    i = i + 1;
  if ((key = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = -1;
  while (env_line[++i] != '\0' && env_line[i] != '=')
    key[i] = env_line[i];
  key[i] = '\0';
  return (key);
}

static char		*take_envline_value(char *env_line)
{
  int			i;
  int			count;
  char			*value;

  count = 0;
  i = 0;
  while (env_line[i] != '=' && env_line[i] != '\0')
    i = i + 1;
  i = i + 1;
  while (env_line[i + count] != '\0')
    count = count + 1;
  if ((value = malloc(sizeof(char) * (count + 1))) == NULL)
    return (NULL);
  count = i;
  while (env_line[i] != '\0')
    {
      value[i - count] = env_line[i];
      i += 1;
    }
  value[i - count] = '\0';
  return (value);
}

static int		put_line_in_list(t_env **env_list, char *env_line)
{
  t_env			*elem;
  t_env			*tmp;

  tmp = *env_list;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if ((elem = malloc(sizeof(t_env))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  if ((elem->key = take_envline_key(env_line)) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  if ((elem->value = take_envline_value(env_line)) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  elem->next = NULL;
  if (tmp == NULL)
    *env_list = elem;
  else
    tmp->next = elem;
  return (EXIT_SUCCESS);
}

int			list_env(t_env **env_list, char **env)
{
  int			env_i;

  *env_list = NULL;
  env_i = -1;
  if (env == NULL)
    return (EXIT_SUCCESS);
  while (env[++env_i] != 0)
    if (put_line_in_list(env_list, env[env_i]) == QUIT_RET)
      return (QUIT_RET);
  return (EXIT_SUCCESS);
}
