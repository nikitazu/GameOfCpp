#include "stdafx.h"
#include "Matrix.h"

// Init
// ====

Matrix::Matrix(int size) : _size(size) {
    _items = new cells_matrix(_size);
    for (int x = 0; x < _size; x++) {
        std::vector<Cell>* v = new std::vector<Cell>(_size);
        for (int y = 0; y < _size; y++) {
            Cell* c = new Cell();
            (*v)[y] = *c;
        }
        (*_items)[x] = *v;
    }
}


Matrix::~Matrix() {
    delete _items;
}


// Public
// ======

Cell& Matrix::GetCell(const int x, const int y) {
    return (*_items)[x][y];
}


const int Matrix::Translate(const int x) {
    return x == _size ? 0 : x == -1 ? _size - 1 : x;
}


void Matrix::CopyTo(Matrix& m) {
    for (int x = 0; x < _size; x++) {
        for (int y = 0; y < _size; y++) {
            GetCell(x, y).CopyTo(m.GetCell(x, y));
        }
    }
}

