#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void affich_ID(char *mat[])
{
    for (int i = 0 ; i < 1000 ; i++)
    {
        printf("%s", mat[i]) ;
        printf("\n") ;
    }
}
void create_llc3(Pointeur_Lb *P, char* mat[]){
    Pointeur_Lb temp = NULL, iter = NULL ,iter1 = NULL, next = NULL ;
    Allouer_Lb(P) ; //allouer
    Aff_val_Lb(*P, mat[0]); //init
    Aff_adrd(*P, *P) ; //init
    Aff_adrg(*P, *P) ; //init
    // creer la liste
    int i = 1 ;
    while(i < 1000){
        Allouer_Lb(&temp) ;
        Aff_val_Lb(temp,mat[i]);
        iter = *P ;
        if (strcmp(Valeur_Lb(temp), Valeur_Lb(*P))<0) {
            Aff_adrd(temp, *P);
            Aff_adrg(temp, Precedent_Lb(*P));
            Aff_adrd(Precedent_Lb(*P),temp);
            Aff_adrg(*P,temp);
            *P = temp;
        }
        else
        {
            while((strcmp(Valeur_Lb(temp),Valeur_Lb(Suivant_Lb(iter)))>0) && (Suivant_Lb(iter)) != *P)
                iter = Suivant_Lb(iter);
                next = Suivant_Lb(iter);
                Aff_adrd(iter, temp);
                Aff_adrg(temp, iter);
                Aff_adrd(temp, next);
                Aff_adrg(next, temp);
        }
        i++;
}
    iter1 = *P;
}
void remp_mat(char *mat[])
{
    for (int i = 0 ; i < 1000 ;i++)
    {
        mat[i] = randstring(16) ;
    }
}
void affich_llc3(Pointeur_Lb P){
    Pointeur_Lb iter1 = P ;
    do
    {
        printf("L identifiant: %s\tl@ prec %p \tl@ du mallion: %p\tl@ du suiv: %p\n", Valeur_Lb(iter1), Precedent_Lb(iter1), iter1, Suivant_Lb(iter1));
        iter1 = Suivant_Lb(iter1) ;
    } while(iter1 != P) ;
}
int rech_val3 (Pointeur_Lb P, char val[]){
    int b = 0 ;
    int cpt = 0 ;
    Pointeur_Lb iter = P ;
    do
    {
        if (strcmp(val, Valeur_Lb(iter)) == 0) {
            b = 1 ;//Trouve
        }
        else
        {
            iter = Suivant_Lb(iter) ;
        }
        cpt++ ;// La position
    }
    while((iter != P) && (b == 0)) ;
    if (b == 0) {
        cpt = 0 ;//Non trouve
    }
    return cpt ;
}
void insersion_val3 (Pointeur_Lb *P,char val[16]){
    Pointeur_Lb temp = NULL, next = NULL;
    int ins = 0, b = 0 ;
    Pointeur_Lb iter = *P;
    Allouer_Lb(&temp);
    Aff_val_Lb(temp,val);
    b = rech_val3(*P,val);
    if (b == 0)
    {
    while (ins == 0)
    {   iter = *P;
        Allouer_Lb(&temp);
        Aff_val_Lb(temp,val);
        if (strcmp(Valeur_Lb(temp),Valeur_Lb(*P))<0) {
            Aff_adrd(temp,*P);
            Aff_adrg(temp,Precedent_Lb(*P));
            Aff_adrd(Precedent_Lb(*P),temp);
            Aff_adrg(*P,temp);
            *P = temp;
            ins = 1 ;
        }
        else
        {
                while((strcmp(Valeur_Lb(temp),Valeur_Lb(Suivant_Lb(iter)))>0) && (Suivant_Lb(iter)!= *P))
                iter = Suivant_Lb(iter);
                next = Suivant_Lb(iter);
                Aff_adrd(iter,temp);
                Aff_adrg(temp,iter);
                Aff_adrd(temp,next);
                Aff_adrg(next,temp);
                ins = 1 ;
        }
    }
    }
    else
    {
        printf("Insertion impossible (identifiant deja existant) \n") ;
    }
}

