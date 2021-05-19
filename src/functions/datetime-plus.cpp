#include "datetime-plus.hpp"

char compare_deadline(tm lhs, tm rhs){
  if (lhs.tm_year > rhs.tm_year) return '>';
  if (lhs.tm_year < rhs.tm_year) return '<';

  if (lhs.tm_mon > rhs.tm_mon) return '>';
  if (lhs.tm_mon < rhs.tm_mon) return '<';

  if (lhs.tm_mday > rhs.tm_mday) return '>';
  if (lhs.tm_mday < rhs.tm_mday) return '<';

  return '=';
}

tm parse_date(const std::string string_form){
  tm temp;
  std::stringstream ss(string_form);
  std::string d, m, y;

  std::getline(ss, d, '-');
  temp.tm_mday = stoi(d);

  std::getline(ss, m, '-');
  temp.tm_mon  = stoi(m);

  std::getline(ss, y, '-');
  temp.tm_year = stoi(y);
  
  return temp;
}