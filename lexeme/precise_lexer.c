/*
** precise_lexer.c for  in /home/girard_z/PSU/PSU_2015_42sh/lexeme/lexeme_new
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Sun May 22 22:40:28 2016 girard_z
** Last update Sat Jun  4 05:48:30 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

static const t_parse	op_p[8] =
{
  {SMC, OP_SMC},
  {OR, OP_OR},
  {AND, OP_AND},
  {PIPE, OP_PIPE},
  {RDL, OP_RDL},
  {RDR, OP_RDR},
  {DRDL, OP_DRDL},
  {DRDR, OP_DRDR}
};

static int		precise_op_type(t_lex **lexer)
{
  int			i;

  i = 0;
  while (i < 8 && my_strcmp(op_p[i].op, (*lexer)->content) != 0)
    ++i;
  (*lexer)->type = op_p[i].type;
  return ((i < 4) ? CMD : FILE_ARG);
}

static int		precise_cmd_type(t_lex **lexer, int type)
{
  (*lexer)->type = type;
  return (CMD_ARG);
}

void			precise_lexer_usability(t_lex **lexer)
{
  t_lex			*tmp;
  int			next_type;

  next_type = CMD;
  tmp = *lexer;
  while (tmp != NULL)
    {
      if (tmp->type == CMD)
	next_type = precise_cmd_type(&tmp, next_type);
      else
	next_type = precise_op_type(&tmp);
      tmp = tmp->next;
    }
}
