/*
** start_grammar.c for  in /home/girard_z/PSU/PSU_2015_42sh/grammar
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Tue May 24 11:27:58 2016 girard_z
** Last update Sat Jun  4 07:11:31 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

static int	insert_elem_in_tree(t_tree **tree, int op_type)
{
  if (insert_left_stick(tree, op_type) == QUIT_RET)
    return (QUIT_RET);
  if (insert_right_stick(tree, op_type) == QUIT_RET)
    return (QUIT_RET);
  if (insert_actual_op(tree, op_type) == QUIT_RET)
    return (QUIT_RET);
  return (EXIT_SUCCESS);
}

static int	create_split(t_tree **tree, int op_ref)
{
  t_lex		*tmp;
  int		op_type;

  op_type = op_ref;
  while (op_type < OP_NB)
    {
      tmp = (*tree)->lexer;
      while (tmp != NULL)
	{
	  if (tmp->type == op_type)
	    return (insert_elem_in_tree(tree, op_type));
	  tmp = tmp->next;
	}
      ++op_type;
    }
  return (EXIT_SUCCESS);
}

static int	place_tree(t_tree **tree)
{
  if (*tree == NULL)
    return (EXIT_SUCCESS);
  if (create_split(tree, OP_SMC) == QUIT_RET)
    return (QUIT_RET);
  if (place_tree(&((*tree)->left)) == QUIT_RET)
    return (QUIT_RET);
  if (place_tree(&((*tree)->right)) == QUIT_RET)
    return (QUIT_RET);
  return (EXIT_SUCCESS);
}

static int	init_tree(t_tree **tree, t_lex *lexer)
{
  if (((*tree) = malloc(sizeof(t_tree))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  (*tree)->lexer = lexer;
  (*tree)->left = NULL;
  (*tree)->right = NULL;
  return (EXIT_SUCCESS);
}

int		start_grammar(t_sh *sh)
{
  if (init_tree(&(sh->tree), sh->lexer) == QUIT_RET)
    return (QUIT_RET);
  if (place_tree(&(sh->tree)) == QUIT_RET)
    return (QUIT_RET);
  return (EXIT_SUCCESS);
}
