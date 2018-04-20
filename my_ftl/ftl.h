/*
** ftl.h for ftl.h in /home/founauser/My_FTL
** 
** Made by Founa Ben Chaabane
** Login   <bencha_f@etna-alternance.net>
** 
** Started on  Mon Apr  9 10:55:33 2018 Founa Ben Chaabane
** Last update Sat Apr 14 13:14:50 2018 Founa Ben Chaabane
*/

#ifndef	__FICHIER_H_
#define __FICHIER_H_

#include	<stdlib.h>
#include	<unistd.h>
#include	<time.h>

typedef struct s_enemy
{
  int	evade;
  int	damage;
  int	hull;
}	t_enemy;

typedef	struct	s_freight
{
  char*	item;
  struct	s_freight*	next;
  struct	s_freight*	prev;
}	t_freight;

typedef	struct	s_container
{
  t_freight*	first;
  t_freight*	last;
  int		nb_elem;
}	t_container;

typedef struct	s_navigation_tools
{
  char*	system_state;
  int	sector;
  int	enemy;
  int	detect;
  int	bonus;
  int	evade;
}	t_navigation_tools;

typedef struct	s_ftl_drive
{
  char*	system_state;
  int	energy;
}	t_ftl_drive;

typedef struct  s_weapon
{
  char*	system_state;
  int   damage;
}       t_weapon;

typedef	struct	s_ship
{
  int			hull;
  t_weapon*		weapon;
  t_ftl_drive*		ftl_drive;
  t_navigation_tools*	navigation_tools;
  t_container*		container;
  t_enemy*		enemy;
}	t_ship;

typedef	struct	s_repair_command
{
  char	*name;
  void	(*psf)(t_ship*);
  
}	t_repair_command;

typedef	struct	s_game_loop
{
  char	*name;
  void	(*psf)(t_ship*);
  
}	t_game_loop;

t_ship	*create_ship();
void	weapon_system_repair(t_ship *);
void	navigation_tools_system_repair(t_ship *);
void	ftl_drive_system_repair(t_ship *);
void	system_repair(t_ship *);
void    ftl_drive_system_check(t_ship *);
void    navigation_tools_system_check(t_ship *);
void	weapon_system_check(t_ship *);
void    system_control(t_ship *);
void	get_bonus(t_ship*);
void	del_freight_from_container(t_ship*, t_freight*);
void	add_freight_to_container(t_ship*, t_freight*);
int	add_container_to_ship(t_ship*);
int	add_navigation_tools_to_ship(t_ship*);
int	add_ftl_drive_to_ship(t_ship*);
int	add_weapon_to_ship(t_ship*);
char	*readline(void);
char	control_replay();
char	*input_command();
void	loop(t_ship*, int);
void	my_free(t_ship*);
void    my_put_nbr(int);
int     my_getnbr(char*);
void	my_putchar(char);
int	my_strlen(char*);
int	my_strcmp(char*, char*);
void	my_putstr(char*);
char	*my_strdup(char*);
void	my_putstr_color(char*, char*);
void	create_enemy(t_ship*);
int	my_random(int);
void	create_enemy(t_ship*);
int	lose(t_ship*);
void	panne_system(t_ship*);
void	enemy_attack(t_ship*);
void	my_detect(t_ship*);
void	delete_enemy(t_ship*);
void	stat(t_ship*);
void	stat_hull(t_ship*);
t_freight	*create_freight();
void	jump(t_ship*);
void	attack(t_ship*);
int	win(t_ship*);
void	help();
void	power(t_ship*);
void	kill(t_ship*);
void	energy(t_ship*);
void	immortal(t_ship*);
int	check_args(int, char**);
void	sheat();
void	pop(t_ship*);
int	ajout();

#endif	/*!__FICHIER_H_ */
