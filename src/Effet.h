#ifndef EFFET_H_INCLUDED
#define EFFET_H_INCLUDED

class effet{

private :

    char nomE;
    string description;
    bool special;

public :

    effet();

    ~effet();

    unsigned char & getNomE() const;

    unsigned char setNomE(char & nouvNomE);

    unsigned char &  getDescription() const;

    unsigned char setDescription(string & nouvDescription);

    unsigned char & getSpecial() const;

    unsigned char setSpecial(bool & nouvSpecial);
};

#endif // EFFET_H_INCLUDED
