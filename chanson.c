#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "chanson.h"

void lectureEnCours(Chanson * ajouer){
    while (ajouer!= NULL){
        printf("Titre en cours de lecture \n");
        printf("%s \n", ajouer->titre);
        printf("%s \n", ajouer->artiste);
        sleep(ajouer->duree);
        ajouer= ajouer->suivante;
    }

}

Chanson * initChanson(char * titre, char * artiste, unsigned int duree){
    Chanson * nouvelleChanson = NULL;

    // Allocation
    nouvelleChanson = (Chanson *)malloc(sizeof(Chanson));

    // Initialisation
    nouvelleChanson->duree = duree;
    strcpy(nouvelleChanson->titre, titre);
    strcpy(nouvelleChanson->artiste, artiste);
    nouvelleChanson->suivante =NULL;

    return nouvelleChanson;
}

void ajouterFileAttente(Chanson** pListe,char * titre, char * artiste, unsigned int duree){
    Chanson * nouvelleChanson = initChanson(titre, artiste, duree);

    nouvelleChanson->suivante = *pListe;
    *pListe = nouvelleChanson;

}

void viderPlaylist(Chanson** pListe){
    Chanson * temp = NULL;

    while(*pListe != NULL){
        temp = (*pListe)->suivante;
        free(*pListe);
        *pListe = temp;
    }

}


void ajouterPlayList(Chanson** pListe, char * titre, char * artiste, unsigned int duree){

    Chanson * tail = NULL;
    // Allocation d'une nouvelle chanson
    Chanson * nouvelleChanson = initChanson(titre, artiste, duree);

    tail= *pListe;
    while (tail->suivante != NULL){
        tail= tail->suivante;
    }
    // on est sur d'etre sur la derniere chanson
    tail->suivante = nouvelleChanson;

}

