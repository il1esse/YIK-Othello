/* Inclusions des entêtes utilisées */
#include "Joueur.h"

    // Constructeur par défaut de la classe Joueur.
    Joueur::Joueur(){
        pseudo = "Joueur";
        couleur = "Aucune";
        nbrJ = 0;
        nbrC = 0;
    }

    // Constructeur de la classe Joueur.
    Joueur::Joueur(char nomJoueur){
        pseudo = nomJoueur;
        couleur = "Aucune";
        nbrJ = 0;
        nbrC = 0;
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
    char & Joueur::getPseudo() const{
        return pseudo;
    }

    // Accesseur : Récupère la couleur associé au joueur.
    char & Joueur::getCouleur() const{
        return couleur;
    }

    // Accesseur : Récupère le nombre de jeton possédé par le joueur.
    unsigned int & Joueur::getNombreJeton() const{
        return nbrJ;
    }

    // Accesseur : Récupère le nombre de case possédé par le joueur.
    unsigned int & Joueur::getNombreCase() const{
        return nbrJ;
    }

    //Mutateur : Modifie le nom du joueur.
    void Joueur::setPseudo(char & nvPseudo){
        pseudo = nvPseudo;
    }

    // Mutateur : Modifie la couleur du joueur.
    void Joueur::setCouleur(char & nvCouleur){
        couleur = nvCouleur;
    }

    //Mutateur : Modifie le nombre de jeton du joueur.
    void Joueur::setNombreJeton(unsigned int nvNbJeton){
        nbrJ = nvNbJeton;
    }

    // Mutateur : Modifie le nombre de case possédé par le joueur.
    void Joueur::setNombreCase(unsigned int nvNbCase){
        nbrC = nvNbCase
    }

    // Crée les 7 jetons.
    void Joueur::creerJeton(){
        tabJeton = new Jeton[7];
        nbrJ = 7;
        for (int i=0; i<7; i++)
        {
            switch(i){
                case 0 : tabJeton[0].setNomJeton("Pion");break;
                case 1 : tabJeton[1].setNomJeton("Soldat");break;
                case 2 : tabJeton[2].setNomJeton("Cavalier");break;
                case 3 : tabJeton[3].setNomJeton("Clown");break;
                case 4 : tabJeton[4].setNomJeton("Danseuse");break;
                case 5 : tabJeton[5].setNomJeton("Sorcier");break;
                case 6 : tabJeton[6].setNomJeton("Empereur");break;
            }
        }
    }


    // Met à jour l'information du nombre de case possédé par le joueur.
    void Joueur::majCaseJoueur(Plateau & p){
        nbrC=0;
        for(int i=1; i<Plateau::getDimensionX()-2; i++)
        {
            for(int j=1; j<Plateau::getDimensionY()-2; j++)
            {
                if(Plateau::getCase(i,j).Case::getCouleurC() == couleur)
                {
                    nbrC++;
                }
            }
        }
    }


    // Permet au joueur de poser un jeton sur le plateau.
    void Joueur::poseJeton(unsigned int x, unsigned int y, Plateau & p, char nomJeton){
        Jeton nvTabJeton = newTabJeton[nbJeton-1];
        int j = 0;
        for(int i=0; i<nbrJ; i++){
            if(tabJeton[i].getNomJeton() == nomJeton)
            {
                tabJeton[i].setUtilisation(true);
            }

            if(tabJeton[i].getUtilisation() != true)
            {
                nvTabJeton[j].setNomJeton(tabJeton[i].getNomJeton());
                nvTabJeton[j].setEffet(tabJeton[i].getEffet());
                nvTabJeton[j].setUtilisation(tabJeton[i].getUtilisation());
                j++
            }
        }
        delete [] tabJeton;
        tabJeton = new Jeton[nbrJ-1];
        for(int i=0; i<nbrJ-1; i++){
                tabJeton[i].setNomJeton(nvTabJeton[i].getNomJeton());
                tabJeton[i].setEffet(nvTabJeton[i].getEffet());
                tabJeton[i].setUtilisation(nvTabJeton[i].getUtilisation());
        }
        delete [] nvTabJeton;
        nbrJ--;
        majCaseJoueur(p);
        Plateau::majPlateau(x,y,tabCase[y*dimx+x]);
    }

    // Affiche les informations du joueur graphiquement.
    void Joueur::afficheJoueurGraph(){

    }


    // Affiche les informations du joueur textuellement.
    void Joueur::afficheJoueurTxt(){
        cout << "Pseudo du joueur : " << pseudo << endl;
        cout << "La couleur associée au joueur : " << couleur << endl;
        cout << "Nombre de Case possédé par le joueur : " << nbrC << endl;
        cout << "Nombre de jeton restant a utilisé : " << nbrJ << endl;
        cout << "Jeton restant : " << endl;
        for(int i =0; i<nbrJ; i++)
        {
            cout << "Nom du jeton : " << tabJeton[i].getNomJeton() << endl;
            cout << "Effet du jeton : " << tabJeton[i].getEffet() << endl;
        }
    }

    // Dessine les Jetons du tableaux de jeton possédé par le joueur.
    void Joueur::dessineJeton(){

    }