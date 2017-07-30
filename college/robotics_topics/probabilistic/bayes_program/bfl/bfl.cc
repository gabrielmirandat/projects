//    BFL::DiscretePdf dp(5);
//    double total = 0;

//    std::vector<BFL::Probability> probs;
//    probs.push_back(BFL::Probability(1.));
//    probs.push_back(BFL::Probability(1.));
//    probs.push_back(BFL::Probability(1.));
//    probs.push_back(BFL::Probability(1.));
//    probs.push_back(BFL::Probability(1.));

//    dp.ProbabilitiesSet(probs);

//    std::cout << "num estados: " << dp.NumStatesGet() << std::endl;

//    for(size_t i=0; i < dp.NumStatesGet(); i++)
//    {
//        BFL::Probability p = dp.ProbabilityGet(i);
//        std::cout << p.getValue() << std::endl;
//        total += p.getValue();
//    }

//    std::cout << "total: " << total << std::endl;

#include <bfl/pdf/uniform.h>
#include <bfl/pdf/discretepdf.h>
#include <bfl/pdf/discreteconditionalpdf.h>

int main()
{
    // OBJ: P(A,B,C) = P(A).P(B|C).P(C|A)

    BFL::DiscretePdf A(5);
    BFL::DiscreteConditionalPdf CdA(25,1);

    BFL::ColumnVector();
    BFL::Matrix();
    // BFL::Matrix_Wrapper();



    //    B.ProbabilitySet(0, BFL::Probability(0.4));
    //    B.ProbabilitySet(1, BFL::Probability(0.4));
    //    B.ProbabilitySet(2, BFL::Probability(0.4));
    //    B.ProbabilitySet(3, BFL::Probability(0.4));
    //    B.ProbabilitySet(4, BFL::Probability(0.4));








    std::cout << A.ProbabilityGet(2).getValue() << std::endl;
//    std::cout << CdA.ProbabilityGet(2).getValue() << std::endl;

}

