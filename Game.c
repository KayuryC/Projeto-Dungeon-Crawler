#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//KayuryC
//Definindo cores para menu
#define RESET   "\x1b[0m"//Voltar para cor padrão ao sair de seleção
#define RED     "\x1b[31m"//Vermelho
#define GREEN   "\x1b[32m"//Verde
#define YELLOW  "\x1b[33m"//Amarelo

//Função para imprimir o menu
void printMenu(int escolha) {
        printf("| %s2. Tutorial             %s \nFilha da o botao e chupa tora	\n", RED, RESET);
	system("cls");
	printf("===========================\n");
	printf("|        MENU PRINCIPAL    |\n");
	printf("===========================\n");
	if (escolha == 1) {
		printf("| %s1. Jogar                %s |\n", RED, RESET);
		printf("| %s2. Tutorial             %s |\n", YELLOW, RESET);
		printf("| %s3. Sair do Jogo         %s |\n", YELLOW, RESET);
	} else if (escolha == 2) {
		printf("| %s1. Jogar                %s |\n", YELLOW, RESET);
		printf("| %s2. Tutorial             %s \nAqui vai um pouco da historia do jogo\nFalta escrever o tutorial, temos que terminar a parte da chave \n", RED, RESET);
		printf("| %s3. Sair do Jogo         %s |\n", YELLOW, RESET);
	} else if (escolha == 3) {
		printf("| %s1. Jogar                %s |\n", YELLOW, RESET);
		printf("| %s2. Tutorial             %s |\n", YELLOW, RESET);
		printf("| %s3. Sair do Jogo         %s |\n", RED, RESET);
	}
	printf("===========================\n");
	printf("Use as setas para cima e para baixo para navegar. Pressione ENTER para selecionar.\n");
}

//Declarando variáveis
char linha = 10;//Fase 1
char coluna = 10; //Fase 1
int enemy_linha, enemy_coluna;//Posição do inimigo
int vida_player = 1;
int escolha = 1;
char tecla;
int i, j;
int existe = 1;

//Função board/Quadrado imprimir mapa1
void print_fase1(char board[linha][coluna], int player_linha, int player_coluna) {
	system("cls");//Limpar mapa1 a cada input do player
	int i, j;
	for (i = 0; i < linha; i++) {
		for (j = 0; j < coluna; j++) {
			if (i == player_linha && j == player_coluna) {
				printf("& ");//Player
			} else {
				printf("%c ", board[i][j]);
			}
		}
		printf("\n");//Pula linha
	}
}

//Função pirncipal
int main() {
	//Inprimir mapa1.
	char board[linha][coluna];
	int player_linha = 5, player_coluna = 5;
	for (i = 0; i < linha; i++) {
		for (j = 0; j < coluna; j++) {
			board[i][j] = ' ';//Interior do mapa1/Alterar colocando algo dentro de ''

		}
	}
	for(j = 0; j < 10; j++) {
		board[0][j] = '*';
	}
	//Parede esquerda
	for(i = 0; i < 10; i++) {
		board[i][0] = '*';
	}
	//Parede direita
	for(i = 0; i < 10; i++) {
		board[i][9] = '*';
	}
	for(j = 0; j < 10; j++) {
		board[9][j] = '*';
	}

	//Sala dentro mapa1
	for(j = 0; j < 5; j++) {
		board[4][j] = '*';
	}
	for(i = 0; i < 5; i++) {
		board[i][4] = '*';
	}

	board[9][4] = 'D';//Porta fechada
	board[2][2] = '@';//Chave
	board[2][4] = '=';//Porta aberta 
	
	if(board[player_linha][player_coluna] == board[9][4] =='='){
		printf(" Parabens, voce passou de fase.\nAguarde o lancamento da fase 2...");
	}
	
	//Printar menu
	do {
		printMenu(escolha);

		//Le a tecla pressionada
		tecla = getch();

		//Atualiza a seleção do menu
		switch (tecla) {
			case 72://Tecla para cima
				escolha--;
				if (escolha < 1)
					escolha = 1;
				break;
			case 80://Tecla para baixo
				escolha++;
				if (escolha > 3)
					escolha = 3;
				break;
		}
	} while (tecla != 13); //13 é o codigo ASCII para a tecla ENTER


	//Realiza a ação correspondente a escolha do usuario
	switch (escolha) {
		case 1:
			system("cls");
			while (1) {
				//Printando a fase dentro do laço para funcionar melhor o efeito movimento
				print_fase1(board, player_linha, player_coluna);
				char move = getch();//Reconhecer teclas de movimento

				switch (move) {
					//Movimento para cima
					case 'w':
						if (player_linha > 0 && board[player_linha - 1][player_coluna] != '*')//Reconhcer parede
							player_linha--;
						break;
					//Movimento para baixo
					case 's':
						if (player_linha < linha - 1 && board[player_linha + 1][player_coluna] != '*' && player_linha < linha - 1 && board[player_linha + 1][player_coluna] != 'D' )//Reconhcer parede
							player_linha++;
						break;
					//Movimento para esquerda
					case 'a':
						if (player_coluna > 0 && board[player_linha][player_coluna - 1] != '*')//Reconhcer parede
							player_coluna--;
						break;
					//Movimento para direita
					case 'd':
						if (player_coluna < coluna - 1 && board[player_linha][player_coluna + 1] != '*')//Reconhcer parede
							player_coluna++;
						break;
					//Q para sair do jogo so para TESTE por enquanto
					case 'q':
						printf("%sEncerrando Jogo...%s",RED,RESET);
						sleep(2);
						exit(0);
						break;
					//Tecla i para pegar chave
					case 105:
						if(board[player_linha][player_coluna] == '@') {
							board[2][2] = ' ';
							board[9][4] = '=';
							printf("%s Pegou a chave com sucesso! %s ", GREEN, RESET);
							sleep(2);
						} else if(board[player_linha][player_coluna] != '@') {
							printf("%sVoce esta longe da chave...%s", YELLOW, RESET);
							sleep(1);
						}
					default:
						break;
				}
			}
			break;
		case 3:
			printf("Saindo do jogo...\n");
			break;
	}
	return 0;
}
