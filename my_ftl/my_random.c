/*
** my_random.c for my_random in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Wed Apr 11 19:10:29 2018 Founa Ben Chaabane
** Last update Fri Apr 13 14:45:21 2018 Founa Ben Chaabane
*/

#include	"ftl.h"

int	my_random(int percent)
{
  int i;

  i = (rand()%100);
  if (i <= percent)
    return (1);
  else
    return (0);
}
