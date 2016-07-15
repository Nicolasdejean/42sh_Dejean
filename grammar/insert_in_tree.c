/*
** insert_in_tree.c for in in /home/dejean_n/PSU_2015_42sh
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Tue May 24 19:01:33 2016 nicolas dejean
** Last update Sat Jun  4 07:11:17 2016 girard_z
*/


#include <stdlib.h>
#include "sh.h"

static int		add_in_lex(t_lex **lexer, char *str, int nbr)
{
  t_lex			*tmp;
  t_lex			*elem;
  int			i;

  i = -1;
  tmp = *lexer;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if ((elem = malloc(sizeof(t_lex))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  if ((elem->content = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  while (str[++i] != '\0')
    elem->content[i] = str[i];
  elem->content[i] = '\0';
  elem->type = nbr;
  elem->next = NULL;
  if (tmp == NULL)
    *lexer = elem;
  else
    tmp->next = elem;
  return (EXIT_SUCCESS);
}
int			insert_left_stick(t_tree **tree, int op_type)
{
  t_lex			*tmp;

  tmp = (*tree)->lexer;
  if (((*tree)->left = malloc(sizeof(t_tree))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  (*tree)->left->left = NULL;
  (*tree)->left->lexer = NULL;
  (*tree)->left->right = NULL;
  while (tmp != NULL && tmp->type != op_type)
    {
      if (add_in_lex(&((*tree)->left->lexer), tmp->content, tmp->type)
	  == QUIT_RET)
	return (QUIT_RET);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int			insert_right_stick(t_tree **tree, int op_type)
{
  t_lex			*tmp;

  tmp = (*tree)->lexer;
  if (((*tree)->right = malloc(sizeof(t_tree))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  (*tree)->right->left = NULL;
  (*tree)->right->lexer = NULL;
  (*tree)->right->right = NULL;
  while (tmp != NULL && tmp->type != op_type)
    tmp = tmp->next;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      if (add_in_lex(&((*tree)->right->lexer), tmp->content, tmp->type)
	  == QUIT_RET)
	return (QUIT_RET);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int			insert_actual_op(t_tree **tree, int op_type)
{
  t_lex			*tmp;
  t_lex			*new_elem;

  tmp = (*tree)->lexer;
  new_elem = NULL;
  while (tmp != NULL && tmp->type != op_type)
    tmp = tmp->next;
  if (add_in_lex(&new_elem, tmp->content, tmp->type))
    return (QUIT_RET);
  free_lexem_delivery(&((*tree)->lexer));
  (*tree)->lexer = new_elem;
  return (EXIT_SUCCESS);
}
