/*
** my_str_to_wordtab.c for  in /home/girard_z/PSU/PSU_2015_42sh/tools
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Mon May 16 07:02:27 2016 benjamin girard
** Last update Fri May 27 21:33:53 2016 girard_z
*/

#include <stdlib.h>

static int	nb_paths(const char *path, char separator)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (path[i] != '\0')
    {
      if (path[i] == separator)
	count += 1;
      i += 1;
    }
  return (count + 1);
}

static int	longest_path(const char *path, char separator)
{
  int		i;
  int		res;
  int		tmp;

  tmp = 0;
  i = -1;
  res = 0;
  while (path[++i] != '\0')
    {
      if (path[i] == separator)
	{
	  if (res < tmp)
	    res = tmp;
	  tmp = 0;
	}
      else
	tmp += 1;
    }
  if (res < tmp)
    res = tmp;
  return (res);
}

static char	**fill_tab(const char *path, char **tab, char separator)
{
  int		path_i;
  int		t_i;
  int		t_j;

  path_i = 0;
  t_j = 0;
  t_i = 0;
  while (path[path_i] != '\0')
    {
      tab[t_j][t_i] = path[path_i];
      path_i = path_i + 1;
      if (path[path_i] == separator)
	{
	  t_i = 0;
	  t_j += 1;
	  path_i += 1;
	}
      else
	t_i += 1;
    }
  return (tab);
}

static char	**malloc_set_tab(const char *path, const int size,
				 char separator)
{
  int		i;
  int		j;
  int		size_line;
  char		**tab;

  size_line = longest_path(path, separator);
  i = 0;
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (i < size)
    {
      j = -1;
      if ((tab[i] = malloc(sizeof(char) * (size_line + 1))) == NULL)
	return (NULL);
      while (++j < size_line + 1)
	tab[i][j] = '\0';
      i += 1;
    }
  tab[i] = 0;
  return (fill_tab(path, tab, separator));
}

char		**my_str_to_tab(const char *path, char separator)
{
  char		**tab;
  int		size;

  if (path == NULL)
    return (NULL);
  size = nb_paths(path, separator);
  if ((tab = malloc_set_tab(path, size, separator)) == NULL)
    return (NULL);
  return (tab);
}
