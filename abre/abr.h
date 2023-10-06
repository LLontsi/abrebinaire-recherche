
#ifndef ABR_H_INCLUDE
#define ABR_H_INCLUDE

typedef struct noeud_s{
	int valeur ;
	struct noeud_s * gauche ;
	struct noeud_s * droit ;
    struct noeud_s * pere ;

} *noeud_t ;

typedef noeud_t arbre_t ;

arbre_t creer( int valeur  ) ;
arbre_t cree_arbre( int valeur , arbre_t gauche , arbre_t droit ) ;
arbre_t insereracine( arbre_t arbre , int vale ) ;
int  Maximum(arbre_t arbre);
int  Minimum(arbre_t arbre);
int Successeur(arbre_t arbre , int  val);
void Predecesseur(arbre_t arbre , int val);
noeud_t  Recherche(arbre_t arbre, int search);
void  Rechercher(arbre_t arbre, int search);
void detruit_arbre( arbre_t arbre);
int nombre_de_noeuds (arbre_t arbre);
void affiche_arbre_rec(arbre_t arbre);
void affiche_arbre(arbre_t  arbre) ;
void affiche_arbre2_rec(arbre_t arbre);
void affiche_arbre2(arbre_t arbre );
arbre_t insere( arbre_t arbre , int valeur ) ;
arbre_t supprime ( arbre_t arbre , int valeur);
void Prefixe(const arbre_t  arbre);
void Postfixe(const arbre_t  arbre);
void Infixe(const arbre_t  arbre);




#endif
