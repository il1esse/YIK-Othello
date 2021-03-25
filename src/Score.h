/**

 @brief Jeton contient les données & les entêtes des fonctions jeton.

 @author YIK

 @version 1.0

 @date 2021/03/17

*/



/* Directives pour éviter les inclusions multiples */

#ifndef SCORE_H

#define SCORE_H

/* Inclusions des entêtes utilisées */





/* Définitions de la classes */

class Score {



/* Données privés */

 private :

    int score;



/* Donnée et fonctions publique */
 public :

    

    /**
    @brief Constructeur par défaut de la classe:
    */
    Score();



    /**
    @brief Destructeur de la classe:
    */
    ~Score();



    /**
    @brief 
    */
    CalculateurScore();



    /**
    @brief 
    */
    AfficherScore();


    /**
    @brief
    */
    EffacerScore();



    /**
    @brief
    */
    GetScore();

    /**
    @brief
    */
   SetScore();


};
#endif /* Termine le #ifndef JETON_H */

