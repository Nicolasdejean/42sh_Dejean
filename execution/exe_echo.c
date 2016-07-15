/*
** exe_echo.c for echo in /home/dejean_n/PSU_2015_42sh/execution
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Tue May 17 16:16:39 2016 nicolas dejean
** Last update Wed Jun  1 21:08:13 2016 girard_z
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

static int	check_echo_err(t_lex *lexer, t_env **env)
{
  t_lex		*tmp_lexer;
  t_env		*tmp_env;

  tmp_env = *env;
  tmp_lexer = lexer;
  while (tmp_lexer != NULL)
    {
      if (tmp_lexer->content[0] == '$' && tmp_lexer->content[1] != '\0')
	{
	  while (tmp_env != NULL
		 && my_strcmp(&tmp_lexer->content[1], tmp_env->key) != 0)
	    tmp_env = tmp_env->next;
	  if (tmp_env == NULL)
	    {
	      write(2, &tmp_lexer->content[1],
		    my_strlen(&tmp_lexer->content[1]));
	      write(2, ECHO_WRONG_VAR, my_strlen(ECHO_WRONG_VAR));
	      return (EXIT_FAILURE);
	    }
	}
      tmp_lexer = tmp_lexer->next;
    }
  return (EXIT_SUCCESS);
}

static int	echo(t_lex *lexer, t_env **env)
{
  t_lex		*tmp;

  tmp = lexer;
  if (check_echo_err(lexer, env) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_strcmp(tmp->content, "-n") == 0)
    tmp  = tmp->next;
  while (tmp != NULL)
    {
      if (tmp->content[0] == '$' && tmp->content[1] != '\0')
	show_line_env(*env, &tmp->content[1]);
      else
	my_putstr(tmp->content);
      if (tmp->next != NULL)
	write(1, " ", 1);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int		exe_echo(t_tree *tree, t_env **env)
{
  if (tree->lexer->next != NULL)
    {
      if (echo(tree->lexer->next, env) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (my_strcmp(tree->lexer->next->content, "-n") == 0)
	return (EXIT_SUCCESS);
      else
	write(1, "\n", 1);
    }
  else
    write(1, "\n", 1);
  return (EXIT_SUCCESS);
}
