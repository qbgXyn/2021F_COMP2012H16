#include "Campfire.h"

const float Campfire::base_collision_radius = 16.0;
const double Campfire::base_max_speed = 0.0;


Campfire::Campfire(Map *map, double x, double y, int inInvulnerable) : Decoration(map, x, y, inInvulnerable) {
    type = Handle::Type::CAMPFIRE;
    pathable += Terrain::Type::GRASS;
    pathable += Terrain::Type::STONE;
    collisionRadius = base_collision_radius;
}
