#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void exibeTabuleiro (char tabuleiro[3][3]) {
	printf("\n");
	printf("\t  %c  |  %c  |  %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
	printf("\t-----------------\n");
	printf("\t  %c  |  %c  |  %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
	printf("\t-----------------\n");
	printf("\t  %c  |  %c  |  %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
	printf("\n");
}

int gameOver(char tabuleiro[3][3]){

  for (int i=0;i<=2;i++){
    if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]){
      return 1;
    }
  }

  for(int j=0;j<=2;j++){
    if(tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[0][j] == tabuleiro[2][j]){
      return 1;
    }
  }
    
   
	//diagonal
	if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
		return 1;
	}
	if (tabuleiro[2][0] != ' ' && tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2]){
		return 1;
	}

	return 0;
}

int main () {
	setlocale (LC_ALL, "");
	int linha, coluna, chances = 0;
	char simbolo;

	char tabuleiro[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '},
	};

	printf("Bem-vindes ao Jogo da Velha!\n\n");
	printf("Jogador1, você será X\nJogador2, você será O\n\n");

	int jogador = 1;

	do {
		if (jogador == 1) {
			simbolo = 'X';
			jogador = 2;
		} else {
			simbolo = 'O';
			jogador = 1;
		}

		do {
			printf("Escolha uma linha [1, 2 ou 3]:\n");
			scanf("%d", &linha);
		} while (linha < 1 || linha > 3);

		do {
			printf("Agora escolha a coluna [1, 2 ou 3]:\n");
			scanf("%d", &coluna);
		} while (coluna < 1 || coluna > 3);


		if (tabuleiro[linha-1][coluna-1] == ' ') {
			tabuleiro[linha-1][coluna-1] = simbolo;
		} else {
			printf("\nEspaço já ocupado!\n");
			jogador = jogador == 1? 2 : 1;
		}

		exibeTabuleiro(tabuleiro);
		int vencedor = gameOver(tabuleiro);

		if (vencedor == 1){
			printf("\nTemos um vencedor! Parabéns!\n");
			exit(0);
		} 

		chances++;
	} while (chances < 9);
	
}
