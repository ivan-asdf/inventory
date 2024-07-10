#include "inventory_manager.h"

int main() {
  InventoryManager manager;

  // manager.addArticle(-1, "Article1", 10, 9.99, "Supplier1");
  // manager.addArticle(200, "Article2", 20, 19.99, "Supplier2");
  // manager.addArticle(-2, "Article2", 20, 19.99, "Supplier2");
  // manager.addArticle(4, "Article2", 20, 19.99, "Supplier2");
  // manager.addArticle(0, "", 20, 19.99, "Supplier2");
  manager.addArticle(1, "Article1", 5, 19.99, "Supplier1");
  manager.updateArticle(1, "Article2", 33, 7.2, "Supplier321312");
  // manager.updateArticle(1, 0, -2, -1, nullptr);

  // manager.updateArticle(1, 15, 8.99);

  // manager.deleteArticle(2);

  // manager.searchArticles("Article1");
  //
  manager.generateReport();

  return 0;
}
