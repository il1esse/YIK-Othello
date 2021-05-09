/* Inclusions de l'entête du module */
#include "Effet.h"

// Constructeur par défaut de la classe Effet.
Effet::Effet()
{
    nomE = "Vide";
    description = "Vide";
    special = false;
}

// Desctructeur par défaut de la classe Effet.
Effet::~Effet()
{
    
}

//Accesseur : Récupère le nom de l'effet.
const std::string & Effet::getNomE() const
{
    return nomE;
}

//Mutateur : Modifie le nom de l'effet.
void Effet::setNomE(std::string & nouvNomE)
{
    nomE = nouvNomE;
}

//Accesseur : Récupère la description de l'effet.
const std::string & Effet::getDescription() const
{
    return description;
}

//Mutateur : Modifie la description de l'effet.
void Effet::setDescription(std::string nouvDescription)
{
    description = nouvDescription;
}

//Accesseur : Récupère la valeur permettant de savoir si l'effet est special.
const bool & Effet::getSpecial() const
{
    return special;
}

//Mutateur : Modifie la valeur special de l'effet.
void Effet::setSpecial(bool & nouvSpecial)
{
    special = nouvSpecial;
}

void Effet::testREffet ()
{
    unsigned int x;
    unsigned int xFin;
    bool specialR_Effet;
    std::string descriptionR_Effet;
    std::string nomE_R_Effet;
    Haut testHaut = Haut();
    std::cout << "Test de regression de la classe Effet." << std::endl;
    std::cout << "1: Test fonction getNomE." << std::endl;
    std::cout << "2: Test fonction setNomE." << std::endl;
    std::cout << "3: Test fonction getDescription." << std::endl;
    std::cout << "4: Test fonction setDescription." << std::endl;
    std::cout << "5: Test fonction getSpecial." << std::endl;
    std::cout << "6: Test fonction setSpecial." << std::endl;
    std::cout << "7: Test fonction comportement effet hérité Haut." << std::endl;
    std::cout << std::endl;
    do{
        std::cout << "Quel test voulez vous lancez ? " << std::endl;
        std::cin >> x;
    }while(x<0 || x>7);
    

    switch (x)
    {
        case 1 :
        {
            std::cout << "getNomE : Récupère le nom de l'effet." << std::endl;
            std::cout << "Veuillez choisir un nom pour l'effet" << std::endl;
            std::cin >> nomE_R_Effet;
            std::cout << std::endl;
            std::cout << "Vous avez crée un effet de nom : " << nomE_R_Effet << std::endl;
            testHaut.setNomE(nomE_R_Effet);
            std::cout << "Utilisation de getNomE."<<std::endl;
            if(testHaut.getNomE() == nomE_R_Effet){
                std::cout << "Test réussi, le nom de l'effet est "<< testHaut.getNomE() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la nom de l'effet n'est pas "<< nomE_R_Effet << "." <<std::endl;
            }
            break;
        }
        
        case 2 :
        {
            std::cout << "setNomE : Modifie le nom de l'effet." << std::endl;
            do{
                std::cout << "Veuillez choisir un nouveau nom pour l'effet" << std::endl;
                std::cin >> nomE_R_Effet;
            }while(nomE_R_Effet == "Haut");
            std::cout << std::endl;
            std::cout << "La nom actuelle de l'effet est  : " << testHaut.getNomE() << std::endl;
            std::cout << "Utilisation de setNomE."<<std::endl;
            testHaut.setNomE(nomE_R_Effet);
            if(testHaut.getNomE() == nomE_R_Effet){
                std::cout << "Test réussi, le nom de l'effet est "<< testHaut.getNomE() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, le nom de l'effet n'est pas "<< nomE_R_Effet << "." <<std::endl;
            }
            break;
        }
        
        case 3 :
        {
            std::cout << "getDescription : Récupère la description de l'effet." << std::endl;
            std::cout << "Veuillez choisir une description d'effet" << std::endl;
            std::cin >> descriptionR_Effet;
            std::cout << std::endl;
            std::cout << "Vous avez crée une description d'effet : " << descriptionR_Effet << std::endl;
            testHaut.setDescription(descriptionR_Effet);
            std::cout << "Utilisation de getDescription."<<std::endl;
            if(testHaut.getDescription() == descriptionR_Effet){
                std::cout << "Test réussi, la description d'effet est "<< testHaut.getDescription() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la description d'effet n'est pas "<< descriptionR_Effet << "." <<std::endl;
            }
            break;
        }

        case 4 :
        {
            std::cout << "setDescription : Modifie la description de l'effet.." << std::endl;
            do{
                std::cout << "Veuillez choisir une nouvelle description d'effet" << std::endl;
                std::cin >> descriptionR_Effet;
            }while(descriptionR_Effet == "Acquiert la case au dessus du l'endroit ou le jeton a été posé, si elle est neutre");
            std::cout << std::endl;
            std::cout << "La description actuelle de l'effet est  : " << testHaut.getDescription() << std::endl;
            std::cout << "Utilisation de setDescription."<<std::endl;
            testHaut.setDescription(descriptionR_Effet);
            if(testHaut.getDescription() == descriptionR_Effet){
                std::cout << "Test réussi, la description de l'effet est "<< testHaut.getDescription() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la description de l'effet n'est pas "<< descriptionR_Effet << "." <<std::endl;
            }
            break;
        }

        case 5 :
        {
            std::cout << "getSpecial : Récupère la valeur spéciale de l'effet." << std::endl;
            do{
                std::cout << "Veuillez choisir une valeur spéciale pour l'effet (true/false)" << std::endl;
                std::cin >> specialR_Effet;
            }while(specialR_Effet != true || specialR_Effet != false);
            
            std::cout << std::endl;
            std::cout << "Vous avez mis la valeur spéciale de l'effet à : " << specialR_Effet << std::endl;
            std::cout << "Utilisation de getSpecial."<<std::endl;
            testHaut.setSpecial(specialR_Effet);
            if(testHaut.getSpecial() == specialR_Effet){
                std::cout << "Test réussi, la couleur de la case est "<< testHaut.getSpecial() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la couleur de la case n'est pas "<< specialR_Effet << "." <<std::endl;
            }
            break;
        }
        
        case 6 :
        {
            std::cout << "setNomE : Modifie la valeur speciale de l'effet." << std::endl;
            std::cout << "La valeur speciale est déclaré à false" << std::endl;
            specialR_Effet = true;
            std::cout << std::endl;
            std::cout << "La valeur actuelle de l'effet est  : " << testHaut.getSpecial() << std::endl;
            std::cout << "Utilisation de setNomE."<<std::endl;
            testHaut.setSpecial(specialR_Effet);
            if(testHaut.getSpecial() == specialR_Effet){
                std::cout << "Test réussi, la valeur speciale de l'effet est à "<< testHaut.getSpecial() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la valeur speciale de l'effet n'est pas "<< specialR_Effet << "." <<std::endl;
            }
            break;
        }

        case 7 :
        {
            unsigned int x;
            unsigned int y;
            std::string couleur;
            Plateau p;
            p.initPlateau();
            
            std::cout << "Comportement : Procédure permettant de gerer le comportement de l'effet HautDroite" << std::endl;
            do{
                
                std::cout << "Choissisez une valeur x comprise entre 1 et 6" << std::endl;
                std::cin >> x;
            }while(x<0 || x>6);
            std::cout << std::endl;

            do{
                
                std::cout << "Choissisez une valeur y comprise entre 1 et 6" << std::endl;
                std::cin >> y;
            }while(y<0 || y>6);
            std::cout << std::endl;

            do{
                
                std::cout << "Choissisez une couleur entre Bleu et Rouge" << std::endl;
                std::cin >> couleur;
            }while(couleur != "Bleu" || couleur != "Rouge");
            std::cout << std::endl;

            std::cout << "Voici le plateau avant effet : " << std::endl;
            p.dessinePlateau();
            std::cout << "Utilisation de comportement."<<std::endl;
            testHaut.comportement(x,y,p,couleur);
            std::cout << "Voici le plateau après effet : " << std::endl;
            p.dessinePlateau();
            if(p.getCase(x,y).getCouleurC() == couleur){
                std::cout << "Test réussi, la case du plateau a bien changé de valeur." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la case du plateau n'a pas changé de valeur" <<std::endl;
            }
            break;
        }

    }
    std::cout << std::endl;
    std::cout << "1: Retour aux tests de régression de Effet" << std::endl;
    std::cout << "2: Quitter les tests de régression de Effet" << std::endl;
    do{
        std::cout << "Que voulez vous faire ? " << std::endl;
        std::cin >> xFin;
    }while(x<0 || x>2);
    switch (xFin)
    {
    case 1:
        testREffet();
        break;
    
    case 2:
        exit(0);
        break;
    }
}


//Constructeur par défaut de la classe HautGauche.
HautGauche::HautGauche()
{
    std::string nomTMP = "Haut Gauche";
    std::string descriptionTMP = "Acquiert la case à la diagonale haute gauche de l'endroit ou a été posé le jeton, si elle est neutre.";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet HautGauche.
 void HautGauche::comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur)
{
    int nvX = x-1;
    int nvY = y+1;
    p.majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe HautDroite.
HautDroite::HautDroite()
{
    std::string nomTMP = "Haut Droite";
    std::string descriptionTMP = "Acquiert la case à la diagonale haute droite de l'endroit ou a été posé le jeton, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet HautDroite.
void HautDroite::comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur)
{
    int nvX = x+1;
    int nvY = y+1;
    p.majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe BasGauche.
BasGauche::BasGauche()
{
    std::string nomTMP = "BasGauche";
    std::string descriptionTMP = "Acquiert la case à la diagonale basse gauche de l'endroit ou a été posé le jeton, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet BasGauche.
void BasGauche::comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur)
{
    int nvX = x-1;
    int nvY = y-1;
    p.majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe BasDroite.
BasDroite::BasDroite()
{
    std::string nomTMP = "BasDroite";
    std::string descriptionTMP = "Acquiert la case à la diagonale basse droite de l'endroit ou a été posé le jeton, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet BasDroite.
void BasDroite::comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur)
{
    int nvX = x+1;
    int nvY = y-1;
    p.majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe Haut.
Haut::Haut()
{
    std::string nomTMP = "Haut";
    std::string descriptionTMP = "Acquiert la case au dessus du l'endroit ou le jeton a été posé, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet Haut.
void Haut::comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur)
{
    int nvY = y+1;
    p.majPlateau(x,nvY,couleur);
}

//Constructeur par défaut de la classe Droite.
Droite::Droite()
{
    std::string nomTMP = "Droite";
    std::string descriptionTMP = "Acquiert la case à droite l'endroit ou le jeton a été posé, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet Droite.
void Droite::comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur)
{
    int nvX = x+1;
    p.majPlateau(nvX,y,couleur);
}

//Constructeur par défaut de la classe Gauche.
Gauche::Gauche()
{
    std::string nomTMP = "Gauche";
    std::string descriptionTMP = "Acquiert la case a gauche l'endroit ou le jeton a été posé, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet Gauche.
void Gauche::comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur)
{
    int nvX = x-1;
    p.majPlateau(nvX,y,couleur);
}

//Constructeur par défaut de la classe Bas.
Bas::Bas()
{
    std::string nomTMP = "Bas";
    std::string descriptionTMP = "Acquiert la case en dessous de l'endroit ou le jeton a été posé, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet Bas.
void Bas::comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur)
{
    int nvY = y-1;
    p.majPlateau(x,nvY,couleur);
}
