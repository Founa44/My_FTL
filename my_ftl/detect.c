/*
** detect.c for detect in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Wed Apr 11 22:18:44 2018 Founa Ben Chaabane
** Last update Fri Apr 13 14:14:06 2018 Founa Ben Chaabane
*/

#include "ftl.h"

void	my_detect(t_ship	*ship)
{
  if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
    my_putstr_color("red","Votre système de navigation est en panne.\n" );
  else if (ship->navigation_tools->detect == 1)
    my_putstr_color("red", "Du calme captain vous avez deja detecté ici\n");
  else
    {
      my_putstr("Fonction detect\n");
      while (ship->container->nb_elem  < 10)
	add_freight_to_container(ship, create_freight());
      ship->navigation_tools->detect = 1;
      if (ship->navigation_tools->enemy == 1)
	{
	  my_putstr("\nIl y a un ennemi dans le secteur! A L'ATTAQUE..\n");
	  enemy_attack(ship);
	}
      else
	my_putstr("\nCaptain Tranquil 0 ennemi dans les parages \n");
    }
}
