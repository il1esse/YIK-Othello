/**

 @brief Jeton contient les données & les entêtes des fonctions jeton.

 @author YIK

 @version 1.0

 @date 2021/03/17

*/



/* Directives pour éviter les inclusions multiples */

#ifndef JETON_H

#define JETON_H

/* Inclusions des entêtes utilisées */





/* Définitions de la classes */

class Jeton {



/* Données privés */

 private :

    char NomJeton;

    Effet EffetJeton;

    bool Utilisé;



/* Donnée et fonctions publique */

 public :

    

    /**

    @brief Constructeur par défaut de la classe:

    */

    Jeton();



    /**

    @brief Destructeur de la classe:

    */

    ~Jeton();



    /**

    @brief 

    */

    GetJeton();



    /**

    @brief 

    */

    SetJeton();



};

#endif /* Termine le #ifndef JETON_H */

