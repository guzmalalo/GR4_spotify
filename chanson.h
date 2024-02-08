#ifndef GR5_SPOTIFY_CHANSON_H
#define GR5_SPOTIFY_CHANSON_H

struct chanson{
    //data
    char titre[20];
    char artiste[20];
    unsigned int duree;

    // lien / link
    struct chanson * next;
    struct chanson * prev;
};

typedef struct chanson Chanson;

void lectureEnCours(Chanson * ajouer);

Chanson * initChanson(char * titre, char * artiste, unsigned int duree);

// Ajouter en tete
void addFirst(Chanson** pListe, char * titre, char * artiste, unsigned int duree);

// Ajouter en fin de liste
void addLast(Chanson** pListe, char * titre, char * artiste, unsigned int duree);

// Effacer par artiste
void deleteByArtist(Chanson** pListe, char * artisteAEffacer);

// Approche double linkedlist
void deleteByArtistTwo(Chanson** pListe, char * artisteAEffacer);

// procedure liberation
void viderPlaylist(Chanson** pListe);

#endif
