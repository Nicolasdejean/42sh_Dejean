/*
** main.c for main in /home/dejean_n/PSU_2015_42sh
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Tue May 17 18:24:02 2016 nicolas dejean
** Last update Sat Jun  4 07:13:47 2016 girard_z
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

static int	set_info_shell(t_sh *sh, char *cmd)
{
  int		ret_value;

  sh->lexer = NULL;
  sh->tree = NULL;
  if (my_strlen(cmd) > 256)
    {
      write(2, "/bin/", 5);
      write(2, cmd, my_strlen(cmd));
      free(cmd);
      return (my_perror(CMD_LONG, EXIT_FAILURE));
    }
  if ((ret_value = init_lexeme(&(sh->lexer), cmd)) == QUIT_RET ||
      ret_value == EXIT_FAILURE)
    return (ret_value);
  if (start_grammar(sh) == QUIT_RET)
    return (QUIT_RET);
  return (EXIT_SUCCESS);
}

static int	launch_shell(t_sh *sh)
{
  char		*cmd;

  while ((cmd = prompt(sh->env_list)) != NULL)
    {
      if ((sh->return_value = set_info_shell(sh, cmd)) == QUIT_RET)
	return (QUIT_RET);
      if (sh->return_value == EXIT_FAILURE)
	{
	  if (sh->lexer != NULL)
	    free_lexem_delivery(&(sh->lexer));
	  continue ;
	}
      if ((sh->return_value =
      	   hub_execution(sh->tree, &sh->env_list)) == QUIT_RET )
	return (QUIT_RET);
      free_tree(&sh->tree);
    }
  my_putstr(EXIT);
  return (sh->return_value);
}

int		main(int ac, char **av, char **env)
{
  t_sh		sh;

  (void)ac;
  (void)av;
  sh.return_value = 0;
  if (list_env(&(sh.env_list), env) == QUIT_RET)
    return (QUIT_RET);
  if (launch_shell(&sh) == QUIT_RET)
    return (QUIT_RET);
  free_env(&(sh.env_list));
  return ((unsigned char)sh.return_value);
}
