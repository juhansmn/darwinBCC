#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include "header.h"

#define JANELA_X 1280
#define JANELA_Y 720

/*
========= YOSTER ISLAND =============
Caio Braga
Juan Soman
Lucas Gomes

Jogo educativo sobre a teoria da evolução criado com
o pacote ALLEGRO na linguagem C.

*/


int main(){
    enum statesGame selecaoTela = Menu;

    //INICIANDO ADDONS E INSTALANDO ELEMENTOS NECESSÁRIOS
    al_init();
    al_init_image_addon();
    al_init_acodec_addon();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();

    ALLEGRO_BITMAP *cursorSprite = al_load_bitmap("../res/images/cursor.png");
    ALLEGRO_DISPLAY *janela = al_create_display(JANELA_X, JANELA_Y);
    ALLEGRO_EVENT_QUEUE *fila;
    ALLEGRO_EVENT evento;

    fila = al_create_event_queue();
    al_register_event_source(fila, al_get_keyboard_event_source());
    al_register_event_source(fila, al_get_display_event_source(janela));

    ALLEGRO_MOUSE_CURSOR *cursor = al_create_mouse_cursor(cursorSprite, 20, 20);
    al_set_mouse_cursor(janela, cursor);

    // Loop de seleção de tela (Jogo)
    while(selecaoTela != Exit){
        switch(selecaoTela){
            case Menu:
              selecaoTela = menu(fila, evento);
              break;
            case Select:
              selecaoTela = menuSelect(fila, evento);
              break;
            case AmbienteUm:
              selecaoTela = ambienteUm(fila, evento);
              break;
        }
    }

    al_destroy_display(janela);
    al_destroy_bitmap(cursorSprite);
    al_destroy_mouse_cursor(cursor);
    al_destroy_event_queue(fila);
    al_uninstall_keyboard();


    return 0;
}
