#pragma once

#include "Matrix.h"
class Matrix;

class Cell
{
public:
    Cell();
    ~Cell();
    bool GetState() {
        return _state;
    }
    void CopyTo(Cell& c);
    bool IsStable();
    bool UpdateState(Matrix& m, int x, int y);
    void InitCounters(Matrix& m, int x, int y);
private:
    bool _state;
    int _count;
    void UpdateNearCounts(Matrix& m, int x1, int y1, int modifier);
    void UpdateCount(Matrix& m, int x, int y, int modifier);
};

