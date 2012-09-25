#ifndef mRMRe_exports_h
#define mRMRe_exports_h

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include <cstdlib>
#include <vector>

#include "Filter.h"
#include "Math.h"
#include "MutualInformationMatrix.h"

extern "C" SEXP
export_concordance_index(SEXP samplesA, SEXP samplesB, SEXP samplesC, SEXP samplesD,
        SEXP sampleStrata, SEXP sampleWeights, SEXP sampleStratumCount, SEXP outX, SEXP out);

extern "C" SEXP
export_filter(SEXP childrenCountPerLevel, SEXP dataMatrix, SEXP priorsMatrix, SEXP priorsWeight,
        SEXP sampleStrata, SEXP sampleWeights, SEXP featureTypes, SEXP sampleCount,
        SEXP featureCount, SEXP sampleStratumCount, SEXP targetFeatureIndex,
        SEXP continuousEstimator, SEXP outX, SEXP bootstrapCount, SEXP miMatrix);

extern "C" SEXP
export_mim(SEXP dataMatrix, SEXP priorsMatrix, SEXP priorsWeight, SEXP sampleStrata,
        SEXP sampleWeights, SEXP featureTypes, SEXP sampleCount, SEXP featureCount,
        SEXP sampleStratumCount, SEXP continuousEstimator, SEXP outX, SEXP bootstrapCount,
        SEXP miMatrix);

extern "C" SEXP
get_thread_count(SEXP threadCount);

extern "C" SEXP
set_thread_count(SEXP threadCount);

#endif /* mRMRe_exports_h */
