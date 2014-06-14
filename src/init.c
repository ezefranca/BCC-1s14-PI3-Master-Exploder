#include "init.h"
#include "comum.h"

/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
int inicializar_allegro(){
	game = malloc(sizeof(GAME));
	game->pontos = malloc(sizeof(PONTUACAO));
	game->fontes = malloc(sizeof(FONTES));
	game->carrega = malloc(sizeof(CARREGAMENTO));
	game->telas = malloc(sizeof(TELAS));
	game->minions = malloc(sizeof(MINIONS));
	game->minions->minion = malloc(5 * sizeof(MINION*));
	
	for(int i = 0; i < 5; i++){
		game->minions->minion[i] = malloc(sizeof(MINION));
	}
	
	game->minions->minion[0]->probabilidade = 0.4;
	game->minions->minion[0]->pontos_perdidos = 1;
	game->minions->minion[0]->pontos_vencidos = 1;
	game->minions->minion[0]->falas = malloc(sizeof(FALAS));
	game->minions->minion[0]->falas->n = 2;
	game->minions->minion[0]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[0]->falas->frase = malloc(game->minions->minion[0]->falas->n * sizeof(char*));
	game->minions->minion[0]->falas->frase[0] = "Now is my turn!";
	game->minions->minion[0]->falas->frase[1] = "I will make you burn!";
	//game->minions->minion[0]->falas->frase[2] = "teste";
	
	game->minions->minion[1]->probabilidade = 0.75;
	game->minions->minion[1]->pontos_perdidos = 2;
	game->minions->minion[1]->pontos_vencidos = 3;
	game->minions->minion[1]->falas = malloc(sizeof(FALAS));
	game->minions->minion[1]->falas->n = 1;
	game->minions->minion[1]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[1]->falas->frase = malloc(game->minions->minion[1]->falas->n * sizeof(char*));
	game->minions->minion[1]->falas->frase[0] = "You can try, but ya gona down";
	
	game->minions->minion[2]->probabilidade = 0.9;
	game->minions->minion[2]->pontos_perdidos = 3;
	game->minions->minion[2]->pontos_vencidos = 2;
	game->minions->minion[2]->falas = malloc(sizeof(FALAS));
	game->minions->minion[2]->falas->n = 3;
	game->minions->minion[2]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[2]->falas->frase = malloc(game->minions->minion[2]->falas->n * sizeof(char*));
	game->minions->minion[2]->falas->frase[0] = "I am not the minion Vinicius.";
	game->minions->minion[2]->falas->frase[1] = "I am the Vinicius Second.";
	game->minions->minion[2]->falas->frase[2] = "Lets play";
	
	game->minions->minion[3]->probabilidade = 0.95;
	game->minions->minion[3]->pontos_perdidos = 10;
	game->minions->minion[3]->pontos_vencidos = 0;
	game->minions->minion[3]->falas = malloc(sizeof(FALAS));
	game->minions->minion[3]->falas->n = 1;
	game->minions->minion[3]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[3]->falas->frase = malloc(game->minions->minion[3]->falas->n * sizeof(char*));
	game->minions->minion[3]->falas->frase[0] = "I am Vinicius!";
	game->minions->minion[3]->falas->frase[0] = "Kibe is not a crime!";
		
	game->minions->minion[4]->probabilidade = 1;
	game->minions->minion[4]->pontos_perdidos = 3;
	game->minions->minion[4]->pontos_vencidos = 2;
	game->minions->minion[4]->falas = malloc(sizeof(FALAS));
	game->minions->minion[4]->falas->n = 1;
	game->minions->minion[4]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[4]->falas->frase = malloc(game->minions->minion[4]->falas->n * sizeof(char*));
	game->minions->minion[4]->falas->frase[0] = "A dica para o EP4 está no EP3!";
	
	int pontos_perdidos;
	int pontos_vencidos;
	
	config = carregar_configuracao("configuration.conf");
    
	if(config == NULL){
        criar_configuracao("configuration.conf");
	}
	
	//largura_imagem = string_para_int(pegar_configuracao("ALTURA","allegro", config)); 
	//altura_imagem = string_para_int(pegar_configuracao("LARGURA","allegro", config));
	
	game->largura_tela = 1280;
	game->altura_tela = 720;
	game->divisor_tempo = 1;
	game->divisor_camera = 1.5;
	game->luminus = 80;
	game->debug = false;
	game->maximo_respeito = 10; 
	game->_vizinhos = 100;
	game->usa_fecho = TRUE;
	game->melhor_de = 5;
	game->calibragem = 3;
	game->tempo_jogada = 5;
	game->pontos->numero_partidas = 0;
	game->pontos->jogador_1 = 0;
	game->pontos->jogador_2 = 0;
	game->pontos->respeito_jogador_1 = 0;
	game->pontos->respeito_jogador_2 = 0;
	
	game->carrega->musica = false;
	game->carrega->fonte = false;
	game->carrega->display = false;
	
	game->telas->sprite = true;
	game->telas->gameover = true;
	game->telas->start = true;
	game->telas->game = true;

	cam = camera_inicializa(0);

	game->largura_camera = cam->largura;
	game->altura_camera = cam->largura;
	
    if(!cam)
        erro("erro na inicializacao da camera\n");

    largura = cam->largura;
    altura = cam->altura;

	if(!al_init())
        erro("erro na inicializacao do allegro\n");

    if(!al_init_image_addon())
        erro("erro na inicializacao do adicional de imagem\n");

    if(!al_init_primitives_addon())
        erro("erro na inicializacao do adicional de primitivas\n");

    if(!al_install_audio())
      	erro("failed to initialize audio!\n");
   
    if(!al_init_acodec_addon())
      erro("failed to initialize audio codecs!\n");
 
	al_init_font_addon();
	al_init_ttf_addon();
		
	if(!al_reserve_samples(1))
		erro("failed to reserve samples!\n");

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
        erro("erro na criacao do relogio\n");

    display = al_create_display(game->largura_tela, game->altura_tela);
    if(!display)
        erro("erro na criacao da janela\n");

    queue = al_create_event_queue();
    if(!queue)
        erro("erro na criacao da fila\n");

    
	//game->idioma_setado = pegar_configuracao("IDIOMA","user", config);
	game->idioma_setado = NULL;
	
	game->fontes->super = al_load_font("assets/font/PAPYRUS.TTF", 150, 10);
	game->fontes->h1 = al_load_font("assets/font/PAPYRUS.TTF", 50, 10);
	game->fontes->h2 = al_load_font("assets/font/PAPYRUS.TTF", 40, 10);
	game->fontes->h3 = al_load_font("assets/font/PAPYRUS.TTF", 30, 10);
	game->fontes->h4 = al_load_font("assets/font/PAPYRUS.TTF", 25, 10);
	game->fontes->h5 = al_load_font("assets/font/PAPYRUS.TTF", 20, 10);
	game->fontes->h6 = al_load_font("assets/font/PAPYRUS.TTF", 15, 10);
	game->fontes->p = al_load_font("assets/font/PAPYRUS.TTF", 12, 10);
	
	if(game->idioma_setado != NULL)
        carregar_idioma(game->idioma_setado);
	else
		carregar_idioma("data/idiomas/pt_br.conf");
	
	char *test = pegar_idioma("test", linguagem);
	printf("%s", test);

	game->musica = al_load_sample("assets/sound/one.wav");

	if (!game->musica)
		{
			erro("Nao carregou o arquivo de musica game->musica");
		}
		al_play_sample(game->musica, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
	
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));

    al_start_timer(timer);
    return 1;
}
