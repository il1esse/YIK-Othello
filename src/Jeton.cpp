/* Inclusion de l'entète du module */
#include "Jeton.h"

// Constructeur par défaut de la classe Jeton.
    Jeton::Jeton() {
       NomJeton = "Pion";
       EffetJeton = NULL;
       Utilise = false;
   }

// Constructeur de la classe Jeton.
   Jeton::Jeton(std::string nom) {
      NomJeton = nom;
      srand(time(NULL));

      int effetRand = rand() % 8 + 1; 
      switch(effetRand)
      {
         case 1:
               EffetJeton = new HautGauche;
               break;
         case 2:
               EffetJeton = new HautDroite;
               break;
         case 3:
               EffetJeton = new BasGauche;
               break;
         case 4:
               EffetJeton = new BasDroite;
               break;
         case 5:
               EffetJeton = new Haut;
               break;
         case 6:
               EffetJeton = new Droite;
               break;
         case 7:
               EffetJeton = new Gauche;
               break;
         case 8:
               EffetJeton = new Bas;
               break;
      }

   }
// Destructeur de la classe Jeton.
   Jeton::~Jeton()
   {
       if(EffetJeton != NULL)
       {
          delete EffetJeton;
       }
   }

// Accesseur : Récupère la valeur NomJeton du Jeton.
   const std::string & Jeton::getNomJeton () const {
      return NomJeton;
   }

// Accesseur : Récupère la valeur EffetJeton du Jeton.
   Effet * Jeton::getEffet () const {
      return EffetJeton;
   }

// Accesseur : Récupère la valeur Utilisé du Jeton.
   const bool & Jeton::getUtilisation () const {
      return Utilise;
   }

// Mutateur : Modifie la valeur NomJeton du Jeton.
   void Jeton::setNomJeton (std::string & nvNom) {
      NomJeton = nvNom;
   }

// Mutateur : Modifie l'effet du Jeton.
   void Jeton::setEffet() {
      
      int effetRand = rand() % 8 + 1; 
      switch(effetRand)
      {
         case 1:
               EffetJeton = new HautGauche;
               break;
         case 2:
               EffetJeton = new HautDroite;
               break;
         case 3:
               EffetJeton = new BasGauche;
               break;
         case 4:
               EffetJeton = new BasDroite;
               break;
         case 5:
               EffetJeton = new Haut;
               break;
         case 6:
               EffetJeton = new Droite;
               break;
         case 7:
               EffetJeton = new Gauche;
               break;
         case 8:
               EffetJeton = new Bas;
               break;
      }
   }

// Mutateur : Modifie la valeur Utilisé du Jeton.
   void Jeton::setUtilisation (bool & nvBool) {
      Utilise = nvBool;
   }

// Test de regression : Lance les test de régressions de Jeton.
void Jeton::testRJeton(){

    unsigned int x;
    unsigned int xFin;
    bool Utilisation_R_Jeton;
    std::string jetonTest;
    Jeton jetonRtest(jetonTest);

    std::string nom_R_Jeton;
    std::cout << "Test de regression de la classe Jeton." << std::endl;
    std::cout << "1: Test fonction getNomJeton." << std::endl;
    std::cout << "2: Test fonction setNomJeton." << std::endl;
    std::cout << "3: Test fonction getEffet." << std::endl;
    std::cout << "4: Test fonction setEffet." << std::endl;
    std::cout << "5: Test fonction getUtilisation." << std::endl;
    std::cout << "6: Test fonction setUtilisation." << std::endl;
    std::cout << std::endl;

    do{
        std::cout << "Quel test voulez vous lancez ? " << std::endl;
        std::cin >> x;
    }while(x<0 || x>6);
    

    switch (x)
    {
        case 1 :
        {
            std::cout << "getNomJeton: Récupère le nom du Jeton." << std::endl;
            std::cout << std::endl;
            nom_R_Jeton = jetonRtest.getNomJeton();
            std::cout << "Utilisation de getNomJeton."<<std::endl;
            if(jetonRtest.getNomJeton() == nom_R_Jeton){
                std::cout << "Test réussi, le nom du Jeton est "<< jetonRtest.getNomJeton()  << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, la nom du Jeton n'est pas "<< nom_R_Jeton << "." <<std::endl;
            }
            break;
        }
        
        case 2 :
        {
            std::cout << "setNomJeton : Modifie le nom du Jeton." << std::endl;
            do{
                std::cout << "Veuillez choisir un nouveau nom pour le Jeton" << std::endl;
                std::cin >> nom_R_Jeton;
            }while(nom_R_Jeton == "jetonTest");
            std::cout << std::endl;
            std::cout << "La nom actuelle du Jeton est  : " << jetonRtest.getNomJeton() << std::endl;
            std::cout << "Utilisation de setNomJeton."<<std::endl;
            jetonRtest.setNomJeton(nom_R_Jeton);
            if(jetonRtest.getNomJeton() == nom_R_Jeton){
                std::cout << "Test réussi, le nom du Jeton est "<< jetonRtest.getNomJeton() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, le nom du Jeton n'est pas "<< nom_R_Jeton << "." <<std::endl;
            }
            break;
        }
        
        case 3 :
        {
            std::cout << "getEffet : Récupère l'effet du Jeton." << std::endl;
            std::cout << std::endl;
            std::cout << "Utilisation de getEffet."<<std::endl;
            std::cout << "Test réussi, l'effet du Jeton est "<< jetonRtest.getEffet() << "." <<std::endl;
            break;
        }

        case 4 :
        {
            Jeton jetonRtest2 = jetonRtest;
            std::cout << "setEffet : Modifie l'effet du Jeton." << std::endl;
            std::cout << std::endl;
            std::cout << "L'effet actuelle du Jeton est  : " << jetonRtest.getEffet()->getNomE() << std::endl;
            std::cout << "Utilisation de setEffet."<<std::endl;
            do
            {
               jetonRtest.setEffet();
            } while (jetonRtest.getEffet()->getNomE()==jetonRtest2.getEffet()->getNomE());
            
            if(jetonRtest.getEffet()->getNomE() != jetonRtest2.getEffet()->getNomE()){
                std::cout << "Test réussi, le nouvelle effet du Jeton est "<< jetonRtest.getEffet()->getNomE() << "." <<std::endl;
            }
            else
            {
                std::cout << "Test échoué, l'effet du Jeton n'a pas changé "<< jetonRtest2.getEffet()->getNomE() << "." <<std::endl;
            }
            break;
        }

        case 5 :
        {
            std::cout << "getUtilisation : Récupère la valeur d'utilisation du Jeton." << std::endl;
            do{
                std::cout << "Veuillez choisir une valeur d'utilisation pour le Jeton (true/false)" << std::endl;
                std::cin >> Utilisation_R_Jeton;
            }while(Utilisation_R_Jeton != true || Utilisation_R_Jeton != false);
            
            std::cout << std::endl;
            std::cout << "Vous avez mis la valeur d'utilisation du Jeton à : " << Utilisation_R_Jeton << std::endl;
            std::cout << "Utilisation de getUtilisation."<<std::endl;
            jetonRtest.setUtilisation(Utilisation_R_Jeton);
            if(jetonRtest.getUtilisation() == Utilisation_R_Jeton){
               std::cout << "Test réussi, la valeur d'utilisation du Jeton est "<< jetonRtest.getUtilisation() << "." <<std::endl;
            }
            else
            {
               std::cout << "Test échoué, la valeur d'utilisation du Jeton n'est pas "<< Utilisation_R_Jeton << "." <<std::endl;
            }
            break;
        }
        
        case 6 :
        {
            std::cout << "setUtilisation : Modifie la valeur d'utilisation du Jeton." << std::endl;
            Utilisation_R_Jeton = true;
            std::cout << std::endl;
            std::cout << "La valeur actuelle d'utilisation actuelle du Jeton est : " << jetonRtest.getUtilisation() << std::endl;
            std::cout << "Utilisation de setUtilisation."<<std::endl;
            jetonRtest.setUtilisation(Utilisation_R_Jeton);
            if(jetonRtest.getUtilisation() == Utilisation_R_Jeton){
               std::cout << "Test réussi, la valeur d'utilisation du Jeton est à "<< jetonRtest.getUtilisation() << "." <<std::endl;
            }
            else
            {
               Utilisation_R_Jeton = false;
               std::cout << "Test échoué, la valeur d'utilisation du Jeton n'est pas "<< Utilisation_R_Jeton << "." <<std::endl;
            }
            break;
        }
      }
    std::cout << std::endl;
    std::cout << "1: Retour aux tests de régression de Jeton" << std::endl;
    std::cout << "2: Quitter les tests de régression de Jeton" << std::endl;
    do{
        std::cout << "Que voulez vous faire ? " << std::endl;
        std::cin >> xFin;
    }while(x<0 || x>2);
    switch (xFin)
    {
    case 1:
        testRJeton();
        break;
    
    case 2:
        exit(0);
        break;
    }

}

