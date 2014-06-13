#ifndef CONFIG_H
#define CONFIG_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include "utils.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define TRUE 1
#define FALSE 0

/**
 *  <#Description#>
 *
 *  @param conf_key   <#conf_key description#>
 *  @param conf_value <#conf_value description#>
 *  @param section    <#section description#>
 *  @param config     <#config description#>
 *
 *  @return <#return value description#>
 */
bool setar_configuracao(const char *conf_key, const char *conf_value, const char *section, ALLEGRO_CONFIG *config);

/**
 *  <#Description#>
 *
 *  @param name <#name description#>
 *
 *  @return <#return value description#>
 */
bool criar_configuracao(char *name);
/**
 *  <#Description#>
 *
 *  @param name   <#name description#>
 *  @param config <#config description#>
 *
 *  @return <#return value description#>
 */
bool salvar_configuracao(char *name, ALLEGRO_CONFIG *config);
/**
 *  <#Description#>
 *
 *  @param name <#name description#>
 *
 *  @return <#return value description#>
 */
ALLEGRO_CONFIG *carregar_configuracao(const char *name);
/**
 *  <#Description#>
 *
 *  @param conf_key <#conf_key description#>
 *  @param section  <#section description#>
 *  @param config   <#config description#>
 *
 *  @return <#return value description#>
 */
const char *pegar_configuracao(const char *conf_key, const char *section, const ALLEGRO_CONFIG *config);

/**
 *  <#Description#>
 */
typedef struct _pontos {
	int numero_partidas;
	int jogador_1;
	int jogador_2;
	int respeito_jogador_1;
	int respeito_jogador_2;
} Pontuacao;

typedef struct _falas {
	int n;
	char **frase;
} Fala;

/**
 *  <#Description#>
 */
typedef struct _minion {
	double probabilidade;
	int pontos_perdidos;
	int pontos_vencidos;
	Fala *falas;
	char *imagem;
} Minion;

/**
 *  <#Description#>
 */
typedef struct _minions {
	Minion **minion;
} Minions;

/**
 *  <#Description#>
 */
typedef struct _fontes {
	ALLEGRO_FONT *super;
	ALLEGRO_FONT *h1;
	ALLEGRO_FONT *h2;
	ALLEGRO_FONT *h3;
	ALLEGRO_FONT *h4;
	ALLEGRO_FONT *h5;
	ALLEGRO_FONT *h6;
	ALLEGRO_FONT *p;	
} Fontes;

/**
 *  <#Description#>
 */
typedef struct _carrega {
	bool musica;
	bool fonte;
	bool display;
} Carregamento;

typedef struct _telas {
	bool sprite;
	bool gameover;
	bool start;
	bool game;
} Telas;
/**
 *  <#Description#>
 */
typedef struct _game {
	int largura_camera;
	int altura_camera;
	int largura_tela;
	int altura_tela;
	
	float divisor_tempo;
	float divisor_camera;
	int luminus;
	bool debug;
	bool usa_fecho;
	int _vizinhos;
	int maximo_respeito;
	int melhor_de;
	int tempo_jogada;
	int calibragem;
	const char *idioma_setado;
	Telas *telas;
	Carregamento *carrega;
	Pontuacao *pontos;
	Fontes *fontes;
	Minions *minions;
	ALLEGRO_SAMPLE *musica;
} Game;

Game *game;

#endif
