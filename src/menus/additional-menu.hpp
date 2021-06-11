#pragma once
#include "../data-structures/linked-list.hpp"
#include "../data-structures/queue.hpp"

#include "../functions/import-export.hpp"
#define NCURSES_MOUSE_VERSION
#include <curses.h>

void import_data_screen(data_structures::CategoryList &list);

void export_data_screen(data_structures::CategoryList &list);

void additional_options_screen(data_structures::CategoryList &list);