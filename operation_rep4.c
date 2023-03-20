#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Biblio_LLC_contigues.h"
void insertval_contig(LLC_contigue *L,Typeelem_Li v)
{
    int i=L->tete,prec;

        while((i+1<Taille_Max)&&(strcmp(L->Tab[i].val,v)>0)) // Recherche de la case correspondarte a v
        {
            prec=i;
            i=suivant_T(*L,i);
        }
        if((i+1<Taille_Max)&&(L->Tab[i+1].vide==TRUE)) // case suivante vide (decalage d'un element)
        {
           aff_val_T(L,i+1,valeur_T(*L,i));
           aff_adr_T(L,i+1,suivant_T(*L,i));
           L->Tab[i+1].vide=FALSE;
           aff_val_T(L,i,v);
           aff_adr_T(L,i,i+1);
        }
        else //case suivante non vide (decalage de tous les elements(se trouvant avant une case vide))
        {
            while((i<Taille_Max)&&(L->Tab[i+1].vide=FALSE))
            i=suivant_T(*L,i);
            if(i<Taille_Max)
            {
              while(i!=suivant_T(*L,prec)-1)
               {
                 aff_val_T(L,i+1,L->Tab[i].val);
                 if(L->Tab[i+1].vide==TRUE)
                     aff_adr_T(L,i+1,suivant_T(*L,i));
                 else
                     aff_adr_T(L,i+1,i+2);
                  L->Tab[i+1].vide=FALSE;
                  i--;
               }
                aff_val_T(L,i+1,v);
                aff_adr_T(L,i+1,i+2);
            }
        }
        L->taille++;
}

int rechval_contigue(LLC_contigue L,Typeelem_Li v) //Recherche par valeur dans une LLC contigue
{
    int i=L.tete,ind=0;

    while((ind<L.taille)&&(L.Tab[i].val!=v))
    {
        ind++;
        i=suivant_T(L,i);
    }
    if(ind<L.taille)
        return i;
    else return -1;
}

void suppval_contigue(LLC_contigue *L,Typeelem_Li v)
{
    int i=L->tete, ind=0, prec; Typeelem_Li* x;

    while((ind<L->taille)&&(valeur_T(*L,i)!=v))
    {
        ind++;
        prec=i;
        i=suivant_T(*L,i);
    }
    if(ind<L->taille)
    {
        aff_adr_T(L,prec,suivant_T(*L,i));
        *x=valeur_T(*L,i);
        L->Tab[i].vide=TRUE;
    }
    else
        printf("\t\t Valeur non trouvee!\n");
}




int main()
{
    LLC_contigue list;

/* Insertion de la premiere valeur */
    init_vide_T(&list);
    printf("Valeur= ");
    scanf("%c",&(list.Tab[list.tete].val));
    list.taille ++;
    ecrit_LLC_contigue(list);
/* Insertion de la suite se fait par appel de la fct insertval_contigue() */

    return 0;
}
