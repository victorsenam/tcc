#include "gtest/gtest.h"
#include "../algoritmos/KnuthYao.h"
#include "aux/SolveIntRec.h"

int dataA[10] = {0,3,4,8,10,34,41,62,108,200};

TEST(IntRecurrence, AccumulateVector) {
    std::function< double(int,int) > C = [] (int i, int j) { return dataA[j+1] - dataA[i]; };
    EXPECT_EQ(SolveIntRec(C,9),KnuthYao(C,9)) << "SolveIntRec e KnuthYao devem retornar matrizes iguais.";
}
