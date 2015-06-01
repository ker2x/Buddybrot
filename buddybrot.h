#ifndef BUDDYBROT_H
#define BUDDYBROT_H

#include <QMainWindow>
#include <QGridLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QStatusBar>
#include <QTabWidget>
#include <QGroupBox>
#include <QTextEdit>
#include <QMenuBar>
#include <QTabBar>
#include <QWidget>
#include <QSlider>
#include <QMenu>

class Buddybrot : public QMainWindow
{
    Q_OBJECT

public:
    Buddybrot(QWidget *parent = 0);
    ~Buddybrot();

    void createUI();

    //Menu stuff
    QMenuBar *menuBar;
    QMenu *fileMenu, *viewMenu, *helpMenu;
    QAction *exitAct, *detachmainAct, *aboutAct, *saveAct;

    QStatusBar *statusBar;

    //Widget and general UI
    QWidget *centralWidget, *mainWidget, *paramWidget, *mainBWidget, *mainScreenWidget;
    QLayout *centralWidgetLayout, *mainWidgetLayout, *paramWidgetLayout, *mainBWidgetLayout;

    QTextEdit *logWidget;

    /* bottom widget */
    QGroupBox *luminosityBox, *contrastBox, *gammaBox;
    QBoxLayout *luminosityBoxLayout, *contrastBoxLayout, *gammaBoxLayout;
    QSlider *luminositySlider, *contrastSlider, *gammaSlider;
    QPushButton *startButton;

    //Tab bar & widget
    //QTabBar *tabBar;
    QTabWidget *mainTab; //, *paramTab, *logTab;

    bool mainWidgetIsDetached = false;

public slots:
    void about();

};

#endif // BUDDYBROT_H
