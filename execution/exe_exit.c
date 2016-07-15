/*
** exe_exit.c for exit in /home/dejean_n/PSU_2015_42sh/execution
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Tue May 17 16:16:01 2016 nicolas dejean
** Last update Sat Jun  4 05:41:22 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

static int	get_nbr_exit(const char *str)
{
  int		i;
  int		res;

  res = 0;
  i = -1;
  while (str[++i] != '\0')
    {
      if (i == 0 && (str[i] < '0' || str[i] > '9') && str[i] != '-')
	return (my_perror(EXIT_BEG, EXIT_FAILURE));
      if (i != 0 && (str[i] < '0' || str[i] > '9'))
	return (my_perror(EXIT_EXP, EXIT_FAILURE));
      if (i == 0 && str[i] == '-')
	++i;
      res = (res * 10) + (str[i] - 48);
    }
  if (str[0] == '-')
    return (res * (-1));
  return (res);
}

int		exe_exit(t_tree *tree, t_env **env)
{
  int		ret_gnbr;

  ret_gnbr = 0;
  my_putstr("exit\n");
  if (tree != NULL && tree->lexer != NULL &&
      tree->lexer->next != NULL && tree->lexer->next->content != NULL)
    ret_gnbr = get_nbr_exit(tree->lexer->next->content);
  free_tree(&tree);
  free_env(env);
  exit(ret_gnbr);
  return (ret_gnbr);
}
