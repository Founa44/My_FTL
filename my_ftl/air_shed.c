/*
** air_shed.c for air_shed.c in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Mon Apr  9 11:38:14 2018 Founa Ben Chaabane
** Last update Fri Apr 13 18:56:29 2018 Founa Ben Chaabane
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"

int	add_weapon_to_ship(t_ship *ship)
{
  ship->weapon = malloc(sizeof(t_weapon));
  if (!ship->weapon)
    return (0);
  ship->weapon->system_state = my_strdup("online");
  if (!ship->weapon->system_state)
    return (0);
  ship->weapon->damage = 10;
  my_putstr_color("magenta", "ajout des armes en cours...\n");
  if (my_strcmp(ship->weapon->system_state, "online") == 0 && ship->weapon->damage == 10)
    {
      my_putstr("les armes on ete ajoutés avec succes!\n\n");
      return (1);
    }
  else
    {
      my_putstr("votre vaisseau a explosé quand vous avez tente d'ajouter les armes\n");
      return (0);
    }
}

int	add_ftl_drive_to_ship(t_ship	*ship)
{
  ship->ftl_drive = malloc(sizeof(t_ftl_drive));
  if (!ship->ftl_drive)
    return (0);
  ship->ftl_drive->energy = 10;
  ship->ftl_drive->system_state = my_strdup("online");
  if (!ship->ftl_drive->system_state)
    return (0);
  my_putstr_color("magenta","ajout du reacteur en cours...\n");
  if (my_strcmp(ship->ftl_drive->system_state, "online") == 0
      && ship->ftl_drive->energy == 10)
    {
      my_putstr("le reacteur a ete ajouté avec succes!\n\n");
      return (1);
    } else
    {
      my_putstr( "votre vaisseau a explosé lorsque vous avez posé le reacteur\n");
      return (0);
    }
}

int	add_navigation_tools_to_ship(t_ship	*ship)
{
  ship->navigation_tools = malloc(sizeof(t_navigation_tools));
  if (!ship->navigation_tools)
    return (0);
  ship->navigation_tools->system_state = my_strdup("online");
  if (!ship->navigation_tools->system_state)
    return (0);
  ship->navigation_tools->sector = 0;
  ship->navigation_tools->enemy = 0;
  ship->navigation_tools->evade = 25;
  ship->navigation_tools->detect = 0;
  ship->navigation_tools->bonus = 0;
  
  my_putstr_color("magenta","ajout des outils de navigations...\n");
  if (my_strcmp(ship->navigation_tools->system_state, "online") == 0
      && ship->navigation_tools->sector == 0
      &&  ship->navigation_tools->evade == 25)
    {
      my_putstr("les outils de navigations ont ete ajoutes avec succes!\n\n");
      return (1);
    }
  else
    {
      my_putstr("votre vaisseau a explose lorsque vous avez ");
      my_putstr("posé les outils de navigations.\n");
      return (0);
    }
}

t_ship	*create_ship()
{
  t_ship	*p_ship;

  p_ship = malloc(sizeof(t_ship));
  if (!p_ship)
    return (NULL);
  p_ship->hull = 50;
  p_ship->weapon = NULL;
  p_ship->ftl_drive = NULL;
  p_ship->navigation_tools = NULL;
  p_ship->container = NULL;
  my_putstr_color("magenta", "construction du vaisseau en cours...\n");
  if (p_ship->hull != 50)
    {
      my_putstr("le vaisseau n'a pas pu etre construit par manque de ");
      my_putstr("de materiaux\n");
      return (NULL);
    }
  else
    {
      my_putstr("amelioration du vaisseau terminée!\n\n");
      return (p_ship);
    }
}
