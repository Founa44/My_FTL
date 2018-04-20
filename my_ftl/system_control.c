/*
** system_control.c for system_control.c in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Mon Apr  9 21:02:14 2018 Founa Ben Chaabane
** Last update Mon Apr  9 21:37:40 2018 Founa Ben Chaabane
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("magenta", "verification du reacteur en cours...\n");
  if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
    my_putstr("reacteur OK!\n");
  else
    my_putstr("reacteur hors service!\n");
}


void    navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("magenta", "verification du système de navigation en cours...\n");
  if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    my_putstr("système de navigation OK!\n");
  else
    my_putstr("système de navigation hors service!\n");
}


void    weapon_system_check(t_ship *ship)
{
  my_putstr_color("magenta", "verification du système d'armement en \
cours...\n");
  if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    my_putstr("système d'armement OK!\n");
  else
    my_putstr("système d'armement hors service!\n");
}

void	system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}
