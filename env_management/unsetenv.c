/*
** unsetenv.c for  in /home/girard_z/PSU/PSU_2015_42sh/env_management
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue May 17 16:34:24 2016 benjamin girard
** Last update Thu Jun  2 23:39:00 2016 nicolas dejean
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

static void		delete_middle_envline(t_env **env_list, char *key)
{
  t_env			*tmp;
  t_env			*tmp2;

  tmp = *env_list;
  while (tmp != NULL && tmp->next != NULL &&
	 my_strcmp(tmp->next->key, key) != 0)
    tmp = tmp->next;
  tmp2 = tmp->next->next;
  free(tmp->next->value);
  free(tmp->next->key);
  tmp->next = NULL;
  tmp->next  = tmp2;
}

static void		delete_first_envline(t_env **env_list)
{
  t_env			*tmp;

  tmp = *env_list;
  *env_list = (*env_list)->next;
  free(tmp->key);
  free(tmp->value);
  tmp = NULL;
}

static void		delete_last_envline(t_env **env_list, char *key)
{
  t_env			*tmp;

  tmp = *env_list;
  while (tmp != NULL && tmp->next != NULL && my_strcmp(tmp->next->key, key) !=0)
    tmp = tmp->next;
  free(tmp->next->key);
  free(tmp->next->value);
  tmp->next = NULL;
}

static void		exec_unset_env(char *key, t_env **env_list)
{
  t_env			*tmp;
  int			first;

  first = 0;
  tmp = *env_list;
  while (tmp != NULL && my_strcmp(tmp->key, key) != 0)
    {
      tmp = tmp->next;
      first = first + 1;
    }
  if (tmp == NULL)
    return ;
  if (first == 0)
    delete_first_envline(env_list);
  else if (tmp->next == NULL)
    delete_last_envline(env_list, key);
  else
    delete_middle_envline(env_list, key);
}

int			unset_env(t_tree *tree, t_env **env)
{
  t_lex			*tmp;

  tmp = tree->lexer->next;
  if (tmp == NULL)
    return (my_perror(UNSETENV_ERR, EXIT_FAILURE));
  while (tmp != NULL)
    {
      exec_unset_env(tmp->content, env);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
