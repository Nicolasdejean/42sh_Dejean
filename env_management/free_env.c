/*
** free_env.c for  in /home/girard_z/PSU/PSU_2015_42sh/env_management
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Mon May 23 17:21:12 2016 girard_z
** Last update Fri May 27 19:42:05 2016 girard_z
*/

#include <stdlib.h>
#include "sh.h"

void		free_env(t_env **env_list)
{
  if (*env_list == NULL)
    return ;
  free_env(&((*env_list)->next));
  free((*env_list)->key);
  free((*env_list)->value);
  free(*env_list);
  *env_list = NULL;
}
