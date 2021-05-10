#include "JeuModeGraphique.h"

#include <iostream>
using namespace std;
    
    // Constructeur par défaut de la classe JeuModeGraphique.
    JeuModeGraphique::JeuModeGraphique(){

    }

    // Constructeur de la classe JeuModeGraphique.
    JeuModeGraphique::JeuModeGraphique(Jeu j){
        jeu = j;
    }

    // Destructeur de la classe JeuModeGraphique.
    JeuModeGraphique::~JeuModeGraphique(){

    }

    // Accesseur : Récupère le jeu.
    const Jeu & JeuModeGraphique::getJeu() const{
        return jeu;
    }

    
    // Mutateur: Change le jeu.
    void JeuModeGraphique::setJeu(Jeu nvJeu){
        jeu = nvJeu;
    }

    // Défini les options du jeu.
    void JeuModeGraphique::menuJeu(){
        jeu.initJeu();
    }

    //Défini les options de choix de départ.
    void JeuModeGraphique::joueurChoix(int x)
    {
        std::cout<<"test"<<std::endl;
                if(x == 1){
                    ordreJeu(jeu.getJoueur1());
                }
                else ordreJeu(jeu.getJoueur2());
        }
    

    // Met fin à la partie.
    void JeuModeGraphique::finDePartie(){
        Score * victoire = jeu.getScore();
        if(jeu.getJoueur1().getNombreCase() > jeu.getJoueur2().getNombreCase())
        {
            victoire->setVictoire(true);
            victoire->AfficherScoreTxt(jeu.getJoueur1(),jeu.getJoueur2(),jeu.getPlateau());
        }
        else if(jeu.getJoueur2().getNombreCase() > jeu.getJoueur1().getNombreCase())
        {
            victoire->setVictoire(false);
            victoire->AfficherScoreTxt(jeu.getJoueur1(),jeu.getJoueur2(),jeu.getPlateau());
        }
        else
        {
            std::cout << "Egalité !" << std::endl;
        }

        std::cout << "1 : Pour rejouer." << std::endl;
        std::cout << "2 : Pour quitter." << std::endl;
        
        unsigned int x;

        do{
            std::cout << "Entrez votre choix" << std::endl;
            std::cin >> x;
        }while(x<0 || x>2);
        
        switch (x)
        {
        case 1 :
            jeu.rejouerPartie();
            break;
        
        case 2 :
            jeu.quitJeu();
            break;
        }


    }

    // Définie aléatoirement l'ordre dans lequelle les joueurs vont jouer.
    void JeuModeGraphique::ordreJeu(){
        srand(time(NULL));
        int joueurRand = rand() % 2 + 1; 
        switch (joueurRand)
        {
        case 1:
            std::cout << "C'est au tour de " << jeu.getJoueur1().getPseudo() << " de commencer." << std::endl;
            joueurTour(jeu.getJoueur1());
            break;
        case 2:
            std::cout << "C'est au tour de " << jeu.getJoueur2().getPseudo() << " de commencer." << std::endl;
            joueurTour(jeu.getJoueur2());
            break;
        }
    }

    // Définie l'ordre dans lequelle les joueurs vont jouer.
    void JeuModeGraphique::ordreJeu(Joueur & joueur)
    {
        std::cout << "C'est au tour de " << joueur.getPseudo() << " de commencer." << std::endl;
        joueurTour(joueur);
    }  

    // Permet de déterminer le tour des joueurs.
    void JeuModeGraphique::joueurTour(Joueur & j){
        Joueur & joueur1 = jeu.getJoueur1();
        Joueur & joueur2 = jeu.getJoueur2();
        for(int i=0; i<7; i++)
        {
            std::cout << "Tour " << i+1 << std::endl;
            if(j.getPseudo() == jeu.getJoueur1().getPseudo())
            {
                actionJoueur(joueur1);
                
                actionJoueur(joueur2);
            }
            else 
            {
                actionJoueur(joueur2);
                actionJoueur(joueur1);
            }
        }
        finDePartie();
    }

    // Permet au joueur de jouer son tour.
    void JeuModeGraphique::actionJoueur(Joueur & joueur)
    {   
        bool test = false;
        const Plateau & plateau = jeu.getPlateau();
        std::cout << "A toi de jouer "<<joueur.getPseudo() << std::endl;
        joueur.majCaseJoueur(plateau);
            std::cout << "Voici tes informations. " << std::endl;
        joueur.afficheJoueurTxt();
        std::cout << "Plateau de jeu : " << std::endl;
        dessinePLATEAUGRAPHIQUE(); 

        while(test == false)
        {
            while (SDL_PollEvent(&events))
            {
                if (events.type) 
                {              // Si une touche est enfoncee
                    
                    switch (events.type) 
                    {

                        case SDL_MOUSEBUTTONUP:
                        
                        if (   (events.button.y > 50) && (events.button.y <= 750) && (events.button.x > 50) && (events.button.x <= 950))
                        {
                            
                            for(int i = 1; i<7;i++)
                            {
                                for(int j=6; j>0;j--)
                                {
                                    
                                    if((events.button.y > 125+(6-j)*100) && (events.button.y <= 175+(6-j)*100) && (events.button.x > 225+(i-1)*100) && (events.button.x <= 275+(i-1)*100))
                                    {

                                        
                                        cout<<"voici X:"<<i<<endl;
                                        cout<<"voici Y:"<<j<<endl;

                                        std::string nomJeton;
                                        Case evalCase = plateau.getCase(i,j);
                                        if(evalCase.getCouleurC() != "Neutre"){
                                            do{
                                                std::cout << "Veuillez entrer des coordonnées pour une case non occupée. " << std::endl;
                                                std::cout << std::endl;
                                            
                                                evalCase = plateau.getCase(i,j);
                                            }while(evalCase.getCouleurC() != "Neutre");
                                            
                                        }
                                        
                                        unsigned int ij = 1;
                                        do{
                                            if(ij<2){
                                                std::cout << "Nom du jeton à jouer : " ;
                                                std::cin >> nomJeton;
                                                std::cout << std::endl;
                                                ij++;
                                            }
                                            else
                                            {
                                                std::cout << "Veuillez entrez un nom de jeton à jouer valide ou non utilisé. " << std::endl;
                                                std::cout << std::endl;
                                                std::cout << "Nom du jeton à jouer : " ;
                                                std::cin >> nomJeton;
                                                std::cout << std::endl;
                                            }
                                            
                                        }while(joueur.existeJeton(nomJeton) == false || joueur.getJeton(nomJeton).getUtilisation() != false);
                                         std::cout << "Vous jouer le jeton " << nomJeton << " sur la case [" << i << "," << j <<"] "<<std::endl;
                                        std::cout << std::endl;
                                        jeu.poseJeton(joueur,i,j,nomJeton);
                                        dessinePLATEAUGRAPHIQUE();
                                        std::cout << joueur.getPseudo() << " possède " <<joueur.getNombreCase() << " case(s) " << std::endl;
                                    }
                                }
                            }
                            test = true;
                        }
                            fprintf(stdout, "Un appuie sur un bouton de la souris :\n");
                        

                    }                    
                        
                }
            } 
        }
    }

    // Lance le mode Joueur vs Joueur.
    void JeuModeGraphique::modeVsJoueur(){
        std::string pseudo_j1;
        std::string pseudo_j2;
        std::cout << "Entrez le pseudo du joueur 1 : ";
        std::cin >> pseudo_j1;
        do{
            std::cout << "Entrez le pseudo du joueur 2 : ";
            std::cin >> pseudo_j2;
        }while(pseudo_j1 == pseudo_j2);

        Joueur &joueur1 = jeu.getJoueur1();
        Joueur &joueur2 = jeu.getJoueur2();
        joueur1.setPseudo(pseudo_j1);
        joueur2.setPseudo(pseudo_j2);
        jeu.setJoueur1(joueur1);
        jeu.setJoueur2(joueur2);
    }

    // Lance le mode vs IA.
    void JeuModeGraphique::modeVsIA()
    {
        std::string pseudo_j1;
        std::string pseudo_j2 = "Ordinateur";
        std::cout << "Entrez le pseudo du joueur 1 : ";
        std::cin >> pseudo_j1;
        Joueur joueur1 = jeu.getJoueur1();
        Joueur joueur2 = jeu.getJoueur2();
        joueur1.setPseudo(pseudo_j1);
        joueur2.setPseudo(pseudo_j2);
        jeu.setJoueur1(joueur1);
        jeu.setJoueur2(joueur2);
    }

//Initialise la fenetre.
    void JeuModeGraphique::AfficherInit()
    {

        //Création d'une fenêtre de dimension 1000 x 800
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1000,800,SDL_WINDOW_SHOWN);
        if (pWindow == NULL) 
        {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; //Message d'erreur si la définition de la fenetre est nulle
        SDL_Quit(); //ferme la fenêtre
        exit(1); 
        }
        renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(renderer, 232, 232, 232, 255); //Dessine un fond de la couleur indiqué
        SDL_RenderClear(renderer);

        SDL_Surface* image = SDL_LoadBMP("data/MENU.bmp"); //On charge l'image menu
        SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer,image);  //La texture monImage contient maintenant l'image importée
        SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, monImage, NULL, NULL);
        SDL_RenderPresent(renderer); //Actualise la page avec les différents réalisé depuis l'appel précédent
    }


//Met à jour fenetre (Evenement/Draw...).
    void JeuModeGraphique::AfficherBoucle()
    {
        //JeuModeGraphique jeu;
        SDL_Surface* image2 = SDL_LoadBMP("data/REGLES.bmp");
        SDL_Texture* monImage2 = SDL_CreateTextureFromSurface(renderer,image2);  //La texture monImage contient maintenant l'image importée
        
        SDL_FreeSurface(image2); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
                        

        SDL_RenderClear(renderer);
        SDL_Surface* image3 = SDL_LoadBMP("data/CHOIX.bmp");
        SDL_Texture* monImage3 = SDL_CreateTextureFromSurface(renderer,image3);  //La texture monImage contient maintenant l'image importée
        SDL_FreeSurface(image3); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

        SDL_RenderClear(renderer);
        SDL_Surface* image4 = SDL_LoadBMP("data/PSEUDO.bmp");
        SDL_Texture* monImage4 = SDL_CreateTextureFromSurface(renderer,image4);  //La texture monImage contient maintenant l'image importée
        SDL_FreeSurface(image4); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

        SDL_RenderClear(renderer);
        SDL_Surface* image5 = SDL_LoadBMP("data/CHOIXDEBUT.bmp");
        SDL_Texture* monImage5 = SDL_CreateTextureFromSurface(renderer,image5);  //La texture monImage contient maintenant l'image importée
        SDL_FreeSurface(image5); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

        SDL_RenderClear(renderer);
        SDL_Surface* image6 = SDL_LoadBMP("data/QUELJOUEUR.bmp");
        SDL_Texture* monImage6 = SDL_CreateTextureFromSurface(renderer,image6);  //La texture monImage contient maintenant l'image importée
        SDL_FreeSurface(image6); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
    
        SDL_Event events;
        bool quit = false;
        bool choix = false;
        bool choixdebut = false;
        bool choixjoueur = false;
        while (!quit)
        {
            while (SDL_PollEvent(&events))
            {
            if(events.type == SDL_QUIT)
            {
                quit = true;
            }
             else if (events.type) 
            {              // Si une touche est enfoncee
                //cout<<choix<<endl;
                switch (events.type) 
                {

                    case SDL_MOUSEBUTTONUP:
                     if (   (events.button.y > 505) && (events.button.y <= 608) && (events.button.x > 324) && (events.button.x <= 637) && choix == false )
                     {
                        //Bouton regle
                       SDL_RenderClear(renderer);
                       SDL_RenderCopy(renderer, monImage2, NULL, NULL);
                       SDL_RenderPresent(renderer); 
                        
                     }
                    
                    if (   (events.button.y > 368) && (events.button.y <= 468) && (events.button.x > 324) && (events.button.x <= 638) && (choix == false))
                     {
                         //bouton jouer
                       SDL_RenderClear(renderer);
                       SDL_RenderCopy(renderer, monImage3, NULL, NULL);
                       SDL_RenderPresent(renderer);
                       menuJeu();
                        choix = true;
                    }

                    else if (   (events.button.y > 416) && (events.button.y <= 603) && (events.button.x > 238) && (events.button.x <= 736) && (choix == true) && (choixdebut == false) )
                    {
                        //Bouton J VS J
                        SDL_RenderClear(renderer);
                        SDL_RenderCopy(renderer, monImage4, NULL, NULL);
                        SDL_RenderPresent(renderer); 
                        modeVsJoueur();
                        SDL_RenderClear(renderer);
                        SDL_RenderCopy(renderer, monImage5, NULL, NULL);
                        SDL_RenderPresent(renderer); 
                        choixdebut = true ; 

                                              

                    }
                    else if (   (events.button.y > 268) && (events.button.y <= 440) && (events.button.x > 240) && (events.button.x <= 724) && (choixdebut == true) && (choixjoueur == false) )
                    {
                        //bOUTON ALEATOIRE
                        dessinePLATEAUGRAPHIQUE();
                        ordreJeu();
                    }                    
                    else if (   (events.button.y > 454) && (events.button.y <= 665) && (events.button.x > 239) && (events.button.x <= 722) && (choixdebut == true) && (choixjoueur == false) )
                    {
                        SDL_RenderClear(renderer);
                        SDL_RenderCopy(renderer, monImage6, NULL, NULL);
                        SDL_RenderPresent(renderer); 
                        choixjoueur = true ; 
                    }
                    else if (   (events.button.y > 112) && (events.button.y <= 359) && (events.button.x > 233) && (events.button.x <= 759) && (choixjoueur == true) ) 
                    {
                        dessinePLATEAUGRAPHIQUE();
                        ordreJeu();
                            
                    }
                        
                        
                    else if (   (events.button.y > 475) && (events.button.y <= 600) && (events.button.x > 300) && (events.button.x <= 640) && (choixjoueur == true) ) 
                    {
                        //jeu.joueurChoix(2);
                        // Set render color to red ( background will be rendered in this color )
                        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

                        // Clear winow
                        SDL_RenderClear( renderer );

                        // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
                        SDL_Rect r;
                        r.x = 50;
                        r.y = 50;
                        r.w = 50;
                        r.h = 50;

                        // Set render color to blue ( rect will be rendered in this color )
                        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

                        // Render rect
                        SDL_RenderFillRect( renderer, &r );

                        // Render the rect to the screen
                        SDL_RenderPresent(renderer);

                    }

                    default: break;
                }
            }
        }

        }
    }

//Dessine le plateau 
    void JeuModeGraphique::dessinePLATEAUGRAPHIQUE()
    {

        SDL_Surface* image7 = SDL_LoadBMP("data/PLATEAU.bmp"); //charge l'image plateau dans une surface
        SDL_Texture* monImage7 = SDL_CreateTextureFromSurface(renderer,image7);  //La texture monImage contient maintenant l'image importée
        SDL_FreeSurface(image7); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, monImage7, NULL, NULL);
        SDL_RenderPresent(renderer); 


        for(int i = 1;i<=6;i++)
        {
            for(int j=6;j>0;j-- )
            {

                SDL_Rect r;
                r.x = 225+(i-1)*100;
                r.y = 125+(6-j)*100;
                r.w = 50;
                r.h = 50;


                int e = getJeu().getPlateau().getCase(i, j).getEtat();

                if(e==2)
                {
                    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
                }
                else if(e==1)
                {
                    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
                }
                else if(e==0)
                {
                    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
                }



                SDL_RenderFillRect( renderer, &r );


                SDL_RenderPresent(renderer);
            }

            
        }

    }

//Ferme la fenetre.
    void JeuModeGraphique::AfficherDetruit()
    {

        SDL_DestroyRenderer(renderer); //Détruit le renderer
        SDL_DestroyWindow(pWindow); //Détruit la fenetre
        SDL_Quit(); //Ferme la fenetre

    }

//Affiche le plateau de jeu dans une fenêtre
void JeuModeGraphique::Afficher(){
    AfficherInit(); //Appel à la fonction pr initialiser la fenêtre
    AfficherBoucle(); //Appel à la boucle d'évenement
    AfficherDetruit(); //Appel à la fonction qui detruit la fenêtre
}