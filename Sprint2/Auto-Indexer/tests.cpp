#include "catch.hpp"
#include <algorithm>
#include <iostream>
#include <cstring>
#include "dvector.h"
#include "dstring.h"


TEST_CASE("DVector class", "[classic]"){

    SECTION("Declaration"){
        DVector<int> x;
        REQUIRE(x.getSize() == 0);
    }

    SECTION("Declaration given length as argument"){
        DVector<int> x = DVector<int>(5);
        REQUIRE(x.getSize() == 5);
        x.pushback(4);
        REQUIRE(x.getSize() == 6);
    }

    SECTION("[] accessor operator"){
        DVector<int> x;
        x.pushback(5);
        x.pushback(4);
        x.pushback(3);
        x.pushback(2);
        x.pushback(-1);
        REQUIRE(x[0] == 5);
        REQUIRE(x[1] == 4);
        REQUIRE(x[4] == -1);
        REQUIRE(-x[0] == -5);
        REQUIRE(x[0] != -5);
    }

    SECTION("Insert Function"){
        DVector<int> x = DVector<int>(5);
        x.insert(4, 10);
        REQUIRE(x[4] == 10);
        x.insert(2, 2);
        REQUIRE(x[2] == 2);
        REQUIRE(x[5] == 10);
        REQUIRE(x.getSize() == 7);
    }

    SECTION("Remove Function"){
        DVector<int> x = DVector<int>(5);
        x.insert(3, 10);
        REQUIRE(x[3] == 10);
        REQUIRE(x.getSize() == 6);
        x.remove(3);
        REQUIRE(x[3] != 10);
        REQUIRE(x.getSize() == 5);
    }

    SECTION("Push Back Function"){
        DVector<int> x = DVector<int>(5);
        x.pushback(10);
        REQUIRE(x[5] == 10);
        REQUIRE(x.getSize() == 6);
        x.pushback(9);
        REQUIRE(x[x.getSize() - 1] == 9);
    }

    SECTION("Pop Back Function"){
        DVector<int> x = DVector<int>(5);
        x.pushback(10);
        REQUIRE(x[5] == 10);
        REQUIRE(x.getSize() == 6);
        x.popback();
        REQUIRE(x[4] != 10);
        REQUIRE(x.getSize() == 5);
    }

    SECTION("Get Size Function"){
        DVector<int> x = DVector<int>(5);
        REQUIRE(x.getSize() == 5);
        x.pushback(4);
        REQUIRE(x.getSize() == 6);
    }

    SECTION("Sort Function"){
        DVector<int> x;
        for(int i = 0; i < 5; i++){
            x.pushback(5 - i);
        }
        x.sortVec();
        REQUIRE(x[0] == 1);
        REQUIRE(x[1] == 2);
        REQUIRE(x[2] == 3);
        REQUIRE(x[3] == 4);
        REQUIRE(x[4] == 5);
    }
}
