#ifndef SURVIVOR_H
#define SURVIVOR_H
/*
//This is the header file of survivor, which is the character which the player controlling. In there, it is designed as the derived
//class of unit such that it can use some common functions such as attack and find handles within the radius. In survivor class,
//it has pick up, switch, use and drop item function which only the player can use but ghost cannot. It also contain the components
//for the inventory array which acts as a "bag" for the player to store picked item and it will be display as a item bar in the
//buttom of the mainwindow like Minecraft. This part will be linked to the 1-9 key press in graphic to display and switch between
//the holding object.
*/
#include "Unit.h"
#include "../Inventory/Item_Inventory.h"

class Survivor : public Unit { //survivor is the derived class of unit
    private:
        vector<Effect*> EffectList; //vector contain of effect
        bool invulerableByCampfire;
    public:
        explicit Survivor(Map *map, double x, double y); //player constructor
        static const int base_max_health; //base maximum health of player
        static const int base_collision_radius; //base collision radius of player
        static const int base_pickup_radius; // base searching area for item of player
        static const double base_max_speed; //base maximum movement speed 
        
        static const int base_damage = 0; //base melee damage
        static const int base_attackInterval; //base melee CD
        static const float base_attack_radius; //base melee radius
        static const double base_attack_sector_angle; //base melee sector angle
        static const int base_armor = 0; //basic armor
        static const int base_visible_size = 3; //basic visibility of player

        static const int maxSlotOfInventory = 9; //the maximum amount of item player can store, like the bag capacbility
        int selectedItemIndex = 0; //by default the player will have the item on the first left box in the buttom item bar 

        double direction;

        virtual void update() override;

        virtual double getDirection() const override;
        void setMoveDirection(bool move, double direction);

        void gainAttributeFromEffect(Effect *e); //effect related functions
        void addEffect(Effect *e);
        void removeAttributeFromEffect(Effect *e);
        void removeEffect(Effect *e);

        Item_inventory* Inventory[maxSlotOfInventory] = {}; //a array of item which acts like a bag for the player to store the items

        bool isInventoryFull() const; //check if the inventory is full
        void useItem(Item_inventory *i); //use the currently selected item
        void pickupItem(); //pick up item on ground
        void dropItem(); //drop the item on ground 

        void switchTorchState();  //switch between torch and set a new durability
        void itemSwitchState(Item::ID oldID, Item::ID newID = Item::ID::EMPTY); //item is run out of time
        int getTorchTime() const; //return the torch time

        void deleteItemInventory(int index);

        int getItemInventoryIndex(Item::ID id) const; //check if player has the item, if yes, return the index, if no, return -1

        void Switch_selectedItem_Index(int index); //change the index item so that it refer to different item in the item array, so that when press 1-9 key, change the color of the item bar background to show the selection

        bool turnOnBoat() const; //start the boat and end the game
};
#endif // SURVIVOR_H
