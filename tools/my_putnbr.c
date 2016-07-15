/*
** my_putnbr.c for a in /home/girard_z/test_putnbr
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Fri Mar 11 08:41:04 2016 benjamin girard
** Last update Mon May 23 02:07:01 2016 girard_z
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putnbr(int nb)
{
  if (nb == -2147483648)
    {
      my_putnbr(-21474);
      my_putnbr(83648);
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb / 10 != 0)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
  return (0);
}
