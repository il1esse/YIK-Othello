   /* Inclusion de l'entète du module */
    #include "Plateau.h"
    
    // Constructeur par défaut de la classe Plateau.

    Plateau::Plateau(){
        dimx = 0;
        dimy = 0;
        classique = true;
        tabCase = NULL;
    }


    // Constructeur de la classe Plateau.

    Plateau::Plateau(unsigned int x, unsigned int y, bool type)
    {
        assert(dimx > 0 && dimy > 0); //précondition x et y >0
        dimx = x;
        dimy = y;
        classique = type;
        tabCase = new Case[dimx*dimy];
    }
    // Destructeur de la classe:

    Plateau::~Plateau(){
        if(tabCase != NULL) delete [] tabCase;
        dimx = 0;
        dimy = 0;
        classique = true;
    }

    // Accesseur : Récupère la dimension x du plateau
    unsigned int Plateau::getDimensionX() const{
        return dimx;
    }

    // Accesseur : Récupère la dimension y du plateau
    unsigned int Plateau::getDimensionY() const{
        return dimy;
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
            tabCase[y*dimx+x].setEtat(1);
            tabCase[y*dimx+x].setCouleurC(couleur);
        }
        else if(couleur == "Bleu"){
            tabCase[y*dimx+x].setEtat(0);
            tabCase[y*dimx+x].setCouleurC(couleur);
        }
        else if(couleur == "Neutre"){
            tabCase[y*dimx+x].setEtat(2);
            tabCase[y*dimx+x].setCouleurC(couleur);
        }

    }


    // Initialise les cases du plateau.

    void Plateau::initPlateau(){
        for (int i = 0; i < dimx; i++)
        {
            for(int j = 0; j < dimy; j++)
            {
                tabCase[j*dimx+i].setEtat("Neutre");
                tabCase[j*dimx+i].setCouleurC("Blanc");
            }
        }

    }


    // Dessine le plateau.

    void Plateau::dessinePlateau(){
        for(int y=1; y< dimy-1; y++)
        {
            std::cout << "_" << std::endl;
            for(int x=1; x<dimx-1; x++)
            {
                std::cout<< "|" << tabCase[y*dimx+x].getEtat()<< std::endl;
            }
            std::cout << "|" << std::endl;

        }
    }


    // Met à jour le plateau par rapport à l'état d'une case.

    void Plateau::majPlateau(unsigned int x, unsigned int y,std::string couleur){
        setCase(x,y,couleur);
        appliRegleHori(x,y);
        appliRegleVerti(x,y);
        appliRegleDiag(x,y);
    }


    // Applique la règle horizontale.

    void Plateau::appliRegleHori(unsigned int x, unsigned int y){
        int i = 1;
        int j = 1;

        while (tabCase[y*dimx+(x-i)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) i++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[y*dimx+(x-i)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(i; i>0; i--)
            {
                tabCase[y*dimx+(x-i)].setEtat(tabCase[y*dimx+x].getEtat());
                tabCase[y*dimx+(x-i)].setCouleurC(tabCase[y*dimx+x].getCouleurC());
            }

        }

        while (tabCase[y*dimx+(x+j)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) j++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[y*dimx+(x+j)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(j; j>0; j--)
            {
                tabCase[y*dimx+(x+j)].setEtat(tabCase[y*dimx+x].getEtat());
                tabCase[y*dimx+(x+j)].setCouleurC(tabCase[y*dimx+x].getCouleurC());
            }

        }

    }


    // Applique la règle verticale.

    void Plateau::appliRegleVerti(unsigned int x, unsigned int y){
        int i = 1;
        int j = 1;

        while (tabCase[(y-i)*dimx+x].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) i++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[(y-i)*dimx+x].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(i; i>0; i--)
            {
                tabCase[(y-i)*dimx+x].setEtat(tabCase[y*dimx+x].getEtat());
                tabCase[(y-i)*dimx+x].setCouleurC(tabCase[y*dimx+x].getCouleurC());
            }

        }

        while (tabCase[(y+j)*dimx+x].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) j++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[(y+j)*dimx+x].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(j; j>0; j--)
            {
                tabCase[(y+j)*dimx+x].setEtat(tabCase[y*dimx+x].getEtat());
                tabCase[(y+j)*dimx+x].setCouleurC(tabCase[y*dimx+x].getCouleurC());
            }

        }


    }


    // Applique la règle diagonale

    void Plateau::appliRegleDiag(unsigned int x, unsigned int y){
        //x et y définissent la position du jeton posé
        int i = 1;
        int j = 1;
        int k = 1;
        int l = 1;

        while (tabCase[(y+i)*dimx+(x+i)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) i++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[(y+i)*dimx+(x+i)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(i; i>0; i--)
            {
                tabCase[(y+i)*dimx+(x+i)].setEtat(tabCase[y*dimx+x].getEtat());
                tabCase[(y+i)*dimx+(x+i)].setCouleurC(tabCase[y*dimx+x].getCouleurC());
            }

        }


        while (tabCase[(y+j)*dimx+(x-j)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) j++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[(y+j)*dimx+(x-j)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(j; j>0; j--)
            {
                tabCase[(y+j)*dimx+(x-j)].setEtat(tabCase[y*dimx+x].getEtat());
                tabCase[(y+j)*dimx+(x-j)].setCouleurC(tabCase[y*dimx+x].getCouleurC());
            }

        }

        while (tabCase[(y-k)*dimx+(x+k)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) k++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[(y-k)*dimx+(x+k)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(j; j>0; j--)
            {
                tabCase[(y-k)*dimx+(x+k)].setEtat(tabCase[y*dimx+x].getEtat());
                tabCase[(y-k)*dimx+(x+k)].setCouleurC(tabCase[y*dimx+x].getCouleurC());
            }

        }

        while (tabCase[(y-l)*dimx+(x-l)].getEtat() == 1 - tabCase[y*dimx+x].getEtat()) l++;
        // ici x+i et y+i définissent la premiere case n'appartenant pas a l'adversaire en suivant cette diagonale
        if (tabCase[(y-l)*dimx+(x-l)].getEtat() == tabCase[y*dimx+x].getEtat()) 
        {
            for(l; l>0; l--)
            {
                tabCase[(y-l)*dimx+(x-l)].setEtat(tabCase[y*dimx+x].getEtat());
                tabCase[(y-l)*dimx+(x-l)].setCouleurC(tabCase[y*dimx+x].getCouleurC());
            }

        }

    }