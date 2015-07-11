#pragma once

#include "Matrix.h"
class Matrix;

class Cell
{
public:
    Cell();
    ~Cell();
    void CopyTo(Cell& c);
    bool IsStable();
    bool UpdateState(Matrix& m, int x, int y, Cell& oldCell);
private:
    bool _state;
    int _count;
    void UpdateNearCounts(Matrix& m, int x1, int y1, int modifier);
    void UpdateCount(Matrix& m, int x, int y, int modifier);
};

