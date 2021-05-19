#include "additional-menu.hpp"

void import_data_screen(data_structures::CategoryList &list){
  system(CLEAR);
  std::cout << "Note: data yang ada di program akan terhapus\n"
            << "Nama file untuk diimpor: (0. Batal)\n"
            << ">> ";
  std::string name;
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  if (name == "0") return;

  if (!import_data(list, name)){
    std::cout << "\nImpor data gagal!\n"
              << "0. Kembali\n"
              << ">> ";
    std::string dummy;
    std::getline(std::cin, dummy);
  };
}

void export_data_screen(data_structures::CategoryList &list){
  system(CLEAR);
  std::cout << "Nama file ekspor: (0. Batal)\n"
            << ">> ";
  std::string name;
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  if (name == "0") return;

  export_data(list, name);
}

void additional_options_screen(data_structures::CategoryList &list){
  // TODO : Implementasikan Stack
  // TODO : Regret my decision to add additional menu
  system(CLEAR);
  std::cout << "1. Impor data\n"
            << "2. Ekspor data\n"
            << "3. Hapus semua data\n"
            << "0. Kembali\n"
            << ">> ";
  char sel;
  std::cin >> sel;
  switch (sel){
      case '1':
        import_data_screen(list);
        break;

      case '2':
        export_data_screen(list);
        break;

      case '3':
        list.make_empty();
        break;

      case '0':
        return;

      default:
        break;
    }
}