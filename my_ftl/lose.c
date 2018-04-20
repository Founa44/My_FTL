/*
** lose.c for lose in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Wed Apr 11 19:21:59 2018 Founa Ben Chaabane
** Last update Fri Apr 13 21:11:58 2018 Founa Ben Chaabane
*/

#include "ftl.h"

int	lose(t_ship	*ship)
{
  if (ship->ftl_drive->energy == 0)
    {
      my_putstr_color("red", "\n\nYOU ARE DEAD!\n\n");
      stat(ship);
      return (1);
    }
  if (my_strcmp(ship->weapon->system_state, "online\0") != 0
      && my_strcmp(ship->ftl_drive->system_state, "online\0") != 0
      && my_strcmp(ship->navigation_tools->system_state, "online\0") != 0
      && ship->ftl_drive->energy < 1)
    {
      my_putstr_color("red", "\n\nYOU ARE DEAD!\n\n");
      my_putstr("Tous vos systèmes sont en pannes et pas assez d'energie");
      stat(ship);
      return (1);
    }
  if (ship->hull <= 0)
    {
      stat(ship);
      my_putstr_color("red", "\n\nYOU ARE DEAD!\n\n");
      return (1);
    }
  return (0);
}
