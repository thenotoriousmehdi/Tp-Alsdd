#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
void Creer_XOR(Pointeur_XOR* P, char* mat[]) {
    Pointeur_XOR  Suiv=NULL,Prec=NULL,iter=NULL,temp=NULL,temp1=NULL;
    int cpt = 2 ;
    while(cpt < 1000) {
    Allouer_XOR(&temp) ;
    aff_val_XOR(temp, mat[cpt]) ;
        aff_adr_XOR(temp , NULL) ;
        iter = *P ;
    if(strcmp(Valeur_XOR(temp),Valeur_XOR(*P))<0)
    {
                     
            iter->npx = XOR(temp,XOR(NULL, iter->npx));
            temp->npx = XOR(NULL, iter);
            *P =  temp;
    }
        
    else {
        iter = *P ;
        Prec = NULL ;
        Suiv = XOR(Prec, iter->npx) ;
        while((Suiv != NULL)&&(strcmp((Valeur_XOR(temp)),(Valeur_XOR(Suiv)))>0)){
            Prec = iter ;
            iter = Suiv ;
            Suiv = XOR(Prec ,iter->npx) ;
        }
                    temp1 = XOR(iter->npx, Suiv);
                    iter->npx = XOR(temp1, temp);
                    if (Suiv!= NULL) {
                        Suiv->npx = XOR(temp,XOR(Suiv->npx, iter));
                    }
                    temp->npx = XOR(iter, Suiv);
    }cpt++ ;
    }
}
void Afficher_GD(Pointeur_XOR P){
    Pointeur_XOR Curr = P, iter = NULL, Prec = NULL ;
    while (Curr != NULL){
        printf("ID: %s\t  @maillon: %p\t  npx:  %p\t     Prec: %p\t   Suiv: %p\n", Valeur_XOR(Curr),Curr, Curr->npx,Precedent_XOR(Suivant_XOR(Prec,Curr), Curr),Suivant_XOR(Prec,Curr)) ;
        iter = XOR(Prec ,Curr ->npx) ;
        Prec = Curr ;
        Curr = iter ;
    }
}
void inserer_XOR(Pointeur_XOR *P,char ID[]){
    Pointeur_XOR temp= NULL,temp1=NULL,iter=NULL,Prec=NULL,Suiv=NULL ;
    Allouer_XOR(&temp) ;
    aff_val_XOR(temp, ID) ;
        aff_adr_XOR(temp , NULL) ;
        iter = *P ;
    if(strcmp(Valeur_XOR(temp),Valeur_XOR(*P))<0)
    {
                     
            iter->npx = XOR(temp,XOR(NULL, iter->npx));
            temp->npx = XOR(NULL, iter);
            *P =  temp;
    }
        
    else {
        iter = *P ;
        Prec = NULL ;
        Suiv = XOR(Prec, iter->npx) ;
        while((Suiv != NULL)&&(strcmp((Valeur_XOR(temp)),(Valeur_XOR(Suiv)))>0)){
            Prec = iter ;
            iter = Suiv ;
            Suiv = XOR(Prec ,iter->npx) ;
        }
                    temp1 = XOR(iter->npx, Suiv);
                    iter->npx = XOR(temp1, temp);
                    if (Suiv!= NULL) {
                        Suiv->npx = XOR(temp,XOR(Suiv->npx, iter));
                    }
                    temp->npx = XOR(iter, Suiv);
}
}
