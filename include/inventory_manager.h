#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <string>

#include <sqlite_orm/sqlite_orm.h>
#include <tabulate.hpp>

#include "article.h"

using namespace sqlite_orm;
using namespace tabulate;

class InventoryManager {

public:
  InventoryManager(const std::string &db_name);

  void addArticle(const std::string &name, int quantity, double price,
                  const std::string &supplier);
  void updateArticle(int id, int quantity, double price);
  void deleteArticle(int id);
  void searchArticles(const std::string &criteria);
  void generateReport();

private:
  decltype(make_storage(
      "",
      make_table("INVENTORY",
                 make_column("ID", &Article::id, primary_key().autoincrement()),
                 make_column("NAME", &Article::name),
                 make_column("QUANTITY", &Article::quantity),
                 make_column("PRICE", &Article::price),
                 make_column("SUPPLIER", &Article::supplier)))) storage;
  void throwException(const char* context, int id, std::system_error error);
};

#endif // INVENTORY_MANAGER_H
