/*
** exe_cd_two.c for two in /home/dejean_n/PSU_2015_42sh/execution
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Sat Jun  4 01:32:55 2016 nicolas dejean
** Last update Sat Jun  4 05:37:28 2016 girard_z
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sh.h"


int			cd_dash(t_env **env)
{
  char			*cmd;
  t_env			*tmp;

  cmd = NULL;
  tmp = *env;
  while (tmp != NULL && my_strcmp(tmp->key, "OLDPWD") == 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (EXIT_SUCCESS);
  cmd = strdup(tmp->value);
  free(tmp->value);
  if ((tmp->value = malloc(sizeof(char) * PWD_SIZE)) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  if (exec_setenv("OLDPWD", getcwd(tmp->value, PWD_SIZE), env) == QUIT_RET)
    return (QUIT_RET);
  chdir(cmd);
  free(cmd);
  return (change_pwd_env(env, "PWD"));
}
