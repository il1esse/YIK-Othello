all: bin/TestR bin/ModeTxt bin/ModeGraphique

bin/TestR : obj/JeuTest.o obj/Case.o obj/Effet.o obj/Jeton.o obj/Jeu.o obj/Joueur.o obj/Plateau.o obj/Score.o
	g++ -g -Wall obj/Case.o obj/Effet.o obj/Jeton.o obj/Jeu.o obj/Joueur.o obj/Plateau.o obj/Score.o

bin/ModeTxt : obj/Case.o obj/Effet.o obj/Jeton.o obj/Jeu.o obj/Joueur.o obj/Plateau.o obj/Score.o
	g++ -g -Wall obj/Case.o obj/Effet.o obj/Jeton.o obj/Jeu.o obj/Joueur.o obj/Plateau.o obj/Score.o

bin/ModeGraphique : obj/Case.o obj/Effet.o obj/Jeton.o obj/Jeu.o obj/Joueur.o obj/Plateau.o obj/Score.o
	g++ -g -Wall obj/Case.o obj/Effet.o obj/Jeton.o obj/Jeu.o obj/Joueur.o obj/Plateau.o obj/Score.o

obj/JeuTest.o : src/JeuTest.cpp src/JeuTest.h src/Jeu.h
	g++ -g -Wall -c src/JeuTest.cpp -o obj/JeuTest.o

obj/Case.o : src/Case.cpp src/Case.h
	g++ -g -Wall -c src/Case.cpp -o obj/Case.o

obj/Effet.o : src/Effet.cpp src/Effet.h
	g++ -g -Wall -c src/Effet.cpp -o obj/Effet.o

obj/Jeton.o : src/Jeton.cpp src/Jeton.h src/Effet.h
	g++ -g -Wall -c src/Jeton.cpp -o obj/Jeton.o

obj/Jeu.o : src/Jeu.cpp src/Jeu.h src/Joueur.h src/Score.h src/Plateau.h
	g++ -g -Wall -c src/Jeu.cpp -o obj/Jeu.o

obj/JeuModeGraphique.o : src/JeuModeGraphique.cpp src/JeuModeGraphique.h src/Jeu.h
	g++ -g -Wall -c src/JeuModeGraphique.cpp -o obj/JeuModeGraphique.o

obj/JeuModeTexte.o : src/JeuModeTexte.cpp src/JeuModeTexte.h src/Jeu.h
	g++ -g -Wall -c src/JeuModeTexte.cpp -o obj/JeuModeTexte.o

obj/Joueur.o : src/Joueur.cpp src/Joueur.h src/Jeton.h
	g++ -g -Wall -c src/Joueur.cpp -o obj/Joueur.o

obj/Plateau.o : src/Plateau.cpp src/Plateau.h src/Case.h
	g++ -g -Wall -c src/Plateau.cpp -o obj/Plateau.o

obj/Score.o : src/Score.cpp src/Score.h
	g++ -g -Wall -c src/Score.cpp -o obj/Score.o

clean:
	rm obj/*.o
	rm bin/*

doc: 
	doxygen doc/YikO.doxy
