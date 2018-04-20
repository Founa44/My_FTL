/*
** stat.c for stat in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Wed Apr 11 22:54:43 2018 Founa Ben Chaabane
** Last update Sun Apr 15 19:38:50 2018 Founa Ben Chaabane
*/

#include "ftl.h"

void	stat(t_ship *ship)
{
  my_putstr_color("yellow","\nEtat de votre vaisseau : \n");
  my_putstr("Point de vie : ");
  my_put_nbr(ship->hull);
  my_putstr("\nSystème d'armement : \n\t system_state : ");
  my_putstr(ship->weapon->system_state);
  my_putstr("\n\t damage : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr("\nSystème de navigation : \n\t system_state : ");
  my_putstr(ship->navigation_tools->system_state);
  my_putstr("\n\t secteur : ");
  my_put_nbr(ship->navigation_tools->sector);
  my_putstr("\n\t valeur d'évitement : "); 
  my_put_nbr(ship->navigation_tools->evade);
  my_putstr("\n\t ennemi présent : "); 
  my_put_nbr(ship->navigation_tools->enemy);
  my_putstr("\nFTL drive : \n\t system_state : ");
  my_putstr(ship->ftl_drive->system_state);
  my_putstr("\n\t Energie : ");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr_color("yellow","\nthat's all\n");
  
}

void	stat_hull(t_ship	*ship)
{
  my_putstr_color("magenta", "\nPoints de vie restants :\n");
  my_putstr_color("cyan", "Vous : \t");
  my_put_nbr(ship->hull);
  my_putstr_color("cyan", "\nEnnemi : \t");
  my_put_nbr(ship->enemy->hull);
  my_putstr("\n\n");
}
