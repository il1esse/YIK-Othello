#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

class case{

private :

    char couleurC;
    bool etat;

public :

    case();

    ~case();

    unsigned char & getCouleurC() const;

    unsigned char setCouleurC(char & nouvCouleur);

    unsigned char & getEtat() const;

    unsigned char setEtat(bool & nouvEtat);



};

#endif // CASE_H_INCLUDED
