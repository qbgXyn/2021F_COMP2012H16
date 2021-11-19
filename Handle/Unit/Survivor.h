#ifndef SURVIVOR_H
#define SURVIVOR_H

#include "Unit.h"
#include "../Inventory/Item_Inventory.h"

class Survivor : public Unit {
    public:
        explicit Survivor(Map *map, double x, double y);
        static const int base_max_health = 10;
        static const float base_collison_radius;
        static const double base_max_speed;
        
        static const int base_damage = 1;
        static const float base_attackInterval;
        static const float base_attack_radius;
        static const int base_armor = 0;
        static const int base_visible_radius = 100;

        static const int maxSlotOfInventory = 9;

        void attack();
        vector<Item_inventory> Inventory;

        inline bool isInventoryFull() const {return (Inventory.size() == maxSlotOfInventory);}
};
#endif // SURVIVOR_H
