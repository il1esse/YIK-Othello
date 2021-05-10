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
    Joueur::Joueur(std::string nomJoueur){
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
    const std::string & Joueur::getPseudo() const{
        return pseudo;
    }

    // Accesseur : Récupère le Jeton du joueur qui porte le nomJeton.
    const Jeton& Joueur::getJeton (std::string nomJeton) const{
        for(unsigned int i=0; i<7; i++)
        {
            if(tabJeton[i].getNomJeton() == nomJeton)
            {
                return tabJeton[i];
            }
            
        } 
    }

    // Accesseur : Récupère la couleur associé au joueur.
    const std::string & Joueur::getCouleur() const{
        return couleur;
    }

    // Accesseur : Récupère le nombre de jeton possédé par le joueur.
    const unsigned int & Joueur::getNombreJeton() const{
        return nbrJ;
    }

    // Accesseur : Récupère le nombre de case possédé par le joueur.
    const unsigned int & Joueur::getNombreCase() const{
        return nbrC;
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

    
    //Retourne un booléen disant si le nom du jeton est un jeton du jeu.
    bool Joueur::existeJeton(std::string nomJeton){
        if(nomJeton == "Pion")
        {
            return true;
        }
        else if(nomJeton == "Soldat")
        {
            return true;
        }
        else if(nomJeton == "Cavalier")
        {
            return true;
        }
        else if(nomJeton == "Clown")
        {
            return true;
        }
        else if(nomJeton == "Danseuse")
        {
            return true;
        }
        else if(nomJeton == "Sorcier")
        {
            return true;
        }
        else if(nomJeton == "Empereur")
        {
            return true;
        }
        return false;
    }

    // Met à jour l'information du nombre de case possédé par le joueur.
    void Joueur::majCaseJoueur(const Plateau & p){
        nbrC=0;
        for(unsigned int i=1; i<p.getDimensionX()-1; i++)
        {
            for(unsigned int j=1; j<p.getDimensionY()-1; j++)
            {
                if(p.getCase(i,j).getCouleurC() == couleur)
                {
                    nbrC++;
                }
            }
        }
    }

    void Joueur::setUtilisationJeton(std::string nomJeton){
        bool vrai = true;
        for(unsigned int i=0; i<7; i++)
        {
            if(tabJeton[i].getNomJeton() == nomJeton)
            {
                tabJeton[i].setUtilisation(vrai);
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
        for(unsigned int i =0; i<7; i++)
        {
            if(tabJeton[i].getUtilisation() == false){
                std::cout << "Nom du jeton : " << tabJeton[i].getNomJeton() << std::endl;
                std::cout << "Effet du jeton : " << tabJeton[i].getEffet()->getDescription() << std::endl;
            }
            
        }
    }

    // Dessine les Jetons du tableaux de jeton possédé par le joueur.
    void Joueur::dessineJeton(){

    }

    // Initialise les infos du Joueur.
    void Joueur::initJoueur(){
        creerJeton();
    }

    //Test de regression : Lance les test de régressions de Joueur.
    void Joueur::testRJoueur(){
        unsigned int x;
        unsigned int xFin;
        std::cout << "Test de regression de la classe Joueur." << std::endl;
        std::cout << "1: Test fonction getPseudo." << std::endl;
        std::cout << "2: Test fonction getJeton." << std::endl;
        std::cout << "3: Test fonction getCouleur." << std::endl;
        std::cout << "4: Test fonction getNombreJeton." << std::endl;
        std::cout << "5: Test fonction getNombreCase" << std::endl;
        std::cout << "6: Test fonction setPseudo." << std::endl;
        std::cout << "7: Test fonction setCouleur." << std::endl;
        std::cout << "8: Test fonction setNombreJeton." << std::endl;
        std::cout << "9: Test fonction setNombreCase." << std::endl;
        std::cout << "10: Test fonction creerJeton." << std::endl;
        std::cout << "11: Test fonction existeJeton." << std::endl;
        std::cout << "12: Test majCaseJoueur" << std::endl;
        std::cout << "13: Test setUtilisationJeton" << std::endl;
        std::cout << "14: Test initJoueur" << std::endl;
        std::cout << std::endl;

        do{
            std::cout << "Quel test voulez vous lancez ? " << std::endl;
            std::cin >> x;
        }while(x<0 || x>14);

        switch (x)
        {
            case 1:
            {
                break;
            }

            case 2:
            {
                break;
            }

            case 3:
            {
                break;
            }

            case 4:
            {
                break;
            }

            case 5:
            {
                break;
            }

            case 6:
            {
                break;
            }

            case 7:
            {
                break;
            }

            case 8:
            {
                break;
            }

            case 9:
            {
                break;
            }
            case 10:
            {
                break;
            }

            case 11:
            {
                break;
            }

            case 12:
            {
                break;
            }

            case 13:
            {
                break;
            }

            case 14:
            {
                break;
            }
        }

        std::cout << std::endl;
        std::cout << "1: Retour aux tests de régression de Joueur" << std::endl;
        std::cout << "2: Quitter les tests de régression de Joueur" << std::endl;

        do{
            std::cout << "Que voulez vous faire ? " << std::endl;
            std::cin >> xFin;
        }while(x<0 || x>2);
        
        switch (xFin)
        {
        case 1:
            testRJoueur();
            break;
        
        case 2:
            exit(0);
            break;
        }
    }
