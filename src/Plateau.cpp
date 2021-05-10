   /* Inclusion de l'entète du module */
    #include "Plateau.h"
    
    // Constructeur par défaut de la classe Plateau.

    Plateau::Plateau(){
        dimx = 8;
        dimy = 8;
        classique = true;
        tabCase = new Case[dimx*dimy];
    }


    // Constructeur de la classe Plateau.

    Plateau::Plateau(unsigned int x, unsigned int y, bool type)
    {
        dimx = x;
        dimy = y;
        assert(dimx > 0 && dimy > 0); //précondition x et y >0
        classique = type;
        tabCase = new Case[dimx*dimy];
    }
    // Destructeur de la classe Plateau.

    Plateau::~Plateau(){
        if(tabCase != NULL) delete [] tabCase;
        dimx = 8;
        dimy = 8;
        classique = true;
    }

    // Accesseur : Récupère la dimension x du plateau.
    unsigned int Plateau::getDimensionX() const{
        return dimx;
    }

    // Accesseur : Récupère la dimension y du plateau.
    unsigned int Plateau::getDimensionY() const{
        return dimy;
    }

    // Accesseur : Récupère le type du plateau.
    bool Plateau::getType() const{
        return classique;
    }

    
    // Accesseur : Récupère la case de coordonnées (x,y) en vérifiant leur 
    // validité, + la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x].
    Case & Plateau::getCase(unsigned int x, unsigned int y) const {
       assert(x >= 0 && y >= 0); // Précondition X et Y positif ou égale à 0.
       assert(x < dimx && y < dimy); // Précondition x et y inférieur à leurs bornes.
       return tabCase[y*dimx+x];
    }


    // Mutateur : Modifie l'état & la couleur de la case de coordonnées (x,y).

    void Plateau::setCase(unsigned int x, unsigned int y, std::string couleur){
        assert(x >= 0 && y >= 0); // Précondition X et Y positif ou égale à 0.
        assert(x < dimx && y < dimy); // Précondition x et y inférieur à leurs bornes.
        
        if(couleur == "Rouge")
        {
            if(getCase(x,y).getEtat() == 2){
                unsigned int valeur_Case = 1;
                tabCase[y*dimx+x].setEtat(valeur_Case);
                tabCase[y*dimx+x].setCouleurC(couleur);
            }
            else if(getCase(x,y).getCouleurC() == "Bleu"){
                unsigned int valeur_Case = 2;
                tabCase[y*dimx+x].setEtat(valeur_Case);
                tabCase[y*dimx+x].setCouleurC("Neutre");
            }
            
        }
        else if(couleur == "Bleu"){
            if(getCase(x,y).getEtat() == 2){
                unsigned int valeur_Case = 0;
                tabCase[y*dimx+x].setEtat(valeur_Case);
                tabCase[y*dimx+x].setCouleurC(couleur);
            }
            else if(getCase(x,y).getCouleurC() == "Rouge"){
                unsigned int valeur_Case = 2;
                tabCase[y*dimx+x].setEtat(valeur_Case);
                tabCase[y*dimx+x].setCouleurC("Neutre");
            }
        }
        else if(couleur == "Neutre"){
            unsigned int valeur_Case = 2;
            tabCase[y*dimx+x].setEtat(valeur_Case);
            tabCase[y*dimx+x].setCouleurC(couleur);
        }

    }


    // Initialise les cases du plateau.

    void Plateau::initPlateau(){
        unsigned int i;
        unsigned int j;

        for (i = 1; i < dimx-1; i++)
        {
            for(j = 1; j < dimy-1; j++)
            {
                unsigned int etatN = 2;
                std::string couleurC = "Neutre";

                tabCase[j*dimx+i].setEtat(etatN);
                tabCase[j*dimx+i].setCouleurC(couleurC);
            }
        }

    }

    // Affiche les bordures du plateau.
    void Plateau::afficheBordureHorizontale(int taille) const{
        for(int i=1; i<taille; i++)
        {
            std::cout<<"+---";
        }
        std::cout<<"+"<<std::endl;
    }

    //Affiche le contenu des cases du plateau.
    void Plateau::afficheContenu(int taille_x,int val_y) const{
        for(int i=1; i<taille_x; i++)
        {
            std::cout<<"| "<< tabCase[val_y*dimx+i].getEtat()<<" ";
        }
        std::cout<<"|"<<std::endl;
    }

    // Dessine le plateau.

    void Plateau::dessinePlateau()const {
        for(unsigned int y=dimy-2; y>0; y--)
        {
                afficheBordureHorizontale(dimx-1);
                afficheContenu(dimx-1,y);
                if(y-1 == 0){
                    afficheBordureHorizontale(dimx-1);
                }
            
        }
        
    }


    // Met à jour le plateau par rapport à l'état d'une case.

    void Plateau::majPlateau(unsigned int x, unsigned int y,std::string couleur){
        if(x != 0 && x != dimx-1)
        {
            if(y != 0 && y!= dimy-1)
            {
                setCase(x,y,couleur);
                appliRegleHori(x,y);
                appliRegleVerti(x,y);
                appliRegleDiag(x,y);
            }
        }
        
    }


    // Applique la règle horizontale.

    void Plateau::appliRegleHori(unsigned int x, unsigned int y){
        unsigned int i = 1;
        unsigned int j = 1;

        while (tabCase[y*dimx+(x-i)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) i++;
        // ici x-i et y définissent la premiere case n'appartenant pas a l'adversaire en suivant cette ligne horizontale
        if (tabCase[y*dimx+(x-i)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(unsigned int k = i; k>0; k--)
            {
                unsigned int etatC = tabCase[y*dimx+x].getEtat() ;
                std::string couleurC = tabCase[y*dimx+x].getCouleurC();
                tabCase[y*dimx+(x-k)].setEtat(etatC);
                tabCase[y*dimx+(x-k)].setCouleurC(couleurC);
            }

        }

        while (tabCase[y*dimx+(x+j)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) j++;
        // ici x+i et y définissent la premiere case n'appartenant pas a l'adversaire en suivant cette ligne horizontale
        if (tabCase[y*dimx+(x+j)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(unsigned int l = j; l>0; l--)
            {
                unsigned int etatC = tabCase[y*dimx+x].getEtat() ;
                std::string couleurC = tabCase[y*dimx+x].getCouleurC();
                tabCase[y*dimx+(x+l)].setEtat(etatC);
                tabCase[y*dimx+(x+l)].setCouleurC(couleurC);
            }

        }

    }


    // Applique la règle verticale.

    void Plateau::appliRegleVerti(unsigned int x, unsigned int y){
        unsigned int i = 1;
        unsigned int j = 1;

        while (tabCase[(y-i)*dimx+x].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) i++;
        // ici x et y-i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette ligne verticale
        if (tabCase[(y-i)*dimx+x].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(unsigned int k = i; k>0; k--)
            {
                unsigned int etatC = tabCase[y*dimx+x].getEtat() ;
                std::string couleurC = tabCase[y*dimx+x].getCouleurC();
                tabCase[(y-k)*dimx+x].setEtat(etatC);
                tabCase[(y-k)*dimx+x].setCouleurC(couleurC);
            }

        }

        while (tabCase[(y+j)*dimx+x].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) j++;
        //  ici x et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette ligne verticale
        if (tabCase[(y+j)*dimx+x].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(unsigned int l = j; l>0; l--)
            {
                unsigned int etatC = tabCase[y*dimx+x].getEtat() ;
                std::string couleurC = tabCase[y*dimx+x].getCouleurC();
                tabCase[(y+l)*dimx+(x)].setEtat(etatC);
                tabCase[(y+l)*dimx+(x)].setCouleurC(couleurC);
            }

        }
    }


    // Applique la règle diagonale

    void Plateau::appliRegleDiag(unsigned int x, unsigned int y){
        //x et y définissent la position du jeton posé
        unsigned int i = 1;
        unsigned int j = 1;
        unsigned int k = 1;
        unsigned int l = 1;

        while (tabCase[(y+i)*dimx+(x+i)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) i++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[(y+i)*dimx+(x+i)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(unsigned int a=i; a>0; a--)
            {
                unsigned int etatC = tabCase[y*dimx+x].getEtat() ;
                std::string couleurC = tabCase[y*dimx+x].getCouleurC();
                tabCase[(y+a)*dimx+(x+a)].setEtat(etatC);
                tabCase[(y+a)*dimx+(x+a)].setCouleurC(couleurC);
            }

        }


        while (tabCase[(y+j)*dimx+(x-j)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) j++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[(y+j)*dimx+(x-j)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(unsigned int b = j; b>0; b--)
            {
                unsigned int etatC = tabCase[y*dimx+x].getEtat() ;
                std::string couleurC = tabCase[y*dimx+x].getCouleurC();
                tabCase[(y+b)*dimx+(x-b)].setEtat(etatC);
                tabCase[(y+b)*dimx+(x-b)].setCouleurC(couleurC);
            }

        }

        while (tabCase[(y-k)*dimx+(x+k)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) k++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if(tabCase[(y-k)*dimx+(x+k)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(unsigned int c = j; c>0; c--)
            {
                unsigned int etatC = tabCase[y*dimx+x].getEtat() ;
                std::string couleurC = tabCase[y*dimx+x].getCouleurC();
                tabCase[(y-c)*dimx+(x+c)].setEtat(etatC);
                tabCase[(y-c)*dimx+(x+c)].setCouleurC(couleurC);
            }

        }

        while (tabCase[(y-l)*dimx+(x-l)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) l++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if(tabCase[(y-l)*dimx+(x-l)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(unsigned int d = l; d>0; d--)
            {
                unsigned int etatC = tabCase[y*dimx+x].getEtat() ;
                std::string couleurC = tabCase[y*dimx+x].getCouleurC();
                tabCase[(y-d)*dimx+(x-d)].setEtat(etatC);
                tabCase[(y-d)*dimx+(x-d)].setCouleurC(couleurC);
            }

        }

    }

    // Test de regression : Lance les test de régressions de Plateau.
    void Plateau::testRPlateau(){
        unsigned int x;
        unsigned int xFin;
        std::cout << "Test de regression de la classe Plateau." << std::endl;
        std::cout << "1: Test fonction getDimensionX." << std::endl;
        std::cout << "2: Test fonction getDimensionY." << std::endl;
        std::cout << "3: Test fonction getType." << std::endl;
        std::cout << "4: Test fonction getCase." << std::endl;
        std::cout << "5: Test fonction setCase" << std::endl;
        std::cout << "6: Test fonction initPlateau." << std::endl;
        std::cout << "7: Test majPlateau." << std::endl;
        std::cout << std::endl;

        do{
            std::cout << "Quel test voulez vous lancez ? " << std::endl;
            std::cin >> x;
        }while(x<0 || x>7);

        switch (x)
        {
            case 1:
            {
                std::cout << "getDimensionX : Retoune la dimension X du Plateau." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getDimX."<<std::endl;
                if(getDimensionX() == 8){
                    std::cout << "Test réussi, la dimension X du plateau est "<< getDimensionX() << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, la dimension X du plateau n'est pas égale à  "<< 8 << "." <<std::endl;
                }
                break;
            }

            case 2:
            {
                std::cout << "getDimensionY : Retoune la dimension Y du Plateau." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getDimX."<<std::endl;
                if(getDimensionY() == 8){
                    std::cout << "Test réussi, la dimension Y du plateau est "<< getDimensionY() << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, la dimension Y du plateau n'est pas égale à  "<< 8 << "." <<std::endl;
                }
                break;
            }

            case 3:
            {
                std::cout << "getType : Retoune le type du Plateau." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getType."<<std::endl;
                if(getType() == true){
                    std::cout << "Test réussi, le type du plateau est "<< getType() << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, le type du plateau n'est pas égale à true ." <<std::endl;
                }
                break;
            }

            case 4:
            {
                std::cout << "getCase : Retoune la case de coordonnée (x,y) du Plateau." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de getCase."<<std::endl;
                if(getCase(0,0).getCouleurC() == "Bord" ){
                    std::cout << "Test réussi, la case(0,0) du plateau est une case de valeur "<< getCase(0,0).getCouleurC() << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, la case(0,0) du plateau n'est pas une case de valeur égale à 'Bord'. " <<std::endl;
                }
                break;
            }

            case 5:
            {
                std::cout << "setCase : Modifie la case de coordonnée (x,y) du Plateau." << std::endl;
                std::cout << std::endl;
                std::cout << "Valeur Actuelle de la case : " << getCase(1,1).getCouleurC() << std::endl;
                std::cout << "Utilisation de setCase."<<std::endl;
                setCase(1,1,"Neutre");
                if(getCase(1,1).getCouleurC() == "Neutre" ){
                    std::cout << "Test réussi, la case(1,1) du plateau est une case de valeur "<< getCase(0,0).getCouleurC() << "." <<std::endl;
                }
                else
                {
                    std::cout << "Test échoué, la case(1,1) du plateau n'est pas une case égale à 'Neutre'. " <<std::endl;
                }
                break;
            }

            case 6:
            {
                std::cout << "initPlateau : Initialise les valeurs du plateau." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de initPlateau."<<std::endl;
                initPlateau();
                dessinePlateau();
                std::string val;
                do
                {
                    std::cout << "Le plateau à t-il bien toutes ses valeurs de case égale à 2 ?(oui/non)" << std::endl;
                    std::cin >> val;
                    std::cout << std::endl;

                } while (val != "o" || val != "oui" || val != "Oui" || val != "O" || val != "OUI" || val != "N" || val != "n" || val != "non" || val != "Non" || val != "NON" );
                
                if(val == "o" || val == "oui" || val == "Oui" || val == "O" || val == "OUI"){
                    std::cout << "Test réussi, le plateau a bien été initialisé. " << std::endl;
                }
                else
                {
                    std::cout << "Test échoué, le plateau n'a pas bien été initialisé." <<std::endl;
                }
                break;
            }

            case 7:
            {
                std::cout << "majPlateau : Met à jour le plateau." << std::endl;
                std::cout << std::endl;
                std::cout << "Utilisation de majPlateau."<<std::endl;
                initPlateau();
                std::cout << "Voici le plateau initiale : " << std::endl;
                dessinePlateau();
                std::cout << "" << std::endl;
                majPlateau(1,1,"Bleu");
                majPlateau(1,2,"Rouge");
                majPlateau(2,1,"Rouge");
                majPlateau(2,2,"Rouge");
                std::cout << "Voici le plateau après le placement de 4 jetons : " << std::endl;
                dessinePlateau();
                std::cout << "Test de la règle appli verticale : " << std::endl;
                majPlateau(1,3,"Bleu");
                std::cout << "Voici les changements de la règle appli verticale : " << std::endl;
                dessinePlateau();
                std::cout << "Test de la règle appli horizontale : " << std::endl;
                majPlateau(3,1,"Bleu");
                std::cout << "Voici les changements de la règle appli horizontale : " << std::endl;
                dessinePlateau();
                std::cout << "Test de la règle appli diagonale : " << std::endl;
                majPlateau(3,3,"Bleu");
                std::cout << "Voici les changements de la règle appli diagonale : " << std::endl;
                dessinePlateau();

                std::string val;
                do
                {
                    std::cout << "Les changements se sont-ils bien appliqué correctement ?(oui/non)" << std::endl;
                    std::cin >> val;
                    std::cout << std::endl;

                } while (val != "o" || val != "oui" || val != "Oui" || val != "O" || val != "OUI" || val != "N" || val != "n" || val != "non" || val != "Non" || val != "NON" );
                
                if(val == "o" || val == "oui" || val == "Oui" || val == "O" || val == "OUI"){
                    std::cout << "Test réussi, les changements ont été correctement appliqués. " << std::endl;
                }
                else
                {
                    std::cout << "Test échoué, les changements n'ont pas été correctement appliqués." <<std::endl;
                }
                break;
            }

        }

        std::cout << std::endl;
        std::cout << "1: Retour aux tests de régression de Plateau" << std::endl;
        std::cout << "2: Quitter les tests de régression de Plateau" << std::endl;

        do{
            std::cout << "Que voulez vous faire ? " << std::endl;
            std::cin >> xFin;
        }while(x<0 || x>2);
        
        switch (xFin)
        {
        case 1:
            testRPlateau();
            break;
        
        case 2:
            exit(0);
            break;
        }
    }
