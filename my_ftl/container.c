/*
** container.c for container.C in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Mon Apr  9 17:02:58 2018 Founa Ben Chaabane
** Last update Fri Apr 13 20:56:02 2018 Founa Ben Chaabane
*/

#include <stdlib.h>
#include "ftl.h"

void	get_bonus(t_ship *ship)
{
  t_freight	*tmp;
  
  if (ship->navigation_tools->bonus == 1)
    my_putstr("Du calme captain le bonus c'est une seule fois\n");
  else
    {
      my_putstr_color("magenta", "Bonus Loading....\n");
      while (ship->container->first != NULL
	     && ship->navigation_tools->detect == 1
	     && ship->navigation_tools->bonus == 0)
	{
	  tmp = ship->container->first;
	  if (my_strcmp(tmp->item, "attackbonus") == 0)
	    {
	      ship->weapon->damage += 5;
	      my_putstr_color("yellow", "+5 de dommages aux armes. Total : ");
	      my_put_nbr(ship->weapon->damage);
	      my_putstr("\n");
	    }
	  if (my_strcmp(tmp->item, "evadebonus") == 0)
	    {
	      ship->navigation_tools->evade += 3;
	      my_putstr_color("yellow", "+3 au evasion du système. Total : ");
	      my_put_nbr(ship->navigation_tools->evade);
	      my_putstr("\n");
	    }
	  if (my_strcmp(tmp->item, "energy") == 0)
	    {
	      ship->ftl_drive->energy += 1;
	      my_putstr_color("yellow", "+1 à l'énergie du réacteur. Total : ");
	      my_put_nbr(ship->ftl_drive->energy);
	      my_putstr("\n");
	    }
	  tmp = ship->container->first->next;
	  del_freight_from_container(ship, ship->container->first);
	  ship->container->first = tmp;
	  ship->container->nb_elem --;
	}
      ship->container->first = NULL;
      ship->container->last = NULL;
      ship->navigation_tools->bonus = 1;
    }
}

void	del_freight_from_container(t_ship* ship, t_freight* freight)
{
  t_freight	*tmp;

  tmp = ship->container->first;
  while (tmp != NULL && tmp != freight)
    tmp = tmp->next;
  if (tmp == NULL)
    {
      return ;
    }
  if (tmp->prev != NULL)
    tmp->prev->next = tmp->next;
  else
    ship->container->first = tmp->next;
  if (tmp->next != NULL)
    tmp->next->prev = tmp->prev;
  else
    ship->container->last = tmp->prev;
  free(freight->item);
  free(freight);
 }

void	add_freight_to_container(t_ship	*ship, t_freight	*freight)
{
  if (!freight)
    return;
  if ( ship->container == NULL)
    add_container_to_ship(ship);
  if (ship->container->first == NULL && ship->container->last == NULL)
    {
      freight->next = NULL;
      freight->prev = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
      ship->container->nb_elem = 1;
      my_putstr(freight->item );
      my_putstr_color("green", ":  is your first freight found\n");
    }
  else
    {
      freight->next = NULL;
      freight->prev = ship->container->last;
      ship->container->last->next = freight;
      ship->container->last = freight;
      ship->container->nb_elem += 1;
      my_putstr(freight->item );
      my_putstr_color("green", ":  has been found\n");
    }
}

int	add_container_to_ship(t_ship	*ship)
{
  t_container	*container;
  
  container = malloc(sizeof(t_container));
  if (!container)
    return (0);
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  my_putstr_color("magenta", "ajout du container en cours...\n");
  if (ship->container->first == NULL && ship->container->last == NULL
      && ship->container->nb_elem == 0)
    {
      my_putstr("le container a été ajouté avec succès!\n");
      return (1);
    }
  else
    {
      my_putstr("votre vaisseau a explosé lorsque vous avez posé ");
      my_putstr("le container \n");
      return (0);
    }
}

t_freight	*create_freight()
{
  int	r;
  t_freight	*freight;

  freight = malloc(sizeof(t_freight));
  if (!freight)
    return (NULL);
  if (my_random(70) == 1)
    freight->item = my_strdup("scrap");
  else
    {
      r = (rand()%100);
      if (r < 33)
	freight->item = my_strdup("energy");
      if (r >= 33 && r < 66)
	freight->item = my_strdup("attack");
      if (r >= 66 && r < 99)
	freight->item = my_strdup("evadebonus");
      if (r == 9)
	freight->item = my_strdup("scrap");
    }
  if (!freight->item)
    return (NULL);
  return (freight);
}
