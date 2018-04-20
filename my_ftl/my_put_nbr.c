/*
** my_put_nbr.c for my_put_nbr in /home/founauser/S02/Jour05-06/my_put_nbr
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Thu Mar 22 05:40:24 2018 Founa Ben Chaabane
** Last update Thu Mar 22 20:36:11 2018 Founa Ben Chaabane
*/

int	my_nb_len(int n)
{
  int	controle;

  controle = 1 ;
  if (n < 0)
    n = -n;
  while (n > 9)
    {
      n = n / 10;
      controle = controle + 1;
    }
  return controle;
}

void	my_putchar(char);

void	my_put_nbr(int n)
{
  int	i;
  int	len;

  if (n < 0)
    {
      my_putchar('-');
      if (n == -2147483648)
	{ 
	  my_putchar('2');
	  n = 147483648;
	}
      else
	n = -n;
    }
  len = my_nb_len(n);
  i = 1;
  while (len > 1)
    {
      i = i * 10;
      len--;
    }
  while (i >= 1)
    {
      my_putchar(48 + (n / i));
      n = n % i;
      i = i / 10;
    }
}
