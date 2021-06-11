#include "additional-menu.hpp"

void import_data_screen(data_structures::CategoryList &list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  noraw();
	echo();

  clear();
  printw("Note: data yang ada di program akan terhapus\n");
  printw("Nama file untuk diimpor: (0. Batal)\n");
  printw(">> ");

  refresh();

  char name[1000];
  getstr(name);
  if (*name == '0') return;

  if (!import_data(list, name)){
    raw();
    noecho();

    clear();
    printw("\nImpor data gagal!\n");
    printw("> Kembali");

    refresh();
    int ch = getch();

    if (ch == KEY_MOUSE) {
      if (getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          if (event.y == 1) return;
        }
      }
    }
  }
}

void export_data_screen(data_structures::CategoryList &list){
  noraw();
	echo();

  clear();
  printw("Nama file ekspor: (0. Batal)\n");
  printw(">> ");

  refresh();

  char name[1000];
  getstr(name);
  if (*name == '0') return;

  export_data(list, name);
}

void additional_options_screen(data_structures::CategoryList &list){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  noraw();
	echo();

  while (true){
    clear();
    printw("> Impor data\n");
    printw("> Ekspor data\n");
    printw("> Hapus semua data\n");
    printw("> Kembali\n");

    refresh();

    int ch = getch();
    if (ch == KEY_MOUSE) {
      if (getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          switch (event.y) {
            case 0:
              import_data_screen(list);
              return;

            case 1:
              export_data_screen(list);
              return;

            case 2:
              list.make_empty();
              return;

            case 3:
              return;

            default:
              break;
          }
        }
      }
    }
  }
}