//A ideia é quebrar cada passo em funções genéricas, que possam ser aproveitadas em todas as modalidades do jogo. Antes, foi precio testar a lógica:

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void personagem(int chance, const char palavraSecreta[]) { 	
	switch (chance) {
	case 0 :
		printf("\n  _______\n");
		printf("  |/   | \n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("__|_________\n\n");
	break;

	case 1 :
		printf("\n  _______\n");
		printf("  |/   | \n");
		printf("  |    O \n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("__|_________\n\n");
	break;

	case 2 :
		printf("\n  _______\n");
		printf("  |/   | \n");
		printf("  |    O \n");
		printf("  |    |\n");
		printf("  |    |\n");
		printf("  |\n");
		printf("__|_________\n\n");
	break;

	case 3 :
		printf("\n  _______\n");
		printf("  |/   | \n");
		printf("  |    O \n");
		printf("  |   /|\n");
		printf("  |    | \n");
		printf("  |   \n");
		printf("__|_________\n\n");
	break;

	case 4 :
		printf("\n  _______\n");
		printf("  |/   | \n");
		printf("  |    O \n");
		printf("  |   /|\\\n");
		printf("  |    | \n");
		printf("  |   \n");
		printf("__|_________\n\n");
	break;

	case 5 :
		printf("\n  _______\n");
		printf("  |/   | \n");
		printf("  |    O \n");
		printf("  |   /|\\\n");
		printf("  |    | \n");
		printf("  |   /  \n");
		printf("__|_________\n\n");
	break;

		case 6 :
		printf("\n  _______\n");
		printf("  |/   | \n");
		printf("  |    X \n");
		printf("  |   /|\\\n");
		printf("  |    | \n");
		printf("  |   / \\\n");
		printf("__|_________\n\n");
		printf("\nPerdeu!!!! A palavra secreta era: %s", palavraSecreta);
		printf("\nGAME OVER!");
		exit(0);
	break;
	}
}


int main(void) {
	setlocale( LC_ALL, "");	
	int chances = 0;
	char letrasUsadas[100];
	char palavraSecreta[100];
	char palavraAux[100];
	char nomeJogador2[50];
	char letra;
	int ganhou = 0;

	printf("\n>>>>HangMan<<<<\n\n");
	printf("Olá, bem-vinde ao Jogo da Forca! O objetivo é adivinhar a palavra secreta antes que você seja enforcado. \nSerá que você consegue? Muahuahuahuahuahuahuahuahuahuahuahauhua (risada maligna).\n");


	printf("\n\nJogador 2, digite o seu nome: \n");
	scanf("%s%*c", nomeJogador2);
	printf("Jogador 1, digite uma palavra secreta para %s adivinhar: \n", nomeJogador2);
	scanf("%s%*c", palavraSecreta);
	system("clear");
	printf("\nPronto, palavra secreta escolhida.");
	printf("\nAgora é sua vez, %s. Tente adivinhar!\n", nomeJogador2);
		
		for (int x=0; palavraSecreta[x]; x++) {
			palavraAux[x] = '-';
		}

		do {
			int acertou = 0;

			printf("\nDigite uma letra:\n");
			scanf("%c%*c", &letra);

			for (int i=0; palavraSecreta[i]; i++) {
				if (palavraSecreta[i] == letra) {
					printf("\nAcertou a letra!");
					palavraAux[i] = letra;
					acertou = 1;
				} 
			}
			
			printf("\nPalavra: %s", palavraAux);

			if (acertou == 0){
				printf("\nA palavra não contém essa letra!");
				chances++;
			}

			personagem(chances, palavraSecreta);

			ganhou = strcmp(palavraSecreta, palavraAux) == 0? 1 : 0;


			if (ganhou == 1) {
				printf("\n _________________________");
				printf("\n|                         |");
				printf("\n| Parabéns! Você acertou! |");
				printf("\n|_________________________|");
				printf("\n        \\ (•◡•) /         ");
				printf("\n");
				exit(0);
			}

	} while (chances <= 6);

	return 0;
}

//encontrar uma forma de fazer um push_back em vetor de letras usadas, para exibir para o usuário
