//
//  functions.h
//  TP3
//
//  Created by Fanni Halmai on 28/09/2020.
//  Copyright © 2020 Fanni Halmai. All rights reserved.
//

#ifndef functions_h
#define functions_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

typedef struct Artiste Artiste;
typedef struct Film Film;
typedef struct Date_naissance Date_naissance;

struct Date_naissance{
    int jour;
    int mois;
    int annee;
};

typedef struct Artiste
{
    char* nom;
    char* prenom;
    Date_naissance date_n;
    char* nationalite;
}artist, *p_artist, **pp_artist;



typedef struct Film
{
    char* titre;
    int annee;
    p_artist real;
    p_artist acteur1;
    p_artist acteur2;
    p_artist acteur3;
    int duree;
    char* genre;
}film, *p_film, **pp_film;


typedef struct Node
{
    p_film data;
    struct Node* p_suiv;
} list,*p_list,**pp_list;



p_list init(void);
p_list insertion_debut (p_list, char* []); /* Ajouter un noeud au début de la liste */
void menu(p_list);
void affichage_films(p_list);
void affichage_realisateurs(p_list);
void affiche_film_unique(p_list);
char choix_film(void);
void free_mem(p_list);

#endif /* functions_h */

