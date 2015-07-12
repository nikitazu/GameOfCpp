#include "stdafx.h"
#include "Brush.h"


Brush::Brush(long cellsCount) 
    : _size(cellsCount * cellsCount * 4) { // 4 vertices per cell (square)
    _verts = new BrushVertex[_size];
}

Brush::~Brush() {
    delete[] _verts;
}

void Brush::UpdateGeometry(long startIndex, int x, int y, GLfloat pixelSize) {
    GLfloat x0 = x * pixelSize;
    GLfloat y0 = y * pixelSize;
    GLfloat x1 = x0 + pixelSize;
    GLfloat y1 = y0 + pixelSize;

    long i = startIndex * 4; // 4 vertices per cell (square)

    _verts[i].x = x0;
    _verts[i].y = y0;
    i++;
    _verts[i].x = x1;
    _verts[i].y = y0;
    i++;
    _verts[i].x = x1;
    _verts[i].y = y1;
    i++;
    _verts[i].x = x0;
    _verts[i].y = y1;
}

void Brush::UpdateColor(long startIndex, bool state) {
    long i = startIndex * 4; // 4 vertices per cell (square)
    GLfloat c = 0;

    if (state) {
        c = (_size - i) / (GLfloat)_size;
        _verts[i].r = c * 1.5f;
        _verts[i].g = c;
        _verts[i].b = c * 0.5f;
        i++;
        _verts[i].r = c * 1.5f;
        _verts[i].g = c;
        _verts[i].b = c * 0.5f;
        i++;
        _verts[i].r = c * 1.5f;
        _verts[i].g = c;
        _verts[i].b = c * 0.5f;
        i++;
        c = (_size - i) / (GLfloat)_size;
        _verts[i].r = c;
        _verts[i].g = c;
        _verts[i].b = c * 1.3f;
    } else {
        c = i / (GLfloat)_size * 0.5f;
        _verts[i].r = c;
        _verts[i].g = c;
        _verts[i].b = c;
        i++;
        _verts[i].r = c;
        _verts[i].g = c;
        _verts[i].b = c;
        i++;
        _verts[i].r = c;
        _verts[i].g = c;
        _verts[i].b = c;
        i++;
        c = i / (GLfloat)_size * 0.3f;
        _verts[i].r = c;
        _verts[i].g = c;
        _verts[i].b = c;
    }
}

