#include "import-export.hpp"

bool import_data(data_structures::CategoryList &list, std::string name){
  if (name.substr(name.length()-4, name.length()-1) != ".csv"){
    name.append(".csv");
  }
  std::string directory = "data/";
  name.insert(0, directory);

  list.make_empty();

  csv2::Reader<> file;
  if (!file.mmap(name)) return 0;

  for (const auto row: file){
    std::string category, task, deadline;
    int i = 0;

    for (const auto it: row){
      if (i == 0) it.read_raw_value(category);
      else if (i == 1) it.read_raw_value(task);
      else if (i == 2) it.read_raw_value(deadline);
      i++;
    }

    list.insert_category(new data_structures::CategoryNode(category));
    if (task != ""){
      list.move_current(category);
      list.get_current()->tasks.enqueue(new data_structures::TaskNode(task, parse_date(deadline)));
    }
  }
  return 1;
}

bool export_data(const data_structures::CategoryList list, std::string name){
  if (name.substr(name.length()-4, name.length()-1) != ".csv"){
    name.append(".csv");
  }
  std::string directory = "data/";
  name.insert(0, directory);

  std::ofstream stream(name);
  csv2::Writer<> writer(stream);

  std::vector<std::string> header = {"category", "task", "deadline(dd-mm-yyyy)"};
  writer.write_row(header);

  list.for_each([&writer](data_structures::CategoryNodePointer category){
    std::vector<std::string> row = {"", "", ""};
    row[0] = category->name;

    if (category->tasks.is_empty()){
      writer.write_row(row);
    }

    else {
      category->tasks.for_each([&writer, &row](data_structures::TaskNodePointer task){
        row[1] = task->description;

        std::string string_date = std::to_string(task->deadline.tm_mday);
        string_date += "-";
        string_date += std::to_string(task->deadline.tm_mon);
        string_date += "-";
        string_date += std::to_string(task->deadline.tm_year);
        row[2] = string_date;

        writer.write_row(row);
      });
    }
  });
  stream.close();
  return 1;
}