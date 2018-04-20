/*
** game_loop.c for game_loop in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Tue Apr 10 18:03:22 2018 Founa Ben Chaabane
** Last update Sat Apr 14 12:57:04 2018 Founa Ben Chaabane
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"ftl.h"

 static const  t_game_loop game_loop[] =
   {
     {"attack", &attack},
     {"detect", &my_detect},
     {"jump", &jump},
     {"getbonus", &get_bonus},
     {"repair_system", &system_repair},
     {"control_system", &system_control},
     {"stat", &stat},
     {"help", &help},
     {"power", &power},
     {"immortal", &immortal},
     {"kill", &kill},
     {"energy", &energy},
     {"pop", &pop},
     {"cheat", &sheat},
     {NULL, NULL}
   };


char	control_replay()
{
  char *replay;
  char	c;
    
  my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
  my_putstr_color("cyan", "USAGE [attack, jump, getbonus, repair_system, ");
  my_putstr_color("cyan", "detect, control_system, stat]\n");
  replay = my_strdup("init");
  if (!replay)
    return (0);
  while (replay != NULL && replay[0] != 'y' && replay[0] != 'n')
    {
      my_putstr("Voulez vous recommencer ? [y,n]\n");
      replay = readline();
    }
  if (!replay)
    return (0);
  c = replay[0];
  free(replay);
  return (c);
}

char	*input_command()
{
  char	*input;
  char	*replay;

  replay = my_strdup("y");
  if (!replay)
    return (NULL);
  while (my_strcmp(replay, "y") == 0)
    {
      input = readline();
      if (input == NULL)
	{
	  my_putstr_color("red", "[SYSTEM FAILURE] : ");
	  my_putstr(" le lecteur de commande est bloqué!\n");
	  my_putstr("Voulez-vous recommencer ?[y/n]\n");
	  replay[0] = control_replay();
	}
      else
	{
	  free(replay);
	  replay = my_strdup("n");
	  if (!replay)
	    return (NULL);
	}
    }
  free(replay);
  return (input);
}

void	loop(t_ship	*ship,	int	max)
{
  int	flag;
  int	i;
  char	replay;
  char	*input;

  flag = 0;
  replay = 'y';
  while (flag == 0 && replay == 'y')
    {
      my_putstr_color("yellow","Choisissez une commande : \n");
      input = input_command();
      if (!input)
	return;
      i = 0;
      while (game_loop[i].name != NULL && flag == 0
	     && i <= max)
	{
	  if (my_strcmp(game_loop[i].name, input) == 0)
	    {
	      game_loop[i].psf(ship);
	      flag = 1;	
	    }
	  i++;
	}
      if (flag == 0)
	replay = control_replay();
    }
  free(input);
}

void	help()
{
  my_putstr_color("cyan","Bienvenue à FASTER THAN LIGHT\n\n");
  my_putstr("Pour gagner il faut atteindre le secteur 10 tout et en vie.\n");
  my_putstr("Vous infliger à l'ennemi autant de dégâts ");
  my_putstr("que la puissance de votre arme et inversement.\n");
  my_putstr("Suite à une attaque ennemi : \n");
  my_putstr("- votre % d'evitement pour l'eviter. \n");
  my_putstr("- 20% de chance qu'un de vos systèmes tombe en panne.\n");
  my_putstr("- 20% de chance qu'un de vos systèmes tombe en panne.\n\n");
  my_putstr("Si vous n'avez plus de points de vie vous êtes mort.\n");
  my_putstr("Si vous n'avez plus assez d'energie pour reparer");
  my_putstr(" vos systèmes en panne vous êtes mort.\n\n");
  my_putstr_color("cyan", "USAGE [attack, jump, getbonus, repair_system, ");
  my_putstr_color("cyan", "detect, control_system, stat]\n");
  my_putstr_color("cyan","\n\n---BON JEU---\n\n");
}

void	sheat()
{
  my_putstr("- immortal : point de vie à 1000.\n");
  my_putstr("- kill : tuer un ennemi.\n");
  my_putstr("- energy : energie à 1000.\n");
  my_putstr("- power : force du système d'armement à 1000.\n");
  my_putstr("- pop : crée un nv ennemi en choisissant ses carac.\n");
}
