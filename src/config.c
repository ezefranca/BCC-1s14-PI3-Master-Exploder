#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "config.h" 
#include "utils.h"

bool setar_configuracao(const char *conf_key, const char *conf_value, const char *section, ALLEGRO_CONFIG *config) {
	char *value;
	
	al_add_config_section(config, section);
	
	//Setar item de configuracao.
	al_set_config_value(config, section, conf_key, conf_value);
	
	
	value = al_get_config_value(config, section, conf_key);
	if(strcmp(value, conf_value)){
		return TRUE;
	}
	return FALSE;
}

bool criar_configuracao(char *name){
	/** Colocar a lista de configuracoes padroes aqui. */
	ALLEGRO_CONFIG *new_config;
	
	new_config = al_create_config();
	
	setar_configuracao("CAM_DIVISOR", "1.5", "camera", new_config);
<<<<<<< HEAD
	setar_configuracao("TIMER_DIVIDENDO", "1.0", "allegro", new_config);
=======
>>>>>>> 007b205307e56e74bb3c93cada309cccc554a52a
	
	if(!al_save_config_file(name, new_config)) {
		free(new_config);
		erro("Erro na criacao do arquivo de configuracao inicial\n");
		}
	free(new_config);
	return TRUE;
}

bool salvar_configuracao(char *name, ALLEGRO_CONFIG *config){
	return al_save_config_file(name, config);
}

ALLEGRO_CONFIG *carregar_configuracao(const char *name) {
	return al_load_config_file(name);
}

char *pegar_configuracao(const char *conf_key, const char *section, const ALLEGRO_CONFIG *config){
	return al_get_config_value(config, section, conf_key);
}