#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef int bool;
# define false	1
# define true	0

typedef struct		s_player
{
	char			*name;
	bool			nameMalloc;
	struct s_player	*(*setName)(struct s_player *this, char *name);
	char			*(*getName)(struct s_player *this);


	int				health;
	struct s_player	*(*setHealth)(struct s_player *this, int health);
	int				(*getHealth)(struct s_player *this);
	struct s_player	*(*addHealth)(struct s_player *this, int health);
	struct s_player	*(*removeHealth)(struct s_player *this, int health);
	int				max_health;
	struct s_player	*(*setMaxHealth)(struct s_player *this, int health);
	int				(*getMaxHealth)(struct s_player *this);
	struct s_player	*(*addMaxHealth)(struct s_player *this, int health);
	struct s_player	*(*removeMaxHealth)(struct s_player *this, int health);
	struct s_player	*(*checkHealth)(struct s_player *this);



	void			(*free)(struct s_player *this);
	struct s_player	*(*clone)(struct s_player *this);
	void			(*dump)(struct s_player *this);
}					t_player;


t_player			*setNamePlayer(t_player *this, char *name);
char				*getNamePlayer(t_player *this);
t_player			*checkHealthPlayer(t_player *this);
t_player			*setHealthPlayer(t_player *this, int value);
t_player			*addHealthPlayer(t_player *this, int value);
t_player			*removeHealthPlayer(t_player *this, int value);
t_player			*setMaxHealthPlayer(t_player *this, int value);
t_player			*addMaxHealthPlayer(t_player *this, int value);
t_player			*removeMaxHealthPlayer(t_player *this, int value);
void				freePlayer(t_player *this);
t_player			*clonePlayer(t_player *player);
void				dumpPlayer(t_player *this);
t_player			*initPlayer(void);
t_player			*createPlayer(void);

t_player			*setNamePlayer(t_player *this, char *name)
{
	if (this->nameMalloc)
		free(this->name);
	this->name = strdup(name);
	this->nameMalloc = true;
	return this;
}

char				*getNamePlayer(t_player *this)
{
	return this->name;
}

t_player			*checkHealthPlayer(t_player *this)
{
	if (this->health > this->max_health)
		this->health = this->max_health;
	if (this->health < 0)
		this->health = 0;
	return this;
}


t_player			*setHealthPlayer(t_player *this, int value)
{
	this->health = value;
	return this->checkHealth(this);
}

t_player			*addHealthPlayer(t_player *this, int value)
{
	this->health += value;
	return this->checkHealth(this);
}

t_player			*removeHealthPlayer(t_player *this, int value)
{
	this->health -= value;
	return this->checkHealth(this);
}

t_player			*setMaxHealthPlayer(t_player *this, int value)
{
	this->max_health = value;
	return this->checkHealth(this);
}

t_player			*addMaxHealthPlayer(t_player *this, int value)
{
	this->health += value;
	return this->checkHealth(this);
}

t_player			*removeMaxHealthPlayer(t_player *this, int value)
{
	this->health -= value;
	return this->checkHealth(this);
}


void				freePlayer(t_player *this)
{
	if (this->nameMalloc)
		free(this->name);
	free(this);
}

t_player			*clonePlayer(t_player *player)
{
	t_player *this;

	this = initPlayer();
	this->nameMalloc = this->nameMalloc;
	return this->setName(this, player->getName(player));
}

void			dumpPlayer(t_player *this)
{
	printf("DUMPING PLAYER\n");
	printf("PLAYER NAME : %s\n", this->name);
	printf("PLAYER NAME MALLOC : %s\n", (this->nameMalloc == true) ? "true" : "false");
	printf("PLAYER CURRENT HEALTH: %i\n", this->health);
	printf("PLAYER CURRENT MAX HEALTH: %i\n", this->max_health);
}

t_player			*initPlayer(void)
{
	t_player *this;

	this = (t_player *)malloc(sizeof(t_player));
	this->setName = &setNamePlayer;
	this->getName = &getNamePlayer;
	this->free = &freePlayer;
	this->clone = &clonePlayer;
	this->dump = &dumpPlayer;
	this->health = 100;
	this->max_health = 100;
	this->setHealth = &setHealthPlayer;
	this->addHealth = &addHealthPlayer;
	this->removeHealth = &removeHealthPlayer;
	this->setMaxHealth = &setMaxHealthPlayer;
	this->addMaxHealth = &addMaxHealthPlayer;
	this->removeMaxHealth = &removeMaxHealthPlayer;
	this->checkHealth = &checkHealthPlayer;
	return this;
}

t_player			*createPlayer(void)
{
	t_player *this;

	this = initPlayer();
	this->nameMalloc = false;
	return this->setName(this, "Arthur");
}

int main(void)
{
	t_player	*player;

	player = createPlayer();
	player->dump(player);
	player->free(player);
	return 0;
}
