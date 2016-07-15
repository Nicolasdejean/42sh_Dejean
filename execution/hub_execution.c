/*
** hub_execution.c for exec in /home/dejean_n/PSU_2015_42sh/execution
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Fri May 27 19:08:34 2016 nicolas dejean
** Last update Sat Jun  4 07:19:11 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

int		hub_execution(t_tree *tree, t_env **env)
{
  if (tree == NULL || tree->lexer == NULL)
    return (EXIT_SUCCESS);
  if (tree->lexer->type == CMD)
    return (execute_simple_cmd(tree, env));
  return (execute_op(tree, env));
}
