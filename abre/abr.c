#include<stdio.h>
#include<stdlib.h>
#include"abr.h"

arbre_t creer( int valeur  ) {
	arbre_t arbre = malloc ( sizeof( struct noeud_s ));
	arbre->valeur = valeur ;
	arbre->gauche = NULL ;
	arbre->droit= NULL ;
    arbre->pere= NULL ;

return arbre ;

}

arbre_t cree_arbre( int valeur , arbre_t gauche , arbre_t droit ) {
	arbre_t arbre = malloc ( sizeof( struct noeud_s ));
	arbre->valeur = valeur ;
	arbre->gauche = gauche ;
	arbre->droit = droit ;
    arbre->pere= NULL ;

return arbre ;

}


void Prefixe(const arbre_t  arbre){
	if(arbre != NULL){
	printf("%d ,    " , arbre->valeur);
	Prefixe(arbre->gauche);
	Prefixe(arbre->droit);
	}
}

void Postfixe(const arbre_t  arbre){
	if(arbre != NULL){
	Postfixe(arbre->gauche);
	Postfixe(arbre->droit);
	printf("%d ,   " , arbre->valeur);
	}
}

void Infixe(const arbre_t arbre){
	if(arbre != NULL){
	Infixe(arbre->gauche);
	printf("%d ,    " , arbre->valeur);
	Infixe(arbre->droit);
	}
}





noeud_t  Recherche(arbre_t arbre, int search){
	if(arbre == NULL){
		printf("ARBRE VIDE");
		return NULL;
	}
	else{
		if( search == arbre->valeur){
			return arbre;
		}
		else{
			if(search < arbre->valeur){
				return Recherche(arbre->gauche ,search);
			}
			else{
				if(search > arbre->valeur){
					return Recherche(arbre->droit ,search);
				}
			}
		}
	}
}


void  Rechercher(arbre_t arbre, int search){
	if(arbre == NULL){
		printf("faux");
		return NULL;
	}
	else{
		if( search == arbre->valeur){
			printf("vrai");
		}
		else{
			if(search < arbre->valeur){
				return Rechercher(arbre->gauche ,search);
			}
			else{
				if(search > arbre->valeur){
					return Rechercher(arbre->droit ,search);
				}
				else{
                    printf("faux");
				}
			}
		}
	}
}

int  Maximum(arbre_t arbre){

	if( arbre == NULL){
		return NULL;
	}
	else{
		while(arbre->droit !=NULL){
			arbre = arbre->droit;
		}
	}
	return  arbre->valeur;
}

int Minimum(arbre_t arbre){

	if( arbre == NULL){
		return NULL;
	}
	else{
		while(arbre->gauche !=NULL){
			arbre = arbre->gauche;
		}
	}
	return  arbre->valeur;

}


int Successeur(arbre_t arbre , int  val){
      noeud_t rval =  Recherche( arbre, val);
      if(rval->droit != NULL){
			return Minimum(rval->droit);
		}
		noeud_t tmp = rval->pere;
        while(tmp != NULL && rval == tmp->droit){
            rval = tmp ;
            tmp->droit = rval;
			}
		return tmp->valeur;
	}

void Predecesseur(arbre_t arbre , int val){
      noeud_t rval =  Recherche( arbre, val);

      if(rval->gauche != NULL){
			return Maximum(rval->gauche);
		}
		noeud_t tmp = rval->pere;
        while(tmp != NULL && rval == tmp->gauche){
            rval = tmp ;
            tmp->gauche = rval;
			}
         printf("le predecesseur est \n");
		/*return tmp->valeur;*/
	}

void detruit_arbre( arbre_t arbre){
	if(arbre == NULL)
		return ;
	detruit_arbre(arbre->gauche ) ;
	detruit_arbre(arbre->droit) ;
	free(arbre) ;
}

int nombre_de_noeuds (arbre_t arbre){
	if(arbre == NULL)
		return 0 ;
	return ( 1 + nombre_de_noeuds (arbre->gauche ) + nombre_de_noeuds (arbre->droit )) ;
}

void affiche_arbre_rec(arbre_t arbre){
	if(arbre != NULL) {
		affiche_arbre_rec(arbre->gauche ) ;
	if(arbre->gauche != NULL)
		printf( " , " ) ;
		printf("%d" ,arbre->valeur) ;
	if(arbre->droit != NULL)
		printf( " , " ) ;
		affiche_arbre_rec( arbre->droit) ;
	}
}

void affiche_arbre(arbre_t  arbre) {
		affiche_arbre_rec(arbre);
		printf( " \n" );
}


void affiche_arbre2_rec(arbre_t arbre) {
	if(arbre == NULL)
		printf( "_" ) ;
	else{
		printf( " { " ) ;
		affiche_arbre2_rec(arbre->gauche ) ;
		printf(",%d," , arbre->valeur) ;
		affiche_arbre2_rec(arbre->droit) ;
		printf( " } " ) ;
	}
}
void affiche_arbre2(arbre_t arbre ) {
	affiche_arbre2_rec ( arbre ) ;
	printf( " \n" ) ;
}


arbre_t insere( arbre_t arbre , int valeur ) {
	if ( arbre == NULL)
		return cree_arbre ( valeur , NULL, NULL ) ;
	else {
		if ( valeur < arbre->valeur )
			arbre->gauche = insere( arbre->gauche , valeur ) ;
		else /* valeur >= arbre->valeur */
			arbre->droit = insere(arbre->droit , valeur ) ;
		return arbre ;
}
}


arbre_t supprime ( arbre_t arbre , int valeur) {
	noeud_t noeud = arbre , * pere = &arbre ;
	noeud_t nouveau_noeud , *nouveau_pere ;
	while ( noeud != NULL) {
		if ( valeur == noeud->valeur )
			break ;
		if(valeur < noeud->valeur ) {
			pere = &noeud->gauche ;
			noeud = noeud->gauche ;
		}
		else{ /* valeur >= noeud->valeur */
			pere = &noeud->droit ;
			noeud = noeud->droit ;
		}
	}
	if ( noeud != NULL) {
		if ( noeud->gauche == NULL) {
			if ( noeud->droit == NULL) {
				* pere= NULL;
				free( noeud ) ;
			}
			else{ /* noeud->droit!= NULL */
				*pere = noeud->droit ;
				free( noeud ) ;
			}
		}
		else { /* noeud->gauche != NULL */
			if( noeud->droit == NULL) {
				* pere = noeud->gauche ;
				free( noeud ) ;
			}
			else{ /* noeud->droit != NULL *//* recherche de la plus petite a leur du sous-arbre droit */
				nouveau_noeud = noeud->droit ;
				nouveau_pere = &noeud->droit ;
				while ( nouveau_noeud != NULL)
					if( nouveau_noeud->gauche != NULL) {
						nouveau_pere = &nouveau_noeud->gauche ;
						nouveau_noeud = nouveau_noeud->gauche ;
					}
				noeud->valeur = nouveau_noeud->valeur ;
				*nouveau_pere = nouveau_noeud->droit ;
				free( nouveau_noeud ) ;
			}
		}
	}
	return arbre ;
}
arbre_t insereracine( arbre_t arbre , int vale )
{
    noeud_t noeud = arbre , *pere ;
	noeud_t nouveau_noeud , *nouveau_pere ;
	if(vale < noeud->valeur ) {

            if(noeud->gauche==NULL){

                noeud_t l=(arbre_t*)malloc(sizeof(arbre_t));
                l->valeur=vale;
                l->gauche=NULL;
                l->droit=noeud;
                l->pere=NULL;
                noeud=l;
                arbre=noeud;
            }
            if(noeud->gauche!=NULL){
                     while ( noeud != NULL) {
		                  if ( vale < noeud->valeur ){
                              pere = noeud->gauche ;
                              noeud = noeud->gauche ;
		                  }
		            }
		            noeud_t l=(arbre_t*)malloc(sizeof(arbre_t));
                    l->valeur=vale;
                    l->gauche=NULL;
                    l->droit=noeud;
                    l->pere=NULL;
                    noeud=l;
                  arbre=noeud;
            }
	}
    else{ /* valeur >= noeud->valeur */
        while ( noeud != NULL) {
		    if ( noeud->valeur < vale < noeud->droit->valeur )
			   break ;
			pere = &noeud->droit ;
			noeud = noeud->droit ;
		}
        noeud_t l=(arbre_t*)malloc(sizeof(arbre_t));
        l->valeur=vale;
        l->gauche=pere;
        l->droit=noeud;
        arbre->pere=l;

	}

/*    arbre_t l,t;
    if(arbre->valeur>vale)
    {
        arbre_t p=arbre->gauche;
        while(p->valeur>vale)
        {
           t=p;
           p=p->gauche;
        }
        l=(arbre_t*)malloc(sizeof(arbre_t));

        l->valeur=vale;
        l->gauche=p;
        l->droit=t;
        arbre=l;
    }
    else{
         if(arbre->valeur<vale)
        {
            arbre_t p=arbre->droit;
            printf("azer");
            while(p->valeur<vale)
            {
               t=p;
               printf("azer");
               p=p->droit;
            }
            printf("azer");
            l=(arbre_t*)malloc(sizeof(arbre_t));
            l->valeur=vale;
            l->gauche=t;
            l->droit=p;
            arbre=l;
        }
    }*/
    return arbre;
}
