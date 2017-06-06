#include "../algoritmos/DivConq.h"
#include "../algoritmos/SMAWK.h"
#include "aux/FindRowMin.h"
#include "gtest/gtest.h"

int dataA[7][5] = {
    {10, 17, 13, 28, 23},
    {17, 22, 16, 29, 23},
    {24, 28, 22, 34, 24},
    {11, 13,  6, 17,  7},
    {45, 44, 32, 37, 23},
    {36, 33, 19, 21,  6},
    {75, 66, 51, 53, 34}
};

void TestGetRowMin (std::function< int(int,int) > f, int n, int m) {
    std::vector<int> ans = FindRowMin(f,n,m);
    EXPECT_EQ(ans,DivConq(f,n,m)) << "FindRowMin and DivConq should return equal vectors";
    EXPECT_EQ(ans,SMAWK(f,n,m)) << "FindRowMin and SMAWK should return equal vectors";
}


TEST(GetRowMin, SquareMatrix) {
    TestGetRowMin([] (int i, int j) { return dataA[i][j]; }, 5, 5);
}
TEST(GetRowMin, WideMatrix) {
    TestGetRowMin([] (int i, int j) { return dataA[i][j]; }, 4, 5);
}
TEST(GetRowMin, NarrowMatrix) {
    TestGetRowMin([] (int i, int j) { return dataA[i][j]; }, 7, 5);
}
