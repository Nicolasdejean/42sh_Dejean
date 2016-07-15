/*
** exe_execve.c for  in /home/girard_z/PSU/PSU_2015_42sh
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Sun May 29 18:20:38 2016 girard_z
** Last update Sat Jun  4 06:07:24 2016 girard_z
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include "sh.h"

static int	use_execve(t_tree *tree, t_env **env, char *cmd)
{
  char		**tab_env;
  char		**tab_lex;
  int		pid;
  int		exec_val;

  exec_val = 0;
  if ((tab_env = env_to_tab(*env)) == NULL ||
      ((tab_lex = lex_to_tab(tree->lexer)) == NULL) ||
      ((pid = fork()) == -1))
    return (my_perror(QUIT_ERR, QUIT_RET));
  if (pid == 0)
    {
      if (execve(cmd, tab_lex, tab_env) == -1)
	return (my_perror(QUIT_ERR, QUIT_RET));
    }
  else
    {
      if (wait(&exec_val) == -1)
	return (my_perror(QUIT_ERR, QUIT_RET));
      exec_val = WEXITSTATUS(exec_val);
    }
  free_tab(tab_env);
  free_tab(tab_lex);
  free(cmd);
  return (exec_val);
}

static char	*check_access(t_tree *tree, t_env *env)
{
  char		**tab;
  int		i_tab;
  char		*cmd_and_path;

  i_tab = -1;
  if ((tab = my_str_to_tab(env->value, ':')) == NULL)
    return (NULL);
  while (tab[++i_tab] != 0)
    {
      if ((cmd_and_path = my_strcat(tab[i_tab], tree->lexer->content, 0))
	  == NULL)
	return (NULL);
      if (access(cmd_and_path, F_OK) == -1)
	free(cmd_and_path);
      else
	{
	  free_tab(tab);
	  return (cmd_and_path);
	}
    }
  free_tab(tab);
  return (NULL);
}

int		exec_execve(t_tree *tree, t_env **env)
{
  t_env		*tmp_env;
  char		*cmd;

  tmp_env = *env;
  while (tmp_env != NULL && my_strcmp(tmp_env->key, "PATH") != 0)
    tmp_env = tmp_env->next;
  if (tmp_env == NULL || tmp_env->value == NULL)
    {
      if (exec_setenv("PATH", DEFAULT_PATH, env) == QUIT_RET)
	return (QUIT_RET);
      return (exec_execve(tree, env));
    }
  if ((cmd = check_access(tree, tmp_env)) == NULL)
    {
      write(2, tree->lexer->content, my_strlen(tree->lexer->content));
      write(2, ACCESS_ERR, my_strlen(ACCESS_ERR));
      return (EXIT_FAILURE);
    }
  return (use_execve(tree, env, cmd));
}
