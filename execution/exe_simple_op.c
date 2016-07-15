/*
** exe_smc.c for  in /home/girard_z/PSU/PSU_2015_42sh/execution
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Thu Jun  2 05:48:27 2016 girard_z
** Last update Sat Jun  4 07:20:02 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

int			exe_and(t_tree *tree, t_env **env)
{
  int			ret_val;

  ret_val = 0;
  if (tree->left == NULL || tree->left->lexer == NULL ||
      tree->right == NULL || tree->right->lexer == NULL)
    return (my_perror(ERR_PIPE, EXIT_FAILURE));
  if ((ret_val = hub_execution(tree->left, env)) != EXIT_SUCCESS)
    return (ret_val);
  else
    return (hub_execution(tree->right, env));
  return (EXIT_SUCCESS);
}

int			exe_or(t_tree *tree, t_env **env)
{
  int			ret_val;

  ret_val = 0;
  if (tree->left == NULL || tree->left->lexer == NULL ||
      tree->right == NULL || tree->right->lexer == NULL)
    return (my_perror(ERR_PIPE, EXIT_FAILURE));
  if ((ret_val = hub_execution(tree->left, env)) != EXIT_SUCCESS)
    {
      if (ret_val == QUIT_RET)
	return (QUIT_RET);
      return (hub_execution(tree->right, env));
    }
  return (EXIT_SUCCESS);
}

int			exe_smc(t_tree *tree, t_env **env)
{
  if (hub_execution(tree->left, env) == QUIT_RET ||
      hub_execution(tree->right, env) == QUIT_RET)
    return (QUIT_RET);
  return (EXIT_SUCCESS);
}
