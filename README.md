# Yik&Othello

(Ce fichier est en .md pour profiter des balises Markdown je vous conseille de l'ouvrir avec vscode et d'appuyer sur ctrl+shift+V) 

Yik&Othello est un jeu reprenant les principes de l’Othello mais avec quelques changements. Le jeu se joue à 2 joueurs sur un plateau de 36 cases (6x6). Chaque joueurs dispose de 7 jetons ayant chacun un effet différent et aléatoire. La partie s’arrête lorsque les 2 joueurs ont posé leurs 7 jetons. Le but du jeu est d’avoir le plus de jetons de sa couleurs sur plateau. Le choix du joueurs qui commence est soit définie aléatoirement soit par les joueurs selon ce qu’ils décident. 
Chacun son tour, les joueurs vont poser un jetons de leur couleur sur une case vide. Lorsqu’un jeton est posé son effet est directement appliqué. Les effets consistent à poser un jeton de sa couleur sur un case adjacente (soit au-dessus, en dessous, à droite, à gauche, en diagonal haut-gauche, diagonal haut-droite, diagonal bas-gauche ou diagonal bas-droite). Si la case est occupée par l’adversaire elle rendra la case neutre et enlèvera donc la couleur du joueur adverse sans la remplacer. Si la case est vide un jeton (de la couleur du joueurs qui a posé le jeton) sera ajouté.
Comme pour l’Othello il existe la règle du retournement. Lorsqu’un pion est encadré par 2 pions de l’adversaire sur une même directions (exemple : Haut dessus et en dessous , a gauche et a droite , diagonal haut-gauche et diagonal bas-droite) il sera changé de couleur et deviendra un jeton adverse. Il n’y a pas de réaction en chaine : un jeton qui vient d’être retourné ne pourra pas influer sur le retournement d’un autre jeton dans ce tour. Cependant les jetons posé grâce a un effet pourront faire se retourner un jeton adverse. 
A la fin de la partie lorsque les 15 jetons ont été posé la partie se fini et le score du joueur ayant le plus de jeton est calculé (multiplicateur de score si par exemple il ne reste plus de jeton adverse sur le plateau).
Concernant l’utilisation du jeu 2 modes sont disponible : Le mode texte et le mode graphique. Les 2 sont fonctionnel mais le mode graphique nécessitera d’avoir la console ouverte pour avoir quelques informations et pour rentrer les pseudos des joueurs ou les noms des jetons que l’on souhaite utiliser.
Il existe aussi un exécutable pour effectuer les tests de régression pour tester le bon fonctionnement du programme.



## Organisation des fichiers 



-**yik/bin** : répertoire où les exécutables seront compilés



-** yik /data** : répertoire où se trouveront les images à afficher



-** yik /doc** : le fichier doxygen qui permet de générer la documentation du code



-** yik /obj** : répertoire comportant les compilations intermédiaires (.o)



-** yik /src** : répertoire ou se trouvent les .cpp et les .h 



## Installation



Concernant l'installation il faut en premier lieu aller dans le répertoire global du programme et exécuter la commande :



```bash

make 

```  



Le fichier makefile va alors s'occuper des compilation et éditions de lien de tous les fichiers du programme. Elle va aussi créer dans le dossier bin/ les 3 exécutables dont on a besoin. Le "test" pour tester la fonction le "exemple" pour créer les images et le "affichage" pour : les afficher dans une fenetre. Toutes les fonction sont visible dans le .h ou sur la documentation doxygen.



## Exigences



Afin de faire fonctionner les programmes il faut avoir installer sur sa machine les logiciels et librairies suivantes : valgrind doxygen libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev 



## Usage



Pour utiliser les 3 exécutable après les avoir créés avec la fonction make on utilise

```c++

./bin/TestR		//Pour tester le programme

./bin/ModeTxt		//Pour lancer le jeu en mode texte dans le terminal

./bin/ModeGraphique	//Pour lancer le jeu en mode graphique et donc dans une fenestre SDL2

```


## Documentation du code



Pour accéder la documentation du code il faut exécuter la commande : 

``` bash

firefox doc/html/index.html

 ```



## Auteurs



VINCENT/Yann/11906701



LARIBI/Iliesse/11911241



ANDRE-LUBIN/Keryann/11914561

