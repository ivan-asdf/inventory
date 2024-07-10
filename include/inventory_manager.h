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

  void addArticle(int id, const std::string &name, int quantity, double price,
                  const std::string &supplier);
  void updateArticle(int id, int quantity, double price);
  void deleteArticle(int id);
  void searchArticles(const std::string &criteria);
  void generateReport();

private:
  decltype(make_storage(
      "",
      make_table("Inventory", make_column("Id", &Article::id, primary_key().autoincrement()),
                 make_column("Name", &Article::name), make_column("Quantity", &Article::quantity),
                 make_column("Price", &Article::price),
                 make_column("Supplier", &Article::supplier)))) storage;
  void throwException(const char *context, int id, std::system_error error);
};

#endif // INVENTORY_MANAGER_H
