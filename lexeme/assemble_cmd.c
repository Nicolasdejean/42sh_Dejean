/*
** assemble_cmd.c for  in /home/girard_z/PSU/PSU_2015_42sh/lexeme/lexeme_new
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Fri Jun  3 00:50:22 2016 girard_z
** Last update Fri Jun  3 04:23:29 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

static const t_err_op	err_op[8] =
  {
    {OP_SMC, &smc_err},
    {OP_OR, &pipe_err},
    {OP_AND, &and_err},
    {OP_PIPE, &pipe_err},
    {OP_RDL, &rd_err},
    {OP_RDR, &rd_err},
    {OP_DRDL, &rd_err},
    {OP_DRDR, &rd_err},
  };

static int		error_lexem(t_lex *lexer)
{
  t_lex			*tmp;
  int			place;
  int			i;

  i = 0;
  place = 0;
  tmp = lexer;
  while (tmp != NULL)
    {
      i = 0;
      while (i < 8 && err_op[i].op != tmp->type)
	++i;
      if (i < 8)
	if (err_op[i].fct_err_op(tmp, place) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
      tmp = tmp->next;
      ++place;
    }
  return (EXIT_SUCCESS);
}

static void		move_cmd_arg(t_lex *com, t_lex *arg, int i)
{
  t_lex			*tmp;

  tmp = com;
  while (--i > 0)
    tmp = tmp->next;
  tmp->next = tmp->next->next;
  arg->next = com->next;
  com->next = arg;
}

static int		assemble_lexeme(t_lex **lexer)
{
  t_lex			*tmp;
  t_lex			*swap;
  int			i;

  tmp = *lexer;
  if (tmp == NULL)
    return (EXIT_SUCCESS);
  if (tmp->type != CMD)
    return (assemble_lexeme(&(tmp->next)));
  swap = tmp->next;
  i = 1;
  while (swap != NULL && swap->type == CMD_ARG && ++i)
    swap = swap->next;
  while (swap != NULL && swap->type > OP_PIPE && swap->type != CMD_ARG &&
	 ++i)
    swap = swap->next;
  if (swap == NULL)
    return (EXIT_SUCCESS);
  if (swap->type <= OP_PIPE)
    return (assemble_lexeme(&(swap->next)));
  move_cmd_arg(tmp, swap, i);
  return (assemble_lexeme(&(tmp->next)));
}

int			lexeme_error_assemble(t_lex **lexer)
{
  if (error_lexem(*lexer) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  assemble_lexeme(lexer);
  return (EXIT_SUCCESS);
}
