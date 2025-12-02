#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
	srand(time(NULL)); // inicializa aleatório
	while(true){
		int l, c, linha = 0, coluna = 0, playagain = 0, menu = 0;
		char marca = 'X';
		bool gameover = false;
		char lista[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
		printf("=========MENU=========\n[1]1v1\n[2]Contra IA\n[3]Sair\n");
		scanf("%d",&menu);
	
		if(menu == 1){
		printf("======================\n");
		while(!gameover){
	
		while(1){
		//Printar tabuleiro
		for(l=0;l<3;l++){
			for(c=0;c<3;c++){
				printf("%c",lista[l][c]);
				if (c < 2) printf("|");
			}
			if (l < 2) printf("\n------\n");
		}
		printf("\n\nVez do jogador %c",marca);
		
		//Receber a entrada
		printf("\nLinha: ");
		scanf("%d",&linha);
		
		printf("Coluna: ");
		scanf("%d",&coluna);
		printf("\n");
		
		//Verificar celula valida
		if(lista[linha][coluna] == ' '){
			lista[linha][coluna] = marca;
			break;
		}else if (lista[linha][coluna] == 'O' || lista[linha][coluna] == 'X'){
			printf("Celula preenchida\n\n");
			continue;
		} else{
			printf("Invalido\n\n");
		}
		}
		
		//verificar vencedor
		for(l=0;l<3;l++){
			if(lista[l][0] != ' ' && lista[l][0] == lista[l][1] && lista[l][0] == lista[l][2]) gameover = true;
			}
		for(c=0;c<3;c++){
			if(lista[0][c] != ' ' && lista[0][c] == lista[1][c] && lista[0][c] == lista[2][c]) gameover = true;
			}
		if (lista[0][0] == lista[1][1] && lista[0][0] == lista[2][2] && lista[0][0] != ' ' || 
		lista[0][2] == lista[1][1] && lista[0][2] == lista[2][0] && lista[0][2] != ' ') gameover = true;
		
		//Verificar se empatou
		bool cheio = true;
		for(l=0;l<3;l++){
			for(c=0;c<3;c++){
				if (lista[l][c] == ' ') cheio = false;
			}
		}
		if (cheio){
			printf("Empate!\n");
			break;
		}
		
		//Mensagem final
		if(gameover){
			for(l=0;l<3;l++){
				for(c=0;c<3;c++){
					printf("%c",lista[l][c]);
					if (c < 2) printf("|");
				}
				if (l < 2) printf("\n------\n");
			}
			printf("\n\nJogador %c Vence!\n",marca);
			break;
		}
		
		//Troca da Marca��o 
		if (marca == 'X') marca = 'O';
		else marca = 'X';
		}
		}

	if(menu == 2){
	
	while(!gameover){
		
		//Printar tabuleiro
		for(l=0;l<3;l++){
			for(c=0;c<3;c++){
				printf("%c",lista[l][c]);
				if (c < 2) printf("|");
			}
			if (l < 2) printf("\n------\n");
		}
		printf("\n\n");

		//Verificar se empatou
		bool cheio = true;
		for(l=0;l<3;l++){
			for(c=0;c<3;c++){
				if (lista[l][c] == ' ') cheio = false;
			}
		}
		if (cheio){
			printf("Empate!\n");
			break;
		}

		// Jogador humano
		if (marca == 'X'){
			printf("Vez do jogador %c\n", marca);
			while(1){
				printf("Linha (0-2): ");
				scanf("%d",&linha);
				printf("Coluna (0-2): ");
				scanf("%d",&coluna);
				
				if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
					printf("Posição inválida!\n");
					continue;
				}
				if(lista[linha][coluna] == ' '){
					lista[linha][coluna] = marca;
					break;
				}else{
					printf("Célula preenchida, tente novamente.\n");
				}
			}
		}
		// Jogada da IA
		else{
			printf("Vez da IA (O)\n");
			do{
				linha = rand() % 3;
				coluna = rand() % 3;
			}while(lista[linha][coluna] != ' ');
			lista[linha][coluna] = marca;
		}

		//Verificar vencedor
		bool venceu = false;
		for(l=0;l<3;l++){
			if(lista[l][0] != ' ' && lista[l][0] == lista[l][1] && lista[l][0] == lista[l][2]) venceu = true;
		}
		for(c=0;c<3;c++){
			if(lista[0][c] != ' ' && lista[0][c] == lista[1][c] && lista[0][c] == lista[2][c]) venceu = true;
		}
		if ((lista[0][0] == lista[1][1] && lista[0][0] == lista[2][2] && lista[0][0] != ' ') || 
			(lista[0][2] == lista[1][1] && lista[0][2] == lista[2][0] && lista[0][2] != ' '))
			venceu = true;

		if (venceu){
			for(l=0;l<3;l++){
				for(c=0;c<3;c++){
					printf("%c",lista[l][c]);
					if (c < 2) printf("|");
				}
				if (l < 2) printf("\n------\n");
			}
			printf("\n\nJogador %c venceu!\n", marca);	
			break;
		}

		// Alternar turno
		if (marca == 'X') marca = 'O';
		else marca = 'X';
	}}
	if(menu == 3){
		printf("Obrigado por jogar!\n");
		break;
	}
	}

	return 0;
}
