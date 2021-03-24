#ifndef EFFET_H_INCLUDED
#define EFFET_H_INCLUDED

class effet{

private :

    string nomE;
    string description;
    bool special;

public :

    effet();

    ~effet();

    unsigned char & getNomE() const;

    unsigned char setNomE(char & nouvNomE);

    unsigned char & getDescription() const;

    unsigned char setDescription(string & nouvDescription);

    unsigned char & getSpecial() const;

    unsigned char setSpecial(bool & nouvSpecial);
};

class HautGauche : public effet
{
    HautGauche();
    void comportementHG(int J.x,int J.y);
};

class HautDroite : public effet
{
    HautDroite();
    void comportementHD(int J.x,int J.y);
};

class BasGauche : public effet
{
    BasGauche();
    void comportementBG(int J.x,int J.y);
};

class BasDroite : public effet
{
    BasDroite();
    void comportementBD(int J.x,int J.y);
};



class Haut : public effet
{
    Haut();
    void comportementH(int J.y);
};

class Droite : public effet
{
    Droite();
    void comportementD(int J.x);
};

class Gauche : public effet
{
    Gauche();
    void comportementG(int J.x);
};

class Bas : public effet
{
    Bas();
    void comportementB(int J.y);
};

#endif // EFFET_H_INCLUDED
