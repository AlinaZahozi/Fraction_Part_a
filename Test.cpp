#include "doctest.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;


TEST_CASE("Test 1- Check constructors & reduce") {
    
    // Test default constructor
    Fraction frac1;
    CHECK(frac1.getFraction().getNumerator() == 0);
    CHECK(frac1.getFraction().getDenominator() == 1);

    // Test constructor with already reduced fraction
    Fraction frac2(8, 9);
    CHECK(frac2.getFraction().getNumerator() == 8);
    CHECK(frac2.getFraction().getDenominator() == 9);

    // Test constructor with unreduced fraction
    Fraction frac3(264, 32);
    CHECK(frac3.getFraction().getNumerator() == 33);
    CHECK(frac3.getFraction().getDenominator() == 4);

    // Test constructor with float
    Fraction frac4(7.5);
    CHECK(frac4.getFraction().getNumerator() == 15);
    CHECK(frac4.getFraction().getDenominator() == 2);
}

TEST_CASE("Test 2- Test throwing an error while dividing by zero") {

    // Test throwing an error while dividing by zero
    CHECK_THROWS(Fraction (3, 0));
}

TEST_CASE("Test 3- Check getters & setters") {

    // Test default constructor
    Fraction frac1;
    CHECK(frac1.getFraction().getNumerator() == 0);
    CHECK(frac1.getFraction().getDenominator() == 1);

    // Test setNumerator & setDenominator
    frac1.setNumerator(1);
    frac1.setDenominator(3);
    CHECK(frac1.getFraction().getNumerator() == 1);
    CHECK(frac1.getFraction().getDenominator() == 3);
}

TEST_CASE("Test 4-Test throwing an error while dividing by zero") {

    Fraction frac1;
    // Test throwing an error while dividing by zero
    CHECK_THROWS(frac1.setDenominator(0));
}


TEST_CASE("Test 5- Test the + operator") {

    // Test fraction + fraction
    Fraction frac1(1,4);
    Fraction frac2(1,3);
    Fraction frac3(7,12);
    CHECK(frac1 + frac2 == frac3);

    // Test fraction + fraction with unreduced fractions
    frac1.setNumerator(783);
    frac1.setDenominator(12);
    // frac1 = 261\4 after reduce
    frac2.setNumerator(62);
    frac2.setDenominator(16);
    // frac2 = 31\8 after reduce
    frac3.setNumerator(553);
    frac3.setDenominator(8);
    CHECK(frac1 + frac2 == frac3);

    float num = 2.5;
    frac3.setNumerator(271);
    frac3.setDenominator(4);

    // Test fraction + float
    CHECK(frac1 + num == frac3);

    // Test float + fraction
    CHECK(num + frac1 == frac3);

    // Test with negative float
    num = -2.5;
    frac3.setNumerator(251);
    frac3.setDenominator(4);
    CHECK(frac1 + num == frac3);
    CHECK(num + frac1 == frac3);
}

TEST_CASE("Test 6- Test the - operator") {

    // Test fraction - fraction
    Fraction frac1(1,3);
    Fraction frac2(1,4);
    Fraction frac3(1,12);
    CHECK(frac1 - frac2 == frac3);

    // Test fraction - fraction with unreduced fractions
    frac1.setNumerator(783);
    frac1.setDenominator(12);
    // frac1 = 261\4 after reduce
    frac2.setNumerator(62);
    frac2.setDenominator(16);
    // frac2 = 31\8 after reduce
    frac3.setNumerator(491);
    frac3.setDenominator(8);
    CHECK(frac1 - frac2 == frac3);

    float num = 2.5;
    frac3.setNumerator(251);
    frac3.setDenominator(4);

    // Test fraction - float
    CHECK(frac1 - num == frac3);

    frac3.setNumerator(-251);
    frac3.setDenominator(4);

    // Test float - fraction
    CHECK(num - frac1 == frac3);

    // Test with negative float
    num = -2.5;
    frac3.setNumerator(271);
    frac3.setDenominator(4);
    CHECK(frac1 - num == frac3);
    frac3.setNumerator(-271);
    frac3.setDenominator(4);
    CHECK(num - frac1 == frac3);
}

TEST_CASE("Test 7- Test the * operator") {

    // Test fraction * fraction
    Fraction frac1(1,3);
    Fraction frac2(1,4);
    Fraction frac3(1,12);
    CHECK(frac1 * frac2 == frac3);

    // Test fraction * fraction with unreduced fractions
    frac1.setNumerator(783);
    frac1.setDenominator(12);
    // frac1 = 261\4 after reduce
    frac2.setNumerator(62);
    frac2.setDenominator(16);
    // frac2 = 31\8 after reduce
    frac3.setNumerator(8091);
    frac3.setDenominator(32);
    CHECK(frac1 * frac2 == frac3);

    float num = 2.5;
    frac3.setNumerator(1305);
    frac3.setDenominator(8);

    // Test fraction * float
    CHECK(frac1 * num == frac3);

    // Test float * fraction
    CHECK(num * frac1 == frac3);

    // Test with negative float
    num = -2.5;
    frac3.setNumerator(-1305);
    frac3.setDenominator(8);
    CHECK(frac1 * num == frac3);
    CHECK(num * frac1 == frac3);
}

TEST_CASE("Test 8-Test the / operator") {

    // Test fraction / fraction
    Fraction frac1(1,3);
    Fraction frac2(1,4);
    Fraction frac3(1,12);
    CHECK(frac1 / frac2 == frac3);

    // Test fraction / fraction with unreduced fractions
    frac1.setNumerator(783);
    frac1.setDenominator(12);
    // frac1 = 261\4 after reduce
    frac2.setNumerator(62);
    frac2.setDenominator(16);
    // frac2 = 31\8 after reduce
    frac3.setNumerator(522);
    frac3.setDenominator(31);
    CHECK(frac1 / frac2 == frac3);

    float num = 2.5;
    frac3.setNumerator(261);
    frac3.setDenominator(10);

    // Test fraction / float
    CHECK(frac1 / num == frac3);

    frac3.setNumerator(10);
    frac3.setDenominator(261);

    // Test float / fraction
    CHECK(num / frac1 == frac3);

    // Test with negative float
    num = -2.5;
    frac3.setNumerator(-261);
    frac3.setDenominator(10);
    CHECK(frac1 / num == frac3);

    frac3.setNumerator(-10);
    frac3.setDenominator(261);

    CHECK(num / frac1 == frac3);

}

TEST_CASE("Test 9-Test if the / operator throwing an error while dividing by zero") {

    Fraction frac1;
    Fraction frac2;
    float num = 0.0;

    CHECK_THROWS(frac1 / frac2);
    CHECK_THROWS(frac2 / frac1);
    CHECK_THROWS(frac1 / num);
    CHECK_THROWS(frac2 / num);
    CHECK_THROWS(num / frac1);
    CHECK_THROWS(num / frac2);
}

TEST_CASE("Test 10-Test the == operator") {

    // Test fraction == fraction
    Fraction frac1;
    Fraction frac2;
    CHECK(frac1 == frac2);
    CHECK(frac2 == frac1);
    CHECK(frac1 == frac1);
    CHECK(frac2 == frac2);

    Fraction frac3(5,2);
    Fraction frac4(80,32);
    CHECK(frac3 == frac4);
    CHECK(frac4 == frac3);

    float num = 2.5;
    // Test fraction == float
    CHECK(frac3 == num);
    CHECK(frac4 == num);

    // Test float == fraction
    CHECK(num == frac3);
    CHECK(num == frac4);
}


TEST_CASE("Test 11-Test the > operator") {

    // Test fraction > fraction
    Fraction frac1(7,2); // 3.5
    Fraction frac2(17,5); // 3.4
    CHECK(frac1 > frac2);
    CHECK_FALSE(frac2 > frac1);

    float num = 2.5;
    // Test fraction > float
    CHECK(frac1 > num);
    CHECK(frac2 > num);

    num = 4.2;
    CHECK_FALSE(frac1 > num);
    CHECK_FALSE(frac2 > num);

    // Test float > fraction
    CHECK(num > frac1);
    CHECK(num > frac2);

    num = 1.7;
    CHECK_FALSE(num > frac1);
    CHECK_FALSE(num > frac2);
}


TEST_CASE("Test 12-Test the >= operator") {

    // Test fraction >= fraction
    Fraction frac1(7,2); // 3.5
    Fraction frac2(17,5); // 3.4
    CHECK(frac1 >= frac2);
    CHECK_FALSE(frac2 >= frac1);

    frac2.setNumerator(7);
    frac2.setDenominator(2);
    CHECK(frac1 >= frac2);
    CHECK(frac2 >= frac1);
    
    float num = 2.5;
    // Test fraction >= float
    CHECK(frac1 >= num);
    CHECK(frac2 >= num);

    num = 4.2;
    CHECK_FALSE(frac1 >= num);
    CHECK_FALSE(frac2 >= num);

    // Test float > fraction
    CHECK(num >= frac1);
    CHECK(num >= frac2);

    num = 1.7;
    CHECK_FALSE(num >= frac1);
    CHECK_FALSE(num >= frac2);
}

TEST_CASE("Test 13-Test the < operator") {

    // Test fraction < fraction
    Fraction frac1(38,5); // 7.6
    Fraction frac2(86,5); // 17.2
    CHECK(frac1 < frac2);
    CHECK_FALSE(frac2 < frac1);

    float num = 17.5;
    // Test fraction < float
    CHECK(frac1 < num);
    CHECK(frac2 < num);

    num = 4.2;
    CHECK_FALSE(frac1 < num);
    CHECK_FALSE(frac2 < num);

    // Test float < fraction
    CHECK(num < frac1);
    CHECK(num < frac2);

    num = 20.4;
    CHECK_FALSE(num < frac1);
    CHECK_FALSE(num < frac2);
}

TEST_CASE("Test 14-Test the <= operator") {

    // Test fraction <= fraction
    Fraction frac1(38,5); // 7.6
    Fraction frac2(86,5); // 17.2
    CHECK(frac1 <= frac2);
    CHECK_FALSE(frac2 <= frac1);

    frac2.setNumerator(38);
    frac2.setDenominator(5);
    CHECK(frac1 >= frac2);
    CHECK(frac2 >= frac1);

    float num = 17.5;
    // Test fraction <= float
    CHECK(frac1 <= num);
    CHECK(frac2 <= num);

    num = 4.2;
    CHECK_FALSE(frac1 <= num);
    CHECK_FALSE(frac2 <= num);

    // Test float <= fraction
    CHECK(num <= frac1);
    CHECK(num <= frac2);

    num = 20.4;
    CHECK_FALSE(num <= frac1);
    CHECK_FALSE(num <= frac2);
}


TEST_CASE("Test 15-Test prefix ++ operator") {
    
    Fraction fruc1(1,1);
    Fraction fruc2(2,1);
    Fraction &fruc = ++fruc1; // prefix ++
    CHECK(fruc1 == fruc);
    CHECK(fruc == fruc2);
}

TEST_CASE("Test 16-Test prefix -- operator") {
    
    Fraction fruc1(2,1);
    Fraction fruc2(1,1);
    Fraction &fruc = --fruc1; // prefix --
    CHECK(fruc1 == fruc);
    CHECK(fruc == fruc2);
}

TEST_CASE("Test 17-Test postfix ++ operator") {
    
    Fraction fruc1(1,1);
    Fraction fruc2(2,1);
    Fraction fruc3(1,1);
    Fraction fruc4 = fruc1++; // postfix ++
    CHECK(fruc4 == fruc3);
    CHECK(fruc1 == fruc2);
}

TEST_CASE("Test 18-Test postfix -- operator") {
    
    Fraction fruc1(1,1);
    Fraction fruc2(0,1);
    Fraction fruc3(1,1);
    Fraction fruc4 = fruc1--; // postfix --
    CHECK(fruc4 == fruc3);
    CHECK(fruc1 == fruc2);
}

TEST_CASE("Test 19-Test << operator") {

    Fraction frac(10,11);
    std::ostringstream stream;
    stream << frac;
    // print a fraction to an output stream in the format “numerator/denominator”
    CHECK(stream.str() == "10/11");
}

TEST_CASE("Test 20-Test >> operator") {

    Fraction frac;
    std::istringstream stream("98/13");
    stream >> frac;
    // read a fraction from an input stream by taking two integers as input
    CHECK(frac.getNumerator() == 98);
    CHECK(frac.getDenominator() == 13);
}