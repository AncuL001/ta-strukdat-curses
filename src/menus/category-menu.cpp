#include "category-menu.hpp"

void print_categories(const data_structures::CategoryList list){
  std::cout << "Daftar Kategori:\n";
  list.for_each([](data_structures::CategoryNodePointer category){
    std::cout << " " << category->name << "\n";
  });
}

void move_category_screen(data_structures::CategoryList &list){
  system(CLEAR);
  print_categories(list);
  std::cout << "\n"
            << "Nama kategori: (0. Batal)\n"
            << ">> ";

  std::string name;
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  if (name == "0") return;

  if (list.move_current(name) == 0){
    system(CLEAR);
    std::cout << "Perpindahan kategori gagal!\n"
              << "Kategori tidak ditemukan.\n"
              << "0. Kembali\n"
              << ">> ";
    std::string dummy;
    std::getline(std::cin, dummy);
  }
}

void rename_category_screen(data_structures::CategoryList &list){
  system(CLEAR);
  print_categories(list);
  std::cout << "\n"
            << "Nama kategori: (0. Batal)\n"
            << ">> ";

  std::string oldName, newName;
  std::getline(std::cin, oldName);
  std::getline(std::cin, oldName);
  if (oldName == "0") return;

  std::cout << "Nama baru : (0. Batal)\n"
            << ">> ";

  std::getline(std::cin, newName);
  if (newName == "0") return;

  if (list.find_category(newName) && (oldName != newName)){
    system(CLEAR);
    std::cout << "Pengubahan nama kategori gagal!\n"
              << "Nama kategori baru tidak boleh sama dengan kategori lain\n"
              << "0. Kembali\n"
              << ">> ";
    std::string dummy;
    std::getline(std::cin, dummy);
    return;
  }

  if (list.rename_category(oldName, newName) == 0){
    system(CLEAR);
    std::cout << "Pengubahan nama kategori gagal!\n"
              << "Kategori tidak ditemukan\n"
              << "0. Kembali\n"
              << ">> ";
    std::string dummy;
    std::getline(std::cin, dummy);
  }
}

void add_category_screen(data_structures::CategoryList &list){
  system(CLEAR);
  std::cout << "Nama kategori: (0. Batal)\n"
            << ">> ";

  std::string name;
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  if (name == "0") return;

  if (list.insert_category(new data_structures::CategoryNode(name)) == 0){
    system(CLEAR);
    std::cout << "Penambahan kategori gagal!\n"
              << "Nama kategori baru tidak boleh sama dengan kategori lain\n"
              << "0. Kembali\n"
              << ">> ";
    std::string dummy;
    std::getline(std::cin, dummy);
  };
}

void remove_category_screen(data_structures::CategoryList &list){
  system(CLEAR);
  print_categories(list);
  std::cout << "\n"
            << "Nama kategori yang ingin dihapus: (0. Batal)\n"
            << ">> ";

  std::string name;
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  if (name == "0") return;

  if (list.find_category(name) && !list.find_category(name)->tasks.is_empty()){
    system(CLEAR);
    std::cout << "Kategori masih memiliki task\n"
              << "Jika melanjutkan, semua task akan dihapus.\n"
              << "1. Melanjutkan\n"
              << "0. Kembali\n"
              << ">> ";
    char sel;
    std::cin >> sel;
    if (sel == '0') return;
  }

  if (list.remove_category(name) == 0){
    system(CLEAR);
    std::cout << "Penghapusan kategori gagal!\n"
              << "Kategori tidak ditemukan\n"
              << "0. Kembali\n"
              << ">> ";
    std::string dummy;
    std::getline(std::cin, dummy);
  }
}

void view_category_screen(const data_structures::CategoryList list){
  system(CLEAR);
  print_categories(list);
  std::cout << "0. Kembali\n"
            << ">> ";

  char sel;
  std::cin >> sel;
  switch (sel){
    case '0':
      return;

     default:
      break;
  }
}

void category_options_screen(data_structures::CategoryList &list){
  data_structures::CategoryNodePointer current = list.get_current();
  system(CLEAR);
  std::cout << "Kategori : " << current->name << "\n\n"
            << "1. Pindah Kategori\n"
            << "2. Ubah Nama Kategori\n"
            << "3. Tambahkan Kategori\n"
            << "4. Hapus Kategori\n"
            << "5. Lihat Semua Kategori\n\n\n"
            << "0. Kembali\n"
            << ">> ";
  char sel;
    std::cin >> sel;
    switch (sel){
      case '1':
        move_category_screen(list);
        break;

      case '2':
        rename_category_screen(list);
        break;

      case '3':
        add_category_screen(list);
        break;

      case '4':
        remove_category_screen(list);
        break;

      case '5':
        view_category_screen(list); 
        break;

      case '0':
        return;

      default:
        break;
    }
}