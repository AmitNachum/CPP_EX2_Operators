#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Matrix_nxn.hpp"

using namespace Squared_Matrix;

TEST_CASE("Matrix Addition") {
    squaredMatrix A(3), B(3);
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 3; ++j) {
            A.getMatrix()[i][j] = 1;
            B.getMatrix()[i][j] = 2;
        }
    squaredMatrix C = A + B;
    CHECK(C.getMatrix()[1][1] == 3);
}

TEST_CASE("Matrix Multiplication") {
    squaredMatrix A(2), B(2);
    A.getMatrix()[0][0] = 1; A.getMatrix()[0][1] = 2;
    A.getMatrix()[1][0] = 3; A.getMatrix()[1][1] = 4;

    B.getMatrix()[0][0] = 5; B.getMatrix()[0][1] = 6;
    B.getMatrix()[1][0] = 7; B.getMatrix()[1][1] = 8;

    squaredMatrix C = A * B;
    CHECK(C.getMatrix()[0][0] == 19);
    CHECK(C.getMatrix()[0][1] == 22);
    CHECK(C.getMatrix()[1][0] == 43);
    CHECK(C.getMatrix()[1][1] == 50);
}

TEST_CASE("Matrix Scalar Division") {
    squaredMatrix A(2);
    A.getMatrix()[0][0] = 10; A.getMatrix()[0][1] = 20;
    A.getMatrix()[1][0] = 30; A.getMatrix()[1][1] = 40;

    squaredMatrix B = A / 10.0;
    CHECK(B.getMatrix()[0][0] == doctest::Approx(1.0));
    CHECK(B.getMatrix()[1][1] == doctest::Approx(4.0));
}

TEST_CASE("Matrix Transpose") {
    squaredMatrix A(2);
    A.getMatrix()[0][1] = 7;
    A.getMatrix()[1][0] = 9;
    A = ~A;
    CHECK(A.getMatrix()[0][1] == 9);
    CHECK(A.getMatrix()[1][0] == 7);
}

TEST_CASE("Matrix Determinant") {
    squaredMatrix A(2);
    A.getMatrix()[0][0] = 4; A.getMatrix()[0][1] = 6;
    A.getMatrix()[1][0] = 3; A.getMatrix()[1][1] = 8;
    CHECK((!A) == doctest::Approx(14.0));
}

TEST_CASE("Matrix Power") {
    squaredMatrix A(2);
    A.getMatrix()[0][0] = 1; A.getMatrix()[0][1] = 1;
    A.getMatrix()[1][0] = 1; A.getMatrix()[1][1] = 0;
    squaredMatrix B = A ^ 3;
    CHECK(B.getMatrix()[0][0] == 3);
    CHECK(B.getMatrix()[0][1] == 2);
}

TEST_CASE("Matrix Pre/Post Increment/Decrement") {
    squaredMatrix A(2);
    A.getMatrix()[0][0] = 1; A.getMatrix()[0][1] = 2;
    A.getMatrix()[1][0] = 3; A.getMatrix()[1][1] = 4;

    squaredMatrix pre = ++A;
    CHECK(pre.getMatrix()[0][0] == 2);
    squaredMatrix post = A++;
    CHECK(post.getMatrix()[0][0] == 2);
    CHECK(A.getMatrix()[0][0] == 3);

    squaredMatrix preDec = --A;
    CHECK(preDec.getMatrix()[0][0] == 2);
    squaredMatrix postDec = A--;
    CHECK(postDec.getMatrix()[0][0] == 2);
    CHECK(A.getMatrix()[0][0] == 1);
}

TEST_CASE("Matrix Stream Output") {
    squaredMatrix A(2);
    A.getMatrix()[0][0] = 1; A.getMatrix()[0][1] = 2;
    A.getMatrix()[1][0] = 3; A.getMatrix()[1][1] = 4;

    std::ostringstream oss;
    oss << A;
    std::string expected = "1, 2\n3, 4\n";
    CHECK(oss.str() == expected);
}

TEST_CASE("Matrix Element-wise Multiplication with %") {
    squaredMatrix A(2), B(2);
    A.getMatrix()[0][0] = 1; A.getMatrix()[0][1] = 2;
    A.getMatrix()[1][0] = 3; A.getMatrix()[1][1] = 4;

    B.getMatrix()[0][0] = 2; B.getMatrix()[0][1] = 3;
    B.getMatrix()[1][0] = 4; B.getMatrix()[1][1] = 5;

    squaredMatrix C = A % B;
    CHECK(C.getMatrix()[0][0] == 2);
    CHECK(C.getMatrix()[0][1] == 6);
    CHECK(C.getMatrix()[1][0] == 12);
    CHECK(C.getMatrix()[1][1] == 20);
}

TEST_CASE("Matrix Modulo with Scalar using %") {
    squaredMatrix A(2);
    A.getMatrix()[0][0] = 5; A.getMatrix()[0][1] = 9;
    A.getMatrix()[1][0] = 14; A.getMatrix()[1][1] = 7;

    squaredMatrix C = A % 4;
    CHECK(C.getMatrix()[0][0] == 1);
    CHECK(C.getMatrix()[0][1] == 1);
    CHECK(C.getMatrix()[1][0] == 2);
    CHECK(C.getMatrix()[1][1] == 3);
}

TEST_CASE("Matrix Logical Comparisons") {
    squaredMatrix A(2), B(2);
    A.getMatrix()[0][0] = 1; A.getMatrix()[0][1] = 1;
    A.getMatrix()[1][0] = 1; A.getMatrix()[1][1] = 1;

    B.getMatrix()[0][0] = 2; B.getMatrix()[0][1] = 2;
    B.getMatrix()[1][0] = 2; B.getMatrix()[1][1] = 2;

    CHECK((A == A));
    CHECK((A != B));
    CHECK((A < B));
    CHECK((B > A));
    CHECK((A <= B));
    CHECK((B >= A));
}
