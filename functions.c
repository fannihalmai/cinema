//
//  functions.c
//  TP3
//
//  Created by Fanni Halmai on 28/09/2020.
//  Copyright © 2020 Fanni Halmai. All rights reserved.
//

#include "functions.h"

/* Initialiser tableau avec les donnees lues du fichier */
p_list init(void){
    FILE *fptr=NULL;
    p_list tete = NULL;
    char chaine[300];
    char* tab_film[100];
    char* info;
    int i=0;
    
    fptr = fopen("/Users/fannihalmai/Desktop/films.txt", "r");

    if (fptr == NULL)
    {
        printf("Ouverture du fichier impossible: fichier vide!");
        exit(0);
    }
    else
    {
        while(fgets(chaine, 300, fptr)!=NULL)
        {

            info=strtok(chaine,";");
            while ( info != NULL )
            {
                tab_film[i++]=info;
                info = strtok ( NULL, ";" );
            }

            tete = insertion_debut(tete, tab_film);
            i=0;
        }
    }
        return tete;
}

/* Affichage du menu */
void menu(p_list p_list) {
    char choix='q';
    while(choix!='a' && choix!='b' && choix!='c' && choix!='x'){
        fflush(stdin);
        printf("Choisissez du menu suivant:\n\na)Lister tous les films \nb)Lister tous les realisateurs \nc)recherchez un film\nx)Quitter \n\nVeuillez choisir: \n");
        scanf("%c", &choix);
    }
    switch (choix) {
        case 'a':
            affichage_films(p_list);
            break;
        case 'b':
            affichage_realisateurs(p_list);
            break;
        case 'c':
            affiche_film_unique(p_list);
            break;
        case 'x':
            exit(0);
        default:
            printf("Reponse non reconnue. Veuillez entrer votre choix.\n");
            menu(p_list);
    }
}


/* Affichage d'un film unique selon l'input de l'utilisateur */
void affiche_film_unique (p_list movie)
{
    char choix=choix_film();
    
    switch (choix) {
        case 'a':
            break;
        case 'b':
            movie=movie->p_suiv;
            break;
        case 'c':
            movie=movie->p_suiv;
            movie=movie->p_suiv;
            break;
        default:
            break;
    }
    
    printf("Titre: %s\n",movie->data->titre);
    printf("Annee: %i\n",movie->data->annee);
    printf("Duree: %i\n",movie->data->duree);
    printf("Genre: %s",movie->data->genre);
    printf("Realisateur: %s %s\n",movie->data->real->prenom,movie->data->real->nom);
    printf("Acteurs principaux: %s %s, %s %s, %s %s\n\n",movie->data->acteur1->prenom,movie->data->acteur1->nom,movie->data->acteur2->prenom,movie->data->acteur2->nom,movie->data->acteur3->prenom,movie->data->acteur3->nom);
}

char choix_film(void){
    char choix;
    printf("Quel film souhaitez-vous afficher? (a/b/c)\na) Fight Club\nb) Jurrassic Parc\nc) Retour vers le futur\n");
    scanf("%c", &choix);
    
    while (choix!='a' && choix!='b' && choix!='b'){
        printf("Veuillez choisir a, b ou c\n");
        scanf("%c", &choix);
    }
    return choix;
}

void affichage_films (p_list movie)
{
    while (movie!=NULL)
    {
        printf("Titre: %s\n",movie->data->titre);
        printf("Annee: %i\n",movie->data->annee);
        printf("Duree: %i\n",movie->data->duree);
        printf("Genre: %s\n",movie->data->genre);
        printf("Realisateur: %s %s\n",movie->data->real->prenom,movie->data->real->nom);
        printf("Acteurs principaux: %s %s, %s %s, %s %s\n\n",movie->data->acteur1->prenom,movie->data->acteur1->nom,movie->data->acteur2->prenom,movie->data->acteur2->nom,movie->data->acteur3->prenom,movie->data->acteur3->nom);
        movie = movie -> p_suiv;
    }
}

void affichage_realisateurs(p_list movie){
    while (movie!=NULL){
        printf("Realisateur: %s %s\n",movie->data->real->prenom,movie->data->real->nom);
        printf("Date de naissance: %d/%d/%d\n",movie->data->real->date_n.annee,movie->data->real->date_n.mois,movie->data->real->date_n.jour);
        printf("Nationalite: %s\n",movie->data->real->nationalite);
        movie = movie -> p_suiv;
    }
}

p_list insertion_debut (p_list tete, char* tab_film[])
{
    p_list temp; //Noeud à retourner
    temp=(p_list)malloc(sizeof(list)); //Création de l'espace mémoire du nouveau noeud
    temp->data=(p_film)malloc(sizeof(film));
    temp->data->titre = (char*)malloc((strlen(tab_film[0])+1)*sizeof(char));

    temp->data->real = (p_artist)malloc(sizeof(artist));
    temp->data->real->prenom = (char*)malloc((strlen(tab_film[2])+1)*sizeof(char));
    temp->data->real->nom = (char*)malloc((strlen(tab_film[3])+1)*sizeof(char));
    temp->data->real->date_n.jour = (int)malloc((sizeof(int)));
    temp->data->real->date_n.mois = (int)malloc((sizeof(int)));
    temp->data->real->date_n.annee = (int)malloc((sizeof(int)));
    temp->data->real->nationalite = (char*)malloc((strlen(tab_film[7])+1)*sizeof(char));

    temp->data->acteur1 = (p_artist)malloc(sizeof(artist));
    temp->data->acteur2 = (p_artist)malloc(sizeof(artist));
    temp->data->acteur3 = (p_artist)malloc(sizeof(artist));

    temp->data->acteur1->prenom = (char*)malloc((strlen(tab_film[8])+1)*sizeof(char));
    temp->data->acteur1->nom = (char*)malloc((strlen(tab_film[9])+1)*sizeof(char));
    temp->data->acteur2->prenom = (char*)malloc((strlen(tab_film[14])+1)*sizeof(char));
    temp->data->acteur2->nom = (char*)malloc((strlen(tab_film[15])+1)*sizeof(char));
    temp->data->acteur3->prenom = (char*)malloc((strlen(tab_film[20])+1)*sizeof(char));
    temp->data->acteur3->nom = (char*)malloc((strlen(tab_film[21])+1)*sizeof(char));
    
    temp->data->acteur1->date_n.jour = (int)malloc((sizeof(int)));
    temp->data->acteur1->date_n.mois = (int)malloc((sizeof(int)));
    temp->data->acteur1->date_n.annee = (int)malloc((sizeof(int)));
    temp->data->acteur1->nationalite = (char*)malloc((strlen(tab_film[13])+1)*sizeof(char));
    temp->data->acteur2->date_n.jour = (int)malloc((sizeof(int)));
    temp->data->acteur2->date_n.mois = (int)malloc((sizeof(int)));
    temp->data->acteur2->date_n.annee = (int)malloc((sizeof(int)));
    temp->data->acteur2->nationalite = (char*)malloc((strlen(tab_film[19])+1)*sizeof(char));
    temp->data->acteur3->date_n.jour = (int)malloc((sizeof(int)));
    temp->data->acteur3->date_n.mois = (int)malloc((sizeof(int)));
    temp->data->acteur3->date_n.annee = (int)malloc((sizeof(int)));
    temp->data->acteur3->nationalite = (char*)malloc((strlen(tab_film[25])+1)*sizeof(char));
    

    strcpy(temp->data->titre, tab_film[0]);
    temp->data->annee = atoi(tab_film[1]);
    strcpy(temp->data->real->prenom, tab_film[2]);
    strcpy(temp->data->real->nom,tab_film[3]);
    temp->data->real->date_n.annee = atoi(tab_film[4]);
    temp->data->real->date_n.mois = atoi(tab_film[5]);
    temp->data->real->date_n.jour = atoi(tab_film[6]);
    strcpy(temp->data->real->nationalite, tab_film[7]);
    
    strcpy(temp->data->acteur1->prenom, tab_film[8]);
    strcpy(temp->data->acteur1->nom, tab_film[9]);
    temp->data->real->date_n.annee = atoi(tab_film[10]);
    temp->data->real->date_n.mois = atoi(tab_film[11]);
    temp->data->real->date_n.jour = atoi(tab_film[12]);
    strcpy(temp->data->real->nationalite, tab_film[13]);
    
    strcpy(temp->data->acteur2->prenom, tab_film[14]);
    strcpy(temp->data->acteur2->nom, tab_film[15]);
    temp->data->acteur2->date_n.annee = atoi(tab_film[16]);
    temp->data->acteur2->date_n.mois = atoi(tab_film[17]);
    temp->data->acteur2->date_n.jour = atoi(tab_film[18]);
    strcpy(temp->data->acteur2->nationalite, tab_film[19]);
    
    strcpy(temp->data->acteur3->prenom, tab_film[20]);
    strcpy(temp->data->acteur3->nom, tab_film[21]);
    temp->data->acteur3->date_n.annee = atoi(tab_film[22]);
    temp->data->acteur3->date_n.mois = atoi(tab_film[23]);
    temp->data->acteur3->date_n.jour = atoi(tab_film[24]);
    strcpy(temp->data->acteur3->nationalite, tab_film[25]);

    temp->data->duree = atoi(tab_film[26]);

    temp->data->genre = (char*)malloc((strlen(tab_film[27])+1)*sizeof(char));
    strcpy(temp->data->genre, tab_film[27]);
    temp -> p_suiv = tete; //Le nouveau noeuds pointe vers le premier noeuds de la liste
    return temp;
}

