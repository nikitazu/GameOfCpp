#pragma once

#include "Cell.h"
class Cell;

typedef std::vector< std::vector<Cell> > cells_matrix;

class Matrix
{
public:
    Matrix(int size);
    ~Matrix();
    Cell& GetCell(const int x, const int y);
    const int Translate(const int x);
    void CopyTo(Matrix& m);
private:
    const int _size;
    cells_matrix* _items;
};

