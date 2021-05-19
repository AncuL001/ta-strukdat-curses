#pragma once
#include <csv2.hpp>
#include <string>
#include <vector>
#include "../data-structures/linked-list.hpp"
#include "../data-structures/queue.hpp"

/**
 * @brief memasukkan data ke program
 * 
 * @note format adalah category,task,deadline(yyyy-mm-dd)
 * @note semua task mempunyai category
 * @note jika ada category yang tidak ada task, field task dan deadline kosong
 * @todo handle case di mana nama file yang dimasukkan tidak ada
 * 
 * @param list list yang akan dimasukkan data
 * @param nama nama file yang ingin diimpor
 * @return 0 jika gagal (nama file tidak ditemukan atau file kosong), 1 jika berhasil
 */
bool import_data(data_structures::CategoryList &list, std::string name);

/**
 * @brief memasukkan data ke program
 * 
 * @note format adalah category,task,deadline(yyyy-mm-dd)
 * @note semua task mempunyai category
 * @note jika ada category yang tidak ada task, field task dan deadline kosong
 * 
 * @param list list yang akan diekspor datanya
 * @param nama nama file ekspor
 * @return selalu 1 (agar konsisten dengan import_data, mungkin nanti bisa dicari kondisi di mana fungsi ini gagal)
 */
bool export_data(const data_structures::CategoryList list, std::string name);