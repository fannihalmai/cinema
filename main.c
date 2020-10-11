//
//  main.c
//  TP3
//
//  Created by Fanni Halmai on 28/09/2020.
//  Copyright © 2020 Fanni Halmai. All rights reserved.
//


#include "functions.h"

int main(int argc, const char * argv[]) {
    p_list liste_film;
    liste_film = init();
    
    menu(liste_film);
    
    free(liste_film);
    return 0;
}
