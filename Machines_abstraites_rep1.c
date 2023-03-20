#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
typedef char* type_elem_XOR ;
typedef struct Maillon_XOR *Pointeur_XOR ;
struct Maillon_XOR {
    type_elem_XOR   Val ;
    Pointeur_XOR   npx ;
} ;
void Allouer_XOR(Pointeur_XOR* P){
     *P = malloc(sizeof(struct Maillon_XOR)) ;
    (*P)-> Val = malloc(sizeof(char)*16) ;
    (*P)-> npx = NULL ;
}
type_elem_XOR Valeur_XOR(Pointeur_XOR P){
    return P -> Val ;
}
Pointeur_XOR XOR(Pointeur_XOR P,Pointeur_XOR Q) // Fonction qui effectue l'operation du XOR entre 2 adresses
{
    return (Pointeur_XOR)((uintptr_t)(P)^ (uintptr_t)(Q));
}
void Liberer_XOR (Pointeur_XOR P){
    free(P) ;
}
Pointeur_XOR Suivant_XOR (Pointeur_XOR Precedent,Pointeur_XOR P){
    return XOR(Precedent, P->npx) ;
}
Pointeur_XOR Precedent_XOR(Pointeur_XOR Suivant, Pointeur_XOR P){
    return  XOR(Suivant, P->npx) ;
}
void aff_val_XOR (Pointeur_XOR P, type_elem_XOR Val){
    P -> Val = Val ;
}
void aff_adr_XOR (Pointeur_XOR P, Pointeur_XOR Q)
{
    P -> npx = Q ;
}
