/*
Jogo de adivinhação

O usuário precisa adivinhar um número aleatório gerado pelo sistema. A quantidade de chutes está condicionada ao nível do jogo, escolhido pelo usuário.

1) Gere um número inteiro aleatório. Dica: o C++ tem uma função pronta para isso => srand().

2) Pergunte para o usuário qual é o nível de dificuldade que ele quer jogar: (1) fácil; (2) médio; (3) difícil. No modo fácil, ele tem 20 chutes; no médio 15 tentativas e, no difícil, 6.

3) Pedir para o usuário fazer seu chute. Se ele não adivinhar o "número mágico", é preciso avisar se o chute está acima ou abaixo do número correto.

4) Não esquecer que essa operação precisa se repetir de acordo com a quantidade de chutes permitida para o nível escolhido anteriormente.

5) Caso o usuário adivinhe o número, exibir uma mensagem de parabéns. Caso ele não tenha acertado no final dos chutes, informar que ele perdeu e qual era, afinal, o número mágico.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>


int main() {
  
  int magicNumber, guessNumber, chooseLevel, guessTimes, gameOver, vez=1;

  printf("Bem vindo ao Jogo de Adivinhação! \nEscolha o nível: (1) fácil, (2) médio, (3) difícil\n");
  scanf("%d", &chooseLevel);

  switch (chooseLevel){
    case 1:
      guessTimes = 20;
      break;
    case 2:
      guessTimes = 15;
      break;
    case 3:
      guessTimes = 6;
      break;
    default:
      printf("Opção inválida");
      return 0;
  }

  srand(time(0));
  magicNumber =	rand()%100;
  
  printf("Ótimo. Já escolhi um número. Tente adivinhá-lo. Você tem %d chances!\n", guessTimes);
  
  for (gameOver = guessTimes; gameOver > 0; gameOver--){
    printf("\nTentativa %d\n", vez);
	printf("Faça seu chute:\n");
    scanf("%d", &guessNumber);

	if (!isalpha(guessNumber)){
		if (guessNumber > magicNumber){
      		printf("Ops, seu chute até acima do número correto!");
    	} else if (guessNumber < magicNumber){
      		printf("Ixi, seu chute está abaixo do número correto!");
    	} else if (guessNumber == magicNumber){
			printf("\n _________________________");
			printf("\n|                         |");
			printf("\n| Parabéns! Você acertou! |");
			printf("\n|_________________________|");
			printf("\n        \\ (•◡•) /         ");
			printf("\n");
			exit(0);
   		} else {
			printf("Ops, algo deu errado! Desculpe");
			exit(0);
		} 
	} else {
		printf("Ops, não é número... GAME OVER!");
		exit(0);
	}
    
	vez++;
  }

  if (gameOver == 0){
    printf("\nAcabaram as suas tentativas. Que pena, você perdeu! O número correto era %d", magicNumber);
  }

  return 0;
}
