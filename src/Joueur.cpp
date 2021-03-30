/* Inclusions des entêtes utilisées */
#include "Joueur.h"

    // Constructeur par défaut de la classe Joueur.
    Joueur::Joueur(){
        pseudo = "Joueur";
        couleur = "Aucune";
        nbrJ = 0;
        nbrC = 0;
        tabJeton = NULL;
    }

    // Constructeur de la classe Joueur.
    Joueur::Joueur(char nomJoueur){
        pseudo = nomJoueur;
        couleur = "Aucune";
        nbrJ = 0;
        nbrC = 0;
        tabJeton = NULL;
    }

    //Destructeur de la classe Joueur.
    Joueur::~Joueur(){
        if(tabJeton != NULL) delete [] tabJeton;
        pseudo = "Joueur";
        couleur = "Aucune";
        nbrJ = 0;
        nbrC = 0;
    }

    
    // Accesseur : Récupère le pseudo du joueur.
    std::string Joueur::getPseudo() const{
        return pseudo;
    }

    // Accesseur : Récupère le Jeton du joueur qui porte le nomJeton.
    Jeton Joueur::getJeton(std::string nomJeton) const{
        for(unsigned int i=0; i<nbrJ; i++)
        {
            if(tabJeton[i].getNomJeton() == nomJeton)
            {
                return tabJeton[i];
            }
            
        } 
    }

    // Accesseur : Récupère la couleur associé au joueur.
    std::string Joueur::getCouleur() const{
        return couleur;
    }

    // Accesseur : Récupère le nombre de jeton possédé par le joueur.
    unsigned int Joueur::getNombreJeton() const{
        return nbrJ;
    }

    // Accesseur : Récupère le nombre de case possédé par le joueur.
    unsigned int Joueur::getNombreCase() const{
        return nbrJ;
    }

    //Mutateur : Modifie le nom du joueur.
    void Joueur::setPseudo(std::string & nvPseudo){
        pseudo = nvPseudo;
    }

    // Mutateur : Modifie la couleur du joueur.
    void Joueur::setCouleur(std::string & nvCouleur){
        couleur = nvCouleur;
    }

    //Mutateur : Modifie le nombre de jeton du joueur.
    void Joueur::setNombreJeton(unsigned int nvNbJeton){
        nbrJ = nvNbJeton;
    }

    // Mutateur : Modifie le nombre de case possédé par le joueur.
    void Joueur::setNombreCase(unsigned int nvNbCase){
        nbrC = nvNbCase;
    }

    // Crée les 7 jetons.
    void Joueur::creerJeton(){
        tabJeton = new Jeton[7];
        nbrJ = 7;

        std::string pion = "Pion";
        std::string soldat = "Soldat";
        std::string cavalier = "Cavalier";
        std::string clown = "Clown"; 
        std::string danseuse = "Danseuse";
        std::string sorcier = "Sorcier";
        std::string empereur = "Empereur";

        for (int i=0; i<7; i++)
        {
            switch(i){
                case 0 : tabJeton[0].setNomJeton(pion);break;
                case 1 : tabJeton[1].setNomJeton(soldat);break;
                case 2 : tabJeton[2].setNomJeton(cavalier);break;
                case 3 : tabJeton[3].setNomJeton(clown);break;
                case 4 : tabJeton[4].setNomJeton(danseuse);break;
                case 5 : tabJeton[5].setNomJeton(sorcier);break;
                case 6 : tabJeton[6].setNomJeton(empereur);break;
            }
        }
    }


    // Met à jour l'information du nombre de case possédé par le joueur.
    void Joueur::majCaseJoueur(Plateau & p){
        nbrC=0;
        for(unsigned int i=1; i<p.getDimensionX()-2; i++)
        {
            for(unsigned int j=1; j<p.getDimensionY()-2; j++)
            {
                if(p.getCase(i,j).getCouleurC() == couleur)
                {
                    nbrC++;
                }
            }
        }
    }


    // Permet au joueur de poser un jeton sur le plateau.
    void Joueur::poseJeton(unsigned int x, unsigned int y, Plateau & p, std::string nomJeton){
        Jeton * nvTabJeton = new Jeton[nbrJ-1];
        int j = 0;
        for(unsigned int i=0; i<nbrJ; i++){
            if(tabJeton[i].getNomJeton() == nomJeton)
            {
                bool uVrai = true;
                tabJeton[i].setUtilisation(uVrai);
            }

            if(tabJeton[i].getUtilisation() != true)
            {
                std::string nom = tabJeton[i].getNomJeton();
                bool u = tabJeton[i].getUtilisation();
                
                nvTabJeton[j].setNomJeton(nom);               
                nvTabJeton[j].setEffet(tabJeton[i].getEffet());
                nvTabJeton[j].setUtilisation(u);
                j++;
            }
        }
        delete [] tabJeton;
        tabJeton = new Jeton[nbrJ-1];
        for(unsigned int i=0; i<nbrJ-1; i++){
            std::string nom = nvTabJeton[i].getNomJeton();
            bool u = nvTabJeton[i].getUtilisation();
                tabJeton[i].setNomJeton(nom);
                tabJeton[i].setEffet(nvTabJeton[i].getEffet());
                tabJeton[i].setUtilisation(u);
        }
        delete [] nvTabJeton;
        nbrJ--;
        majCaseJoueur(p);
        p.majPlateau(x,y,couleur);
    }

    // Affiche les informations du joueur graphiquement.
    void Joueur::afficheJoueurGraph(){

    }


    // Affiche les informations du joueur textuellement.
    void Joueur::afficheJoueurTxt(){
        std::cout << "Pseudo du joueur : " << pseudo << std::endl;
        std::cout << "La couleur associée au joueur : " << couleur << std::endl;
        std::cout << "Nombre de Case possédé par le joueur : " << nbrC << std::endl;
        std::cout << "Nombre de jeton restant a utilisé : " << nbrJ << std::endl;
        std::cout << "Jeton restant : " << std::endl;
        for(unsigned int i =0; i<nbrJ; i++)
        {
            std::cout << "Nom du jeton : " << tabJeton[i].getNomJeton() << std::endl;
            std::cout << "Effet du jeton : " << tabJeton[i].getEffet() << std::endl;
        }
    }

    // Dessine les Jetons du tableaux de jeton possédé par le joueur.
    void Joueur::dessineJeton(){

    }
