#include "data-structures/linked-list.hpp"
#include "data-structures/queue.hpp"

#include "menus/task-menu.hpp"
#include "menus/category-menu.hpp"
#include "menus/additional-menu.hpp"
#include <curses.h>

bool empty_list_screen(data_structures::CategoryList &list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  raw();
  noecho();

  while (true){
    clear();
    printw("Tidak ada kategori.\n");
    printw("> Buat kategori baru\n");
    printw("> Impor data\n");
    printw("> Keluar\n");

    refresh();

    int ch = getch();
    if (ch == KEY_MOUSE) {
      if (getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          switch (event.y) {
            case 1:
              add_category_screen(list);
              return true;
            
            case 2:
              import_data_screen(list);
              return true;

            case 3:
              return false;

            default:
              break;
          }
        }
      }
    }
  }
}

void main_menu(data_structures::CategoryList &list){
  while (true){
    if (list.is_empty()){
      if (!empty_list_screen(list)) return;
    }

    else {
      MEVENT event;
      mmask_t old;
      mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
      raw();
      noecho();

      data_structures::CategoryNodePointer current = list.get_current();

      clear();
      printw("Kategori: "); printw(current->name.c_str()); printw("\n\n");
      printw("> Lihat task pertama \n");
      printw("> Lihat semua task\n");
      printw("> Tambahkan task\n\n");
      printw("> Pengaturan kategori\n");
      printw("> Pengaturan lain\n\n");
      printw("> Keluar\n");

      refresh();

      int ch = getch();

      if (ch == KEY_MOUSE) {
        if (getmouse(&event) == OK){
          if (event.bstate & BUTTON1_CLICKED){
            switch (event.y) {
              case 2:
                first_task_screen(current);
                break;
              
              case 3:
                all_task_screen(current);
                break;
              
              case 4:
                add_task_screen(current);
                break;

              case 6:
                category_options_screen(list);
                break;

              case 7:
                additional_options_screen(list); 
                break;

              case 9:
                return;

              default:
                break;
            }
          }
        }
      }
    }
  }
}

int main(){
  data_structures::CategoryList list;
  //list.insert_category(new data_structures::CategoryNode("test"));
  initscr();
  keypad(stdscr, TRUE);
  main_menu(list);
  endwin();
}