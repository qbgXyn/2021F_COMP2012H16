#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Map/Map.h"

#include <QString>
#include <QTimer>
#include <QMainWindow>

const QString BACKGROUND = "background-color: rgba(255, 255, 255, 128);";

const QString SELECTED = "background-color: rgba(255, 255, 255, 128);";
const QString NOT_SELECTED = "background-color: rgba(85, 85, 85, 128);";

const QString WORD = "color: rgba(255, 255, 255, 255)";
const QString SHADOW = "color: rgba(0, 128, 255, 255)";

#include <iostream>

MainWindow::MainWindow(Map *const map, QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        map(map),
        TORCH_LIT_COUNT(0)
{
    ui->setupUi(this);

    // Initialize Information, Inventory
    init_Information();
    init_Inventory();
    init_Current_Item();

    // Load Icons
    load_icons();

    // Run main loop
    loop_timer = new QTimer{this};
    connect(loop_timer, &QTimer::timeout, this, &MainWindow::main_loop);
    // 50 updates per second
    loop_timer->start(GAME_INTERVAL);
}

void MainWindow::init_Information() {
    ui->label_instruction->setStyleSheet(BACKGROUND);
    ui->label_health->setStyleSheet(BACKGROUND);
    ui->label_time->setStyleSheet(BACKGROUND);
    ui->label_torch->setStyleSheet(BACKGROUND);
}

void MainWindow::init_Inventory() {
    ui->label_inventory_1->setStyleSheet(NOT_SELECTED);
    ui->label_inventory_2->setStyleSheet(NOT_SELECTED);
    ui->label_inventory_3->setStyleSheet(NOT_SELECTED);
    ui->label_inventory_4->setStyleSheet(NOT_SELECTED);
    ui->label_inventory_5->setStyleSheet(NOT_SELECTED);
    ui->label_inventory_6->setStyleSheet(NOT_SELECTED);
    ui->label_inventory_7->setStyleSheet(NOT_SELECTED);
    ui->label_inventory_8->setStyleSheet(NOT_SELECTED);
    ui->label_inventory_9->setStyleSheet(NOT_SELECTED);
}

void MainWindow::init_Current_Item() {
    ui->label_current_item->setStyleSheet(WORD);
    ui->label_current_item_shadow->setStyleSheet(SHADOW);
}

MainWindow::~MainWindow() {
    dealloc_icons();
    delete ui;
    loop_timer->stop();
    delete loop_timer;
    delete map;
}

// This is called 50 times per second
void MainWindow::main_loop() {
    game_time = map->getGameTime();
    torch_time = map->player->getTorchTime();
//    int torch_time = 10;
    if (game_time > 0)
        map->setGameTime(game_time - 1);
    if (torch_time > 0 && map->player->hasItem(Item::ID::TORCH_LIT)) {
        if (torch_time - 1 >= 0) {
            map->player->setTorchTime(torch_time - 1);
        }else {
            map->player->switchTorchState();
        }

    }
    ui->label_health->setText(": 100");
    ui->label_time->setText(": " + QString::number(game_time/GAME_TICK) + "s");
    ui->label_torch->setText(": " + QString::number(torch_time/GAME_TICK) + "s");
//    ui->label_torch->setText(": " + QString::number(50/GAME_TICK) + "s");

    // Set Selected Item in Inventory
    init_Inventory();
    switch (map->player->selectedItemIndex) {
        case 0:
            ui->label_inventory_1->setStyleSheet(SELECTED);
            break;
        case 1:
            ui->label_inventory_2->setStyleSheet(SELECTED);
            break;
        case 2:
            ui->label_inventory_3->setStyleSheet(SELECTED);
            break;
        case 3:
            ui->label_inventory_4->setStyleSheet(SELECTED);
            break;
        case 4:
            ui->label_inventory_5->setStyleSheet(SELECTED);
            break;
        case 5:
            ui->label_inventory_6->setStyleSheet(SELECTED);
            break;
        case 6:
            ui->label_inventory_7->setStyleSheet(SELECTED);
            break;
        case 7:
            ui->label_inventory_8->setStyleSheet(SELECTED);
            break;
        case 8:
            ui->label_inventory_9->setStyleSheet(SELECTED);
            break;
    }

    // Draw Items in Inventory
    QLabel* inventory [9] = {
        ui->label_inventory_1, ui->label_inventory_2, ui->label_inventory_3,
        ui->label_inventory_4, ui->label_inventory_5, ui->label_inventory_6,
        ui->label_inventory_7, ui->label_inventory_8, ui->label_inventory_9
    };
    for (int i = 0; i < 9; i++) {
        if (map->player->Inventory[i]!=nullptr) {
            if (map->player->Inventory[i]->item->getName()=="torch (lit)") {
                inventory[i]->setPixmap(TORCH_LIT[TORCH_LIT_COUNT]);
                TORCH_LIT_COUNT = (TORCH_LIT_COUNT+1)%12;
            }
            else {
                QPixmap Item(QString::fromStdString(map->player->Inventory[i]->item->getTexture()));
                inventory[i]->setPixmap(Item);
            }
        }
    }

    // Set Selected Item Name to Current Item
    if (map->player->Inventory[map->player->selectedItemIndex]!=nullptr) {
        ui->label_current_item->setText(QString::fromStdString(map->player->Inventory[map->player->selectedItemIndex]->item->getName()));
        ui->label_current_item_shadow->setText(QString::fromStdString(map->player->Inventory[map->player->selectedItemIndex]->item->getName()));
    }
    else {
        ui->label_current_item->setText("");
        ui->label_current_item_shadow->setText("");
    }

    ui->widget->loop();
}

void MainWindow::load_icons() {
    TORCH_LIT = new QPixmap [12] {{":/resources/images/item/torch_lit01.png"},
                                  {":/resources/images/item/torch_lit01.png"},
                                  {":/resources/images/item/torch_lit02.png"},
                                  {":/resources/images/item/torch_lit02.png"},
                                  {":/resources/images/item/torch_lit03.png"},
                                  {":/resources/images/item/torch_lit03.png"},
                                  {":/resources/images/item/torch_lit04.png"},
                                  {":/resources/images/item/torch_lit04.png"},
                                  {":/resources/images/item/torch_lit05.png"},
                                  {":/resources/images/item/torch_lit05.png"},
                                  {":/resources/images/item/torch_lit06.png"},
                                  {":/resources/images/item/torch_lit06.png"}};
}

void MainWindow::dealloc_icons() {
    delete [] TORCH_LIT;
}
