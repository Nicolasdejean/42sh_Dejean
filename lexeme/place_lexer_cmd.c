/*
** place_lexer_cmd.c for  in /home/girard_z/PSU/PSU_2015_42sh/lexeme/lexeme_new
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Thu Jun  2 22:37:58 2016 girard_z
** Last update Fri Jun  3 04:38:14 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

int		place_lexer_cmd(t_lex **lexer, const char *cmd, int *cmd_i,
				int ret)
{
  t_lex		*tmp;
  t_lex		*elem;
  int		set;

  set = -1;
  tmp = *lexer;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if ((elem = malloc(sizeof(t_lex))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  if ((elem->content = malloc(sizeof(char) * (ret + 1))) == NULL)
    return (my_perror(QUIT_ERR, QUIT_RET));
  while (++set < ret)
    elem->content[set] = '\0';
  set = -1;
  elem->type = CMD;
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
