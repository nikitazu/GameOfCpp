#include "stdafx.h"
#include "Cell.h"

// Init
// ====

Cell::Cell() {
    _state = (rand() % 10) == 0;
    _count = 0;
}


Cell::~Cell() {
}


// Public
// ======

void Cell::CopyTo(Cell& c) {
    c._state = _state;
    c._count = _count;
}


bool Cell::IsStable() {
    return (_state && (_count == 2 || _count == 3))
        || ((!_state) && (_count != 3));
}


bool Cell::UpdateState(Matrix& m, int x, int y) {
    Cell& c = m.GetCell(x, y);
    c._state = !_state;
    UpdateNearCounts(m, x, y, c._state ? 1 : -1);
    return c._state;
}

void Cell::InitCounters(Matrix& m, int x, int y) {
    if (_state) {
        UpdateNearCounts(m, x, y, 1);
    }
}


// Private
// =======

void Cell::UpdateNearCounts(Matrix& m, int x1, int y1, int modifier) {
    int x0 = m.Translate(x1 - 1);
    int x2 = m.Translate(x1 + 1);
    int y0 = m.Translate(y1 - 1);
    int y2 = m.Translate(y1 + 1);

    UpdateCount(m, x0, y0, modifier);
    UpdateCount(m, x0, y1, modifier);
    UpdateCount(m, x0, y2, modifier);
    
    UpdateCount(m, x2, y0, modifier);
    UpdateCount(m, x2, y1, modifier);
    UpdateCount(m, x2, y2, modifier);

    UpdateCount(m, x1, y0, modifier);
    UpdateCount(m, x1, y2, modifier);
}


void Cell::UpdateCount(Matrix& m, int x, int y, int modifier) {
    Cell& c = m.GetCell(x, y);
    c._count += modifier;
}

