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
        std::cout << "5: Test fonction setPseudo." << std::endl;
        std::cout << "6: Test fonction setCouleur." << std::endl;
        std::cout << "7: Test fonction setNombreJeton." << std::endl;
        std::cout << "8: Test fonction setNombreCase." << std::endl;
        std::cout << "9: Test fonction getNombreCase" << std::endl;
        std::cout << "10: Test fonction creerJeton." << std::endl;
        std::cout << "11: Test fonction existeJeton." << std::endl;
        std::cout << "12: Test majCaseJoueur" << std::endl;
        std::cout << "13: Test setUtilisationJeton" << std::endl;
        std::cout << std::endl;

        do{
            std::cout << "Quel test voulez vous lancez ? " << std::endl;
            std::cin >> x;
        }while(x<0 || x>13);

        switch (x)
        {
            case 1:
            {
                std::cout << "getPseudo : Retoune le Pseudo du joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getPseudo."<<std::endl;
                std::cout << "Pseudo du Joueur : " << getPseudo() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 2:
            {
                creerJeton();
                std::string empereur = "Empereur";
                std::cout << "getJeton : Retoune le Jeton du nom demandé." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getJeton."<<std::endl;
                std::cout << "Jeton du Joueur : " << getJeton(empereur).getNomJeton() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 3:
            {
                std::cout << "getCouleur : Retoune la couleur du joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getCouleur."<<std::endl;
                std::cout << "Couleur du Joueur : " << getCouleur() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 4:
            {
                creerJeton();
                std::cout << "getNombreJeton : Retoune le nombre de jeton possédé par le joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getNombreJeton."<<std::endl;
                std::cout << "Nombre de jeton du Joueur : " << getNombreJeton() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 5:
            {
                std::string test = "Joueur1Test";
                std::cout << "setPseudo : Modifie le Pseudo du joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de setPseudo."<<std::endl;
                std::cout << "Pseudo du Joueur avant utilisation : " << getPseudo() << std::endl;
                setPseudo(test);
                std::cout << "Pseudo du Joueur après utilisation : " << getPseudo() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 6:
            {
                std::string test = "Bleu";
                std::cout << "setCouleur : Modifie la couleur du joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de setCouleur."<<std::endl;
                std::cout << "Couleur du Joueur avant utilisation : " << getCouleur() << std::endl;
                setCouleur(test);
                std::cout << "Couleur du Joueur après utilisation : " << getCouleur() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 7:
            {
                creerJeton();
                std::cout << "setNombreJeton : Modifie le nombre de jeton du joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de setNombreJeton."<<std::endl;
                std::cout << "Nombre de Jeton du Joueur avant utilisation : " << getNombreJeton() << std::endl;
                setNombreJeton(10);
                std::cout << "Nombre de Jeton du Joueur après utilisation : " << getNombreJeton() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 8:
            {
                std::cout << "setNombreCase : Modifie le nombre de case du joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de setNombreJeton."<<std::endl;
                std::cout << "Nombre de Case du Joueur avant utilisation : " << getNombreCase() << std::endl;
                setNombreCase(5);
                std::cout << "Nombre de Case du Joueur après utilisation : " << getNombreCase() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 9:
            {
                std::cout << "getNombreCase : Retoune le nombre de Case possédé par le joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getNombreCase."<<std::endl;
                std::cout << "Nombre de Case du Joueur : " << getNombreCase() << std::endl;
                std::cout << "Test effectué."<<std::endl;
                break;
            }
            case 10:
            {
                creerJeton();
                std::cout << "creerJeton : Créer les jetons du joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de creerJeton."<<std::endl;
                for(unsigned int i = 0; i<7; i++)
                {
                    if(i == 0)
                    {
                        std::cout << "Le jeton n°"<< i << " est : " << getJeton("Pion").getNomJeton() << std::endl;
                        std::cout << "L'effet du jeton n°"<< i << " est : " << getJeton("Pion").getEffet() << std::endl;
                    }
                    else if(i == 1)
                    {
                        std::cout << "Le jeton n°"<< i << " est : " << getJeton("Soldat").getNomJeton() << std::endl;
                        std::cout << "L'effet du jeton n°"<< i << " est : " << getJeton("Soldat").getEffet() << std::endl;
                    }
                    else if(i == 2)
                    {
                        std::cout << "Le jeton n°"<< i << " est : " << getJeton("Cavalier").getNomJeton() << std::endl;
                        std::cout << "L'effet du jeton n°"<< i << " est : " << getJeton("Cavalier").getEffet() << std::endl;
                    }
                    else if(i == 3)
                    {
                        std::cout << "Le jeton n°"<< i << " est : " << getJeton("Clown").getNomJeton() << std::endl;
                        std::cout << "L'effet du jeton n°"<< i << " est : " << getJeton("Clown").getEffet() << std::endl;
                    }
                    else if(i == 4)
                    {
                        std::cout << "Le jeton n°"<< i << " est : " << getJeton("Danseuse").getNomJeton() << std::endl;
                        std::cout << "L'effet du jeton n°"<< i << " est : " << getJeton("Danseuse").getEffet() << std::endl;
                    }
                    else if(i == 5)
                    {
                        std::cout << "Le jeton n°"<< i << " est : " << getJeton("Sorcier").getNomJeton() << std::endl;
                        std::cout << "L'effet du jeton n°"<< i << " est : " << getJeton("Sorcier").getEffet() << std::endl;
                    }
                    else if(i == 6)
                    {
                        std::cout << "Le jeton n°"<< i << " est : " << getJeton("Empereur").getNomJeton() << std::endl;
                        std::cout << "L'effet du jeton n°"<< i << " est : " << getJeton("Empereur").getEffet() << std::endl;
                    }
                }
                std::cout << "Test effectué."<<std::endl;
                break;
            }

            case 11:
            {
                creerJeton();
                std::cout << "existeJeton : Vérifie qu'un nom de jeton existe." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de exiseJeton."<<std::endl;
                std::string nomTest;
                std::cout << " Entrer le nom de Jeton à tester : " << std::endl;
                std::cin >> nomTest;
                if(existeJeton(nomTest) == true)
                {
                    std::cout << "Le jeton existe."<<std::endl;
                }
                else
                {
                    std::cout << "Le jeton n'existe pas."<<std::endl;
                }
                break;
            }

            case 12:
            {
                creerJeton();
                Plateau p;
                p.initPlateau();
                std::cout << "majCaseJoueur : Met à jour le nombre de case du joueur." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de majCaseJoueur."<<std::endl;
                std::cout << "Nombre de case possédé avant utilisation : " << getNombreCase() << std::endl;
                p.majPlateau(3,3,"Pion");
                std::cout << "Nombre de case possédé après utilisation : " << getNombreCase() << std::endl;
                std::cout << "Test effectué." << std::endl;
                break;
            }

            case 13:
            {
                creerJeton();
                std::string empereur = "Empereur";
                std::cout << "setUtilisation : Modifie la valeur d'utilisation du Jeton." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de setUtilisation."<<std::endl;
                std::cout << "Jeton Empereur du Joueur avant utilisation : " << getJeton(empereur).getNomJeton() << std::endl;
                setUtilisationJeton(empereur);
                std::cout << "Jeton Empereur du Joueur après utilisation : " << getJeton(empereur).getNomJeton() << std::endl;
                std::cout << "Test effectué."<<std::endl;
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
