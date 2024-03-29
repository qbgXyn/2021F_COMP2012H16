#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
//Mainwindow ui for gui. It will start game loop and call loop in graphics
*/
#include "Map/Map.h"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "menuwindow.h"

namespace Ui { class MainWindow; }

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(Map *const map, MenuWindow* menuwindow, QWidget *parent = nullptr); //constructor
    ~MainWindow(); //destructor

    MainWindow(const MainWindow&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;

private:
    // Initialization functions, called in constructor
    void init_Information();
    void init_Inventory();
    void init_Current_Item();

    // Load and unload icons
    void load_icons();
    void dealloc_icons();

    void main_loop();

    Ui::MainWindow* ui;

    MenuWindow* menuwindow;

    Map *const map;

    QTimer* loop_timer;

    Survivor *survivor;

    friend class GameWidget;
    QMediaPlayer *bgm;
    QMediaPlaylist *bgmList;


    QPixmap* TORCH_LIT;
    int TORCH_LIT_COUNT;

};
#endif // MAINWINDOW_H
