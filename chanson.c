#include <stdio.h> // printf, scanf
#include <unistd.h> // sleep
#include <stdlib.h> // malloc, free
#include <string.h> // strcmp
#include "chanson.h"

Chanson *initChanson(char *titre, char *artiste, unsigned int duree) {
    Chanson *nouvelleChanson = NULL;

    // Allocation
    nouvelleChanson = (Chanson *) malloc(sizeof(Chanson));

    // Initialisation data
    nouvelleChanson->duree = duree;
    strcpy(nouvelleChanson->titre, titre);
    strcpy(nouvelleChanson->artiste, artiste);

    // initialisation links/liens
    nouvelleChanson->next = NULL;
    nouvelleChanson->prev = NULL;

    return nouvelleChanson;
}


void lectureEnCours(Chanson *ajouer) {
    int choix;
    while (ajouer != NULL) {
        printf("Titre en cours de lecture \n");
        printf("%s \n", ajouer->titre);
        printf("%s \n", ajouer->artiste);
        //sleep(ajouer->duree);
        printf("1: Next, 2: Prev, 3: Exit \n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouer = ajouer->next;
                break;
            case 2:
                ajouer = ajouer->prev;
                break;
            case 3:
                return; // go back to main
            default:
                break;
        }

        if (ajouer == NULL) {
            printf("\n Fin de la playlist \n");
        }
    }
}

void addFirst(Chanson **pListe, char *titre, char *artiste, unsigned int duree) {
    Chanson *nouvelleChanson = initChanson(titre, artiste, duree);

    nouvelleChanson->next = *pListe;
    if (*pListe != NULL) {
        (*pListe)->prev = nouvelleChanson;
    }
    *pListe = nouvelleChanson;
}


void addLast(Chanson **pListe, char *titre, char *artiste, unsigned int duree) {

    Chanson *tail = NULL;
    // Allocation d'une nouvelle chanson
    Chanson *nouvelleChanson = initChanson(titre, artiste, duree);

    tail = *pListe;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    // on est sûr d'etre sur la dernière chanson
    tail->next = nouvelleChanson;
    nouvelleChanson->prev = tail;
}


void viderPlaylist(Chanson **pListe) {
    Chanson *temp = NULL;
    // tant qu'on a quelque chose à effacer.
    while (*pListe != NULL) {
        temp = (*pListe)->next;
        free(*pListe);
        *pListe = temp;
    }
}

// version liste simplement chainée
void deleteByArtist(Chanson **pListe, char *artisteAEffacer) {
    // Vous avez 15 min
    if (*pListe != NULL) {
        Chanson *previous = *pListe;
        Chanson *aEffacer = previous->next;

        // on cherche après le premier element
        while (aEffacer != NULL) {
            if (strcmp(aEffacer->artiste, artisteAEffacer) == 0) {
                previous->next = aEffacer->next;
                free(aEffacer);
                aEffacer = previous->next;
            } else {
                previous = aEffacer;
                aEffacer = aEffacer->next;
            }
        }

        // est-ce que le premier element est aussi à effacer ?
        if (strcmp((*pListe)->artiste, artisteAEffacer) == 0) {
            previous = *pListe;
            *pListe = (*pListe)->next;
            free(previous);
        }
    }
}

// version doublement chainée
void deleteByArtistTwo(Chanson **pListe, char *artisteAEffacer) {
    // si la liste n'est pas vide
    if(*pListe!=NULL) {
        Chanson *aEffacer = (*pListe)->next;
        Chanson *temp = NULL;

        while (aEffacer != NULL) {
            if (strcmp(aEffacer->artiste, artisteAEffacer) == 0) {
                aEffacer->prev->next = aEffacer->next;

                // si on n'est pas à la fin de la liste
                if (aEffacer->next != NULL) {
                    aEffacer->next->prev = aEffacer->prev;
                }

                temp = aEffacer;
                aEffacer = aEffacer->next;
                free(temp);
            } else {
                aEffacer = aEffacer->next;
            }
        }

        // est-ce que le premier element est aussi à effacer ?
        if (strcmp((*pListe)->artiste, artisteAEffacer) == 0) {
            aEffacer = *pListe;
            *pListe = (*pListe)->next;
            (*pListe)->prev = NULL;
            free(aEffacer);
        }
    }
}
