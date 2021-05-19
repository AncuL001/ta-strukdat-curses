#pragma once
#include <iomanip>
#include "../data-structures/linked-list.hpp"
#include "../data-structures/queue.hpp"

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void first_task_screen(data_structures::CategoryNodePointer &current);

void all_task_screen(const data_structures::CategoryNodePointer current);

void add_task_screen(data_structures::CategoryNodePointer &current);