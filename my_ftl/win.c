/*
** win.c for win in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Thu Apr 12 05:27:05 2018 Founa Ben Chaabane
** Last update Fri Apr 13 21:11:39 2018 Founa Ben Chaabane
*/

#include "ftl.h"

int	win(t_ship	*ship)
{
  if (ship->navigation_tools->sector >= 10
     && ship->hull > 0)
    {
      my_putstr_color("cyan","\n\nFELICITATIONS CAPTAIN TU DECHIRE!!\n\n");
      stat(ship);
      return (1);
    }
  else
    return (0);
}
