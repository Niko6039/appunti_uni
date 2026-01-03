#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NUMERO_CARTE 52
#define NUMERO_SEMI 4
#define NUMERO_SCALA 13

void mischia_carte(unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA]);
void azzeraMazzo(unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA]);
void dai_carte(unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA], unsigned int numeroGiocatori, unsigned int cartePerGiocatore);
void visualizza_mazzo(unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA]);

void main()
{
	unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA];
	int altroGiro = 1;
	unsigned int numeroCarteRimaste = NUMERO_CARTE;
	unsigned int cartePerGiocatore = 4;
	unsigned int numeroGiocatori = 4;
	char risposta;
	while (altroGiro == 1)
	{

		mischia_carte(mazzo);
		// visualizza_mazzo(mazzo);
		dai_carte(mazzo, numeroGiocatori, cartePerGiocatore);
		printf("Altro giro?: (y/n):");
		scanf("%c", &risposta);

		while (getchar() != '\n')
			; // svuoto stdin

		if (risposta == 'y')
		{
			altroGiro = 1;
		}
		else
		{
			altroGiro = 0;
		}
	}
}
//----------------------------------------------------------------------------------
void visualizza_mazzo(unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA])
{
	for (int j = 0; j < NUMERO_SEMI; j++)
	{
		switch (j)
		{
		case 0:
			printf("cuori  :");
			break;

		case 1:
			printf("quadri :");
			break;

		case 2:
			printf("fiori  :");
			break;

		case 3:
			printf("picche :");
			break;
		}
		for (int k = 0; k < NUMERO_SCALA; k++)
		{
			printf("%d-", mazzo[j][k]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}
//----------------------------------------------------------------------------------
void azzeraMazzo(unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA])
{
	for (int i = 0; i < NUMERO_SEMI; i++)
		for (int j = 0; j < NUMERO_SCALA; j++)
			mazzo[i][j] = 0;
}
//----------------------------------------------------------------------------------
void mischia_carte(unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA])
{
	unsigned int riga, colonna;
	srand(time(0));
	azzeraMazzo(mazzo);
	for (int i = 1; i < NUMERO_CARTE; i++)
	{
		do
		{

			riga = rand() % (NUMERO_SEMI);	   // genera indice da da 0 a 3
			colonna = rand() % (NUMERO_SCALA); // genera indice da 0 a 12
			printf("riga:%d;colonna:%d; i=%d\n", riga, colonna, i);
		} while (mazzo[riga][colonna] != 0);
		mazzo[riga][colonna] = i;
	}
}
//--------------------------------------------------------------------------------------------------------------------------
void dai_carte(unsigned int mazzo[NUMERO_SEMI][NUMERO_SCALA], unsigned int numeroGiocatori, unsigned int cartePerGiocatore)
{
	unsigned int riga, colonna;
	char *semi[NUMERO_SEMI] = {"cuori", "quadri", "fiori", "picche"};
	char *carte[NUMERO_SCALA] = {"asso", "due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove", "dieci", "jack", "regina", "Kappa"};
	for (int i = 1; i <= numeroGiocatori; i++)
	{
		printf("GIOCATORE %d :", i);
		for (int j = 1; j <= cartePerGiocatore; j++)
		{
			do
			{
				riga = rand() % (NUMERO_SEMI);	   // genera indice da da 0 a 3
				colonna = rand() % (NUMERO_SCALA); // genera indice da 0 a 12
			} while (mazzo[riga][colonna] == 0); // non devo dare carte che ho gi� dato
			printf("%s di %s - ", carte[colonna], semi[riga]);
			mazzo[riga][colonna] = 0;
		}
		printf("\n\n");
	}
	visualizza_mazzo(mazzo);
}
