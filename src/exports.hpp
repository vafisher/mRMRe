#ifndef ensemble_exports_hpp
#define ensemble_exports_hpp

#include <cmath>
#include <vector>

#include <Rcpp.h>

#include "Tree.hpp"

extern "C" SEXP
mRMR_filter(SEXP R_ChildrenCountPerLevel, SEXP R_FeatureInformationMatrix, SEXP R_TargetFeatureIndex);

#endif /* ensemble_exports_hpp */
