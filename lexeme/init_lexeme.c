/*
** init_lexeme.c for  in /home/girard_z/PSU/PSU_2015_42sh/lexeme/lexeme_new
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Thu Jun  2 21:45:34 2016 girard_z
** Last update Fri Jun  3 00:59:40 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

static int		place_op_lexer(t_lex **lexer,
				       const char *cmd, int *cmd_i, int ret)
{
  t_lex			*tmp;
  t_lex			*elem;
  int			set;

  set = -1;
  tmp = *lexer;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if ((elem = malloc(sizeof(t_lex))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  if ((elem->content = malloc(sizeof(char) * (ret + 1))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  set = -1;
  elem->type = OP;
  elem->next = NULL;
  while (++set < ret)
    elem->content[set] = cmd[(*cmd_i)++];
  elem->content[set] = '\0';
  if (tmp == NULL)
    *lexer = elem;
  else
    tmp->next = elem;
  return (EXIT_SUCCESS);
}

static int		precise_size_place_op(t_lex **lexer, const char *cmd,
					      int *cmd_i)
{
  if (cmd[*cmd_i] == ';')
    return (place_op_lexer(lexer, cmd, cmd_i, 1));
  if (cmd[*cmd_i] == '&' && cmd[*cmd_i + 1] != '&')
    return (my_perror(AND_ERR_OP, EXIT_FAILURE));
  if (cmd[*cmd_i + 1] == cmd[*cmd_i])
    return (place_op_lexer(lexer, cmd, cmd_i, 2));
  return (place_op_lexer(lexer, cmd, cmd_i, 1));
}

static int		precise_size_place_cmd(t_lex **lexer, const char *cmd,
					       int *cmd_i)
{
  int			i;

  i = 0;
  while (cmd[*cmd_i + i] != '|' && cmd[*cmd_i + i] != '&' &&
	 cmd[*cmd_i + i] != ';' && cmd[*cmd_i + i] != '<' &&
	 cmd[*cmd_i + i] != '>' && cmd[*cmd_i + i] != ' ' &&
	 cmd[*cmd_i + i] != '\t' && cmd[*cmd_i + i] != '\0')
    ++i;
  return (place_lexer_cmd(lexer, cmd, cmd_i, i));
}

static int		dif_op_from_cmd(t_lex **lexer, const char *cmd,
					int *cmd_i)
{
  if (cmd[*cmd_i] == '|' || cmd[*cmd_i] == '&' ||
      cmd[*cmd_i] == ';' || cmd[*cmd_i] == '<' ||
      cmd[*cmd_i] == '>')
    return (precise_size_place_op(lexer, cmd, cmd_i));
  if (cmd[*cmd_i] != '\0')
    return (precise_size_place_cmd(lexer, cmd, cmd_i));
  return (EXIT_SUCCESS);
}

int			init_lexeme(t_lex **lexer, char *cmd)
{
  int			cmd_i;
  int			ret_val;

  cmd_i = 0;
  while (cmd[cmd_i] != '\0')
    {
      delete_space(cmd, &cmd_i);
      if ((ret_val = dif_op_from_cmd(lexer, cmd, &cmd_i)) == QUIT_RET ||
	  ret_val == EXIT_FAILURE)
	{
	  free(cmd);
	  return (ret_val);
	}
    }
  free(cmd);
  precise_lexer_usability(lexer);
  if (lexeme_error_assemble(lexer) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
