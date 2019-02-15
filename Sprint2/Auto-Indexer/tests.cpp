#include "catch.hpp"
#include <cstring>
#include "dvector.h"
#include "dstring.h"


TEST_CASE("DVector class", "[DVector]"){



    SECTION("Template Test"){
        DVector<int> x;
        x.pushback(5);
        REQUIRE(x[2] == 5);
    }


//    SECTION("Greater than operator"){
//        REQUIRE(s[0] > s[1]);
//        REQUIRE(s[4] > s[3]);
//        REQUIRE(s[9] > s[6]);
//        REQUIRE(s[7] > s[6]);
//    }

//    SECTION("[] Operator"){
//        REQUIRE(s[0][1] == 'e');
//        REQUIRE(s[4][4] == ' ');
//        REQUIRE(s[6][0] == 0);
//    }


//    SECTION("SubDVector function"){
//        REQUIRE(s[0].subDVector(0, 5) == "testS");
//        REQUIRE(s[4].subDVector(0, 4) == "this");
//        REQUIRE(s[4].subDVector(1, 3) == "his");
//    }

//    SECTION("c_str function"){
//        REQUIRE(strcmp(s[0].c_str(), "testDVector") == 0);
//        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
//        REQUIRE(strcmp(s[2].c_str(), "") == 0);
//    }

}
