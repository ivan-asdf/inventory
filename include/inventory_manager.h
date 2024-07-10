#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <string>

#include <sqlite_orm/sqlite_orm.h>
#include <tabulate.hpp>

#include "article.h"

using namespace sqlite_orm;
using namespace tabulate;

class InventoryManager {
  static const std::string DB_NAME;

public:
  InventoryManager();

  enum SearchField { Id, Name, Quantity, Price, Supplier };
  enum SearchType { Equals, GreaterThan, LesserThan };
  struct SearchValue {
    enum class Type { String, Integer, Double };
    Type type;
    union {
      const char *String;
      int Integer;
      double Double;
    };

  public:
    SearchValue(const char *s);
    SearchValue(int x);
    SearchValue(double doubleValue);

    std::string toString();
  };

  void addArticle(int id, const std::string &name, int quantity, double price,
                  const std::string &supplier);
  void updateArticle(int id, const char *name, int quantity, double price, const char *supplier);
  void deleteArticle(int id);
  void searchArticles(SearchField field, SearchType type, SearchValue value);
  void generateReport();

private:
  decltype(make_storage(
      DB_NAME,
      make_table("Inventory", make_column("Id", &Article::id, primary_key().autoincrement()),
                 make_column("Name", &Article::name), make_column("Quantity", &Article::quantity),
                 make_column("Price", &Article::price),
                 make_column("Supplier", &Article::supplier)))) storage;

  void throwException(const char *context, int id, std::system_error error);

  std::string SearchFieldToString(SearchField field);
  std::string SearchTypeToString(SearchType type);
  std::string searchOptionsString(SearchField field, SearchType type, SearchValue value);
};

#endif // INVENTORY_MANAGER_H
