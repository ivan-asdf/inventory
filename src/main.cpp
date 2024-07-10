#include "inventory_manager.h"

int main() {
  InventoryManager manager;

  // manager.addArticle(-1, "Article1", 10, 9.99, "Supplier1");
  // manager.addArticle(200, "Article2", 20, 19.99, "Supplier2");
  // manager.addArticle(-2, "Article2", 20, 19.99, "Supplier2");
  // manager.addArticle(4, "Article2", 20, 19.99, "Supplier2");
  // manager.addArticle(0, "", 20, 19.99, "Supplier2");
  manager.addArticle(1, "Article1", 5, 19.99, "Supplier1");
  manager.addArticle(2, "Article1", 5, 19.99, "Supplier1");
  manager.addArticle(3, "Article1", 5, 19.99, "Supplier1");
  manager.addArticle(4, "Article1", 7, 8.5, "Supplier3");
  manager.addArticle(5, "Article1", 7, 8.5, "Supplier3");
  manager.updateArticle(1, "Article2", 33, 7.2, "Supplier321312");
  // manager.updateArticle(1, 0, -2, -1, nullptr);

  // manager.updateArticle(1, 15, 8.99);

  // manager.deleteArticle(2);

  manager.searchArticles(InventoryManager::SearchField::Id,
                         InventoryManager::SearchType::GreaterThan,
                         InventoryManager::SearchValue(1));
  manager.searchArticles(InventoryManager::SearchField::Name,
                         InventoryManager::SearchType::Equals,
                         InventoryManager::SearchValue("cle2"));
  manager.searchArticles(InventoryManager::SearchField::Quantity,
                         InventoryManager::SearchType::Equals,
                         InventoryManager::SearchValue(5));
  manager.searchArticles(InventoryManager::SearchField::Quantity,
                         InventoryManager::SearchType::GreaterThan,
                         InventoryManager::SearchValue(4));
  manager.searchArticles(InventoryManager::SearchField::Quantity,
                         InventoryManager::SearchType::GreaterThan,
                         InventoryManager::SearchValue(30));
  manager.searchArticles(InventoryManager::SearchField::Price,
                         InventoryManager::SearchType::GreaterThan,
                         InventoryManager::SearchValue(19.0));
  manager.searchArticles(InventoryManager::SearchField::Price,
                         InventoryManager::SearchType::Equals,
                         InventoryManager::SearchValue(19.99));
  manager.searchArticles(InventoryManager::SearchField::Supplier,
                         InventoryManager::SearchType::Equals,
                         InventoryManager::SearchValue("ier3"));
  manager.searchArticles(InventoryManager::SearchField::Supplier,
                         InventoryManager::SearchType::GreaterThan,
                         InventoryManager::SearchValue("ier3"));

  // Should cause error
  // manager.searchArticles(InventoryManager::SearchField(5),
  //                        InventoryManager::SearchType::GreaterThan,
  //                        InventoryManager::SearchValue("ier3"));
  //
  manager.deleteArticle(4);
  manager.deleteArticle(4);
  manager.generateReport();

  return 0;
}
