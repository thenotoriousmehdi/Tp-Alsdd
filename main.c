#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Machines_abstraites_rep2.c"
#include "Operations_LLC2.c"
#include "Machines_abstraites_rep3.h"
#include "Operations_LLC3.c"
#include "Machines_abstraites_rep1.c"
#include "Operations_LLC1.c"
 
int main() {
    
    Pointeur_XOR P=NULL,Prec=NULL,temp=NULL ;
    Pointeur_Li Q = NULL;
    Pointeur_Lb R = NULL;
    int trouv = 0 ;
    int cas = 0 ;
    char ID1[16] ;
    char ID2[16] ;
    char *mat [1000] ;
    int choix ;
    for (int i = 0 ; i <1000 ; i++)
    {
        mat[i] = randstring(16) ;
    }
    printf("******** Bienvenue dans le TP1 d'ALSDD ********\n") ;
    printf("On affiche ci-dessous les 1000 identifiants a mettre dans les 4 listes :\n") ;
    for (int i = 0 ; i <1000 ; i++)
    {
        printf("%s\n", mat[i]) ;
    }
    printf("Quelle representation choisirez-vous pour stocker les 1000 identifiants dans l'ordre :\n") ;
    scanf("%d",&cas) ;
    switch (cas)
    {
        case 1 :
            printf("Donc vous avez choisi la reprensentation 1\n") ;
            Allouer_XOR(&P);
            aff_val_XOR(P, mat[0]);
            aff_adr_XOR(P, NULL);
            Prec = NULL ;
            Allouer_XOR(&temp) ;
            aff_val_XOR(temp, mat[1]) ;
            aff_adr_XOR(P, XOR(NULL,temp)) ;
            aff_adr_XOR(temp, XOR(P,NULL)) ;
            Creer_XOR(&P, mat) ;
            printf("Affichons la liste dans l'ordre des identifiants :\n") ;
            Afficher_GD(P) ;
            printf("Voulez-vous inserer un element dans la liste ?\n") ;
            printf("Si oui saisissez '1' et cliquez sur entrer, sinon saisissez '0' \n") ;
            scanf("%d", &choix) ;
            if (choix == 1){
                printf("Veuillez saisir l'ID que vous voulez inserer :\n");
                scanf("%s",ID1) ;
                inserer_XOR(&P, ID1) ;
                printf("Affichons la liste apres modification :\n") ;
                Afficher_GD(P) ;
            }
            break ;
        case 2 :
            printf("Donc vous avez choisi la reprensentation 2\n") ;
            Allouer_Li(&Q);
            Aff_val_Li(Q, mat[0]);
            Aff_adr_Li(Q, Q);
            create_llc_2(&Q, mat) ;
            printf("Affichons la liste dans l'ordre des identifiants :\n") ;
            afficher_LLC2(Q) ;
            printf("Voulez-vous rechercher un identifiant dans la liste ?\n") ;
            printf("Si oui saisissez '1' et cliquez sur entrer, sinon saisissez '0' \n") ;
            scanf("%d", &choix) ;
            if (choix == 1){
                printf("Veuillez saisir l'ID que vous voulez rechercher :\n");
                scanf("%s",ID2) ;
                trouv = rech_val2(Q, ID2) ;
                if(trouv == 0){
                    printf("ID non trouve\n") ;
                }
                else
                    printf("ID trouve a la position %d \n", trouv) ;
                
                printf("Voulez-vous ajouter un identifiant dans la liste ?\n") ;
                printf("Si oui saisissez '1' et cliquez sur entrer, sinon saisissez '0' \n") ;
                scanf("%d", &choix) ;
                if (choix == 1) {
                    printf("Veuillez saisir l'ID que vous voulez ajouter :\n");
                    scanf("%s",ID2) ;
                    insersion_val2(&Q, ID2) ;
                    printf("Affichons la liste apres modification :\n") ;
                    afficher_LLC2(Q) ;
                }
                printf("Voulez-vous supprimer un identifiant dans la liste ?\n") ;
                printf("Si oui saisissez '1' et cliquez sur entrer, sinon saisissez '0' \n") ;
                scanf("%d\n", &choix) ;
                if (choix == 1) {
                    printf("Veuillez saisir l'ID que vous voulez supprimer :\n");
                    scanf("%s",ID2) ;
                    supp_LLC2(&Q, ID2) ;
                    printf("Affichons la liste apres modification :\n") ;
                    afficher_LLC2(Q) ;
                }
                break ;
            case 3 :
                printf("Donc vous avez choisi la reprensentation 3\n") ;
                create_llc3(&R, mat) ;
                printf("Affichons la liste dans l'ordre des identifiants :\n") ;
                affich_llc3(R) ;
                printf("Voulez-vous rechercher un identifiant dans la liste ?\n") ;
                printf("Si oui saisissez '1' et cliquez sur entrer, sinon saisissez '0' \n") ;
                scanf("%d", &choix) ;
                if (choix == 1){
                    printf("Veuillez saisir l'ID que vous voulez rechercher :\n");
                    scanf("%s",ID2) ;
                    trouv = rech_val3(R, ID2) ;
                    if(trouv == 0){
                        printf("ID non trouve\n") ;
                    }
                    else
                        printf("ID trouve a la position %d \n", trouv) ;
                    
                    printf("Voulez-vous ajouter un identifiant dans la liste ?\n") ;
                    printf("Si oui saisissez '1' et cliquez sur entrer, sinon saisissez '0' \n") ;
                    scanf("%d", &choix) ;
                    if (choix == 1) {
                        printf("Veuillez saisir l'ID que vous voulez ajouter :\n");
                        scanf("%s",ID2) ;
                        insersion_val3(&R, ID2);
                        printf("Affichons la liste apres modification :\n") ;
                        affich_llc3(R) ;
                    }
            
                }
                break ;
            
             }
    return 0;
}
}
