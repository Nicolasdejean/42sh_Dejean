/*
** set_env.c for  in /home/girard_z/PSU/PSU_2015_42sh/env_management
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue May 17 16:13:42 2016 benjamin girard
** Last update Sat Jun  4 05:34:40 2016 girard_z
*/

#include <string.h>
#include <stdlib.h>
#include "sh.h"

static int		env_name_check(const char *name)
{
  int			i;

  i = -1;
  while (name[++i] != '\0')
    {
      if (i == 0 && ((name[i] < 'A' || name[i] > 'Z') &&
		     (name[i] < 'a' || name[i] > 'z') &&
		     name[i] != '_'))
	return (my_perror(SETENV_BEG_ERR, EXIT_FAILURE));
      if ((name[i] < 'A' || name[i] > 'Z') &&
		     (name[i] < 'a' || name[i] > 'z') &&
		     name[i] != '_')
	return (my_perror(SETENV_NAM_ERR, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}

static int		modify_env(char *name, char *value, t_env **env_list)
{
  t_env			*tmp;

  tmp = *env_list;
  while (my_strcmp(tmp->key, name) == 1)
    tmp = tmp->next;
  (value == NULL) ? (tmp->value = NULL) : (tmp->value = strdup(value));
  return (EXIT_SUCCESS);
}

static int		create_env(char *name, char *value, t_env **env_list)
{
  t_env			*new_env;
  t_env			*tmp;

  tmp = *env_list;
  if ((new_env = malloc(sizeof(t_env))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  if ((new_env->key = strdup(name)) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  (value == NULL) ? (new_env->value = NULL) : (new_env->value = strdup(value));
  new_env->next = NULL;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if (tmp == NULL)
    *env_list = new_env;
  else
    tmp->next = new_env;
  return (EXIT_SUCCESS);
}

int			exec_setenv(char *name, char *value, t_env **env_list)
{
  t_env			*find_env;

  find_env = *env_list;
  if (env_name_check(name) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (find_env != NULL && my_strcmp(find_env->key, name) != 0)
    find_env = find_env->next;
  if (find_env == NULL)
    return (create_env(name, value, env_list));
  else
    return (modify_env(name, value, env_list));
  return (EXIT_SUCCESS);
}

int			set_env(t_tree *tree, t_env **env)
{
  if (tree->lexer != NULL &&
      tree->lexer->next != NULL &&
      tree->lexer->next->next != NULL &&
      tree->lexer->next->next->next != NULL)
    return (my_perror(SETENV_TOO_MANY_ARG, EXIT_FAILURE));
  if (tree->lexer != NULL &&
      tree->lexer->next != NULL && tree->lexer->next->next != NULL)
    return (exec_setenv(tree->lexer->next->content,
			tree->lexer->next->next->content, env));
  if (tree->lexer->next != NULL)
    return (exec_setenv(tree->lexer->next->content, NULL, env));
  my_show_env_list(tree, env);
  return (EXIT_SUCCESS);
}
