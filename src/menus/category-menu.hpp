#pragma once
#include "../data-structures/linked-list.hpp"
#include "../data-structures/queue.hpp"
#define NCURSES_MOUSE_VERSION
#include <curses.h>

void print_categories(const data_structures::CategoryList list);

void move_category_screen(data_structures::CategoryList &list);

void rename_category_screen(data_structures::CategoryList &list);

void add_category_screen(data_structures::CategoryList &list);

void remove_category_screen(data_structures::CategoryList &list);

void view_category_screen(const data_structures::CategoryList list);

void category_options_screen(data_structures::CategoryList &list);