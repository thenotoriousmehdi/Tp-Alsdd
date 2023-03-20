#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *randstring(size_t length) { // const size_t length, supra

static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ0123456789";
char *randomString;
 
    randomString = malloc(length +1);//+1 to reserve a place for the null char
    if (randomString) {
        int l = (int) (sizeof(charset) -1); //Because the void char is counted
        int key;
        for (int n = 0;n < length;n++) {
            key = rand() % l; // Generate an alphanumeric char randomly
            randomString[n] = charset[key];
        }
        randomString[length] = '\0';
}
return randomString;
} // initialement y a le maillon p avec p comme adresse du suivant
void create_llc_2(Pointeur_Li *P, char* mat[]){
    int cpt = 1 ;
    Pointeur_Li iter = NULL,temp = NULL ;
while ((cpt < 1000))
{   iter = *P;
    Allouer_Li(&temp);
    Aff_val_Li(temp,mat[cpt]);
    if (strcmp(Valeur_Li(temp),Valeur_Li(*P))<0) {
        while(Suivant_Li(iter)!= *P){
            iter = Suivant_Li(iter);
        }
        Aff_adr_Li(temp,*P) ;
        *P = temp ;
        Aff_adr_Li(iter,*P) ;
    }
    else
    {
        while((strcmp(Valeur_Li(temp),Valeur_Li(Suivant_Li(iter)))>0) && (Suivant_Li(iter)!= *P))
            iter = Suivant_Li(iter);
            Aff_adr_Li(temp, Suivant_Li(iter));
            Aff_adr_Li(iter, temp);
    }
    cpt++;
}
}
int rech_val2 (Pointeur_Li P, char val[]){
    int b = 0 ;
    int cpt = 0 ;
    Pointeur_Li iter = P ;
    do
    {
        if (strcmp(val, Valeur_Li(iter)) == 0) {
            b = 1 ;
        }
        else
        {
            iter = Suivant_Li(iter) ;
        }
        cpt++ ;
    }
    while((iter != P) && (b == 0)) ;
    if (b == 0) {
        cpt = 0 ;
    }
    return cpt ;
}
void insersion_val2 (Pointeur_Li *P,char val[]){
    Pointeur_Li temp = NULL;
    int ins = 0, b = 0 ;
    Pointeur_Li iter = *P;
    Allouer_Li(&temp);
    Aff_val_Li(temp, val);
    b = rech_val2(*P, val);
    if (b == 0)
    {
    while (ins == 0)
    {   iter = *P;
        Allouer_Li(&temp);
        Aff_val_Li(temp, val);
        if (strcmp(Valeur_Li(temp),Valeur_Li(iter))<0) {
            while(Suivant_Li(iter)!=*P)
            iter = Suivant_Li(iter);
            Aff_adr_Li(temp, *P);
            *P = temp;
            Aff_adr_Li(iter, *P);
            ins = 1 ;
        }
        else
        {
                while((strcmp(Valeur_Li(temp), Valeur_Li(Suivant_Li(iter)))>0) && (Suivant_Li(iter)!= *P))
                iter = Suivant_Li(iter);
                Aff_adr_Li(temp, Suivant_Li(iter));
                Aff_adr_Li(iter, temp);
                ins = 1 ;
        }
    }
         
    }
    else
    {
        printf("Insertion impossible (identifiant deja existant) \n") ;
    }
}
void Longuer_LLC2(Pointeur_Li P){
    Pointeur_Li iter1 = P;
    int cpt = 1 ;
    while (Suivant_Li(iter1) != P) {
        cpt++ ;
        iter1 = Suivant_Li(iter1) ;
    }
}
void afficher_LLC2(Pointeur_Li P){
    Pointeur_Li iter1 = P;
    do
    {
        printf("L identifiant: %s\tl@ du mallion: %p\tl@ du suiv: %p\n", Valeur_Li(iter1), iter1, Suivant_Li(iter1));
        iter1 = Suivant_Li(iter1) ;
    } while(iter1 != P) ;
}
void supp_LLC2(Pointeur_Li *P, char val[]){
    Pointeur_Li iter1 = *P;
    Pointeur_Li iter2 = Suivant_Li(iter1);
    Pointeur_Li temp = NULL;
    temp = *P ;
    int found = 0;
    if (strcmp(val,Valeur_Li(*P)) == 0){
        do
        {
            temp = Suivant_Li(temp);
        }
        while(Suivant_Li(temp) != *P);
        *P = Suivant_Li(*P);
        Liberer_Li(iter1);
        Aff_adr_Li(temp, *P);
    }
    else
        while (found == 0)
        {
            if(strcmp(val, Valeur_Li(iter2)) != 0)
            {
                iter1 = Suivant_Li(iter1) ;
                iter2 = Suivant_Li(iter2) ;
            }
            else
            {
                Aff_adr_Li(iter1, Suivant_Li(iter2)) ;
                Liberer_Li(iter2) ;
                found = 1 ;
            }
        }
     
}
