#include <stdio.h>
#include "chanson.h"

int main() {
    // Tête de la liste
    Chanson * favoris = NULL;
    favoris = initChanson("Low rider","War",3);

    // ajouter en tete
    ajouterFileAttente(&favoris, "Back in Black", "AC/DC", 3);

    // ajouter à la fin
    ajouterPlayList(&favoris, "Creep", "Radio Head", 4);

    // Affichage
    lectureEnCours(favoris);

    // liberation memoire
    viderPlaylist(&favoris);

    return 0;
}
