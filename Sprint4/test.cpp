#include "catch.hpp"
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "flight.h"
#include "city.h"
#include "adjacencylist.h"
#include"stack.h"


TEST_CASE("Node struct", "[classic]"){

    SECTION("Destructor"){
        Node<int>* x = new Node<int>();
        x->data = 1;
        REQUIRE(x->data == 1);
        delete x;
    }

    SECTION("Copy Constructor"){
        Node<int>* x = new Node<int>();
        x->data = 1;
        Node<int>* y = new Node<int>();
        *y = *x;
        delete x;
        REQUIRE(y->data == 1);
        delete y;
    }
}

TEST_CASE("List", "[classic]"){

    SECTION("Destructor"){
        List<int> x;
        x.push_back(1);
        REQUIRE(x.head->data == 1);
    }

    SECTION("Copy Constructor"){
        List<int>* x = new List<int>();
        x->push_back(1);
        x->push_back(2);
        List<int>* y = new List<int>();
        *y = *x;
        delete x;
        REQUIRE(y->head->data == 1);
        REQUIRE(y->tail->data == 2);
        delete y;
    }

    SECTION("Pop Back Function"){
        List<int>* x = new List<int>();
        x->push_back(1);
        x->push_back(2);
        x->push_back(3);
        REQUIRE(x->head->data == 1);
        REQUIRE(x->head->next->data == 2);
        REQUIRE(x->head->next->next->data == 3);
        delete x;
    }
}

TEST_CASE("City Class", "[classic]"){

    char test[4] = {'T', 'e', 's', 't'};

    SECTION("Declaration with Name"){
        City a(test);
        REQUIRE(strcmp(a.name, "Test") == 0);

    }

    SECTION("Copy Constructor"){
        City a(test);
        City b(a);
        REQUIRE(strcmp(b.name, "Test") == 0);

    }

    SECTION("Equals Operator"){
        City* a = new City(test);
        City b = *a;
        delete a;
        REQUIRE(strcmp(b.name, "Test") == 0);
    }
}

TEST_CASE("Flight Class", "[classic]"){

    char test[4] = {'T', 'e', 's', 't'};

    SECTION("Declaration with name"){
        Flight a(test, 1, 2);
        REQUIRE(strcmp(a.name, "Test") == 0);
        REQUIRE(a.price == 1);
        REQUIRE(a.time == 2);
    }

    SECTION("Copy Constructor"){
        Flight a(test, 1, 2);
        Flight b(a);
        REQUIRE(strcmp(b.name, "Test") == 0);
        REQUIRE(b.price == 1);
        REQUIRE(b.time == 2);
    }

    SECTION("Equals Operator"){
        Flight* a = new Flight(test, 1, 2);
        Flight b = *a;
        delete a;
        REQUIRE(strcmp(b.name, "Test") == 0);
        REQUIRE(b.price == 1);
        REQUIRE(b.time == 2);
    }
}

TEST_CASE("AdjacencyList", "[classic]"){

    char KC[2] = {'K', 'C'};
    char MO[2] = {'M', 'O'};
    char TX[2] = {'T', 'X'};
    char CA[2] = {'C', 'A'};

    SECTION("add Function"){
        AdjacencyList x;
        x.add(KC, MO, 1, 2);
        REQUIRE(strcmp(x.getHead()->data.name,KC) == 0);
        REQUIRE(strcmp(x.getHead()->data.data.head->data.name,MO) == 0);
    }

    SECTION("getHead Function"){
        AdjacencyList x;
        x.add(KC, MO, 1, 2);
        REQUIRE(strcmp(x.getHead()->data.name,KC) == 0);
        REQUIRE(strcmp(x.getHead()->data.data.head->data.name,MO) == 0);
    }

    SECTION("getTail Function"){
        AdjacencyList x;
        x.add(KC, MO, 1, 2);
        REQUIRE(strcmp(x.getTail()->data.name,KC) == 0);
        REQUIRE(strcmp(x.getTail()->data.data.head->data.name,MO) == 0);
    }

    SECTION("find Function"){
        AdjacencyList x;
        x.add(KC, MO, 1, 2);
        REQUIRE(x.find(KC) == x.getHead());
    }
}

TEST_CASE("Stack", "[classic]"){

    char KC[2] = {'K', 'C'};
    char MO[2] = {'M', 'O'};

    SECTION("push_back Function"){
        City* city = new City(KC);
        Stack stack;
        stack.push_back(city);
        REQUIRE(strcmp(stack.peek()->data->name, city->name) == 0);
        City* c = new City(KC);
        stack.push_back(c);
        REQUIRE(strcmp(stack.peek()->data->name, c->name) == 0);
    }

    SECTION("pop_back Function"){
        City* city = new City(KC);
        Stack stack;
        stack.push_back(city);
        REQUIRE(strcmp(stack.peek()->data->name, city->name) == 0);
        City* c = new City(KC);
        stack.push_back(c);
        REQUIRE(strcmp(stack.peek()->data->name, c->name) == 0);
        stack.pop_back();
        REQUIRE(strcmp(stack.peek()->data->name, city->name) == 0);
    }

    SECTION("isEmpty Function"){
        City* city = new City(KC);
        Stack stack;
        REQUIRE(stack.isEmpty());
        stack.push_back(city);
        REQUIRE(!stack.isEmpty());
        stack.pop_back();
        REQUIRE(stack.isEmpty());
    }

    SECTION("contains Function"){
        City* city = new City(KC);
        Stack stack;
        stack.push_back(city);
        REQUIRE(stack.contains(KC));
        REQUIRE(!stack.contains(MO));
    }

    SECTION("flip Function"){
        City* city = new City(KC);
        Stack stack;
        stack.push_back(city);
        City* c = new City(MO);
        stack.push_back(c);
        stack.flip();
        REQUIRE(strcmp(stack.peek()->data->name, KC) == 0);
        stack.pop_back();
        REQUIRE(strcmp(stack.peek()->data->name, MO) == 0);
    }
}
