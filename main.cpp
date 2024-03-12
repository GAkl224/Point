#include <iostream>
#include <cmath>

using namespace std;

class Point {
    private:
        double x;
        double y;

    public:
        Point(double xCd, double yCd) : x(xCd), y(yCd) {

        }

        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }

        double distance(const Point& other) const {
            return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
        }

        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }

        bool operator!=(const Point& other) const {
            return !(*this == other);
        }

        Point operator-(const Point& other) const {
            return Point(fabs(x - other.x), fabs(y - other.y));
        }

        Point operator/(const Point& other) const {
            return Point((x + other.x) /2, (y + other.y) /2);
        }
};

//driver
int main() {
    //point class objects
    Point p1 = Point(1.45, 2.2);
    Point p2 = Point(30.23, 4.5);

    Point distance = p1 - p2;
    cout << "Distance between p1 and p2: " << distance.distance(Point(0, 0)) << endl;

    cout << "p1 == p2: " << boolalpha << (p1 == p2) << endl;
    cout << "p1 != p2: " << boolalpha <<(p1 != p2) << endl;

    Point midpoint = p1 / p2;
    cout << "midpoint p1 & p2: (" << midpoint.getX() << "," << midpoint.getY() << ")" << endl;

    return 0;
}