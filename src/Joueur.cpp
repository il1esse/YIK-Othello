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
                case 0 : tabJeton[0].setNomJeton(pion);tabJeton[0].setEffet();break;
                case 1 : tabJeton[1].setNomJeton(soldat);tabJeton[1].setEffet();break;
                case 2 : tabJeton[2].setNomJeton(cavalier);tabJeton[2].setEffet();break;
                case 3 : tabJeton[3].setNomJeton(clown);tabJeton[3].setEffet();break;
                case 4 : tabJeton[4].setNomJeton(danseuse);tabJeton[4].setEffet();break;
                case 5 : tabJeton[5].setNomJeton(sorcier);tabJeton[5].setEffet();break;
                case 6 : tabJeton[6].setNomJeton(empereur);tabJeton[6].setEffet();break;
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
        for(int i=0; i<7; i++){
            if(tabJeton[i].getNomJeton() == nomJeton && tabJeton[i].getUtilisation() == false){
                bool uVrai = true;
                tabJeton[i].setUtilisation(uVrai);
                nbrJ--;
                p.majPlateau(x,y,couleur);
                tabJeton[i].getEffet()->comportement(x,y,p,couleur);
                majCaseJoueur(p);
            }
        }
        
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
            std::cout << "Effet du jeton : " << tabJeton[i].getEffet()->getDescription() << std::endl;
        }
    }

    // Dessine les Jetons du tableaux de jeton possédé par le joueur.
    void Joueur::dessineJeton(){

    }

    // Initialise les infos du Joueur.
    void Joueur::initJoueur(){
        creerJeton();
    }
