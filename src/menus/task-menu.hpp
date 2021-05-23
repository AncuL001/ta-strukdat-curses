#pragma once
#include "../data-structures/linked-list.hpp"
#include "../data-structures/queue.hpp"
#include <curses.h>

void first_task_screen(data_structures::CategoryNodePointer &current);

void all_task_screen(const data_structures::CategoryNodePointer current);

void add_task_screen(data_structures::CategoryNodePointer &current);