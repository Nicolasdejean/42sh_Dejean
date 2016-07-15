/*
** execute_simple_cmd.c for  in /home/girard_z/PSU/PSU_2015_42sh
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Sat May 28 01:33:46 2016 girard_z
** Last update Sat Jun  4 05:39:40 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

int			execute_simple_cmd(t_tree *tree, t_env **env)
{
  int			i;
  static t_func		func[6] =
    {
      {SETENV, &set_env},
      {UNSETENV, &unset_env},
      {ENV, &my_show_env_list},
      {ECHO, &exe_echo},
      {EXIT, &exe_exit},
      {CD, &exe_cd}
    };

  if (tree == NULL || tree->lexer == NULL)
    return (EXIT_SUCCESS);
  i = 0;
  while (i < 6 && my_strcmp(func[i].cmd, tree->lexer->content) != 0)
    ++i;
  if (i == 6)
    return (exec_execve(tree, env));
  return (func[i].cmd_fct(tree, env));
}
