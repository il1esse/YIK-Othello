/* Inclusion de l'entète du module */
#include "Score.h"

/* Inclusion d'entêtes standards */
#include <cassert>
#include <iostream>

/* Définitions des fonctions membres publiques et privées */


    // Constructeur par défaut de la classe Score.
    Score::Score()
    {
        score = 0;
        nbCaseJ1Sco = 0;
        nbCaseJ2Sco = 0;
        tabClassiqueSco = true;
        victoireJ1 = false;

    }

    // Constructeur de la classe Score.
    Score::Score(Plateau & p, Joueur & j1, Joueur & j2) {
        score = 0;
        nbCaseJ1Sco = j1.getNombreCase();
        nbCaseJ2Sco = j2.getNombreCase();
        tabClassiqueSco = p.getType();
        pSco = p;
        victoireJ1 = false;
    }

    // Destructeur de la classe Score/
   Score::~Score () {
       
   }

    // Accesseur : Retoune le score.
   const int & Score::getValScore() const {
      return score;
   }

    // Mutateur : Modifie la valeur du score.
   void Score::setValScore(int nouvScore) {
        score = nouvScore;
   }

    //Accesseur : Retourne la valeur de la variable victoire
   const bool & Score::getVictoire() const{
       return victoireJ1;
   }

   //Mutateur : Modifie la valeur de de victoire

   void Score::setVictoire(bool nvvictoire)
   {
       victoireJ1 = nvvictoire;
   }
   
    // Retourne le multiplicateur de score du joueur victorieux selon les conditions de bonus.
    int Score::condMultiplicateur(const Plateau & p)
    {
        int nbCaseMax = (p.getDimensionX()-2)*(p.getDimensionY()-2);
        int m=1;

        if(victoireJ1 == true)
        {
            m=m*3;
        }
        else if(victoireJ1 == false)
        {
            m=m*3;
        }
        if(victoireJ1 == true && nbCaseJ2Sco == 0)
        {
            m=m*2;
        }
        else if(victoireJ1 == false && nbCaseJ1Sco == 0){
            m=m*2;
        }
        if((nbCaseJ1Sco + nbCaseJ2Sco) == nbCaseMax)
        {
            m=m*2;
        }
        if(tabClassiqueSco == true)
        {
            m=m*2;
        }
        else
        {
            m=m*3;
        }
        return m;
        
    }

    // Retourne le score final du joueur victorieux.
    int Score::CalculateurScore(const Plateau & p)
    {   
        int m = condMultiplicateur(p);
        int scorefiJ2 = nbCaseJ2Sco * m;
        int scorefiJ1 = nbCaseJ1Sco * m;
        if (victoireJ1 == true)
        {
            return scorefiJ1;
        }
        else{
            return scorefiJ2;
        }
        
    }

    // Affiche textuellement et de manière détaillé le score du joueur victorieux.
    void Score::AfficherScoreTxt(const Joueur & j1, const Joueur & j2, const Plateau &p)
    {
        nbCaseJ1Sco = j1.getNombreCase();
        nbCaseJ2Sco = j2.getNombreCase();
        score = CalculateurScore(p);
        if(victoireJ1 == true){
            std::cout << std::endl;
            std::cout << "Bien joué !!! " << j1.getPseudo() << ", Tu as gagné ! " <<std::endl;
            std::cout << "Nombre de case de " << j1.getPseudo() << " est " << j1.getNombreCase() << std::endl;
            std::cout << "Ton adversaire possède " << j2.getNombreCase() << std::endl;
            if(j2.getNombreCase() == 0){ std::cout << "Bonus de domination sur ton adversaire score multiplié par 2" << std::endl;}
            if(tabClassiqueSco == true){ std::cout << "Bonus de plateau classique, score multiplié par 2."<< std::endl;}
            else{std::cout << "Bonus de plateau extravagant, score multiplié par 3."<< std::endl;}
            if(j1.getNombreCase()+j2.getNombreCase() == (p.getDimensionX()-1)*(p.getDimensionY()-1)){
                { std::cout << "Bonus de plateau plateau rempli, score multiplié par 2."<< std::endl;}
            }
            std::cout << "Bonus de victoire, score multiplié par 3." <<std::endl;
            std::cout << "Ton score total est de : " << score <<std::endl;
        }
        if(victoireJ1 == false){
            std::cout << std::endl;
            std::cout << "Bien joué !!! " << j2.getPseudo() << ", Tu as gagné ! " <<std::endl;
            std::cout << "Nombre de case de " << j2.getPseudo() << " est " << j2.getNombreCase() << std::endl;
            std::cout << "Ton adversaire possède " << j1.getNombreCase() << std::endl;
            if(j1.getNombreCase() == 0){ std::cout << "Bonus de domination sur ton adversaire score multiplié par 2" << std::endl;}
            if(tabClassiqueSco == true){ std::cout << "Bonus de plateau classique, score multiplié par 2."<< std::endl;}
            else{std::cout << "Bonus de plateau extravagant, score multiplié par 3."<< std::endl;}
            if(j2.getNombreCase()+j1.getNombreCase() == (p.getDimensionX()-2)*(p.getDimensionY()-2)){
                { std::cout << "Bonus de plateau plateau rempli, score multiplié par 2."<< std::endl;}
            }
            std::cout << "Bonus de victoire, score multiplié par 3." <<std::endl;
            std::cout << "Ton score total est de : " << score <<std::endl;
        }
        

    }

    // Test de regression : Lance les test de régressions de Score.
    void Score::testRScore(){
        unsigned int x;
        unsigned int xFin;
        score = 100;
        nbCaseJ1Sco = 36;
        nbCaseJ2Sco = 0;
        Plateau pSco;
        std::cout << "Test de regression de la classe Score." << std::endl;
        std::cout << "1: Test fonction getValScore." << std::endl;
        std::cout << "2: Test fonction setValScore." << std::endl;
        std::cout << "3: Test fonction getVictoire." << std::endl;
        std::cout << "4: Test fonction setVictoire." << std::endl;
        std::cout << "5: Test fonction condMultiplicateur" << std::endl;
        std::cout << "6: Test fonction calculateurScore." << std::endl;
        std::cout << std::endl;

        do{
            std::cout << "Quel test voulez vous lancez ? " << std::endl;
            std::cin >> x;
        }while(x<0 || x>6);

        switch (x)
        {
            case 1:
            {
                std::cout << "getValScore : Retoune le score." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getValScore."<<std::endl;
                if(getValScore() == 100){
                    std::cout << "Test réussi, le score est "<< score << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, le score n'est pas "<< score << "." <<std::endl;
                }
                break;
            }

            case 2:
            {
                unsigned int scoreTest;
                std::cout << "setValScore : Modifie le score." << std::endl;
                std::cout << "Entrez la nouvelle valeur du score" << std::endl;
                std::cin >> scoreTest;
                std::cout << std::endl;
                std::cout << "Utilisation de setValScore."<<std::endl;
                setValScore(scoreTest);
                if(getValScore() == scoreTest){
                    std::cout << "Test réussi, le score est "<< score << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, le score n'est pas "<< score << "." <<std::endl;
                }
                break;
            }

            case 3:
            {
                std::cout << "getVictoire : Récupère la valeur de la variable victoire." << std::endl;            
                std::cout << std::endl;
                std::cout << "Utilisation de getSpecial."<<std::endl;
                if(getVictoire() == false){
                    std::cout << "Test réussi, la valeur de victoire est à "<< getVictoire() << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, la valeur de victoire n'est pas à false." <<std::endl;
                }
                break;

            }

            case 4:
             {
                bool victoireTest=true;
                std::cout << "setVictoire : Modifie la valeur de la variable victoire." << std::endl;
                std::cout << std::endl;
                std::cout << "La valeur de victoire actuelle est à : " << getVictoire() << std::endl;
                std::cout << "Utilisation de setVictoire."<<std::endl;
                setVictoire(victoireTest);
                if(getVictoire() == victoireTest){
                    std::cout << "Test réussi, la valeur de victoire est à "<< getVictoire() << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, la valeur de victoire n'est pas à "<< victoireTest << "." <<std::endl;
                }
                break;

            }

            case 5:
            {
                bool victoireTest = true;
                setVictoire(victoireTest);
                std::cout << "condMultiplicateur : Retoune le multiplicateur de score." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de condMultiplicateur."<<std::endl;
                if(condMultiplicateur(pSco) == 24){
                    std::cout << "Test réussi, le multiplicateur est " << condMultiplicateur(pSco) << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, le multiplicateur n'est pas "<< condMultiplicateur(pSco) << "." <<std::endl;
                }
                break;
            }

            case 6:
            {
                bool victoireTest = true;
                setVictoire(victoireTest);
                std::cout << "CalculateurScore : Retoune le score final." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de calculateurScore."<<std::endl;
                if(CalculateurScore(pSco) == (24*36)){
                    std::cout << "Test réussi, le multiplicateur est " << CalculateurScore(pSco)<< "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, le multiplicateur n'est pas "<< CalculateurScore(pSco) << "." <<std::endl;
                }
                break;
            }
        }

        std::cout << std::endl;
        std::cout << "1: Retour aux tests de régression de Score" << std::endl;
        std::cout << "2: Quitter les tests de régression de Score" << std::endl;

        do{
            std::cout << "Que voulez vous faire ? " << std::endl;
            std::cin >> xFin;
        }while(x<0 || x>2);

        switch (xFin)
        {
        case 1:
            testRScore();
            break;
        
        case 2:
            exit(0);
            break;
        }
    }