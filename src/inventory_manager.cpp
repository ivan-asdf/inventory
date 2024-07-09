#include <exception>
#include <sstream>
#include <system_error>

#include "inventory_manager.h"

InventoryManager::InventoryManager(const std::string &db_name)
    : storage(make_storage(
          db_name,
          make_table("Inventory", make_column("Id", &Article::id, primary_key().autoincrement()),
                     make_column("Name", &Article::name),
                     make_column("Quantity", &Article::quantity),
                     make_column("Price", &Article::price),
                     make_column("Supplier", &Article::supplier)))) {
  storage.sync_schema();
}

void InventoryManager::addArticle(const std::string &name, int quantity, double price,
                                  const std::string &supplier) {
  Article article{-1, name, quantity, price, supplier};

  try {
    storage.insert(article);
  } catch (const std::system_error e) {
    std::stringstream errorMsg;
    errorMsg << "Error when creating article " << article.toString() << ": " << e.what();
    std::throw_with_nested(std::runtime_error(errorMsg.str()));
  }

  std::cout << "Record created successfully\n";
}

void InventoryManager::updateArticle(int id, int quantity, double price) {
  Article article;

  try {
    article = storage.get<Article>(id);
    article.quantity = quantity;
    article.price = price;
    storage.update(article);
  } catch (const std::system_error e) {
    std::stringstream errorMsg;
    errorMsg << "Error when updating article with ID " << id << ": " << e.what();
    std::throw_with_nested(std::runtime_error(errorMsg.str()));
  }

  std::cout << "Record updated successfully\n";
}

void InventoryManager::deleteArticle(int id) {
  try {
    storage.remove<Article>(id);
  } catch (const std::system_error e) {
    std::stringstream errorMsg;
    errorMsg << "Error when deliting article with ID " << id << ": " << e.what();
    std::throw_with_nested(std::runtime_error(errorMsg.str()));
  }
  std::cout << "Record deleted successfully\n";
}

void InventoryManager::searchArticles(const std::string &criteria) {
  std::vector<Article> articles;

  try {
    articles = storage.get_all<Article>(
        where(like(&Article::name, criteria) or like(&Article::supplier, criteria)));
  } catch (const std::system_error e) {
    std::stringstream errorMsg;
    errorMsg << "Error when searching articles : " << e.what();
    std::throw_with_nested(std::runtime_error(errorMsg.str()));
  }

  Table table;
  table.add_row({"ID", "Name", "Quantity", "Price", "Supplier"});
  for (const Article &article : articles) {
    table.add_row({std::to_string(article.id), article.name, std::to_string(article.quantity),
                   std::to_string(article.price), article.supplier});
  }

  std::cout << "Search results:\n";
  std::cout << table << std::endl;
}

void InventoryManager::generateReport() {
  std::vector<Article> articles;

  try {
    articles = storage.get_all<Article>();
  } catch (const std::system_error e) {
    std::stringstream errorMsg;
    errorMsg << "Error when generating report: " << e.what();
    std::throw_with_nested(std::runtime_error(errorMsg.str()));
  }

  Table table;
  table.add_row({"ID", "Name", "Quantity", "Price", "Supplier"});
  for (const Article &article : articles) {
    table.add_row({std::to_string(article.id), article.name, std::to_string(article.quantity),
                   std::to_string(article.price), article.supplier});
  }

  std::cout << "Report:\n";
  std::cout << table << std::endl;
}
