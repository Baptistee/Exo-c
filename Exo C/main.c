#include <stdlib.h>
#include <stdio.h>

#define SIZE 10


int* init_matrice()
{
	int i = 0;

	int* matrice = (int*)malloc((SIZE * SIZE) * sizeof(int));

	for (i; i < SIZE * SIZE; i++)
	{
		matrice[i] = 0;
	}

	return matrice;
}

int* init_liste()
{
	int i = 0;

	int* liste = (int*)malloc((SIZE) * sizeof(int));

	for (i; i < SIZE ; i++)
	{
		liste[i] = 0;
	}

	return liste;
}

void affiche_matrice(int* tab)
{
	int i = 0;

	for (i; i < SIZE * SIZE; i++)
	{
		if ((i % SIZE) == 0)
		{
			printf("\n");
		}
		printf("%d ", tab[i]);
	}
}

void affiche_sommet(int *tab, int x, int y)
{
	printf("\n SOMMET = %d \n", tab[x * SIZE + y]);
}

void affiche_liste(int *liste)
{
	int i = 0;

	while (liste[i] != 0)
	{
		printf("\n LISTE VAL = %d \n", liste[i]);
		i++;
	}
}

int* ajoute_sommet(int *matrice, int x, int y)
{
	matrice[x * SIZE + y] = 1;
	matrice[y * SIZE + x] = 1;

	return matrice;
}

int* marquer_sommet(int *matrice, int x, int y)
{
	matrice[x * SIZE + y] = 0;
	matrice[y * SIZE + x] = 0;

	return matrice;
}

int* insert_tail(int* liste, int val)
{
	int i = 0;

	while (liste[i] != 0)
	{
		i++;
	}

	liste[i] = val;

	return liste;
}

void parcours_comp(int* matrice, int *marc, int val)
{
	int i;

	marc[val] = 1;

	printf("%d ", val+1);

	for (i = 0; i < SIZE; i++)
	{
		if (matrice[val * SIZE + i] != 0 && marc[i] == 0)
		{
			parcours_comp(matrice, marc, i);
		}
	}
}

void parcours_prof(int *matrice, int *marc)
{
	int i;

	for (i = 0; i < SIZE; i++)
	{
		marc[i] = 0;
	}

	for (i = 0; i < SIZE; i++)
	{
		if (marc[i] == 0)
		{
			parcours_comp(matrice, marc, i);
		}
	}
}

int main()
{
	int i = 0;

	int* matrice = init_matrice();

	matrice = ajoute_sommet(matrice, 0, 1);
	matrice = ajoute_sommet(matrice, 2, 1);
	matrice = ajoute_sommet(matrice, 3, 2);
	matrice = ajoute_sommet(matrice, 4, 3);
	matrice = ajoute_sommet(matrice, 5, 1);
	matrice = ajoute_sommet(matrice, 6, 5);
	matrice = ajoute_sommet(matrice, 7, 4);
	matrice = ajoute_sommet(matrice, 7, 6);
	matrice = ajoute_sommet(matrice, 8, 1);

	affiche_matrice(matrice);

	int* marc = init_liste();

	parcours_prof(matrice, marc);
}
