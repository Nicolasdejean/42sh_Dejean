/*
** free_lexeme_list.c for free in /home/dejean_n/PSU_2015_42sh/lexeme
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Mon May 23 16:54:21 2016 nicolas dejean
** Last update Thu May 26 22:02:20 2016 girard_z
*/

#include "sh.h"
#include "stdlib.h"

void		free_lexem_delivery(t_lex **lexer)
{
  if (*lexer == NULL)
    return ;
  free_lexem_delivery(&((*lexer)->next));
  free((*lexer)->content);
  (*lexer)->content = NULL;
  free(*lexer);
  *lexer = NULL;
}
