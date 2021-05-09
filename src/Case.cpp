/* Inclusions de l'entête du module */
#include "Case.h"

/* Constructeur par défaut de la classe Case, met les valeurs à la case Neutre */
Case::Case()
{
    couleurC = "Bord";
    etat = 3;
}

/* Constructeur de la classe Case */
Case::Case(std::string c, unsigned int e)
{
    couleurC = c;
    etat = e;
}

/* Destructeur de la classe Case */
Case::~Case()
{

}

/* Accesseur : Récupère la valeur de couleur de la case. */
const std::string & Case::getCouleurC() const
{
    return couleurC;
}

/* Mutateur : Modifie la couleur de la case. */
void Case::setCouleurC(std::string nvCouleur)
{
    couleurC = nvCouleur;
}

/* Accesseur : Récupère la valeur d'état de la case. */
const unsigned int & Case::getEtat() const
{
    return etat;
}

/* Mutateur : Modifie l'état de la case. */
void Case::setEtat(unsigned int nvEtat)
{
    etat = nvEtat;
}

/* Test de regression : Lance les test de régressions de Case. */
void Case::testRCase(){
    unsigned int x;
    unsigned int xFin;
    unsigned int etatCaseTest=2;
    std::string couleurCaseTest="Neutre";
    Case caseTestR("Neutre",2);
    std::cout << "Test de regression de la classe Case." << std::endl;
    std::cout << "1: Test fonction getCouleurC." << std::endl;
    std::cout << "2: Test fonction setCouleurC." << std::endl;
    std::cout << "3: Test fonction getEtat." << std::endl;
    std::cout << "4: Test fonction setEtat." << std::endl;
    std::cout << std::endl;
    do{
        std::cout << "Quel test voulez vous lancez ? " << std::endl;
        std::cin >> x;
    }while(x<0 || x>4);
    

    switch (x)
    {
        case 1 :
        {
            std::cout << "getCouleurC : Récupère la valeur de couleur de la case." << std::endl;
            std::cout << "Veuillez choisir une couleur" << std::endl;
            std::cin >> couleurCaseTest;
            std::cout << std::endl;
            Case caseTestR(couleurCaseTest,2);
            std::cout << "Vous avez crée une case de couleur : " << couleurCaseTest << std::endl;
            std::cout << "Utilisation de getCouleurC."<<std::endl;
            if(caseTestR.getCouleurC() == couleurCaseTest){
                std::cout << "Test réussi, la couleur de la case est "<< caseTestR.getCouleurC() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la couleur de la case n'est pas "<< couleurCaseTest << "." <<std::endl;
            }
            break;
        }
        
        case 2 :
        {
            std::cout << "setCouleurC : Modifie la couleur de la case." << std::endl;
            do{
                std::cout << "Veuillez choisir une nouvelle couleur" << std::endl;
                std::cin >> couleurCaseTest;
            }while(couleurCaseTest == "Neutre");
            std::cout << std::endl;
            std::cout << "La couleur actuelle de la Case est  : " << caseTestR.getCouleurC() << std::endl;
            std::cout << "Utilisation de setCouleurC."<<std::endl;
            caseTestR.setCouleurC(couleurCaseTest);
            if(caseTestR.getCouleurC() == couleurCaseTest){
                std::cout << "Test réussi, la couleur de la case est "<< caseTestR.getCouleurC() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la couleur de la case n'est pas "<< couleurCaseTest << "." <<std::endl;
            }
            break;
        }
        
        case 3 :
        {
            std::cout << "getEtat : Récupère la valeur d'état de la case." << std::endl;
            std::cout << "Veuillez choisir une nouvelle valeur pour la case" << std::endl;
            std::cin >> etatCaseTest;
            std::cout << std::endl;
            Case caseTestR("Neutre",etatCaseTest);
            std::cout << "Vous avez crée une case de valeur : " << etatCaseTest << std::endl;
            std::cout << "Utilisation de getEtat."<<std::endl;
            if(caseTestR.getEtat() == etatCaseTest){
                std::cout << "Test réussi, la valeur de la case est "<< caseTestR.getEtat() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la valeur de la case n'est pas "<< etatCaseTest << "." <<std::endl;
            }
            break;
        }

        case 4 :
        {
            std::cout << "setEtat : Modifie la valeur d'état de la case." << std::endl;
            do{
                std::cout << "Veuillez choisir une nouvelle valeur pour la case" << std::endl;
                std::cin >> etatCaseTest;
            }while(etatCaseTest == 2);
            std::cout << std::endl;
            std::cout << "La valeur actuelle de la Case est  : " << caseTestR.getEtat() << std::endl;
            std::cout << "Utilisation de setEtat."<<std::endl;
            caseTestR.setEtat(etatCaseTest);
            if(caseTestR.getEtat() == etatCaseTest){
                std::cout << "Test réussi, la valeur de la case est "<< caseTestR.getEtat() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la valeur de la case n'est pas "<< etatCaseTest << "." <<std::endl;
            }
            break;
        }

    }
    std::cout << std::endl;
    std::cout << "1: Retour aux tests de régression de Case" << std::endl;
    std::cout << "2: Quitter les tests de régression de Case" << std::endl;
    do{
        std::cout << "Que voulez vous faire ? " << std::endl;
        std::cin >> xFin;
    }while(x<0 || x>2);
    switch (xFin)
    {
    case 1:
        testRCase();
        break;
    
    case 2:
        exit(0);
        break;
    }
}