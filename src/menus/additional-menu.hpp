#pragma once
#include "../data-structures/linked-list.hpp"
#include "../data-structures/queue.hpp"

#include "../functions/import-export.hpp"
#include <curses.h>

void import_data_screen(data_structures::CategoryList &list);

void export_data_screen(data_structures::CategoryList &list);

void additional_options_screen(data_structures::CategoryList &list);