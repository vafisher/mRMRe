#include "exports.hpp"

extern "C" SEXP
mRMR_filter(SEXP R_ChildrenCountPerLevel, SEXP R_FeatureInformationMatrix)
{
    std::vector<unsigned int> children_count_per_level = Rcpp::as < std::vector<unsigned int>
            > (R_ChildrenCountPerLevel);
    std::vector<float> feature_information_matrix = Rcpp::as < std::vector<float>
            > (R_FeatureInformationMatrix);

    Tree tree(&(children_count_per_level[0]), children_count_per_level.size(),
            &(feature_information_matrix[0]), feature_information_matrix.size());
    tree.build();

    return R_ChildrenCountPerLevel;
}
