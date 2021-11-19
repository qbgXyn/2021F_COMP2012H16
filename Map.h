#include "Handle/Handle.h"

class Map {

    private:
        static const int grid_radius = 8; // length of a square of a grid on the map, for displaying texture only(grass, sea, etc.)
        double width; // x
        double height; // y
        vector<Handle&> List; // all handle
    public:
        Map(double width, double height);
        inline double getMaxWidth() const {return width / 2;}
        inline double getMaxHeight() const {return height / 2;}
        inline bool isCoordinateInMap(double x, double y) {return (x > 0) && (x <= width) && (y > 0) && (y <= height);}
        bool isCoordinatePathable(double x, double y);

        inline double distanceBetweenPoints(double x1, double y1, double x2, double y2) {return std::hypot(x2-x1, y2-y1);}


};
