linux: main.cpp menus/task-menu.cpp menus/category-menu.cpp menus/additional-menu.cpp functions/datetime-plus.cpp functions/import-export.cpp
	g++ -o main main.cpp menus/task-menu.cpp menus/category-menu.cpp menus/additional-menu.cpp functions/datetime-plus.cpp functions/import-export.cpp -I../libs/include/csv2 -lncurses -Wall -Wpedantic -Wextra -std=c++17

linuxexe: main.cpp menus/task-menu.cpp menus/category-menu.cpp menus/additional-menu.cpp functions/datetime-plus.cpp functions/import-export.cpp
	x86_64-w64-mingw32-g++ -o main main.cpp menus/task-menu.cpp menus/category-menu.cpp menus/additional-menu.cpp functions/datetime-plus.cpp functions/import-export.cpp -I../libs/include/csv2 -I../libs/include/pdcurses ../libs/windows/pdcurses/pdcurses.a -Wall -Wpedantic -Wextra -std=c++17

windows: main.cpp menus/task-menu.cpp menus/category-menu.cpp menus/additional-menu.cpp functions/datetime-plus.cpp functions/import-export.cpp
	g++ -o main main.cpp menus/task-menu.cpp menus/category-menu.cpp menus/additional-menu.cpp functions/datetime-plus.cpp functions/import-export.cpp -I../libs/include/csv2 -I../libs/include/pdcurses ../libs/windows/pdcurses/pdcurses.a -Wall -Wpedantic -Wextra -std=c++17