#define Taille_Max 1000

typedef enum {FALSE,TRUE} Booleen;
typedef char* Typeelem_Li;

struct Elt_Tab_LLC
{
    Typeelem_Li val;
    int suiv;
    Booleen vide;
};
typedef struct Elt_Tab_LLC Tab_LLC [Taille_Max];
typedef struct LLC_contigue
{
    Tab_LLC Tab;
    int tete;
    int taille;
} LLC_contigue;
/********************************************************************************/
/*                        Déclaration des fonctions                            */
/********************************************************************************/
void init_vide_T(LLC_contigue *Lc);
Typeelem_Li valeur_T(LLC_contigue Lc, int p);
int suivant_T(LLC_contigue Lc, int p);
void aff_adr_T(LLC_contigue *Lc, int p, int adr);
void aff_val_T(LLC_contigue *Lc, int p, Typeelem_Li val);
void ecrit_LLC_contigue(LLC_contigue Lc);
/********************************************************************************/
/*                Procédure d'implémentation de la bibliothèque                 */
/********************************************************************************/
void init_vide_T(LLC_contigue *Lc)
//Initialiser tout les champs Lc.Tab[].vide à vrai
{
    for (int i = 0; i < Taille_Max; i++)
        Lc->Tab[i].vide = TRUE;
    Lc->tete=0;
    Lc->taille=0;
}
/********************************************************************************/
Typeelem_Li valeur_T(LLC_contigue Lc, int p )
{
    return Lc.Tab[p].val;
}
/********************************************************************************/
int suivant_T(LLC_contigue Lc, int p)
{
    return Lc.Tab[p].suiv;
}
/********************************************************************************/
void aff_adr_T(LLC_contigue *Lc, int p, int adr)
{
    Lc->Tab[p].suiv = adr;
}
/********************************************************************************/
void aff_val_T(LLC_contigue *Lc, int p, Typeelem_Li val)
{
    Lc->Tab[p].val = val;
}
/********************************************************************************/
void ecrit_LLC_contigue(LLC_contigue Lc)
//Afficher le contenu d'une LLC contigue
{
    int p = Lc.tete, i=0;

    printf("----------Ecriture de la liste contigue----------\n");
    while (i< Lc.taille)
    {
        printf("| %s | -> ", Lc.Tab[p].val);
        p = suivant_T(Lc, p);
        i++;
    }
    printf("[= \n");
    printf("-------------------------------------------------\n");
}
/********************************************************************************/


