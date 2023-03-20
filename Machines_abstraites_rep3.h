/** Implémentation **\: LISTE DE ENTIERS**/
typedef char* Typeelem_Li ;
typedef struct Maillon_Lb * Pointeur_Lb ;
typedef int bool ;

#define True 1 
#define False 0

struct Maillon_Lb
{
Typeelem_Li Val ;
Pointeur_Lb Adrg ;	// adresse vers le maillon à gauche
Pointeur_Lb Adrd ; // adresse vers le maillon à droite
} ; // on définit la strcuture du maillon 


void Allouer_Lb (Pointeur_Lb *P) // allouer un espace et retourner son adresse
{
*P = (struct Maillon_Lb *) malloc(sizeof(struct Maillon_Lb));
(*P)->Val = malloc(sizeof(char)*16);
(*P)->Adrg = NULL;
(*P)->Adrd = NULL;
}


void Liberer_Lb ( Pointeur_Lb P) // libérer l'espace déja alloué
{ free (P);}

Pointeur_Lb Suivant_Lb( Pointeur_Lb P) // retourner l'adresse du prochain élément contenu dans le maillon P
{ return( P->Adrd ) ; }

Pointeur_Lb Precedent_Lb( Pointeur_Lb P) // retourner l'adresse du l'élément qui precède le maillon P
{ return( P->Adrg ) ; }

Typeelem_Li Valeur_Lb( Pointeur_Lb P) // retourner l'information contenue dans le maillon P
{ return( P->Val) ; }

void Aff_val_Lb(Pointeur_Lb P, Typeelem_Li Val) // affecter l'information au champ vam du maillon P
{
P->Val = Val ;
}

void Aff_adrd( Pointeur_Lb P, Pointeur_Lb Q)// lier P à une autre adresse vers la droite
{
P->Adrd = Q ;
}

void Aff_adrg( Pointeur_Lb P, Pointeur_Lb Q)// lier P à une autre adresse vers la gauche
{
P->Adrg = Q ;
}
// end of abstract machines *******************

 
