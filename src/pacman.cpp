#include "../inc/game.h"
#include "../inc/personnage.h"
#include "../inc/ghost.h"
#include "../inc/pacman.h"
#include "../inc/graine.h"
#include "../inc/recompense.h"

SDL_Window* pWindow = nullptr;
SDL_Surface* win_surf = nullptr;
SDL_Surface* plancheSprites = nullptr;


int coun;

void init_walls(Board *b)
{
	//Voir pour ensuite confondre la map dans le jeu en entier 
	int nb_murs = b->getMap().getMurs().size();
	for(int i = 0 ; i < nb_murs; i++) {
		SDL_Rect seed = (lgum);// pour simuler le mur 
		SDL_Rect *mur = (b->getMap().getMur_with_index(i));
		SDL_BlitScaled(plancheSprites, &seed, win_surf, mur);
	}
}

void init_seeds(Board *b)
{	
	//On évite le surplus et la superposition de graine 
	//en signifiant que les graines sont toutes à la verticales
	//Ce n'est donc que elles qui comptent 
	//On saute donc sur x toutes celle qui pourrait faire office de croisement

		
	//On fait pour le moment une version simple sans classe 
	int x = 46+(32); // reference pour les horizontales
	int y = 46;		//+32 aussi pour les verticales
	int w = 6; // *3
	int h = 6; // *3
	// *********************************************Les horizontales *************************************************//
	for(int i = 0 ; i < 12 ; i++) {
		if((i == 3) || (i == 9))
			x += 32;
		if(i == 6)
			x += 96;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 32;
	}
	//PLACEMENT DANS LE BOARD//
	cout << b->get_tab_elem().size() << endl;

	//La seconde horizontale en partant d'en haut à gauche
	y = 46+(32*4); 
	x = 46+(32);
	for(int i = 0 ; i < 11 ; i++) {
		if((i == 3) || (i == 4) || (i == 5) || (i == 6) || (i == 7) || (i == 8))
			x += 32;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 32;
	}
	//La troisième horizontale en partant d'en haut à gauche
	y = 46+(32*7);
	x = 46+(32);
	for(int i = 0 ; i < 8 ; i++) {
		if((i == 3) || (i == 4) || (i == 5))
			x += 96; //saut de 3 cases
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 32;
	}
	//La quatrieme horizontale 
	y = 46+(32*17);
	x = 46+(32);
	for(int i = 0 ; i < 8 ; i++) {
		// a opti ici -> trop de comparaison à faire 
		if((i == 1) || (i == 2) || (i == 3) || (i == 5) || (i == 6) || (i == 7))
			x += 32; //saut de 1 case
		if(i == 4)
			x += 96;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 32;
	}
	//La cinquieme horizontale 
	y = 46+(32*19);
	x = 46+(32);
	for(int i = 0 ; i < 7 ; i++) {
		if((i == 2) || (i == 3) || (i == 4) || (i == 5))
			x += 32; //saut de 1 case
		if((i == 1) || (i == 6))
			x += 96;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 32;
	}
	//La sizieme horizontale en partant d'en haut à gauche
	y = 46+(32*22);
	x = 46+(32);
	for(int i = 0 ; i < 6 ; i++) {
		if((i == 2) || (i == 3) || (i == 4))
			x += 96;
		if((i == 1) || (i == 5))
			x += 32;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 32;
	}	
	//La septieme 
	y = 46+(32*24);
	x = 46+(32);
	for(int i = 0 ; i < 9 ; i++) {
		if((i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 6)
			|| (i == 7) || (i == 8))
			x += 32;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		x += 32;
	}

	// ************************************Les verticales********************************************************************** //
	//La verticale en haut à gauche
	x = 46;
	y = 46;
	for(int i = 0 ; i < 14 ; i++) {
		if(i == 8)
			y += 32*9;
		if(i == 11)
			y += 64;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//La seconde verticale en partant de la gauche 
	x = 46+(32*4);
	y = 46;
	for(int i = 0 ; i < 24 ; i++) {
		if(i == 23)
			y += 32;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//La troisieme verticale en partant de la gauche 
	x = 46+(32*6);
	y = 46+(32*4);
	for(int i = 0 ; i < 10 ; i++) {
		if(i == 4) 
			y += 32*9;
		if((i == 5) || (i == 9))
			y += 32;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//La quatrième verticale en partant de la gauche 
	x = 46+(32*8);
	y = 46;
	for(int i = 0 ; i < 12 ; i++) {
		if((i == 5) || (i == 9))
			y += 64;
		if(i == 6)
			y += 32*9;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//La cinquième = quatrième verticale en partant de la gauche
	x = 46+(32*10);
	y = 46;
	for(int i = 0 ; i < 12 ; i++) {
		if((i == 5) || (i == 9))
			y += 64;
		if(i == 6)
			y += 32*9;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//La sizieme = troisieme verticale en partant de la gauche 
	x = 46+(32*12);
	y = 46+(32*4);
	for(int i = 0 ; i < 10 ; i++) {
		if(i == 4) 
			y += 32*9;
		if((i == 5) || (i == 9))
			y += 32;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//La septieme = deuxieme verticale en partant de la gauche
	x = 46+(32*14);
	y = 46;
	for(int i = 0 ; i < 24 ; i++) {
		if(i == 23)
			y += 32;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//La verticale en haut à droite
	x = 46+(32*18);
	y = 46;
	for(int i = 0 ; i < 14 ; i++) {
		if(i == 8)
			y += 32*9;
		if(i == 11)
			y += 64;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//Verticales du bas de la MAP
	//La deuxieme en partant de la gauche
	x = 46+(32*2);
	y = 46+(32*17);
	for(int i = 0 ; i < 6 ; i++) {
		if((i == 1) || (i == 5))
			y += 32;

		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
	//La deuxieme en partant de la droite -> similaire à celle de la gauche 
	x = 46+(32*16);
	y = 46+(32*17);
	for(int i = 0 ; i < 6 ; i++) {
		if((i == 1) || (i == 5))
			y += 32;
		SDL_Rect seed = (lgum);// ou bgum 
		SDL_Rect emplacement{x,y,w,h};
		b->add_gum(emplacement);
		SDL_BlitScaled(plancheSprites, &seed, win_surf, &emplacement);
		y += 32;
	}
}

void init(Board *b)
{
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 672, 864, SDL_WINDOW_SHOWN);
	win_surf = SDL_GetWindowSurface(pWindow);

	plancheSprites = SDL_LoadBMP("../inc/pacman_sprites.bmp");
	coun = 0;

	SDL_SetColorKey(plancheSprites, false, 0);
	SDL_BlitScaled(plancheSprites, &src_b3, win_surf, &bg);

	SDL_BlitScaled(plancheSprites, &ghost_rr1, win_surf, &ghost_rstart);
	SDL_BlitScaled(plancheSprites, &ghost_pr1, win_surf, &ghost_pstart);
	SDL_BlitScaled(plancheSprites, &ghost_cr1, win_surf, &ghost_cstart);
	SDL_BlitScaled(plancheSprites, &ghost_yr1, win_surf, &ghost_ystart);
	SDL_BlitScaled(plancheSprites, &lpacman_c, win_surf, &pacman_start);
	b->add_ghost(ghost_r);
	b->add_ghost(ghost_p);
	b->add_ghost(ghost_c);
	b->add_ghost(ghost_y);
	b->add_ghost(pacman_p);

	
	Utile_elem g_r{&ghost_r}; //Utile_elem par Ghost
	cout << "g_r x :: " << g_r.get_x() << endl;
	cout << "ghost r x :: " << ghost_r.x << endl;
	g_r.set_x(ghost_rstart.x);
	cout << "g_r x :: " << g_r.get_x() << endl;
	cout << "ghost r x :: " << ghost_r.x << endl;
	g_r.set_y(ghost_rstart.y);
	g_r.set_w(32);// x2 scale
	g_r.set_h(32);// x2 scale
	Utile_elem g_p{&ghost_p};
	g_p.set_x(ghost_pstart.x);
	g_p.set_y(ghost_pstart.y);
	g_p.set_w(32);// x2 scale
	g_p.set_h(32);// x2 scale
	Utile_elem g_c{&ghost_c};
	g_c.set_x(ghost_cstart.x);
	g_c.set_y(ghost_cstart.y);
	g_c.set_w(32);// x2 scale
	g_c.set_h(32);// x2 scale
	Utile_elem g_y{&ghost_y};
	g_y.set_x(ghost_ystart.x);
	g_y.set_y(ghost_ystart.y);
	g_y.set_w(32);// x2 scale
	g_y.set_h(32);// x2 scale
	Utile_elem p{&pacman_p}; //Utile_elem par Pacman
	p.set_x(pacman_start.x);
	p.set_y(pacman_start.y);
	p.set_w(32);
	p.set_h(32);
	b->add_elem(g_r);
	b->add_elem(g_p);
	b->add_elem(g_c);
	b->add_elem(g_y);
	b->add_elem(p);
	//Init seeds
	init_seeds(b);
	//Init walls 
	//init_walls(b);

	SDL_SetColorKey(plancheSprites, true, 0);
	//Affichage des 4 fantomes aux centres et du pacman
}

void exit_ghost(Board *b,char ghost_name) { // r,p,c,o
	/*SDL_SetColorKey(plancheSprites, false, 0);
	SDL_BlitScaled(plancheSprites, &src_b3, win_surf, &bg);*/
	SDL_Rect* ghost_choice = nullptr;
	int index_choice = -1;
	switch (ghost_name) {
		case 'r':
			index_choice = 0;
			ghost_choice = &(ghost_rr1);
			/*SDL_BlitScaled(plancheSprites, &ghost_p, win_surf, &ghost_pstart);
			SDL_BlitScaled(plancheSprites, &ghost_c, win_surf, &ghost_cstart);
			SDL_BlitScaled(plancheSprites, &ghost_y, win_surf, &ghost_ystart);*/
			break;
		case 'p':
			index_choice = 1;
			ghost_choice = &(ghost_pr1);
			/*SDL_BlitScaled(plancheSprites, &ghost_r, win_surf, &ghost_rstart); //normalement deja sortit
			SDL_BlitScaled(plancheSprites, &ghost_c, win_surf, &ghost_cstart);
			SDL_BlitScaled(plancheSprites, &ghost_y, win_surf, &ghost_ystart);*/
			break;
		case 'c':
			index_choice = 2;
			ghost_choice = &(ghost_cr1);
			/*SDL_BlitScaled(plancheSprites, &ghost_p, win_surf, &ghost_pstart); //normalement deja sortit
			SDL_BlitScaled(plancheSprites, &ghost_r, win_surf, &ghost_rstart); //normalement deja sortit
			SDL_BlitScaled(plancheSprites, &ghost_y, win_surf, &ghost_ystart);*/
			break;
		case 'y':
			index_choice = 3;
			ghost_choice = &(ghost_yr1);
			/*SDL_BlitScaled(plancheSprites, &ghost_p, win_surf, &ghost_pstart); //normalement deja sortit
			SDL_BlitScaled(plancheSprites, &ghost_c, win_surf, &ghost_cstart); // ""
			SDL_BlitScaled(plancheSprites, &ghost_r, win_surf, &ghost_rstart); // ""*/
			break;
	}
	b->change_pos(index_choice,ghost_free.x,ghost_free.y);
	SDL_BlitScaled(plancheSprites, ghost_choice, win_surf, &ghost_free);
	SDL_SetColorKey(plancheSprites, true, 0);
}



int main(int argc, char** argv)
{



	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
		return 1;
	}
	
	Board gmboard{3};


	init(&gmboard);
	Game g("jojo",&gmboard,pWindow,win_surf,plancheSprites);

	cout << gmboard.getMap().hitWall(321,326,321,331,24) << endl;
	int out_ghosts = -1;

	gmboard.sort_gums_by_xy();
	//char true_sens = 'd';
	char sens_r = 'd';
	char sens_p = 'd';
	char sens_c = 'd';
	char sens_y = 'd';
	char *sens_ghosts[4] = {&sens_r,&sens_p,&sens_c,&sens_y};//un peu overkill , on pourrais juste suppr les sens_ et mettre
	//direct des 'd'/'g' dans le tableau 
	*sens_ghosts[0] = 'g';
	cout << "sens g 0 : " << sens_ghosts[0] << endl;
	cout << "sens_r : " << sens_r << endl;


	// BOUCLE PRINCIPALE
	bool quit = false;
	int cou = 0;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			default: break;
			}
		}

		if(out_ghosts != -1) { //fonctionne
			cout << "out ghosts : " << out_ghosts << endl;
			if(g.updateGhosts(g.get_board()->get_elem_with_index(4).get_x(),g.get_board()->get_elem_with_index(4).get_y(),*sens_ghosts,out_ghosts) == -1)
				quit = true;
		}
		
		// Gestion du clavier        
		int nbk;
		const Uint8* keys = SDL_GetKeyboardState(&nbk);
		if (keys[SDL_SCANCODE_ESCAPE])
			quit = true;
		if (keys[SDL_SCANCODE_LEFT]) {
			g.updatePacman(-6,0,'g');

		}

		if (keys[SDL_SCANCODE_RIGHT]) {
			g.updatePacman(6,0,'d');
		}

		if (keys[SDL_SCANCODE_DOWN]) {
			g.updatePacman(0,6,'b');
		}

		if (keys[SDL_SCANCODE_UP]) {
			g.updatePacman(0,-6,'h');
		}

		if (keys[SDL_SCANCODE_0]) {
			exit_ghost(&gmboard,'r');
			out_ghosts++;
			puts("Exit Rouge");
		}
		if (keys[SDL_SCANCODE_1]) {
			exit_ghost(&gmboard,'p');
			out_ghosts++;
			puts("Exit Rose");
		}
		if (keys[SDL_SCANCODE_2]) {
			exit_ghost(&gmboard,'c');
			out_ghosts++;
			puts("Exit Cyan");
		}
		if (keys[SDL_SCANCODE_3]) {
			exit_ghost(&gmboard,'y');
			out_ghosts++;
			puts("Exit Jaune");
		}
		SDL_SetColorKey(plancheSprites, true, 0);

		// AFFICHAGE
		//draw();*/
		SDL_UpdateWindowSurface(pWindow); 
		// LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
	}
	SDL_Quit(); // ON SORT
	return 0;
}