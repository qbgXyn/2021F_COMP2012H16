//This is the game map part. It contains basic setting like width and height with some helping functions like distanceBetweenPoint
//It also contains function used in many cpp like handle, item and unit
#ifndef MAP_H
#define MAP_H

// #include "../Handle/Handle.h"
// #include "../Handle/Unit/Unit.h"
// #include "../Handle/Decoration/Decoration.h"

#include "Terrain.h"

#include "../Handle/Unit/Survivor.h"
#include "../Handle/Unit/Ghost.h"

#include "../Handle/Decoration/Chest.h"
#include "../Handle/Decoration/Tree.h"
#include "../Handle/Decoration/Campfire.h"
#include "../Handle/Decoration/Boat.h"

#include "../Handle/Decoration/Item_Handle.h"

#include <string>
#include <QString>

class Map {

    private:

        double width; // x
        double height; // y

        int game_time {30*GAME_TICK}; //seconds*50


    public:
        Map(double width, double height, QString filePath); //constructor
        ~Map(); //destructor

        double getMaxWidth() const; //accessor 
        double getMaxHeight() const;

        bool isCoordinateInMap(double x, double y) const; //check if the coordinate exist

        Terrain::Type getTerrainOfGrid(double x, double y) const; //convert x and y coordinate into corresponding grid

        double getRandomDouble(double minValue, double maxValue) const; //create random double

        double distanceBetweenPoints(double x1, double y1, double x2, double y2) const; //function to calculate distance between two points

        vector<Handle*> getHandleGroup(double x, double y, double radius); //a frequently called function which check all handles that exist within the circle with input radius

        Terrain::Type get_at(double x, double y) const; //return the type of terrain of given location

        static Item* createItem(Item::ID); //item related functions
        bool createItem_Handle(Item::ID id, double x, double y);

        Handle* createHandle(Handle::Type type, double x, double y); //create and remove handle in handle list
        void removeHandle(Handle *h);

        void handleLoading();

        int getGameTime() const; //accessor and mutator of game time
        void setGameTime(int time);
       
        Survivor* player; //construct player

        vector<Ghost*> ghostList; //a list of ghosts so it can call the ghost ai function and move in every game loop

        vector<Handle*> List; // vector container of all handle

        Terrain::Type** grid; //map gird which store terrain type in every grid

        static const int grid_size = 64; // length of a square of a grid on the map, for displaying texture only(grass, sea, etc.)
};
#endif // MAP_H
