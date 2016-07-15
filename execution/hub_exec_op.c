/*
** execute_cmd_with_op.c for cmd_with_op in /home/dejean_n/PSU_2015_42sh/execution
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Wed Jun  1 11:30:20 2016 nicolas dejean
** Last update Sat Jun  4 07:18:32 2016 girard_z
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

int			execute_op(t_tree *tree, t_env **env)
{
  int			i;
  static t_exec_op	exec[3] =
    {
      {";", &exe_smc},
      {"||", &exe_or},
      {"&&", &exe_and},
    };

  i = 0;
  while (i < 3 && my_strcmp(exec[i].op, tree->lexer->content) != 0)
    ++i;
  if (i == 3)
    return (my_perror(WRONG_OP, EXIT_FAILURE));
  return (exec[i].fct_op(tree, env));
}
