#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

typedef struct sommet {
	int num;
}sommet;

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

void affiche(int* tab)
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

int* ajoute_sommet(int *matrice, int x, int y)
{
	matrice[x * SIZE + y] = 1;
	matrice[y * SIZE + x] = 1;

	return matrice;
}

parcours_comp()
{

}

parcours_prof()
{

}

main()
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

	affiche(matrice);
}
