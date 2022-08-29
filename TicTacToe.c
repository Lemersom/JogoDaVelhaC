/*
Implemente um tipo abstrato de dados para representar um jogo da velha que tenha as
seguintes operações:
? Cria um jogo vazio
? Jogadores X e O realizam uma jogada
? Exibe tabuleiro
? Verifica se um dos jogadores venceu o jogo
? Gera uma jogada aleatória para um dos jogadores
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> //sleep()

struct {
	char casas[10];
	char vencedor; // X ou O	
	int njogadas;
}typedef jogo;

jogo *criarVazio();
void printJogo(jogo*);
jogo *jogadaPlayer(char, jogo*);
jogo *jogadaPc(jogo*);
void venceu(jogo*);

int main(){
	jogo *velha;
	
	
	velha = criarVazio();
	velha->vencedor = ' ';
	printJogo(velha);
	while(1){
		char escolha = ' ';
		
		printf("\nEscolha o local: ");
		scanf(" %c", &escolha);
		velha = jogadaPlayer(escolha, velha);
		velha->njogadas += 1;
		
		if(velha->njogadas == 9){ //Deu velha
			break;
		}
		
		venceu(velha);
		printJogo(velha);
		printf("\nEspere...\n"); sleep(1);
		
		if(velha->vencedor == 'X' || velha->vencedor == 'O'){
			break;
		}
		
		velha = jogadaPc(velha);
		venceu(velha);
		printJogo(velha);
		velha->njogadas += 1;
		printf("\nEspere...\n"); sleep(1); 
		
		if(velha->vencedor == 'X' || velha->vencedor == 'O'){
			break;
		}
	}
	
	if(velha->vencedor == ' '){
		printf("\n ----- Deu Velha! ------");
	}else{
		printf("\n ----- Vencedor: %c -----", velha->vencedor);
	}
	
	return 0;
}


jogo *criarVazio(){
	jogo *velha = malloc(sizeof(jogo));
	
	strncpy(velha->casas, "123456789", sizeof(velha->casas));
}


void printJogo(jogo *velha){
	int c = 0;
	
	for(c = 1;c <= 9;c++){
		printf("%c",velha->casas[c-1]);
		if(c % 3 == 0){
			printf("\n");
		}
	}
	printf("\n");
}


jogo *jogadaPlayer(char escolha, jogo *velha){
	int c = 0;
	
	for(c = 0; c < 9; c++){
		if(velha->casas[c] == escolha){
			velha->casas[c] = 'X';
			return velha;
		}
	}
}


jogo *jogadaPc(jogo *velha){
	int jogada = 0;
	char convertido = ' ';
	
	srand(time(NULL));
	
	while(1){
		if(velha->vencedor == 'X' || velha->vencedor == 'O'){
			break;
		}
		jogada = rand() % 9;
		convertido = jogada;
		if(velha->casas[jogada] != 'O' && velha->casas[jogada] != 'X'){
			velha->casas[jogada] = 'O';
			return velha;
		}
	}
}


void venceu(jogo *velha){
	if((velha->casas[0] == 'X' && velha->casas[1] == 'X' && velha->casas[2] == 'X') || (velha->casas[3] == 'X' && velha->casas[4] == 'X' && velha->casas[5] == 'X') || (velha->casas[6] == 'X' && velha->casas[7] == 'X' && velha->casas[8] == 'X') ||
	(velha->casas[0] == 'X' && velha->casas[4] == 'X' && velha->casas[8] == 'X') || (velha->casas[2] == 'X' && velha->casas[4] == 'X' && velha->casas[6] == 'X') || (velha->casas[0] == 'X' && velha->casas[3] == 'X' && velha->casas[6] == 'X') || 
	(velha->casas[1] == 'X' && velha->casas[4] == 'X' && velha->casas[7] == 'X') || (velha->casas[2] == 'X' && velha->casas[5] == 'X' && velha->casas[8] == 'X')){
		velha->vencedor = 'X';
	}
	else if((velha->casas[0] == 'O' && velha->casas[1] == 'O' && velha->casas[2] == 'O') || (velha->casas[3] == 'O' && velha->casas[4] == 'O' && velha->casas[5] == 'O') || (velha->casas[6] == 'O' && velha->casas[7] == 'O' && velha->casas[8] == 'O') ||
	(velha->casas[0] == 'O' && velha->casas[4] == 'O' && velha->casas[8] == 'O') || (velha->casas[2] == 'O' && velha->casas[4] == 'O' && velha->casas[6] == 'O') || (velha->casas[0] == 'O' && velha->casas[3] == 'O' && velha->casas[6] == 'O') || 
	(velha->casas[1] == 'O' && velha->casas[4] == 'O' && velha->casas[7] == 'O') || (velha->casas[2] == 'O' && velha->casas[5] == 'O' && velha->casas[8] == 'O')){
		velha->vencedor = 'O';
	}
	
}
