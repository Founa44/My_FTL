/*
** enemy.c for enemy in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Wed Apr 11 15:49:20 2018 Founa Ben Chaabane
** Last update Fri Apr 13 21:17:19 2018 Founa Ben Chaabane
*/

#include	"ftl.h"

void	create_enemy(t_ship	*ship)
{
  static int damage_prec = 7;

  if (my_random(30) == 1)
    {
      ship->enemy = malloc(sizeof(t_enemy));
      if (!ship->enemy)
	return;
      ship->enemy->hull = 20;
      ship->enemy->damage = damage_prec + (damage_prec / 2);
      damage_prec = ship->enemy->damage;
      ship->navigation_tools->enemy = 1;
      ship->enemy->evade = damage_prec;
      my_putstr_color("red","\nATTENTION! Un ennemi vient de surgir!!\n\n");
      my_putstr_color("magenta","Caracteristique Ennemi : \n");
      my_putstr("Points de vie : \t");
      my_put_nbr(ship->enemy->hull);
      my_putstr("\n");
      my_putstr("Damages : \t");
      my_put_nbr(ship->enemy->damage);
       my_putstr("\n");
      my_putstr("% evadement : \t");
      my_put_nbr(ship->enemy->evade);
       my_putstr("\n");
    }
}

void	delete_enemy(t_ship	*ship)
{
  free(ship->enemy);
  ship->navigation_tools->enemy = 0;
  my_putstr_color("\ngreen", "Bimmm Enemie détruit!!! \n");
}

void	enemy_attack(t_ship *ship)
{
  if (my_random(ship->navigation_tools->evade) == 1)
    {
      my_putstr_color("green","LA CHANCE ! attaque ennemie evitée\n");
    }
  else
    {
      my_putstr_color("red","Suite à une attaque d'ennemie vous etes touché\n");
      ship->hull -= ship->enemy->damage;
      if (my_random(20) == 1)
	{
	  my_putstr_color("red","PAS DE CHANCE! ");
	  panne_system(ship);
	}
      else
	my_putstr_color("green", "OUFF! aucune panne signalée \n");
    }
}

void	panne_system(t_ship	*ship)
{
  int	i;

  i = (rand()%3);
  if (i == 0)
    {
      free(ship->ftl_drive->system_state);
      ship->ftl_drive->system_state = my_strdup("down");
      if (!ship->ftl_drive->system_state)
	return;
      my_putstr_color("red","ftl_drive est en panne...\n");
    }
   if (i == 1)
    {
      free(ship->navigation_tools->system_state);
      ship->navigation_tools->system_state = my_strdup("down");
      if (!ship->navigation_tools->system_state)
	return;
      my_putstr_color("red","Votre système de navigation est en panne...\n");
    }
   if (i == 2)
    {
      free(ship->weapon->system_state);
      ship->weapon->system_state = my_strdup("down");
      if (!ship->weapon->system_state)
	return;
      my_putstr_color("red","votre système d'armement est en panne...\n");
    }
}
