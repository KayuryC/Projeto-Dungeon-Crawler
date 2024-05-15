#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//Definindo cores para menu
#define RESET   "\x1b[0m"//Voltar para cor padrão ao sair de seleção
#define RED     "\x1b[31m"//Vermelho
#define GREEN   "\x1b[32m"//Verde
#define YELLOW  "\x1b[33m"//Amarelo


//Função para imprimir o menu
void print_menu(int escolha) {
	system("cls");
	printf("===========================\n");
	printf("|%s     DUGEON CRAWLER       %s|\n", RED,RESET);
	printf("===========================\n");
	if (escolha == 1) {
		printf("| %s1. Jogar                %s |\n", GREEN, RESET);
		printf("| %s2. Tutorial             %s |\n", YELLOW, RESET);
		printf("| %s3. Sair do Jogo         %s |\n", YELLOW, RESET);
	} else if (escolha == 2) {
		printf("| %s1. Jogar                %s |\n", YELLOW, RESET);
		printf("| %s2. Tutorial             %s \n O objetivo do jogo e mover um personagem atraves de um cenario\ne interagir com objetos e enfrentar desafios simples.\nUsando W, A, S, D para se movimentar e a tecla I para interagir com o mapa\nTome cuidado com os inimigos pelo mapa, boa sorte!\n", GREEN, RESET);
		printf("| %s3. Sair do Jogo         %s |\n", YELLOW, RESET);
	} else if (escolha == 3) {
		printf("| %s1. Jogar                %s |\n", YELLOW, RESET);
		printf("| %s2. Tutorial             %s |\n", YELLOW, RESET);
		printf("| %s3. Sair do Jogo         %s |\n", GREEN, RESET);
	}
	printf("===========================\n");
	printf("Use as setas para cima e para baixo para navegar. Pressione ENTER para selecionar.\n");
}
//Declarando variáveis
char linha = 10;//Fase 1
char coluna = 10; //Fase 1
char linha2 = 20;
char coluna2 = 20;
int escolha = 1;//Opção menu
char tecla;//Input tecla para menu
int i, j;//Contador
int player_vida = 3;
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
//Função para imprimir mapa2
void print_fase2(char board2[linha2][coluna2], int player_linha2, int player_coluna2) {
	system("cls");//Limpar mapa1
	int i, j;
	for (i = 0; i < linha2; i++) {
		for (j = 0; j < coluna2; j++) {
			if (i == player_linha2 && j == player_coluna2) {
				printf("& ");//Player
			} else {
				printf("%c ", board2[i][j]);
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
	//Inprimir mapa2.
	char board2[linha2][coluna2];
	int player_linha2 = 0, player_coluna2 = 10;
	for (i = 0; i < linha2; i++) {
		for (j = 0; j < coluna2; j++) {
			board2[i][j] = ' ';//Interior do mapa2/Alterar colocando algo dentro de ''
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
	int enemy_linha = 3;
	int enemy_coluna = 7;
	board[9][4] = 'D';//Porta fechada
	board[2][2] = '@';//Chave
	board[2][4] = '=';//Porta aberta
	board[enemy_linha][enemy_coluna] = 'X'; //Inimigo nivel 1

	//MAPA2
	//Parede decima
	for(j = 0; j < 20; j++) {
		board2[0][j] = '*';
	}
	//Parede esquerda
	for(i = 0; i < 20; i++) {
		board2[i][0] = '*';
	}
	//Parede direita
	for(i = 0; i < 20; i++) {
		board2[i][19] = '*';
	}
	//Parede na vertical no meio da sala
	for(i = 0; i < 10; i++) {
		board2[i][7] = '*';
	}
	//Parede do meio da sala
	for(j = 0; j < 20; j++) {
		board2[9][j] = '*';
	}

	//Parede de baixo da sala
	for(j = 0; j < 20; j++) {
		board2[19][j] = '*';
	}
	int enemy_linha2 = 16;
	int enemy_coluna2 = 13;
	
	board[4][11] = '#';//Espinho
	board2[4][3] = 'O';//botão mapa 2
	board2[enemy_linha2][enemy_coluna2] = 'Y'; //Inimigo nivel 2
	board2[9][9] = '=';//Porta aberta
	board2[4][7] = '=';//Porta aberta
	board2[19][9] = 'D';//Porta fechada para proxima fase
	board2[0][10] = '=';//Porta aberta

	//Printar menu
	do {
		print_menu(escolha);
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
				printf("\nSua vida %s%d%s",GREEN, player_vida,RESET);
				char move = getch();//Reconhecer teclas de movimento

				switch (move) {
					//Movimento para cima
					case 'w':
						if (player_linha > 0 && board[player_linha - 1][player_coluna] != '*')//Reconhcer parede
							player_linha--;
						break;
					//Movimento para baixo
					case 's':
						if (board[player_linha + 1][player_coluna] != '*' && board[player_linha + 1][player_coluna] != 'D' )//Reconhcer parede
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
						printf("%s\nEncerrando Jogo...%s",RED,RESET);
						sleep(2);
						system("cls");
						printf("%sAte a proxima! ;)%s", GREEN, RESET);
						exit(0);
						break;
					//Tecla i para pegar chave
					case 105:
						if(board[player_linha][player_coluna] == board[2][2]) {
							board[2][2] = ' ';
							board[9][4] = '=';
							printf("%s\n Voce pegou a chave com sucesso! %s ", GREEN, RESET);
							sleep(2);
						} else if(board[player_linha][player_coluna] != '@') {
							printf("%s\n Voce esta longe da chave...%s", YELLOW, RESET);
							sleep(1);
						}
						break;
					case 27:
						do {
							print_menu(escolha);

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
					default:
						break;
				}
				if(player_linha == enemy_linha && player_coluna == enemy_coluna) {
					player_vida--;
					if(player_vida == 0) {
						printf("\n%sGame Over%s!",RED, RESET);
						sleep(1);
						printf("\nVoce nao perdera o progresso.");
						sleep(3);
						system("cls");
						do {
							print_menu(escolha);
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
						player_vida += 3;
					}
				}
				//Inimigo X /mapa1
				int mov_aleatorio;
				srand(time(NULL));
				mov_aleatorio = 1 + rand() % 4;
				//Para esquerda
				if(mov_aleatorio == 1) {
					if(board[enemy_linha][enemy_coluna - 1] == ' ') {
						board[enemy_linha][enemy_coluna] = ' ';
						enemy_coluna--;
						board[enemy_linha][enemy_coluna] = 'X';
					}
				}
				//Para direita
				if(mov_aleatorio == 2) {
					if(board[enemy_linha][enemy_coluna + 1] == ' ') {
						board[enemy_linha][enemy_coluna] = ' ';
						enemy_coluna++;
						board[enemy_linha][enemy_coluna] = 'X';
					}
				}
				//Para cima
				if(mov_aleatorio == 3) {
					if(board[enemy_linha - 1][enemy_coluna] == ' ') {
						board[enemy_linha][enemy_coluna] = ' ';
						enemy_linha--;
						board[enemy_linha][enemy_coluna] = 'X';
					}
				}
				//Para baixo
				if(mov_aleatorio == 4) {
					if(board[enemy_linha + 1][enemy_coluna] == ' ') {
						board[enemy_linha][enemy_coluna] = ' ';
						enemy_linha++;
						board[enemy_linha][enemy_coluna] = 'X';
					}
				}
				//INICIAR MAPA2
				if(board[player_linha][player_coluna] == board[10][4]) {
					printf("%s\nNesta proxima fase tome cuidado com os espinhos e inimigos...%s",RED,RESET);
					sleep(4);

					while(1) {
						print_fase2(board2, player_linha2, player_coluna2);
						printf("\nSua vida %s%d%s",GREEN, player_vida,RESET);
						char move = getch();

						switch (move) {
							//Movimento para cima
							case 'w':
								if (player_linha2 > 0 && board2[player_linha2 - 1][player_coluna2] != '*')//Reconhcer parede
									player_linha2--;
								if(board2[enemy_linha2 - 1][enemy_coluna2] != '*' && board2[enemy_linha2 - 1][enemy_coluna2] == board2[player_linha2 - 1][player_coluna2] != '*') {
									board2[enemy_linha2][enemy_coluna2] = ' ';
									enemy_linha2--;
									board2[enemy_linha2][enemy_coluna2] = 'Y';
								}
								break;
							//Movimento para baixo
							case 's':
								if (board2[player_linha2 + 1][player_coluna2] != '*' && board2[player_linha2 + 1][player_coluna2] != 'D')//Reconhcer parede
									player_linha2++;
								if(board2[enemy_linha2 + 1][enemy_coluna2] == ' ' && board2[enemy_linha2 + 1][enemy_coluna2 ] != 'D' && board2[enemy_linha2 + 1][enemy_coluna2] != '=' ) {
									board2[enemy_linha2][enemy_coluna2] = ' ';
									enemy_linha2++;
									board2[enemy_linha2][enemy_coluna2] = 'Y';
								}
								break;
							//Movimento para esquerda
							case 'a':
								if (player_coluna2 > 0 && board2[player_linha2][player_coluna2 - 1] != '*') { //Reconhcer parede
									player_coluna2--;

									if(board2[enemy_linha2][enemy_coluna2 - 1] == ' ' && board2[enemy_linha2][enemy_coluna2 - 1] != 'D' && board2[enemy_linha2][enemy_coluna2 - 1] != '=') {
										board2[enemy_linha2][enemy_coluna2] = ' ';
										enemy_coluna2--;
										board2[enemy_linha2][enemy_coluna2] = 'Y';
									}

								}
								break;
							//Movimento para direita
							case 'd':
								if (player_coluna2 < coluna2 - 1 && board2[player_linha2][player_coluna2 + 1] != '*') { //Reconhcer parede
									player_coluna2++;
									if(board2[enemy_linha2][enemy_coluna2 + 1] == ' ' && board2[enemy_linha2][enemy_coluna2 + 1] != 'D' && board2[enemy_linha2][enemy_coluna2 + 1] != '=') {
										board2[enemy_linha2][enemy_coluna2] = ' ';
										enemy_coluna2++;
										board2[enemy_linha2][enemy_coluna2] = 'Y';
									}
								}
								break;
							//Q para sair do jogo so para TESTE por enquanto
							case 'q':
								printf("%s\nEncerrando Jogo...%s",RED,RESET);
								sleep(2);
								system("cls");
								printf("%sAte a proxima! ;) %s", GREEN, RESET);
								exit(0);
								break;
							//Interação do player com objetos
							case 'i':
								if(board2[player_linha2][player_coluna2] == 'O') {
									board2[4][3] = ' ';
									board2[13][4] = '@';
									printf("%s\nVoce apertou o botao com sucesso! %s ", GREEN, RESET);
									printf("%s\nAgora va ate a chave!%s", GREEN, RESET);
									sleep(2);
								} else if(board2[player_linha2][player_coluna2] == '@') {
									board2[13][4] = ' ';
									board2[19][9] = '=';
									printf("%s\nVoce pegou a chave com sucesso%s", GREEN, RESET);
									printf("%s\nVa ate a porta!%s", GREEN, RESET);
									sleep(2);
								} else if(player_linha2 != '@' && player_coluna2 != '@') {
									printf("%s\nProcure a chave...%s", YELLOW, RESET);
									sleep(1);
								}
								break;
							case 27:
								do {
									print_menu(escolha);

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
							default:
								break;
						}
						if(player_linha2 == enemy_linha2 && player_coluna2 == enemy_coluna2 && board2[player_linha2][player_coluna2] == '#') {
							player_vida--;
							if(player_vida == 0) {
								printf("\n%sGame Over%s!",RED, RESET);
								sleep(1);
								printf("\nVoce nao perdera o progresso.");
								sleep(3);
								system("cls");
								do {
									print_menu(escolha);
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
								player_vida += 3;
							}
						}
						//Inimigo X /MAPA2
						int mov_aleatorio2;
						srand(time(NULL));
						mov_aleatorio2 = 1 + rand() % 2;
						//Para esquerda
						if(mov_aleatorio2 == 1) {
							if(board2[enemy_linha2][enemy_coluna2 - 1] == ' ') {
								board2[enemy_linha2][enemy_coluna2] = ' ';
								enemy_coluna2--;
								board2[enemy_linha2][enemy_coluna2] = 'Y';
							}
						}
						//Para direita
						if(mov_aleatorio2 == 2) {
							if(board2[enemy_linha2][enemy_coluna2 + 1] == ' ') {
								board2[enemy_linha2][enemy_coluna2] = ' ';
								enemy_coluna2++;
								board2[enemy_linha2][enemy_coluna2] = 'Y';
							}
						}
					}
					break;
				}
			}
		case 3:
			printf("Saindo do jogo...\n");
			break;
	}
	return 0;
}
