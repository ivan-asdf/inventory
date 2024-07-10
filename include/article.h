#ifndef ARTICLE_H
#define ARTICLE_H

#include <sstream>
#include <string>

struct Article {
  int id;
  std::string name;
  int quantity;
  double price;
  std::string supplier;

  std::string toString() const {
    std::stringstream ss;
    ss << "Article{ID: " << id << ", Name: " << name << ", Quantity: " << quantity
       << ", Price: " << price << ", Supplier: " << supplier << "}";
    return ss.str();
  }
};

#endif // ARTICLE_H
