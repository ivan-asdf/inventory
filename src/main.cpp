#include "inventory_manager.h"

int main() {
  InventoryManager manager("inventory.db");

  manager.addArticle("Article1", 10, 9.99, "Supplier1");
  // manager.addArticle("Article2", 20, 19.99, "Supplier2");

  // manager.updateArticle(20, 15, 8.99);

  // manager.deleteArticle(2);
  //
  manager.searchArticles("Article1");
  //
  // manager.generateReport();

  return 0;
}
