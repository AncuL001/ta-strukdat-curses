#include "category-menu.hpp"

void print_categories(const data_structures::CategoryList list){
  printw("Daftar Kategori:\n");
  list.for_each([](data_structures::CategoryNodePointer category){
    printw("> "); printw(category->name.c_str()); printw("\n");
  });
}

void move_category_screen(data_structures::CategoryList &list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  raw();
	noecho();

  while (true){
    clear();
    print_categories(list);
    printw("\n> Batal\n");
    refresh();

    int ch = getch();
    if (ch == KEY_MOUSE) {
      if (nc_getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          if (event.y > 0 && event.y <= list.get_size()){
            list.move_current(event.y - 1);
            return;
          }
          if (event.y == list.get_size() + 2) return;
        }
      }
    }
  }
}

void rename_category_screen(data_structures::CategoryList &list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  raw();
	noecho();

  while (true){
    clear();
    print_categories(list);
    printw("\n> Batal\n");
    refresh();

    int ch = getch();
    if (ch == KEY_MOUSE) {
      if (nc_getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          if (event.y > 0 && event.y <= list.get_size()){
            size_t index = event.y - 1;
            
            noraw();
            echo();

            clear();
            printw("\n"); printw("Nama baru : (0. Batal)\n");
            printw(">> ");
            refresh();

            char newName[1000];
            getstr(newName);
            if (*newName == '0') return;

            if (list.at(index)->name != newName && list.does_exist(newName)){
              while (true){
                clear();
                printw("Penggantian nama kategori gagal!\n");
                printw("Nama kategori baru tidak boleh sama dengan kategori lain\n");
                printw("> Kembali\n");
                refresh();

                int ch = getch();
                if (ch == KEY_MOUSE){
                  if (nc_getmouse(&event) == OK){
                    if (event.bstate & BUTTON1_CLICKED){
                      if (event.y == 2) return;
                    }
                  }
                }
              }
            }
            list.rename_category(index, newName);
            return;
          }
          if (event.y == list.get_size() + 2) return;
        }
      }
    }
  }
}

void add_category_screen(data_structures::CategoryList &list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  noraw();
	echo();

  clear();
  printw("\n"); printw("Nama baru: (0. Batal)\n");
  printw(">> ");
  refresh();

  char name[1000];
  getstr(name);
  if (*name == '0') return;

  if (list.does_exist(name)){
    raw();
    noecho();

    while (true){
      clear();
      printw("Penambahan kategori gagal!\n");
      printw("Nama kategori baru tidak boleh sama dengan kategori lain\n");
      printw("> Kembali\n");
      refresh();

      int ch = getch();
      if (ch == KEY_MOUSE){
        if (nc_getmouse(&event) == OK){
          if (event.bstate & BUTTON1_CLICKED){
            if (event.y == 2) return;
          }
        }
      }
    }
  }
  list.insert_category(new data_structures::CategoryNode(name));
}

void remove_category_screen(data_structures::CategoryList &list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  raw();
  noecho();

  while (true){
    clear();
    print_categories(list);
    printw("\n> Batal\n");
    refresh();

    int ch = getch();
    if (ch == KEY_MOUSE) {
      if (nc_getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          if (event.y > 0 && event.y <= list.get_size()){
            size_t index = event.y - 1;
            
            if (!list.at(index)->tasks.is_empty()){
              while(true){
                clear();
                printw("Kategori masih memiliki task\n");
                printw("Jika melanjutkan, semua task akan dihapus.\n");
                printw("> Melanjutkan\n");
                printw("> Kembali\n");
                refresh();

                ch = getch();
                if (ch == KEY_MOUSE) {
                  if (nc_getmouse(&event) == OK){
                    if (event.bstate & BUTTON1_CLICKED){
                      if (event.y == 2){
                        list.remove_category(index);
                        return;
                      }
                      if (event.y == 3) return;
                    }
                  }
                }
              }
            }
            list.remove_category(index);
            return;
          }
          if (event.y == list.get_size() + 2) return;
        }
      }
    }
  }
}

void view_category_screen(const data_structures::CategoryList list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  raw();
  noecho();

  while (true){
    clear();
    printw("Daftar Kategori:\n");
    list.for_each([](data_structures::CategoryNodePointer category){
      printw(" "); printw(category->name.c_str()); printw("\n");
    });
    printw("\n> Kembali\n");
    refresh();

    int ch = getch();
    if (ch == KEY_MOUSE) {
      if (nc_getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          if (event.y == list.get_size() + 2) return;
        }
      }
    }
  }
}

void category_options_screen(data_structures::CategoryList &list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  raw();
  noecho();

  data_structures::CategoryNodePointer current = list.get_current();
  while (true){
    clear();
    printw("Kategori: "); printw(current->name.c_str()); printw("\n\n");
    printw("> Pindah Kategori\n");
    printw("> Ubah Nama Kategori\n");
    printw("> Tambahkan Kategori\n");
    printw("> Hapus Kategori\n");
    printw("> Lihat Semua Kategori\n\n");
    printw("> Kembali\n");

    refresh();
    
    int ch = getch();
    if (ch == KEY_MOUSE) {
      if (nc_getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          switch (event.y){
            case 2:
              move_category_screen(list);
              return;

            case 3:
              rename_category_screen(list);
              break;

            case 4:
              add_category_screen(list);
              break;

            case 5:
              remove_category_screen(list);
              break;

            case 6:
              view_category_screen(list); 
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