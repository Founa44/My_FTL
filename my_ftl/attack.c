/*
** attack.c for attack in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Wed Apr 11 21:30:41 2018 Founa Ben Chaabane
** Last update Sat Apr 14 12:51:45 2018 Founa Ben Chaabane
*/

#include "ftl.h"

void	attack(t_ship	*ship)
{
  if (my_strcmp(ship->weapon->system_state,"online") != 0)
    my_putstr_color("red","Votre système d'armement est en panne. \n");
  else if (ship->navigation_tools->enemy == 0)
    my_putstr_color("cyan","aucun enemi detecté\n");
  else if (my_random(ship->enemy->evade) == 1)
    {
      my_putstr_color("red", "Pas de chance! l'enemi a esquivé votre attaque\n");
      enemy_attack(ship);
      stat_hull(ship);
    }
  else
    {
      ship->enemy->hull -= ship->weapon->damage;
      my_putstr_color("green","Ennemi touché\n");
      my_putstr("L'equipe evalue les dégâts\n");
      if (ship->enemy->hull <= 0)
	delete_enemy(ship);
      else
	{
	  my_putstr("Aiie il est presque mort! ENCORE\n\n");
	  enemy_attack(ship);
	}
      stat_hull(ship);
    }
}
