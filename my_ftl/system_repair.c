/*
** system_repair.c for system_repair in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Mon Apr  9 21:44:16 2018 Founa Ben Chaabane
** Last update Fri Apr 13 21:04:18 2018 Founa Ben Chaabane
*/

#include "ftl.h"

void	ftl_drive_system_repair(t_ship *ship)
{
  if (my_strcmp(ship->ftl_drive->system_state, "online") != 0
      && ship->ftl_drive->energy >1)
    {
      my_putstr_color("magenta", "reparation du reacteur en cours...\n");
      free(ship->ftl_drive->system_state);
      ship->ftl_drive->system_state = my_strdup("online");
      ship->ftl_drive->energy --;
      if (!ship->ftl_drive->system_state)
	return;
    }
  else if (ship->ftl_drive->energy < 1)
    my_putstr("Energie insuffisante.\n");
  if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
    my_putstr("reparation terminée! systeme reacteur OK!\n");
  else
    my_putstr("les reparations du reacteur ont echoué\n");
}


void    navigation_tools_system_repair(t_ship *ship)
{
  if (my_strcmp(ship->navigation_tools->system_state, "online") != 0
      && ship->ftl_drive->energy >1)
    {
      my_putstr_color("magenta", "reparation du système de navigation ");
      my_putstr_color("magenta", "en cours...\n");
      free(ship->navigation_tools->system_state);
      ship->navigation_tools->system_state = my_strdup("online");
      ship->ftl_drive->energy --;
      if (!ship->navigation_tools->system_state)
	return;
    }
  else if (ship->ftl_drive->energy < 1)
    my_putstr("Energie insuffisante.\n");
  if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    my_putstr("reparation terminée! systeme de navigation OK!\n");
  else
    my_putstr("les reparations du système de navigation ont echoué\n"); 
}

void    weapon_system_repair(t_ship *ship)
{
  if (my_strcmp(ship->weapon->system_state, "online") != 0
    && ship->ftl_drive->energy >1)
    {
      my_putstr_color("magenta", "reparation du system d'armement en cours\n");
      free(ship->weapon->system_state);
      ship->weapon->system_state = my_strdup("online");
      ship->ftl_drive->energy --;
      if (!ship->weapon->system_state)
	return;
    }
    else if (ship->ftl_drive->energy < 1)
      my_putstr("Energie insuffisante.\n");
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
    my_putstr("reparation terminée! systeme d'armement OK!\n");
  else
    my_putstr("les reparations du système d'armement ont echoué\n");
}

 static const  t_repair_command repair[] =
   {
     {"ftl_drive", &ftl_drive_system_repair},
     {"navigation_tools", &navigation_tools_system_repair},
     {"weapon", &weapon_system_repair},
     {NULL, NULL}
   };

void	system_repair(t_ship *ship)
{
  int	i;
  int	flag;
  char	*input;

  my_putstr_color("red","repair_system~> ");
  input = readline();
  i = 0;
  flag = 0;
  while (repair[i].name != NULL && flag != 1)
    {
      if (my_strcmp(repair[i].name, input) == 0)
	{
	  repair[i].psf(ship);
	  flag = 1;
	}
      i++;
    }
  if (input == NULL)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : ");
      my_putstr("le lecteur de commande est bloqué\n");
    }
  else if (i > 3)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
      my_putstr_color("cyan", "USAGE [ftl_drive, navigation_drive, weapon]\n");
    }
  free(input);
}
