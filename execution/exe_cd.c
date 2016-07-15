/*
** exe_cd.c for cd in /home/dejean_n/PSU_2015_42sh/execution
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Tue May 17 16:14:26 2016 nicolas dejean
** Last update Sat Jun  4 05:31:56 2016 nicolas dejean
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

int			change_pwd_env(t_env **env, char *key)
{
  t_env			*tmp;
  char			*pwd;

  tmp = *env;
  pwd = NULL;
  while (tmp != NULL && my_strcmp(tmp->key, key) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    {
      if ((pwd = malloc(sizeof(char) * PWD_SIZE)) == NULL)
	return (my_perror(QUIT_ERR, QUIT_RET));
      if (exec_setenv(key, getcwd(pwd, PWD_SIZE), env) == QUIT_RET)
	return (QUIT_RET);
      free(pwd);
      return (change_pwd_env(env, key));
    }
  free(tmp->value);
  if ((tmp->value = malloc(sizeof(char) * PWD_SIZE)) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  getcwd(tmp->value, PWD_SIZE);
  return (EXIT_SUCCESS);
}

static int		cd_home(t_env **env)
{
  t_env			*tmp;
  char			*pwd;

  tmp = *env;
  if ((pwd = malloc(sizeof(char) * PWD_SIZE)) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  if (exec_setenv("OLDPWD", getcwd(pwd, PWD_SIZE), env) == QUIT_RET)
    return (QUIT_RET);
  while (tmp != NULL && my_strcmp("HOME", tmp->key) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    chdir("/");
  else if (chdir(tmp->value) == -1)
    write(2, CD_FAILED, my_strlen(CD_FAILED));
  else
    if (change_pwd_env(env, "PWD") == QUIT_RET)
      return (QUIT_RET);
  return (EXIT_SUCCESS);
}

static int		move_to_arg(char *dir, t_env **env)
{
  if (chdir(dir) == -1)
    {
      write(2, dir, my_strlen(dir));
      write(2, CD_WRONG_ARG, my_strlen(CD_WRONG_ARG));
      return (EXIT_FAILURE);
    }
  else
    if (change_pwd_env(env, "PWD") == QUIT_RET)
      return (QUIT_RET);
  return (EXIT_SUCCESS);
}

static int		cd_arg(t_lex *lexer, t_env **env)
{
  if (lexer->next != NULL)
    return (my_perror(CD_NB_ARG, EXIT_FAILURE));
  if (my_strcmp(lexer->content, "-") == 0)
    {
      if (cd_dash(env) == QUIT_RET)
	return (QUIT_RET);
    }
  else
    return (move_to_arg(lexer->content, env));
  return (EXIT_SUCCESS);
}

int			exe_cd(t_tree *tree, t_env **env)
{
  if (tree->lexer->next == NULL
      || my_strcmp(tree->lexer->next->content, "~") == 0)
    return (cd_home(env));
  return (cd_arg(tree->lexer->next, env));
}
