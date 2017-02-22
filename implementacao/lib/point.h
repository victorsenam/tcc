#ifndef TCC_LIB_point
#define TCC_LIB_point

class point {
public:
    int x, y;

    point ();
    point (int a, int b);

    inline bool operator < (const point & ot) const
    { return (x < ot.x) || (x == ot.x && y < ot.y); }
    inline bool operator == (const point & ot) const
    { return x == ot.x && y == ot.y; }
    inline point operator - (const point & ot) const
    { return point(x - ot.x, y - ot.y); }
    inline point operator + (const point & ot) const
    { return point(x + ot.x, y + ot.y); }
    inline point operator * (int a) const
    { return point(x * a, y * a); }

    // cross product (counterclockwise oriented)
    inline long long operator ^ (const point & ot) const
    { return (long long)(x) * ot.y - (long long)(y) * ot.x; }
    // inner product
    inline long long operator * (const point & ot) const
    { return (long long)(x) * ot.x + (long long)(y) * ot.y; }
};

#endif
