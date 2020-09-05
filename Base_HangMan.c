//Ana Carolina Cortez Alves PT300855X

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define NPALAVRAS 5
#define LIMITE 10

//Parte gráfica do jogo: conforme a quantidade de chues, personagem, letras escolhidas e palavra auxiliar são exibidos em tela
void personagem(int chances, char palavraSecreta[], char palavraAux[], char letrasUsadas[]) { 	
	
	printf("\nLetras digitadas: %s ", letrasUsadas);
	printf("\nPalavra: %s\n", palavraAux);
	
	switch (chances) {
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
		printf("\nOh, nãoooooooooo!!!! Poxa, não foi dessa vez! \nA palavra secreta era: %s\n", palavraSecreta);
		printf("\nGAME OVER!");
		exit(0);
	break;

	case 7:
		printf("\n _________________________");
		printf("\n|                         |");
		printf("\n| Parabéns! Você acertou! |");
		printf("\n|_________________________|");
		printf("\n        \\ (•◡•) /         ");
		printf("\n");
		exit(0);
	break; 
	}
}

//Função para jogador definir qual modalidade estará jogando
int escolhaTipoJogo() {
	//variáveis auxiliares para escolhas do usuário
	int opcao = 0;
	int tipojogo = 0;

	//Jogador escolhe tipo de jogo. Laço de repetição só finaliza com informação correta
		do {
			printf("\nEscolha o tipo de jogo: [1] Jogador VS Jogador, [2] Jogador VS Computador\n");
			scanf("%d", &tipojogo);

			switch(tipojogo){
			case 1:
				tipojogo = 1;
				opcao = 9;
				break;
			case 2:
				tipojogo = 2;
				opcao = 9;
				break;
			default:
				printf("\nOpção inválida");
				opcao = 0;
				break;
			}
			
		} while(opcao == 0);

	//Jogador escolheu jogar em dupla com colega
	if (tipojogo == 1){
		opcao = 11;
		printf("\nAh, você tem um arquinimigo, então...\n");
		return opcao;
	}

	//Jogador escolheu jogar contra o computador. Novo looping de opções é iniciado, com outra validação de modalidade de jogo
	if (tipojogo == 2) {
		printf("\nOh, que audácia! Quer jogar contra mim!!!! o.O Desafio aceito!\n");
		printf("\n ... (__)");
		printf("\n (|) (00)");
		printf("\n  | /(__)\\");
		printf("\n  | _/  \\_\n");

		do {
			printf("\nAgora, escolha uma opção: [3] Jogador escolhe a palavra, [4] Computador escolhe a palavra\n");
			scanf("%d", &opcao);

			switch (opcao){
			case 3:
				opcao = 3;
				break;
			case 4:
				opcao = 4;
				break;
			default:
				opcao = 10; //retoma o loop para nova validação
				printf("\nOpção inválida!\n");
				break;
			}
		} while (opcao == 10);

		//Recebe um valor para opção conforme escolhido e mensagem com sequência do jogo
		if (opcao == 3) {
			opcao = 21;
			printf("\nOra, ora, ora... Então você quer que eu adivinhe a palavra que você vai escolher... Prepare-se para perder! Muahuahuahauhauaha (risada maligna)\n");
			return opcao;
		}

		if (opcao == 4) {
			opcao = 22;
			printf("\nHmmmm... eu que vou escolher a palavra para você adivinhar, então! Prepare-se para perder! Muahuahuahauhauaha (risada maligna)\n");
			return opcao;
		}

	}
	return opcao;
}

//Função para jogador escolher o grau de dificuldade do jogo
int escolhaNivel(){
	int nivel = 0;

	//validação dos dados recebidos do usuário. Loop finaliza somente com as opções corretas
	do {
		printf("Nível: [1] Fácil, [2] Médio, [3] Difícil\n");
		scanf("%d", &nivel);

		switch(nivel){
		case 1:
			printf("\nOk. A palavra a ser adivinhada terá 4 letras.\n");
			nivel = 4; //iguala o nivel ao numero de letras da palavra correspondente
			break;
		case 2:
			printf("\nOk. A palavra a ser adivinhada terá 6 letras.\n");
			nivel = 6; //iguala o nivel ao numero de letras da palavra correspondente
			break;
		case 3:
			printf("\nUau! Ok, então... A palavra a ser adivinhada terá 8 letras.\n");
			nivel = 8; //iguala o nivel ao numero de letras da palavra correspondente
			break;
		default:
			printf("\nOpção inválida!\n");
			nivel = 0; //retoma o loop para nova validação
			break;
		}
	} while (nivel == 0);

	return nivel;
}


void escolhaPalavra(int dificuldade, char palavraSecreta[], char palavraAux[]) {
	int validado = 0;
	int nchar = 0;
	char palavraSecretaAux[LIMITE];

	//loop para verificar se quandade de letra é compatível com nível selecionado
	do{
		printf("\nPalavra secreta: \n");
		scanf("%s%*c", palavraSecretaAux);
		system("clear");
		nchar = strlen(palavraSecretaAux);
		
		if (nchar != dificuldade){
			printf("\nO número de letras percisa estar de acordo com o nível escolhido!\nLembrando => Fácil: 4 letras; Médio: 6 letras; Difícil: 8 letras!\n");
		} else {
			validado = 1;
		}

	}while(validado == 0);
	
	//preenche vetor palavraAux[] com traços, para auxiliar o jogador na posição de cada letra dentro da palavra secreta
	for (int t = 0; t < nchar; t++){
		palavraAux[t] = '-';
	}

	//uniformiza a palavra secreta, para que uso de caixa alta ou baixa pelo usuário não altere resultado
	for (int c = 0; c < strlen(palavraSecretaAux); c++){
		palavraSecreta[c] = toupper(palavraSecretaAux[c]);
	}

	printf("\nPronto, palavra secreta escolhida.");
	printf("\nHora da adivinhação!\n");

}

void chutaLetra(){
	printf("Computador escolhe letra radomicamente");
}

char digitaLetra(){
	int checaAlfa = 0;
	char letra;

	do{
		//usuário chuta letra;
		printf("\nDigite uma letra:\n");
		scanf("%c%*c", &letra);

		//repete digitação até que seja digitado uma letra
		if((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')){
			checaAlfa = 1;
			return letra;
		} else {
			printf("\nDigite somente letras sem acentos nem caracteres especiais");
		}

	} while (checaAlfa == 0);

	printf("%c", letra);
	return letra;
}

void listaDeLetras(char letra, char letrasUsadas[]) {
	int adicionar = 0;
	int y;

	//caso o vetor de letras esteja vazio, preenche com a primeira letra recebida do usuário
	if (strlen(letrasUsadas) == 0){
		letrasUsadas[0] = letra;
	}

	//confere se letra recebida está na lista
	for (y = 0; y < strlen(letrasUsadas); y++) {
		if (letrasUsadas[y] == letra || letrasUsadas[y] == toupper(letra)){
			adicionar = 0;
		} else {
			adicionar = 1;
		}
	}
	
	//caso letra não esteja na lista, adiciona na próxima posição
	if (adicionar == 1){
		letrasUsadas[y+1] = toupper(letra);
	}

}

void confereLetra(int dificuldade, int chances, int modalidade, char palavraSecreta[], char palavraAux[], char letrasUsadas[]){

	char letra;
	int ganhou;
		
	do {
		//variável de controle do loop
		int acertou = 0;

		//direciona para as funções adequadas de acordo com a modalidade do jogo
		if (modalidade == 11){
			letra = digitaLetra();
			listaDeLetras(letra, letrasUsadas);
		} else if (modalidade == 21){
			printf("Implementar");
			letra = 'a';
		} else if (modalidade == 22) {
			printf("Implementar");
			letra = 'b';
		} else {
			printf("Algo estranho aconteceu. Desculpe =(");
			exit(0);
		}

		//confere se palavra contém a letra digitada. Caso tenha, traço correspondente da palavra auxiliar é substituído pela letra correta
		for (int i=0; i < dificuldade; i++) {
			if (palavraSecreta[i] == letra || palavraSecreta[i] == toupper(letra)) {
				printf("\nAcertou a letra!");
				palavraAux[i] = toupper(letra);
				acertou = 1;
			} 
		}
		
		//informa o usuário que a letra chutada não está correta e reduz o número de chances disponíveis para novos chutes;
		if (acertou == 0){
			printf("\nA palavra não contém essa letra!");
			chances++;
		}

		//compara palavra secreta à palavra auxiliar. Se estiverem iguais, usuário acertou e ganhou jogo
		chances = strcmp(palavraSecreta, palavraAux) == 0? 7 : chances;

		//exibe na tela o resultado da rodada
		personagem(chances, palavraSecreta, palavraAux, letrasUsadas);

	} while (chances < 7);	
}

int main(void) {
	setlocale( LC_ALL, "");	
	char letrasUsadas[100];
	char palavraSecreta[LIMITE];
	char palavraAux[LIMITE];
	char nomeJogador2[20];
	char nomeJogador1[20];
	int chances = 0;
	
	//Inicio do jogo
	printf("\n>>>>>>> HangMan <<<<<<<\n\n");
	printf("\nOlá, bem-vinde ao Jogo da Forca! \nO objetivo é adivinhar a palavra secreta antes que você seja enforcade. Será que você consegue? \nMuahuahuahuahuahuahuahuahuahuahuahauhua (risada maligna).\n");
	
	//Leitura do nome do Jogador 1
	printf("\n\nAntes de começarmos, preciso só de algumas informaçõezinhas... \n\nJogador1, qual o seu nome?\n");
	scanf("%s%*c", nomeJogador1);

	//Escolha da modalidade
	printf("\nLegal, %s. Agora, me conte qual modalidade jogaremos.\n", nomeJogador1);
	int modalidade = escolhaTipoJogo();

	//Escolha do nível
	printf("\nEscolha o nível de diculdade do jogo!\n");
	int dificuldade = escolhaNivel();

	//Direcionamento para funções cabíveis a cada modalidade de jogo
	if (modalidade == 11){
		printf("\n\nArquinimigo (Jogador 2), digite o seu nome: \n");
		scanf("%s%*c", nomeJogador2);
		printf("\n%s, digite uma palavra secreta para %s adivinhar: \n", nomeJogador1, nomeJogador2);
		escolhaPalavra(dificuldade, palavraSecreta, palavraAux);
		confereLetra(dificuldade, chances, modalidade, palavraSecreta, palavraAux, letrasUsadas);
	} else if (modalidade == 21) {
		//dificuldade entra como parâmetro;
	} else if (modalidade == 22) {
		//dificuldade entra como parâmetro;
	} else {
		printf("Ops, algo de muito errado aconteceu. Peço desculpas =(");
		exit(0);
	}

	return 0;
}
