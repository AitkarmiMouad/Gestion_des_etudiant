#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct type _Date ayant les variable num , ville
typedef struct
{
    int mois;
    int jour;
    int annee;
} _Date;
// struct type _adress ayant les variable num , ville
typedef struct
{
    int num;
    char *ville[20];
} _adress;
// struct type Etudiant ayant les variable CNE , nom , prenom , adress
typedef struct
{
    int CNE;
    char *nom[50];
    char *prenom[50];
    _Date dateNaissance;
    _adress adress;
} Etudiant;
// declaration variable globale pointeur Etudiant e
Etudiant *e;
//declaration des variable
int nbr_etudiant, cne, x, posa, posb;
// fonction presentation interface du programe
void presentation()
{
    system("title PROGRAMME DE GESTION D'ETUDIANTS");
    printf("\t\t****************************************************\n");
    printf("\t\t*                                                  *\n");
    printf("\t\t*         PROGRAMME DE GESTION D'ETUDIANTS         *\n");
    printf("\t\t*             ------------------------             *\n");
    printf("\t\t*                                                  *\n");
    printf("\t\t****************************************************\n\n\n\n");
    system("pause");
}
// fonction saisie pour ajouter un etudiant et retourne le tableau de type Etudiant
Etudiant *saisie(int taille)
{
    //inintialisation de variable 'e' et allocation
    e = (Etudiant *)malloc(taille * sizeof(Etudiant));

    //for loop sur la table pour remplissage
    for (int i = 0; i < taille; i++)
    {
        system("CLS");
        printf("\n\t\t\t***Ajout d'etudiant Numero %d ***\n", i + 1);
        printf("\n Entrer le CNE du nouveau Etudiant: ");
        scanf("%d", &e[i].CNE);
        printf("\n Entrer le Nom de l'Etudiant: ");
        scanf("%s", &e[i].nom);
        printf("\n Entrer le Prenom de l'Etudiant: ");
        scanf("%s", &e[i].prenom);
        printf("\n Entrer la Date de Naissance de l'Etudiant: ");
        printf("\n Jour : ");
        scanf("%d", &e[i].dateNaissance.jour);
        printf("\n Mois : ");
        scanf("%d", &e[i].dateNaissance.mois);
        printf("\n Annee : ");
        scanf("%d", &e[i].dateNaissance.annee);
        printf("\n Entrer l'adresse de l'Etudiant: ");
        printf("\n Num : ");
        scanf("%d", &e[i].adress.num);
        printf("\n Ville : ");
        scanf("%s", &e[i].adress.ville);
        printf("\n\n\t\t\t***Ajout avec succes***\n\n\n");
        system("pause");
    }
    // reinitialisation de variable nbr_etudiant
    nbr_etudiant = taille;

    return e;
}
// fonction Affichage des Etudiant
void Afficher(Etudiant *LEtd, int taille)
{
    system("CLS");

    printf("\t------------------------------------Liste Des Etudiants------------------------------------\n");
    printf("\t-------------------------------------------------------------------------------------------\n");
    // for loop sur la table avec gestion en cas de table vide
    if (taille > 0)
    {
        for (int i = 0; i < taille; i++)
        {
            printf("\n\n\n\t\t\t****************** Etudiant Numero %d ******************\n", i + 1);
            printf("\n CNE               : %d ", LEtd[i].CNE);
            printf("\n Nom               : %s ", LEtd[i].nom);
            printf("\n Prenom            : %s ", LEtd[i].prenom);
            printf("\n Date de Naissance : %d/%d/%d ", LEtd[i].dateNaissance.jour, LEtd[i].dateNaissance.mois, LEtd[i].dateNaissance.annee);
            printf("\n Adresse           : %d,%s \n\n\n ", LEtd[i].adress.num, LEtd[i].adress.ville);
        }

        system("pause");
    }
    else
    {
        printf("\nLe Tableau est Vide\n");
        system("pause");
    }
}
// fonction Menu Pour afficher un menu avec des choix pour naviguer
int Menu()
{
    system("cls");

    int op; //options du menu

    system("title PROGRAMME DE GESTION D'ETUDIANTS");
    system("cls");
    printf("\t\t\t\t       MENU \n");
    printf("\t\t\t--------------------------------------------------\n");
    printf("\t\t\t| 1>> Ajouter un Etudiant                        |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 2>> Supprimer un Etudiant                      |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 3>> Afficher tout le contenu                   |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 4>> Chercher un Etudiant                       |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 5>> Afficher les informations d un etudiant    |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 6>> Modifier les enregistrements d un etudiant |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 7>> Trier la liste des étudiants               |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 8>> Changer la Position d un enregistrement    |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 9>> Sauvegarder les donnees                    |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 10>> Chercher Dans Fichier                     |\n");
    printf("\t\t\t|                                                |\n");
    printf("\t\t\t| 11>> Quitter le programme                      |\n");
    printf("\t\t\t|------------------------------------------------|\n");

    printf("\n Entrer votre choix: ");
    scanf("%d", &op);

    return op;
}
// fonction affichage par CNE
void AfficheParCNE(Etudiant *LEtd, int cne, int taille)
{
    system("CLS");
    printf("\t-------------------------------------------------------------------------------------------\n");
    printf("\t-------------------------------------------------------------------------------------------\n");

    // for loop sur la table avec gestion en cas de table vide
    if (taille > 0)
    {
        for (int i = 0; i < taille; i++)
        {
            //comparaison du cne donnee avec cne dans la table
            if (LEtd[i].CNE == cne)
            {
                printf("\nPosition Numero : %d \n", i + 1);
                printf("\n\n\t\t\t****************** Info Etudiant ******************\n");
                printf("\n CNE               : %d ", LEtd[i].CNE);
                printf("\n Nom               : %s ", LEtd[i].nom);
                printf("\n Prenom            : %s ", LEtd[i].prenom);
                printf("\n Date de Naissance : %d/%d/%d ", LEtd[i].dateNaissance.jour, LEtd[i].dateNaissance.mois, LEtd[i].dateNaissance.annee);
                printf("\n Adresse           : %d,%s \n\n\n ", LEtd[i].adress.num, LEtd[i].adress.ville);
                system("pause");
                return;
            }
        }
        printf("\n\nCe CNE n'existe pas\n\n");
        system("pause");
    }
    else
    {

        printf("\n\nLa Table est vide\n\n");
        system("pause");
    }
}
// fonction pour supprimer un etudiant a travers son CNE
void SupprimerEtdParCNE(Etudiant *LEtd, int cne, int taille)
{
    system("CLS");
    printf("\t-------------------------------------------------------------------------------------------\n");
    printf("\t-------------------------------------------------------------------------------------------\n");

    //boucle imbrique pour supprimer la cellule et decaler les autre cellule par une case
    for (int i = 0; i < taille; i++)
    {
        // comparaison du CNE
        if (LEtd[i].CNE == cne)
        {

            for (int j = i; j < taille; j++)
            {
                LEtd[i] = LEtd[j + 1];
                i++;
            }
            // Table etudiant de nouvelle taille (taille - 1) avec les enregistrement sans celui qu'on a supprimer
            Etudiant *temp = (Etudiant *)realloc(LEtd, (taille - 1) * (sizeof(Etudiant)));

            printf("\n\nSupprimer avec succes\n\n");
            // initialisation de variable globale e et le nbr_etudiant
            e = temp;
            nbr_etudiant = taille - 1;
            system("pause");

            return;
        }
    }

    printf("\n\nCe CNE n'existe pas\n\n");
    system("pause");
}
//fonction de recherche dichotomique retourne la table etudiant
Etudiant *ChercherDich(Etudiant *LEtd, int cne)
{
    int POS = -1;                             /* position de la valeur */
    int INF = 0, MIL, SUP = nbr_etudiant - 1; /* limites du champ de recherche */
    while ((INF <= SUP) && (POS == -1))
    {
        MIL = (SUP + INF) / 2;
        if (cne < LEtd[MIL].CNE)
            SUP = MIL - 1;
        else if (cne > LEtd[MIL].CNE)
            INF = MIL + 1;
        else
            POS = MIL;
    }

    /* Edition du résultat */
    if (POS == -1)
    {
        printf("La Valeur recherchée ne se trouve pas dans le tableau.\n");
        system("pause");
        return NULL;
    }
    else
    {
        printf("La Valeur %d se trouve a la position %d. \n", cne, POS + 1);
        Etudiant e[1] = {LEtd[POS]};
        system("pause");
        return e;
    }
}
//fonction pour changer la place entre de enregistrement i et j
void echange_Etd(int i, int j, Etudiant *LEtd)
{

    Etudiant temp = LEtd[j - 1];
    LEtd[j - 1] = LEtd[i - 1];
    LEtd[i - 1] = temp;
    e = LEtd;

    printf("\n\Changer avec succes\n\n");

    system("pause");
}
// fonction de Tri par selection d'une table etudiant
void Tri(Etudiant *LEtd, int taille)
{
    Etudiant a;
    for (int i = 0; i < taille; ++i)
    {

        for (int j = i + 1; j < taille; ++j)
        {

            if (LEtd[i].nom > LEtd[j].nom)
            {

                a = LEtd[i];
                LEtd[i] = LEtd[j];
                LEtd[j] = a;
            }
        }
    }
}
// fonction pour sauvegarder Une table etudiant dans un fichier .txt
void Sauvegarde(Etudiant *LEtd, int taille)
{
    // creer et ouvrir le fichier
    FILE *f = fopen("etudiant.txt", "w+");
    // ecrire dans le fichier
    for (int i = 0; i < taille; i++)
    {
        fprintf(f, "CNE : %d , Nom : %s , Prenom : %s , Date de Naiss : %d/%d/%d , Adresse : %d,%s\n", LEtd[i].CNE, LEtd[i].nom, LEtd[i].prenom, LEtd[i].dateNaissance.jour, LEtd[i].dateNaissance.mois, LEtd[i].dateNaissance.annee, LEtd[i].adress.num, LEtd[i].adress.ville);
    }
    // fermer le fichier
    fclose(f);
}
// fonction pour modifier un enregistrement (nom,prenom,date de naissance,adresse)
void Modifier(Etudiant *LEtd, int cne, int taille)
{
    // variable utilise pour while
    int q;
    if (taille > 0)
    {
        // choix d'enregistrement a modifier
        int choix;
        system("cls");
        printf("Choisisser l enregistrement a Modifier :\n\n 1)Nom\t2)Prenom\t3)Date de naissance\t4)Adresse\n\n");
        scanf("%d", &choix);

        for (int i = 0; i < taille; i++)
        {
            //gestion du CNE s'il existe
            if (LEtd[i].CNE == cne)
            {
                do
                {
                    // choix d'enregistrement a modifier
                    system("cls");
                    printf("Choisisser l enregistrement a Modifier :\n\n 1)Nom\t2)Prenom\t3)Date de naissance\t4)Adresse\n\n");
                    scanf("%d", &choix);
                    q = 0;
                    switch (choix)
                    {
                    case 1:
                        printf("\n Entrer le Nom de l'Etudiant: ");
                        scanf("%s", &LEtd[i].nom);
                        break;
                    case 2:
                        printf("\n Entrer le Prenom de l'Etudiant: ");
                        scanf("%s", &LEtd[i].prenom);
                        break;
                    case 3:
                        printf("\n Entrer la Date de Naissance de l'Etudiant: ");
                        printf("\n Jour : ");
                        scanf("%d", &LEtd[i].dateNaissance.jour);
                        printf("\n Mois : ");
                        scanf("%d", &LEtd[i].dateNaissance.mois);
                        printf("\n Annee : ");
                        scanf("%d", &LEtd[i].dateNaissance.annee);
                        break;
                    case 4:
                        printf("\n Entrer l'adresse de l'Etudiant: ");
                        printf("\n Num : ");
                        scanf("%d", &LEtd[i].adress.num);
                        printf("\n Ville : ");
                        scanf("%s", &LEtd[i].adress.ville);
                        break;
                    default:
                        printf("\nVous devez choisir un chiffre figurant dans le MENU !!!\n");
                        break;
                    }
                    printf("\n\nModifier avec Succes\n");
                    printf("\n\nVous Voulez Continuer a modifier?\n\n1) oui\n2) non\n");
                    scanf("%d", &q);
                } while (q == 1);

                system("pause");
                return;
            }
        }
        printf("\n\nCe CNE n'existe pas\n\n");
        system("pause");
    }
    else
    {

        printf("\n\nLa Table est vide\n\n");
        system("pause");
    }
}
// fonction Pour Chercher Dans un fichier .txt sur un enregistrement utilisant (CNE,nom,Prenom)
void ChercherFichier()
{
    // Declaration Des Variable
    char chunk[225], var[255], buf[255];
    int varInt, choix;
    // choix de la methode de recherche
    system("cls");
    printf("Choisisser la Methode de recherche :\n\n 1)Cne\t2)Nom\t3)Prenom\n\n");
    scanf("%d", &choix);
    // ouverture de fichier en lecture et gestion d'erreur
    FILE *f = fopen("etudiant.txt", "r");
    if (f == NULL)
        exit(EXIT_FAILURE);

    switch (choix)
    {
    case 1:
        //lecture de variable a chercher
        printf("\nEntrez le CNE : \t\t");
        scanf("%d", &varInt);
        //lecture line par line dans le fichier et stockage de line en variable chunk
        while (fgets(chunk, sizeof(chunk), f))
        {
            //Creation de la line a chercher (buf)
            snprintf(buf, sizeof(buf), "CNE : %d", varInt);
            // chercher dans la line du fichier (chunk) sur la line a chercher (buf)
            if (strstr(chunk, buf) != NULL)
                printf("%s\n", chunk);
        }
        break;
    case 2:
        //lecture de variable a chercher
        printf("\nEntrez le Nom : \t\t");
        scanf("%d", &varInt);
        //lecture line par line dans le fichier et stockage de line en variable chunk
        while (fgets(chunk, sizeof(chunk), f))
        {
            //Creation de la line a chercher (buf)
            snprintf(buf, sizeof(buf), "Nom : %s", var);
            // chercher dans la line du fichier (chunk) sur la line a chercher (buf)
            if (strstr(chunk, buf) != NULL)
                printf("%s\n", chunk);
        }
        break;
    case 3:
        //lecture de variable a chercher
        printf("\nEntrez le Prenom : \t\t");
        scanf("%d", &varInt);
        //lecture line par line dans le fichier et stockage de line en variable chunk
        while (fgets(chunk, sizeof(chunk), f))
        {
            //Creation de la line a chercher (buf)
            snprintf(buf, sizeof(buf), "Prenom : %s", var);
            // chercher dans la line du fichier (chunk) sur la line a chercher (buf)
            if (strstr(chunk, buf) != NULL)
                printf("%s\n", chunk);
        }
        break;
    default:
        printf("\nVous devez choisir un chiffre figurant dans le MENU !!!\n");
        break;
    }

    fclose(f);
    system("pause");
}

int main()
{
    // appel de la fonction presentation
    presentation();
    system("cls");
    // lecture de variable nbr_etudiant (taille de tableau)
    printf("Combien d'etudiant voulez-vous saisir?\t");
    scanf("%d", &nbr_etudiant);

    //appel de fonction saisie et initialisation de table etudiant e
    e = saisie(nbr_etudiant);
    do
    {
        // Appel du menu
        x = Menu();
        switch (x)
        {
        case 1:
            // appel de fonction saisie
            e = saisie(nbr_etudiant);
            break;
        case 2:
            system("cls");
            printf("Veuiller Entrez le CNE d'etudiant :\t");
            scanf("%d", &cne);
            //appel de fonction SupprimerEtdParCNE
            SupprimerEtdParCNE(e, cne, nbr_etudiant);
            break;
        case 3:
            //appel de fonction Afficher
            Afficher(e, nbr_etudiant);
            break;
        case 4:
            //appel de fonction ChercherDich
            system("cls");
            printf("Entrez le CNE : \t");
            scanf("%d", &cne);
            ChercherDich(e, cne);
            break;
        case 5:
            //appel de fonction AfficheParCNE
            system("cls");
            printf("Entrez le CNE : \t");
            scanf("%d", &cne);
            AfficheParCNE(e, cne, nbr_etudiant);
            break;
        case 6:
            //appel de fonction Modifier
            system("cls");
            printf("Entrez le CNE d etudiant a modifier: \t");
            scanf("%d", &cne);
            Modifier(e, cne, nbr_etudiant);
            break;
        case 7:
            //appel de fonction Tri
            Tri(e, nbr_etudiant);
            break;
        case 8:
            //appel de fonction echange_Etd
            system("cls");
            printf("Entrez la position a : \t");
            scanf("%d", &posa);
            printf("Entrez la position b : \t");
            scanf("%d", &posb);
            echange_Etd(posa, posb, e);
            break;
        case 9:
            //appel de fonction Sauvegarde
            Sauvegarde(e, nbr_etudiant);
            break;
        case 10:
            //appel de fonction ChercherFichier
            ChercherFichier();
            break;
        case 11:
            //Quitter le Programme
            exit(EXIT_SUCCESS);
        default:
            printf("\nVous devez choisir un chiffre figurant dans le MENU !!!\n");
            break;
        }

        // Affichage des etudiant depuis Table Etudiant
        Afficher(e, nbr_etudiant);
    } while (x != 11);
}
