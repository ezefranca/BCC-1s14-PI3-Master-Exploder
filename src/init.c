#include "init.h"
/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
int inicializar_allegro(){	
	game = malloc(sizeof(Game));
	game->pontos = malloc(sizeof(Pontuacao));
	game->fontes = malloc(sizeof(Fontes));
	
	//config = carregar_configuracao("configuration.conf");
    
	//if(config == NULL)
    //    criar_configuracao("configuration.conf");
	
	//largura_imagem = string_para_int(pegar_configuracao("ALTURA","allegro", config)); 
	//altura_imagem = string_para_int(pegar_configuracao("LARGURA","allegro", config));
	
	game->largura_tela = 2000;
	game->altura_tela = 800;
	game->divisor_tempo = 1;
	game->divisor_camera = 1;
	game->luminus = 150;
	game->debug = TRUE;
	game->maximo_respeito = 10; 
	game->_vizinhos = 100;
	
	game->pontos->numero_partidas = 0;
	game->pontos->jogador_1 = 0;
	game->pontos->jogador_2 = 0;
	game->pontos->respeito_jogador_1 = 0;
	game->pontos->respeito_jogador_2 = 0;
	
	game->tela_sprite = false;
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
	
	game->fontes->h1 = al_load_font("assets/font/h1.ttf", 50, 10);
	game->fontes->h2 = al_load_font("assets/font/h1.ttf", 50, 10);
	game->fontes->h3 = al_load_font("assets/font/h1.ttf", 50, 10);
	game->fontes->h4 = al_load_font("assets/font/h1.ttf", 50, 10);
	game->fontes->h5 = al_load_font("assets/font/h1.ttf", 50, 10);
	game->fontes->h6 = al_load_font("assets/font/h1.ttf", 50, 10);
	game->fontes->p = al_load_font("assets/font/h1.ttf", 50, 10);
	
	if(game->idioma_setado != NULL)
        carregar_idioma(game->idioma_setado);
	else
		carregar_idioma("data/idiomas/pt_br.conf");
	
	char *test = pegar_idioma("test", linguagem);
	printf("%s", test);
	
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));

    al_start_timer(timer);
    return 1;
}
