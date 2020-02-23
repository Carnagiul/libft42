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
	char			*(*free)(struct s_player *this);
}					t_player;

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

void				freePlayer(t_player *this)
{

	if (this->nameMalloc)
		free(this->name);
	free(this);
}

t_player			*create_player()
{
	t_player *player;

	player = (t_player *)malloc(sizeof(t_player));
	player->setName = &setNamePlayer;
	player->getName = &getNamePlayer;
	player->getName = &freePlayer;
	player->nameMalloc = false;
	return player->setName(player, "Arthur");
}

int main(void)
{
	t_player	*player;

	player = create_player();
	printf("%s\n", player->getName(player));
	player->free(player);
	printf("Player free\n");
	return 0;
}
