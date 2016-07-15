/*
** lex_to_tab.c for  in /home/girard_z/PSU/PSU_2015_42sh/tools
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Sun May 29 22:43:52 2016 girard_z
** Last update Sun May 29 23:21:48 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

static int		env_len(t_env *env)
{
  int			i;
  t_env			*tmp;

  i = 0;
  tmp = env;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      ++i;
    }
  return (i);
}

static int		lex_len(t_lex *lexer)
{
  int			i;
  t_lex			*tmp;

  i = 0;
  tmp = lexer;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      ++i;
    }
  return (i);
}

char			**lex_to_tab(t_lex *lexer)
{
  t_lex			*tmp;
  char			**tab;
  int			i;
  int			cp;

  i = -1;
  tmp = lexer;
  if ((tab = malloc(sizeof(char *) * (lex_len(lexer) + 1))) == NULL)
    return (NULL);
  while (++i < lex_len(lexer))
    {
      cp = -1;
      if ((tab[i] = malloc(sizeof(char) *
			   (my_strlen(tmp->content) + 1))) == NULL)
	return (NULL);
      while (++cp < my_strlen(tmp->content))
	tab[i][cp] = tmp->content[cp];
      tab[i][cp] = '\0';
      tmp = tmp->next;
    }
  tab[i] = NULL;
  return (tab);
}

char			**env_to_tab(t_env *env)
{
  t_env			*tmp;
  char			**tab;
  int			i;

  i = -1;
  tmp = env;
  if ((tab = malloc(sizeof(char *) * (env_len(env) + 1))) == NULL)
    return (NULL);
  while (++i < env_len(env))
    {
      if ((tab[i] = my_strcat(tmp->key, tmp->value, 1)) == NULL)
	return (NULL);
      tmp = tmp->next;
    }
  tab[i] = NULL;
  return (tab);
}
