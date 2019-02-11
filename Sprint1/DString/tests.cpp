#include "catch.hpp"
#include <cstring>
#include "dstring.h"


TEST_CASE("DString class", "[DString]"){

    DString s[10];
    s[0] = DString("testDString");
    s[1] = DString("a test DString");
    s[2] = DString("");
    s[3] = DString("THIS IS AN UPPERCASE DString");
    s[4] = DString("this is an uppercase DString");
    s[5] = DString("\n");
    s[6] = DString("");
    s[7] = DString("  split  split  split  ");
    s[8] = DString("                          ");
    s[9] = DString("testDString");

    SECTION("Equality operators"){
        REQUIRE(s[0] == DString("testDString"));
        REQUIRE(s[0] == s[9]);
        REQUIRE(s[2] == "");
        REQUIRE(s[1] == "a test DString");
        REQUIRE(!(s[3] == s[4]));
    }

    SECTION("Assignment operators"){
        DString str;
        str = "a test DString";
        REQUIRE(str == s[1]);
        str = DString("testDString");
        REQUIRE(str == s[0]);
        str = "";
        REQUIRE(str == s[6]);
        str = DString("\n");
        REQUIRE(str == s[5]);
    }

    SECTION("Addition operator"){
        REQUIRE(DString("testDStringtestDString") == s[0]+s[9]);
        REQUIRE(s[6] + s[6] == "");
        REQUIRE(s[5] + s[6] == DString("\n"));
        REQUIRE(s[0] + s[1] + s[2] == "testDStringa test DString");
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

    SECTION("getLength function"){
        REQUIRE(s[9].getLength() == 10);
        REQUIRE(s[2].getLength() == 0);
        REQUIRE(s[8].getLength() == 26);
        REQUIRE(s[3].getLength() == 27);
    }

//    SECTION("SubDString function"){
//        REQUIRE(s[0].subDString(0, 5) == "testS");
//        REQUIRE(s[4].subDString(0, 4) == "this");
//        REQUIRE(s[4].subDString(1, 3) == "his");
//    }

//    SECTION("c_str function"){
//        REQUIRE(strcmp(s[0].c_str(), "testDString") == 0);
//        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
//        REQUIRE(strcmp(s[2].c_str(), "") == 0);
//    }

}
