#include <stdio.h>
#include "chanson.h"

int main() {
    // Tête de la liste
    Chanson * favoris = NULL;

    // Chansons
    addFirst(&favoris, "Back in Black", "AC/DC", 1);
    addLast(&favoris, "Oops i Did ..", "Britney", 1);
    addLast(&favoris, "TNT", "Tortoise", 1);
    addFirst(&favoris, "Gimme more", "Britney", 1);

    // Affichage
    lectureEnCours(favoris);

    // effacer par artiste
    //deleteByArtist(&favoris,"Britney");
    deleteByArtistTwo(&favoris, "Britney");
    printf("2nd loop \n");
    lectureEnCours(favoris);

    // liberation memoire
    viderPlaylist(&favoris);

    return 0;
}
