#ifndef GR5_SPOTIFY_CHANSON_H
#define GR5_SPOTIFY_CHANSON_H

struct chanson{
    //data
    char titre[20];
    char artiste[20];
    unsigned int duree;

    // lien / link
    struct chanson * suivante;
};

typedef struct chanson Chanson;

void lectureEnCours(Chanson * ajouer);

Chanson * initChanson(char * titre, char * artiste, unsigned int duree);

// Ajouter en tete
void ajouterFileAttente(Chanson** pListe, char * titre, char * artiste, unsigned int duree);

// Ajouter en fin de liste
void ajouterPlayList(Chanson** pListe, char * titre, char * artiste, unsigned int duree);

// procedure liberation
void viderPlaylist(Chanson** pListe);

#endif
