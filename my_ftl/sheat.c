/*
** sheat.c for sheat in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Sat Apr 14 10:32:01 2018 Founa Ben Chaabane
** Last update Sun Apr 15 19:37:07 2018 Founa Ben Chaabane
*/

#include "ftl.h"

void	power(t_ship	*ship)
{
  if (!ship)
    return;
  my_putstr_color("green","\n\nCaptain Vous etes le plus fort xD\n\n");
  ship->weapon->damage = 1000;
}

void	kill(t_ship	*ship)
{
  if (!ship)
    return;
  if (ship->navigation_tools->enemy == 1)
    {
      my_putstr_color("green","\n\nCaptain des forces surnaturelles");
      my_putstr_color("green"," ont détruit le vaisseau ennemi\n\n");     
      delete_enemy(ship);
    }
  else
    my_putstr("il n y a pas d'ennemi \n");
}

void	energy(t_ship	*ship)
{
  if (!ship)
    return;
  my_putstr_color("green","\n\nCaptain Wahou la forme  xD\n\n");
  ship->ftl_drive->energy = 1000;
}


void    immortal(t_ship   *ship)
{
  if (!ship)
    return;
  my_putstr_color("green","\n\nLongue vie Captain xD\n\n");
  ship->hull = 1000;
}

void	pop(t_ship	*ship)
{
  int	i;
  
  if (!ship)
    return;
  ship->enemy = malloc(sizeof(t_enemy));
  if (!ship->enemy)
    return;
  my_putstr("point de vie ennemi : \n");
  i = ajout();
  if (i == 0)
    return; 
  ship->enemy->hull = i;
  my_putstr("Damage ennemi : \n");
  i = ajout();
  if (i == 0)
    return;
  ship->enemy->damage = i;
  my_putstr("evade ennemi : \n");
  i = ajout();
  if (i == 0)
    return;
  ship->enemy->evade = i;
  ship->navigation_tools->enemy = 1;
}

int	ajout()
{
  char	*str;
  int	i;

  str = readline();
  if (!str)
    return (0);
  i = my_getnbr(str);
  free(str);
  return (i);
}
