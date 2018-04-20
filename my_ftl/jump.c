/*
** jump.c for jump.c in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Tue Apr 10 20:18:47 2018 Founa Ben Chaabane
** Last update Fri Apr 13 19:22:19 2018 Founa Ben Chaabane
*/

#include <stdlib.h>
#include "ftl.h"

void	jump(t_ship *ship)
{
  if (my_strcmp(ship->ftl_drive->system_state, "online") != 0)
    my_putstr_color("red","Votre ftl_drive est en panne.\n");
  else if (win(ship) == 1)
    win(ship);
  else if (lose(ship) == 1)
    lose(ship);
  else if (ship->navigation_tools->detect == 1
	   && ship->navigation_tools->bonus == 0)
    my_putstr("Il y a encore du bonus à collecter Captain\n");
  else if (ship->navigation_tools->enemy == 1)
    my_putstr("Il y a encore un ennemie dans le secteur\n");
  else
    {
      ship->navigation_tools->sector ++;
      my_putstr("\n\n***SECTEUR : ");
      my_put_nbr(ship->navigation_tools->sector);
      my_putstr("***\n");
      ship->navigation_tools->detect = 0;
      ship->navigation_tools->bonus = 0;
      ship->weapon->damage ++;
      create_enemy(ship);
      if (my_random(50) == 1)
	ship->ftl_drive->energy--;
    }
}
