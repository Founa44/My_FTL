/*
** my_getnbr.c for my_getnbr in /home/founauser/S02/Jour05-06/my_getnbr
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Thu Mar 22 06:31:59 2018 Founa Ben Chaabane
** Last update Thu Mar 22 08:31:54 2018 Founa Ben Chaabane
*/

int	format(int nbr, int sign)
{
  if (sign == -1)
    return (-nbr);
  else
    return (nbr);
}

int	my_getnbr(char *str)
{
  int sign;
  int nbr;
  int i;

  i = 0;
  nbr = 0;
  sign = 1;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	sign = -sign;
      i++;
    }
  while (str[i] != '\0')
    {
      if ((str[i] >= '0') && (str[i] <= '9'))
	nbr = (nbr * 10) + (str[i] - 48);
      else
	return (format(nbr, sign));
      i++;
    }
  return (format(nbr, sign));
}
