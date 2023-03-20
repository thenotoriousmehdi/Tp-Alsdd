#include <stdio.h>
#include <stdlib.h>
/** ImplÈmentation **\: LISTE DE ENTIERS**/
typedef char* Typeelem_Li ;
typedef struct Maillon_Li * Pointeur_Li ;
struct Maillon_Li
{
Typeelem_Li Val ;
Pointeur_Li Suiv ;
} ; // on dÈfinit la strcuture du maillon

void Allouer_Li (Pointeur_Li *P) // allouer un espace et retourner son adresse
{
*P = (struct Maillon_Li *)malloc(sizeof(struct Maillon_Li)) ;
(*P)-> Val = malloc(sizeof(char)*16) ;
(*P)->Suiv = NULL;
}


void Liberer_Li ( Pointeur_Li P) // libÈrer l'espace dÈja allouÈ
{ free (P);}

Pointeur_Li Suivant_Li( Pointeur_Li P) // retourner l'adresse du prochain ÈlÈment contenu dans le maillon P
{ return( P->Suiv ) ; }


Typeelem_Li Valeur_Li(Pointeur_Li P) // retourner l'information contenue dans le maillon P
{ return( P->Val) ; }

void Aff_val_Li(Pointeur_Li P, Typeelem_Li Val) // affecter l'information au champ vam du maillon P
{
P->Val = Val ;
}

void Aff_adr_Li( Pointeur_Li P, Pointeur_Li Q)// lier P ‡ une autre adresse
{
P->Suiv = Q ;
}
