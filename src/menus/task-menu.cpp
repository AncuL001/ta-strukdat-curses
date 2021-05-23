#include "task-menu.hpp"

void first_task_screen(data_structures::CategoryNodePointer &current){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  noraw();
	echo();

  auto top = current->tasks.top();

  while(true){
    clear();
    printw("Kategori: "); printw(current->name.c_str()); printw("\n\n\n");

    if (current->tasks.is_empty()){
      printw("Tidak ada task!\n");
      printw("> Kembali\n");
      refresh();

      int ch = getch();
      if (ch == KEY_MOUSE) {
        if (nc_getmouse(&event) == OK){
          if (event.bstate & BUTTON1_CLICKED){
            if (event.y == 4) return;
          }
        }
      }
    }

    printw(top->description.c_str());
    printw("\nDeadline : ");
    printw("%02d-", top->deadline.tm_mday);
    printw("%02d-", top->deadline.tm_mon);
    printw("%04d\n\n\n", top->deadline.tm_year);

    printw("> Tandai selesai\n");
    printw("> Kembali\n");
    refresh();

    int ch = getch();
      
    if (ch == KEY_MOUSE){
      if (nc_getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED){
          switch (event.y) {
            case 7:
              current->tasks.dequeue();
              return;
            
            case 8:
              return;


            default:
              break;
          }
        }
      }
    }
  }
}

void all_task_screen(const data_structures::CategoryNodePointer current){
  MEVENT event;
  mmask_t old;
  mousemask (ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);
  noraw();
	echo();

  auto tasks = current->tasks;

  while(true){
    clear();
    printw("Kategori: "); printw(current->name.c_str()); printw("\n\n\n");

    if (current->tasks.is_empty()){
      printw("Tidak ada task!\n");
      printw("> Kembali\n");
      refresh();

      int ch = getch();
      if (ch == KEY_MOUSE) {
        if (nc_getmouse(&event) == OK){
          if (event.bstate & BUTTON1_CLICKED){
            if (event.y == 4) return;
          }
        }
      }
    }

    printw("Deadline   | Task\n");
    tasks.for_each([](data_structures::TaskNodePointer task){
      printw("%02d-", task->deadline.tm_mday);
      printw("%02d-", task->deadline.tm_mon);
      printw("%04d | ", task->deadline.tm_year);
      printw(task->description.c_str()); printw("\n");
    });

    printw("\n> Kembali\n");
    refresh();

    int ch = getch();
      
    if (ch == KEY_MOUSE){
      if (nc_getmouse(&event) == OK){
        if (event.bstate & BUTTON1_CLICKED) return;
      }
    }
  }
}


void add_task_screen(data_structures::CategoryNodePointer &current){
  // TODO : Benahi input tanggal yang tidak benar
  noraw();
	echo();

  clear();
  printw("Kategori: "); printw(current->name.c_str()); printw("\n\n\n");
  printw("Nama task (0. Batal)\n");
  printw(">> ");
  refresh();
  
  char name[1000];
  getstr(name);
  if (*name == '0') return;

  printw("\n");
  printw("Deadline (DD-MM-YYYY) (0. Batal)\n");
  printw(">> ");
  refresh();

  char deadline[1000];
  getstr(deadline);
  if (*deadline == '0') return;

  current->tasks.enqueue(new data_structures::TaskNode(name, parse_date(deadline)));
}