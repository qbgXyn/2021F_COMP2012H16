#include "Decoration.h"

class Boat : public Decoration {
    private:
        static const int base_max_health = 10;
        static const float base_collison_radius;
        static const double base_max_speed;
    public:
        explicit Boat(Map *map, int x, int y, int inInvulnerable = 1);

        Decoration::Type get_type() const {return Decoration::Type::BOAT;}

};