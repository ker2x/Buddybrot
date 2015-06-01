#include "buddybrot.h"

/**
 * @brief Buddybrot::Buddybrot
 * @param parent
 */
Buddybrot::Buddybrot(QWidget *parent)
    : QMainWindow(parent)
{

    createUI();
    statusBar->showMessage(tr("Welcome!"));

}

/**
 * @brief Buddybrot::~Buddybrot
 */
Buddybrot::~Buddybrot()
{

}

/**
 * @brief Buddybrot::createUI
 */
void Buddybrot::createUI() {

    /*
     * Here is how it works :
     * -> MainWindow
     *     -> Menubar
     *         -> File
     *             -> Save as...
     *             -> Exit
     *         -> View
     *             -> detach render view
     *         -> About
     *             -> about
     *     -> Statusbar
     *     -> centralWidget
     *         -> mainTab
     *             -> mainWidget
     *                 -> mainScreen
     *                     -> TODO (this is where we draw the fractal)
     *                 -> mainB
     *                     -> luminosityBox
     *                         -> luminositySlider
     *                     -> contrastBox
     *                         -> contrastSlider
     *                     -> gammaBox
     *                         -> gammaSlider
     *             -> paramWidget
     *                 -> TODO
     *             -> logWidget
     *                 -> Just a textbox
     */


    /* MENU STUFF HERE */
    menuBar = new QMenuBar( this ); // Create menubar
        /* file menu */
        fileMenu = new QMenu(tr("&File"), menuBar ); // Create File Menu
            //Save as....
            saveAct = new QAction(tr("&Save as..."), this);
            saveAct->setShortcut(tr("Ctrl+S"));
            saveAct->setStatusTip(tr("[NOT IMPLEMENTED] Save rendering to image file"));
            saveAct->setEnabled(false);
            //TODO: add slot connection here

            //Exit
            exitAct = new QAction(tr("E&xit"), this);   // Create File->Exit action
            exitAct->setShortcut(tr("Ctrl+Q"));
            exitAct->setStatusTip(tr("Goodbye ! *hugs*"));
            connect(exitAct, SIGNAL(triggered()), this, SLOT(close())); //FIXME: (call a custom method ?)

        fileMenu->addAction(saveAct);
        fileMenu->addAction(exitAct);

        /* edit menu */
        // Not yet ;)

        /* view menu */
        viewMenu = new QMenu(tr("View"), menuBar);
            //detach render view
            detachmainAct = new QAction(tr("detach render view"), this);
            detachmainAct->setEnabled(false);
            detachmainAct->setStatusTip(tr("[NOT IMPLEMENTED] detach the main render view to a standalone window (eg: for dual screen)"));
        viewMenu->addAction(detachmainAct);


        /* help menu */
        helpMenu =  new QMenu(tr("&Help"), menuBar); // Create Help Menu
            //About
            aboutAct = new QAction(tr("&About Buddybrot"), this);
            connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
            aboutAct->setStatusTip(tr("nobody ever click on this one :("));

            //aboutQtAct = new QAction(tr("About &Qt"), this);
            //connect(aboutQtAct, SIGNAL(triggered()),this , SLOT(aboutQt()));
            //aboutQtAct->setStatusTip(tr("About Qt"));

        helpMenu->addAction(aboutAct);
        //helpMenu->addAction(aboutQtAct);

    /* add menu */
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(viewMenu);
    menuBar->addMenu(helpMenu);
    setMenuBar(menuBar);




    /* STATUS BAR */
    statusBar = new QStatusBar();
    setStatusBar(statusBar);




    /* CENTRAL WIDGET */
    /* just a maximized placehoder */
    centralWidget = new QWidget(this);
    centralWidgetLayout = new QHBoxLayout();
    setCentralWidget(centralWidget);
    centralWidget->setLayout(centralWidgetLayout);

    /* TAB BAR & WIDGETS */
    /* the whole UI stuff is here */
    mainTab = new QTabWidget(centralWidget);
    centralWidgetLayout->addWidget(mainTab);

    /* main tab */
    mainWidget = new QWidget();
    mainWidgetLayout = new QVBoxLayout();
    mainWidget->setLayout(mainWidgetLayout);
//    mainWidget->setAutoFillBackground(true); mainWidget->setPalette(Qt::black);

    /* main screen */
    mainScreenWidget = new QWidget(mainWidget);
    mainScreenWidget->setAutoFillBackground(true); mainScreenWidget->setPalette(Qt::black);
    mainWidgetLayout->addWidget(mainScreenWidget);

    /* bottom widget of the main screen */
    mainBWidget = new QWidget(mainWidget);
    mainWidgetLayout->addWidget(mainBWidget);

    mainBWidgetLayout = new QHBoxLayout();
    mainBWidget->setLayout(mainBWidgetLayout);
    mainBWidget->setMaximumHeight(80);

    /* Stuff inside the bottom widget */
    luminosityBox = new QGroupBox(tr("Luminosity"), mainBWidget);
    luminosityBoxLayout = new QBoxLayout(QBoxLayout::LeftToRight, luminosityBox);
    luminosityBox->setLayout(luminosityBoxLayout);
    luminositySlider = new QSlider(Qt::Horizontal, luminosityBox);
    luminosityBox->setAlignment(Qt::AlignCenter);
    luminosityBoxLayout->addWidget(luminositySlider);
    mainBWidgetLayout->addWidget(luminosityBox);

    contrastBox = new QGroupBox(tr("Contrast"), mainBWidget);
    contrastBoxLayout = new QBoxLayout(QBoxLayout::LeftToRight,contrastBox);
    contrastBox->setLayout(contrastBoxLayout);
    contrastSlider = new QSlider(Qt::Horizontal, contrastBox);
    contrastBox->setAlignment(Qt::AlignCenter);
    contrastBoxLayout->addWidget(contrastSlider);
    mainBWidgetLayout->addWidget(contrastBox);

    gammaBox = new QGroupBox(tr("Gamma"), mainBWidget);
    gammaBoxLayout = new QBoxLayout(QBoxLayout::LeftToRight,gammaBox);
    gammaBox->setLayout(gammaBoxLayout);
    gammaSlider = new QSlider(Qt::Horizontal, gammaBox);
    gammaBox->setAlignment(Qt::AlignCenter);
    gammaBoxLayout->addWidget(gammaSlider);
    mainBWidgetLayout->addWidget(gammaBox);

    startButton = new QPushButton(tr("Start/Pause"), mainBWidget);
    mainBWidgetLayout->addWidget(startButton);


    /* param tab */
    paramWidget = new QWidget();
    paramWidgetLayout = new QGridLayout();
    paramWidget->setLayout(paramWidgetLayout);


    /* log tab */
    logWidget = new QTextEdit();

    mainTab->addTab(mainWidget,tr("Main Screen"));
    mainTab->addTab(paramWidget, tr("Parameters"));
    mainTab->addTab(logWidget, tr("Logs / Debug"));

    this->showMaximized();

}


/**
 * @brief Buddybrot::about
 * A simple About messagebox
 */
void Buddybrot::about() {
    QMessageBox::about( this, tr("About Buddybrot"), tr("TODO ;)"));
}
