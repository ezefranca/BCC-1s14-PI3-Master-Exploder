#include "jogabilidade.h"
#include <time.h>

/**
 *  <#Description#>
 *
 *  @param jogador_1 <#jogador_1 description#>
 *  @param jogador_2 <#jogador_2 description#>
 *
 *  @return <#return value description#>
 */

int ganhador_rodada(int jogador_1, int jogador_2){
	if(jogador_1 == jogador_2)
		return EMPATE;
	
	if(jogador_1 == PEDRA && jogador_2 == PAPEL)
		return JOGADOR_2;
	
	if(jogador_2 == PEDRA && jogador_1 == PAPEL)
		return JOGADOR_1;
	
	if(jogador_1 > jogador_2)
		return JOGADOR_1;
	else 
		return JOGADOR_2;
}


/**
 *  <#Description#>
 *
 *  @param jogador_1 <#jogador_1 description#>
 *  @param jogador_2 <#jogador_2 description#>
 *
 *  @return <#return value description#>
 */
int ganhador_jogo(int jogador_1, int jogador_2){
	if(jogador_1 == jogador_2){
		return EMPATE;
	}
	if(jogador_1 > jogador_2){
		return JOGADOR_1;
	}
	else 
		return JOGADOR_2;
}

//Retorna a jogada vencedora. Exemplo: Se jogador colocar tesoura, a funcao retorna Pedra.
/**
 *  <#Description#>
 *
 *  @param jogador <#jogador description#>
 *
 *  @return <#return value description#>
 */
int fazer_jogada_melhor(int jogador){
	if(jogador == PEDRA)
		return PAPEL;
	return jogador + 1;
}

/**
 *  <#Description#>
 *
 *  @param jogador <#jogador description#>
 *
 *  @return <#return value description#>
 */
int fazer_jogada_pior(int jogador) {
	if(jogador == PAPEL)
		return PEDRA;
	return jogador - 1;
}

/**
 *  <#Description#>
 *
 *  @param jogador <#jogador description#>
 *
 *  @return <#return value description#>
 */
int mao_adversario(int jogador_1){
	srand(abs(time(NULL)));
	int randomic = rand();

	if(randomic % 10 == 0){
		//Trapaceia
		return fazer_jogada_melhor(jogador_1);
	}
	else {
		return randomic % 3;
	}
}

/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
MINION *rand_boss(bool *minion_4_usado){
	double resultado;
	int randomic;
	srand(abs(time(NULL)));
	randomic = rand();
	resultado = (double) (randomic % 11)/ 10;
	
	if(resultado <= game->minions->minion[MINION_1]->probabilidade) {
		return game->minions->minion[MINION_1];
	}
	else if(resultado <= game->minions->minion[MINION_2]->probabilidade) {
		return game->minions->minion[MINION_2];
	}
	else if(resultado <= game->minions->minion[MINION_3]->probabilidade) {
		return game->minions->minion[MINION_3];
	}
	else if(resultado <= game->minions->minion[MINION_4]->probabilidade) {
		if(!minion_4_usado) {
			minion_4_usado = TRUE;
			return game->minions->minion[MINION_4];
		}
		return game->minions->minion[MINION_1];
	}
	else {
		return game->minions->minion[MINION_5];
	}
}

/**
 *  <#Description#>
 *
 *  @param pontos_jogador_1 <#pontos_jogador_1 description#>
 *  @param pontos_jogador_2 <#pontos_jogador_2 description#>
 *  @param melhor_jogo      <#melhor_jogo description#>
 *
 *  @return <#return value description#>
 */

int fim_jogada(int pontos_jogador_1, int pontos_jogador_2, int melhor_jogo){
	if(pontos_jogador_1 == 0 && pontos_jogador_2 == 0)
		return 0;

	//Verifica se jogadas sao impares.
	if((melhor_jogo % 2) > 0)
		return (pontos_jogador_1 > (melhor_jogo/2) || pontos_jogador_2 > (melhor_jogo/2));
	else
		return (pontos_jogador_1 > (melhor_jogo/2) || pontos_jogador_2 > (melhor_jogo/2) || (pontos_jogador_1 + pontos_jogador_2) == melhor_jogo);
}

/**
 *  <#Description#>
 *
 *  @param respeito      <#respeito description#>
 *
 *  @return <#return value description#>
 */
int fim_de_jogo(int respeito){
	return (respeito >= game->maximo_respeito || respeito <= 0);
}