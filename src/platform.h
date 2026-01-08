#pragma once
// ###################################################################################
//                                  Platform Globals 
// ###################################################################################
static bool running = true;

// ###################################################################################
//                                  Platform Globals 
// ###################################################################################
bool platform_create_window(int width, int height, const char* title);
void platform_update_window();
void *platform_load_gl_function(char* funName);
void platform_swap_buffers();
