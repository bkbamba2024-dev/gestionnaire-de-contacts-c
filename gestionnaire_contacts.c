#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char nom[30];
    char prenom[30];
    char telephone[20];
} Contact;

void afficherMenu();
void ajouterContact(Contact contacts[], int *n);
void afficherContacts(Contact contacts[], int n);
void rechercherContact(Contact contacts[], int n);
void modifierContact(Contact contacts[], int n);
void supprimerContact(Contact contacts[], int *n);

int main()
{
    Contact contacts[MAX];
    int n = 0;
    int choix;

    do
    {
        afficherMenu();

        printf("Quel est votre choix ? ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterContact(contacts, &n);
            break;

        case 2:
            afficherContacts(contacts, n);
            break;

        case 3:
            rechercherContact(contacts, n);
            break;

        case 4:
            modifierContact(contacts, n);
            break;

        case 5:
            supprimerContact(contacts, &n);
            break;

        case 6:
            printf("Merci d'avoir utilise le gestionnaire de contacts.\n");
            break;

        default:
            printf("Choix invalide !\n");
        }

    } while (choix != 6);

    return 0;
}

void afficherMenu()
{
    printf("\n========================================\n");
    printf("     GESTIONNAIRE DE CONTACTS\n");
    printf("========================================\n");
    printf("1. Ajouter un contact\n");
    printf("2. Afficher les contacts\n");
    printf("3. Rechercher un contact\n");
    printf("4. Modifier un contact\n");
    printf("5. Supprimer un contact\n");
    printf("6. Quitter\n");
    printf("========================================\n");
}

void ajouterContact(Contact contacts[], int *n)
{
    if (*n >= MAX)
    {
        printf("Le carnet de contacts est plein !\n");
        return;
    }

    printf("Entrez votre nom : ");
    scanf("%s", contacts[*n].nom);

    printf("Entrez votre prenom : ");
    scanf("%s", contacts[*n].prenom);

    printf("%s %s, veuillez entrer votre numero de telephone : ",
           contacts[*n].nom,
           contacts[*n].prenom);

    scanf("%s", contacts[*n].telephone);

    (*n)++;

    printf("Contact ajoute avec succes !\n");
}

void afficherContacts(Contact contacts[], int n)
{
    if (n == 0)
    {
        printf("Aucun contact enregistre.\n");
        return;
    }

    printf("\nNombre de contacts : %d\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("\n----- CONTACT %d -----\n", i + 1);
        printf("Nom : %s\n", contacts[i].nom);
        printf("Prenom : %s\n", contacts[i].prenom);
        printf("Telephone : %s\n", contacts[i].telephone);
    }
}

void rechercherContact(Contact contacts[], int n)
{
    if (n == 0)
    {
        printf("Aucun contact enregistre.\n");
        return;
    }

    char nom[30];
    int trouve = 0;

    printf("Entrez le nom du contact : ");
    scanf("%s", nom);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(nom, contacts[i].nom) == 0)
        {
            printf("\n----- CONTACT TROUVE -----\n");
            printf("Nom : %s\n", contacts[i].nom);
            printf("Prenom : %s\n", contacts[i].prenom);
            printf("Telephone : %s\n", contacts[i].telephone);

            trouve = 1;
            break;
        }
    }

    if (trouve==0)
    {
        printf("Aucun contact trouve.\n");
    }
}

void modifierContact(Contact contacts[], int n)
{
    if (n == 0)
    {
        printf("Aucun contact enregistre.\n");
        return;
    }

    char nom[30];
    int trouve = 0;

    printf("Entrez le nom du contact : ");
    scanf("%s", nom);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(nom, contacts[i].nom) == 0)
        {
            printf("\n----- CONTACT A MODIFIER -----\n");
            printf("Nom : %s\n", contacts[i].nom);
            printf("Prenom : %s\n", contacts[i].prenom);
            printf("Telephone : %s\n", contacts[i].telephone);

            printf("Entrez le nouveau nom : ");
            scanf("%s", contacts[i].nom);

            printf("Entrez le nouveau prenom : ");
            scanf("%s", contacts[i].prenom);

            printf("Entrez le nouveau telephone : ");
            scanf("%s", contacts[i].telephone);

            printf("\nContact modifie avec succes !\n");

            trouve = 1;
            break;
        }
    }

    if (trouve==0)
    {
        printf("Aucun contact trouve.\n");
    }
}

void supprimerContact(Contact contacts[], int *n)
{
    if (*n == 0)
    {
        printf("Aucun contact enregistre.\n");
        return;
    }

    char nom[30];
    int trouve = 0;

    printf("Entrez le nom du contact a supprimer : ");
    scanf("%s", nom);

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(nom, contacts[i].nom) == 0)
        {
            printf("\n----- CONTACT A SUPPRIMER -----\n");
            printf("Nom : %s\n", contacts[i].nom);
            printf("Prenom : %s\n", contacts[i].prenom);
            printf("Telephone : %s\n", contacts[i].telephone);

            for (int j = i; j < *n - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }

            (*n)--;

            printf("Contact supprime avec succes !\n");

            trouve = 1;
            break;
        }
    }

    if (trouve==0)
    {
        printf("Aucun contact trouve.\n");
    }
}
