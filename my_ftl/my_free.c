/*
** free.c for free in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Mon Apr  9 14:43:56 2018 Founa Ben Chaabane
** Last update Fri Apr 13 16:16:49 2018 Founa Ben Chaabane
*/

#include <stdlib.h>
#include "ftl.h"

void	my_free(t_ship* ship)
{
  t_freight	*tmp;
  
  free(ship->weapon->system_state);
  free(ship->ftl_drive->system_state);
  free(ship->navigation_tools->system_state);
  while (ship->container->last)
    {
      tmp = ship->container->last;
      ship->container->last = ship->container->last->prev;
      free(tmp->item);
      free(tmp);
    }
  free(ship->navigation_tools);
  free(ship->weapon);
  free(ship->ftl_drive);
  free(ship->container);
  if (ship->enemy)
    free(ship->enemy);
  free(ship);
}
