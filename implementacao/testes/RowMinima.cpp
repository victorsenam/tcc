#include "../algoritmos/DivConq.h"
#include "../algoritmos/SMAWK.h"
#include "aux/FindRowMin.h"
#include "gtest/gtest.h"

void TestGetRowMin (std::function< int(int,int) > f, int n, int m) {
    std::vector<int> a = FindRowMin(f, n, m);
    std::vector<int> b = SMAWK(f, n, m);
    EXPECT_EQ(a,b) << "FindRowMin and SMAWK should return equal vectors";

    b = DivConq(f, n, m);
    EXPECT_EQ(a,b) << "FindRowMin and DivConq should return equal vectors";
}

TEST(GetRowMin, test0) {
    int A[7][5] = {
        {10, 17, 13, 28, 23},
        {17, 22, 16, 29, 23},
        {24, 28, 22, 34, 24},
        {11, 13,  6, 17,  7},
        {45, 44, 32, 37, 23},
        {36, 33, 19, 21,  6},
        {75, 66, 51, 53, 34}
    };

    TestGetRowMin([A] (int i, int j) { return A[i][j]; }, 7, 5);
}
