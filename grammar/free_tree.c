/*
** free_tree.c for  in /home/girard_z/PSU/PSU_2015_42sh/grammar
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Thu May 26 21:14:07 2016 girard_z
** Last update Thu May 26 21:40:47 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

void		free_tree(t_tree **tree)
{
  if (*tree == NULL)
    return ;
  free_tree(&((*tree)->left));
  free_tree(&((*tree)->right));
  free_lexem_delivery(&((*tree)->lexer));
  free(*tree);
  *tree = NULL;
}
