#pragma once
#include "../data-structures/linked-list.hpp"
#include "../data-structures/queue.hpp"

#include "../functions/import-export.hpp"

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void import_data_screen(data_structures::CategoryList &list);

void export_data_screen(data_structures::CategoryList &list);

void additional_options_screen(data_structures::CategoryList &list);