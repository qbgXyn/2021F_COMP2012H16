#include "Boat.h"

const float Boat::base_collison_radius = 32.0;
const double Boat::base_max_speed = 0.0;


Boat::Boat(Map *map, Category category, Type type, double x, double y, int inInvulnerable) : Decoration(map, category, type, x, y, inInvulnerable) {
    pathable += Map::Terrain::SHOAL;
    pathable += Map::Terrain::OCEAN;
}