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
    void Plateau::afficheBordureHorizontale(int taille){
        for(int i=1; i<taille; i++)
        {
            std::cout<<"+---";
        }
        std::cout<<"+"<<std::endl;
    }

    //Affiche le contenu des cases du plateau.
    void Plateau::afficheContenu(int taille_x,int val_y){
        for(int i=1; i<taille_x; i++)
        {
            std::cout<<"| "<< tabCase[val_y*dimx+i].getEtat()<<" ";
        }
        std::cout<<"|"<<std::endl;
    }

    // Dessine le plateau.

    void Plateau::dessinePlateau(){
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
