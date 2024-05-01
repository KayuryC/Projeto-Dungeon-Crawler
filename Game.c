#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//KayuryC
//Definindo valores mapa1/teste...
#define linha 10
#define coluna 10

//Função board/Quadrado imprimir mapa1
void print_quadrado(char board[linha][coluna], int player_linha, int player_coluna) {
	system("cls");//Limpar mapa1 a cada input do player
	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < coluna; j++) {
			if (i == player_linha && j == player_coluna) {
				printf("& ");//Player
			} else {
				printf("%c ", board[i][j]);
			}
		}
		printf("\n");//Pula linha
	}
}
int main() {
	//Inprimir mapa1.
	char board[linha][coluna];
	int player_linha = 0, player_coluna = 0;
	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < coluna; j++) {
			board[i][j] = '.';//Interior do mapa1/Alterar colocando algo dentro de ''
		}
	}
	//Paredes pode ser adicionada em qualquer area da matriz/Ainda veremos onde colocar, por enquanto deixem assim.
	board[2][2] = '*';
	board[3][2] = '*';
	board[4][2] = '*';
	board[5][2] = '*';
	board[6][2] = '*';
	board[7][2] = '*';
	board[8][2] = '*';
	board[8][3] = '*';
	board[8][4] = '*';
	board[8][5] = '*';
	//Pra gente ter ideia da parede teremos que fazer um mapa/matriz 10x10
	//Para não se confundir na hora de colocar as parades

	int menu_principal;//Menu do jogo/Por enquanto é por leitura de input do leitor, seria bom o player poder selecionar nas setinhas
	printf("\tBem-Vindo ao [NOME do jogo]...\n\n(1) Jogar\n(2) Tutorial\n(3) Sair do jogo\n");
	scanf("%d", &menu_principal);
	system("cls");//Limpar CMD
	
	//Falta adicionar mecanica para pecorrer no menu (Meu maior inimigo)
	if(menu_principal == 1){
	while (1) {
		print_quadrado(board, player_linha, player_coluna);

		char move = getch();

		switch (move) {
			case 'w':
				if (player_linha > 0 && board[player_linha - 1][player_coluna] != '*')//Reconhcer parede
					player_linha--;
				break;
			case 's':
				if (player_linha < linha - 1 && board[player_linha + 1][player_coluna] != '*')//Reconhcer parede
					player_linha++;
				break;
			case 'a':
				if (player_coluna > 0 && board[player_linha][player_coluna - 1] != '*')//Reconhcer parede
					player_coluna--;
				break;
			case 'd':
				if (player_coluna < coluna - 1 && board[player_linha][player_coluna + 1] != '*')//Reconhcer parede
					player_coluna++;
				break;
			case 'q':
				exit(0);//Q para sair do jogo so para TESTE por enquanto
				break;
			default:
				break;
		}
	}
}
	if(menu_principal == 2){
		system("cls");//Limpar CMD
		printf("\tTutorial>>\n\n.........TEXTO..........\n........TEXTO.........\n............TEXTO...........");
	}
	if(menu_principal == 3){
		printf("\n\n\n\tSaindo do Jogo...\n\n\n");
		system("pause");
		
	}
	else{
		printf("\tERRO!ERRO!ERRO!\nDigite uma das opcoes validas da proxima...");
		return 0;
	}
	return 0;
}
