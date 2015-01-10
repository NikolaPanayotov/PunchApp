#include <pebble.h>
#include "main.h"

static Window *titleWindow;
static Window *countdownWindow;
static TextLayer *titleMessage;
static TextLayer *playMessage;

static void main_window_load(Window *window){
  //initialize the text box
  titleMessage = text_layer_create(GRect(0,10, 144,50));
  text_layer_set_background_color(titleMessage, GColorClear);
  text_layer_set_text_color(titleMessage, GColorBlack);
  text_layer_set_text(titleMessage, "PuNcH!");
  //display it
  text_layer_set_font(titleMessage, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(titleMessage, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(titleMessage));
  
  //play message
  playMessage = text_layer_create(GRect(0, 70, 144, 100));
  text_layer_set_background_color(playMessage, GColorBlack);
  text_layer_set_text_color(playMessage, GColorWhite);
  text_layer_set_text(playMessage, "Press Select to Play");
  text_layer_set_font(playMessage, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_text_alignment(playMessage, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(playMessage));
}

static void main_window_unload(Window *window){
  text_layer_destroy(titleMessage);
  text_layer_destroy(playMessage);
}

static void init(){
  titleWindow = window_create();
  window_set_window_handlers(titleWindow, (WindowHandlers){
    .load = main_window_load,
    .unload = main_window_unload
  });
  window_stack_push(titleWindow, true);
}

static void deinit(){
  window_destroy(titleWindow);
}

int main(void){
  init();
  app_event_loop();
  deinit();
}