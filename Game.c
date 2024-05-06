#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"

// Função para imprimir o menu
void printMenu(int escolha) {
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
        printf("| %s2. Tutorial             %s \nFilha da o botao e chupa tora	\n", RED, RESET);
        printf("| %s3. Sair do Jogo         %s |\n", YELLOW, RESET);
    } else if (escolha == 3) {
        printf("| %s1. Jogar                %s |\n", YELLOW, RESET);
        printf("| %s2. Tutorial             %s |\n", YELLOW, RESET);
        printf("| %s3. Sair do Jogo         %s |\n", RED, RESET);
    }
    printf("===========================\n");
    printf("Use as setas para cima e para baixo para navegar. Pressione ENTER para selecionar.\n");
}

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
    int escolha = 1;
    char tecla;

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


    do {
        printMenu(escolha);

        // Lê a tecla pressionada
        tecla = getch();

        // Atualiza a seleção do menu
        switch (tecla) {
            case 72: // Tecla para cima
                escolha--;
                if (escolha < 1)
                    escolha = 1;
                break;
            case 80: // Tecla para baixo
                escolha++;
                if (escolha > 3)
                    escolha = 3;
                break;
        }
    } while (tecla != 13); // 13 é o código ASCII para a tecla Enter

    // Realiza a ação correspondente à escolha do usuário
    switch (escolha) {
        case 1:
            system("cls");
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
            
            break;
        case 3:
            printf("Saindo do jogo...\n");
            break;
    }

    return 0;
}
