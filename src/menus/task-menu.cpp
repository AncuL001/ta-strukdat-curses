#include "task-menu.hpp"

void first_task_screen(data_structures::CategoryNodePointer &current){
  auto top = current->tasks.top();

  system(CLEAR);
  std::cout << "Kategori: " << current->name << "\n\n\n";
  if (current->tasks.is_empty()){
    std::cout << "Tidak ada task!\n"
              << "0. Kembali\n"
              << ">> ";
    std::string dummy;
    std::getline(std::cin, dummy);
    std::getline(std::cin, dummy);
    return;
  }

  std::cout << top->description
            << "\nDeadline : "
            << std::setfill('0') << std::setw(2) << top->deadline.tm_mday << "-" 
            << std::setfill('0') << std::setw(2) << top->deadline.tm_mon << "-" 
            << std::setfill('0') << std::setw(4) << top->deadline.tm_year << "\n\n\n\n" 
            << "1. Tandai selesai\n"
            << "0. Kembali\n"
            << ">> ";
  char sel;
  std::cin >> sel;
  switch (sel){
    case '1':
      current->tasks.dequeue();
      break;

    case '0':
      return;

     default:
      break;
  }
}

void all_task_screen(const data_structures::CategoryNodePointer current){
  auto tasks = current->tasks;

  system(CLEAR);
  std::cout << "Kategori: " << current->name << "\n\n\n";
  if (tasks.is_empty()){
    std::cout << "Tidak ada task!\n"
              << "0. Kembali\n"
              << ">> ";
    std::string dummy;
    std::getline(std::cin, dummy);
    std::getline(std::cin, dummy);
    return;
  }

  std::cout << "Deadline   | Task\n";
  tasks.for_each([](data_structures::TaskNodePointer task){
    std::cout << std::setfill('0') << std::setw(2) << task->deadline.tm_mday << "-" 
              << std::setfill('0') << std::setw(2) << task->deadline.tm_mon << "-" 
              << std::setfill('0') << std::setw(4) << task->deadline.tm_year << " | " 
              << task->description << "\n";
  });
  std::cout << "\n\n\n0. Kembali\n>> ";
  char sel;
  std::cin >> sel;
  switch (sel){
    case '0':
      return;

     default:
      break;
  }
}

void add_task_screen(data_structures::CategoryNodePointer &current){
  // TODO : Benahi input tanggal yang tidak benar
  system(CLEAR);
  std::cout << "Kategori: " << current->name << "\n\n\n"
            << "Nama task : (0. Batal)\n"
            << ">> ";
  
  std::string name, deadline;
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  if (name == "0") return;

  std::cout << "\n"
            << "Deadline (DD-MM-YYYY) : (0. Batal)\n"
            << ">> ";
  std::cin >> deadline;
  if (deadline == "0") return;
  current->tasks.enqueue(new data_structures::TaskNode(name, parse_date(deadline)));
}