#pragma once

struct BrushVertex
{
    GLfloat x;
    GLfloat y;
    GLfloat r;
    GLfloat g;
    GLfloat b;
};

class Brush
{
public:
    Brush(long size);
    ~Brush();
    inline GLvoid* GetVertsHandle() {
        return _verts;
    }
    inline GLvoid* GetColorsHandle() {
        return &_verts[0].r;
    }
    inline long GetSize() {
        return _size;
    }
    void UpdateGeometry(long startIndex, int x, int y, GLfloat pixelSize);
    void UpdateColor(long startIndex, bool state);
private:
    BrushVertex* _verts;
    const long _size;
};

