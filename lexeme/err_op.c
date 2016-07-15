/*
** err_op.c for  in /home/girard_z/PSU/PSU_2015_42sh
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Fri Jun  3 02:25:29 2016 girard_z
** Last update Fri Jun  3 02:40:27 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

int			rd_err(t_lex *lexer, int place)
{
  if (place == 0 || lexer->next == NULL || lexer->next->type < OP_NB)
    return (my_perror(ERR_RD, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}

int			and_err(t_lex *lexer, int place)
{
  if (place != 0 && (lexer->next == NULL || lexer->next->type < OP_NB))
    return (my_perror(WRONG_OP, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}

int			pipe_err(t_lex *lexer, int place)
{
  if (place == 0 || lexer->next == NULL || lexer->next->type < OP_NB)
    return (my_perror(WRONG_OP, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}

int			smc_err(t_lex *lexer, int place)
{
  (void)lexer;
  (void)place;
  return (EXIT_SUCCESS);
}
