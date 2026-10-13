#include <iostream>
#include <memory>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene ----
    std::cout << std::endl << "== Uno table scene ==" << std::endl;
    std::unique_ptr<List<Player>> table = makeList<Player>();
    table->addFront(new Player(3, "Chloe"));
    table->addFront(new Player(2, "Ben"));
    table->addFront(new Player(1, "Ava"));
    std::cout << "The first table forms:" << std::endl;
    table->print();

    std::cout << "Dylan joins between Ava and Ben:" << std::endl;
    table->addAnywhere(1, new Player(4, "Dylan"));
    table->print();

    std::cout << "Reverse card! Order before reversing:" << std::endl;
    table->print();
    table->reverse();
    std::cout << "Order after reversing:" << std::endl;
    table->print();

    std::cout << "Ben runs out of cards and leaves:" << std::endl;
    table->deleteAnywhere(1);
    table->print();

    std::unique_ptr<List<Player>> secondTable = makeList<Player>();
    secondTable->addFront(new Player(6, "Farah"));
    secondTable->addFront(new Player(5, "Ethan"));
    std::cout << "Second table before merging:" << std::endl;
    secondTable->print();
    std::cout << "First table before merging:" << std::endl;
    table->print();

    table->concat(secondTable.get());
    std::cout << "First table after merging:" << std::endl;
    table->print();
    std::cout << "Second table after ownership transfer (empty):" << std::endl;
    secondTable->print();

    return 0;
}
