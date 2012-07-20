#include "Matrix.hpp"

Matrix::Matrix(unsigned int const rowCount, unsigned int const columnCount) :
        mpData(new float[rowCount * columnCount]), mRowCount(rowCount), mColumnCount(columnCount), mHasAllocation(
                true)
{

}

/* explicit */
Matrix::Matrix(unsigned int const size, unsigned int const rowCount, unsigned int const columnCount) :
        mpData(new float[size]), mRowCount(rowCount), mColumnCount(columnCount), mHasAllocation(
                true)
{

}

/* explicit */
Matrix::Matrix(float* const pData, unsigned int const rowCount, unsigned int const columnCount) :
        mpData(pData), mRowCount(rowCount), mColumnCount(columnCount), mHasAllocation(false)
{

}

/* virtual */
Matrix::~Matrix()
{
    if (mHasAllocation)
        delete[] mpData;
}

/* virtual */float&
Matrix::operator()(unsigned int const i, unsigned int const j)
{
    return mpData[(j * mRowCount) + i];
}

unsigned int const
Matrix::getColumnCount() const
{
    return mColumnCount;
}

unsigned int const
Matrix::getRowCount() const
{
    return mRowCount;
}

std::vector<float> const
Matrix::getVectorizedData()
{
    std::vector<float> vector;
    vector.resize(mRowCount * mColumnCount);

#pragma omp parallel for schedule(dynamic)
    for (unsigned int i = 0; i < mColumnCount; ++i)
        for (unsigned int j = 0; j < mRowCount; ++j)
            vector[(i * mRowCount) + j] = operator()(i, j);

    return vector;
}
