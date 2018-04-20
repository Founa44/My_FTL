/*
** main.c for main.c in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Mon Apr  9 11:17:35 2018 Founa Ben Chaabane
** Last update Sat Apr 14 13:03:36 2018 Founa Ben Chaabane
*/

#include "ftl.h"

int	check_args(int argc, char **argv)
{
  if (!argc && !argv)
    return (0);
  if (argc == 1)
    return (7);
  if (argc == 3)
    {
      if (my_strcmp(argv[1], "--version") == 0
	  || my_strcmp(argv[1], "-v") == 0)
	{
	  if (my_strcmp(argv[2], "dev") == 0)
	    return (13);
	  return (0);
	}
      else
	{
	  my_putstr("Command failure\n");
	  return (0);
 	}
    }
  return (0);  
}
int	main(int argc, char **argv)
{
   t_ship	*p_ship;
   int	max;

   my_putstr("\033[H\033[2J");
   max = check_args(argc, argv);
   if (max == 0)
     return (1);
   p_ship = create_ship();
   if (!p_ship)
     return (1);
   srand (time (NULL));
   if (!add_weapon_to_ship(p_ship))
     return (1);
   if (!add_ftl_drive_to_ship(p_ship))
     return (1);
   if (!add_navigation_tools_to_ship(p_ship))
     return (1);
   if (!add_container_to_ship(p_ship))
     return (1);
   while (win(p_ship) != 1 && lose(p_ship) !=1)
     {
       loop (p_ship, max);
     }
   my_free(p_ship);
   return (0);
}
