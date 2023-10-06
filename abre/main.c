#include <stdio.h>
#include <stdlib.h>
#include"abr.h"

int main()
{


    printf(" ******************** ARBRE BINAIRE DE RECHERCHE *****************");
    printf("1- CREATION DES DE L'ARBRE BINAIRE DE RECHERCHE PAR AJOUT SUCCESSIF A LA RACINE \n\n");
    arbre_t Arbre = creer(11);
	insere(Arbre , 9);insere(Arbre , 0);insere(Arbre , 5);insere(Arbre , 4);insere(Arbre , 3);insere(Arbre , 2);insere(Arbre , 3);
    insere(Arbre , 1);insere(Arbre , 10);insere(Arbre , 7);insere(Arbre , 8);insere(Arbre , 37);insere(Arbre , 21);insere(Arbre , 17);

    printf("2- AFFICHARGE DES DIFFERENTS PARCOURS : \n\n\n");

    printf("2- AFFICHARGE DES DIFFERENTS PARCOURS : \n\n\n");

    printf("2- 1 - AFFICHARGE  PARCOURS PREFIXE  : \n\n");
    Prefixe(Arbre);
    printf("\n\n");
    printf("2- 2 - AFFICHARGE  PARCOURS PostFIXE  : \n\n");
    Postfixe(Arbre);
    printf("\n\n");

    printf("2- 3- AFFICHARGE  PARCOURS INFIXE  : \n\n");
    Infixe(Arbre);
    printf("\n\n");
    printf("3- LE PARCOURS PERMETTANT D'AVOIR LES VALEURS TRIEES DANS L'ORDRE CROISSANT EST LE PARCOURS  #### INFIXE  ###!\n\n\n\n");
    printf("\n\n\n");

    printf("4 - SUPPRESSION DE LA VALEUR 11  \n\n");
    arbre_t Arb = creer(10);
	insere(Arb , 9);insere(Arb , 0);insere(Arb , 5);insere(Arb , 4);insere(Arb , 3);insere(Arb , 2);insere(Arb , 3);insere(Arb , 1);insere(Arb , 7);
	insere(Arb , 8);insere(Arb , 37);insere(Arb , 21);insere(Arb , 17);
    printf("\n\n\n");
    printf("5- AFFICHARGE DES DIFFERENTS PARCOURS SUITE A LA SUPPRESSION DE LA VALEUR 11  : \n\n\n");
    printf("\n\n\n");
    printf("5- 1 - AFFICHARGE  PARCOURS PREFIXE  : \n\n");
    Prefixe(Arb);
    printf("\n\n\n");
    printf("5- 2 - AFFICHARGE  PARCOURS PostFIXE  : \n\n");
    Postfixe(Arb);
    printf("\n\n\n");
    printf("5- 3- AFFICHARGE  PARCOURS INFIXE  : \n\n");
    printf("\n\n");
    Infixe(Arb);
    printf("\n\n");
    printf("6- AJOUT A LA RACINE DE LA VALEUR 13 :");
    arbre_t Arbr = creer(13);
    insere(Arbr , 10);insere(Arbr , 9);insere(Arbr, 0);insere(Arbr , 5);insere(Arbr , 7);insere(Arbr , 8);insere(Arbr , 4);insere(Arbr , 3);
    insere(Arbr , 2);insere(Arbr , 1);insere(Arbr , 3);insere(Arbr, 37);insere(Arbr , 21);insere(Arbr , 17);
    printf("\n\n");
    printf("7- AFFICHARGE DES DIFFERENTS PARCOURS SUITE A L'AJOUT DE LA VALEUR 13  : \n\n\n");
    printf("\n\n\n");
    printf("7- 1 - AFFICHARGE  PARCOURS PREFIXE  : \n\n");
    Prefixe(Arbr);
    printf("\n\n\n");
    printf("7- 2 - AFFICHARGE  PARCOURS PostFIXE  : \n\n");
    Postfixe(Arbr);
    printf("\n\n\n");
    printf("7- 3- AFFICHARGE  PARCOURS INFIXE  : \n\n");
    Infixe(Arbr);
    printf("\n\n");
    printf("8- AJOUT DE 11 EN FEUILLE SUIVANT LE PRINCIPE DES ABR : \n\n");
    insere(Arbr , 11);
    printf("\n\n");
    printf("9- AFFICHARGE DES DIFFERENTS PARCOURS SUITE A L'AJOUT DE LA VALEUR 11  EN FEUILLE  : \n\n\n");
    printf("\n\n\n");
    printf("9- 1 - AFFICHARGE  PARCOURS PREFIXE  : \n\n");
    Prefixe(Arbr);
    printf("\n\n\n");
    printf("9- 2 - AFFICHARGE  PARCOURS PostFIXE  : \n\n");
    Postfixe(Arbr);
    printf("\n\n\n");
    printf("9- 3- AFFICHARGE  PARCOURS INFIXE  : \n\n");
    Infixe(Arbr);
    printf("\n\n");
    Rechercher( Arbre, 8);
    return 0;
}
