/*
** free_tab.c for  in /home/girard_z/PSU/PSU_2015_42sh
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Sun May 29 22:34:55 2016 girard_z
** Last update Sun May 29 22:35:43 2016 girard_z
*/

#include <stdlib.h>

void			free_tab(char **tab)
{
  int			i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
}
