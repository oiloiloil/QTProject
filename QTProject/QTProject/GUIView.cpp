#include "GUIView.h"

GUIView::GUIView()
{

}

GUIView::GUIView(int argc, char *argv[])
{
	QApplication app(argc, argv);

	painterWidgt = new PainterWidgt();

	GUIPresentationModel model;
	model.init(painterWidgt);

	QMainWindow *mainWindow = new QMainWindow;
	mainWindow->setWindowTitle("QMainWindow");
	mainWindow->resize(800, 800);

	mainWindow->setCentralWidget(painterWidgt);


	// 蹦現選單
	QMenu *fileMenu = new QMenu("&File");
	QAction *fileAction = new QAction("Open..", fileMenu);

	fileMenu->addAction(QIcon("create.jpg"), "Create a new mind map", &model, SLOT(getCreateMindMap()));
	fileMenu->addAction(QIcon("open.jpg"), "Open a mind map", &model, SLOT(openFile()));
	fileMenu->addAction(QIcon("save.jpg"), "Save a mind map");
	// 分隔線
	fileMenu->addSeparator();
	// 快捷鍵 Ctrl+X，動作連接至 QApplication 的 quit() 
	fileMenu->addAction("Close", &app, SLOT(quit()));

	QPushButton *button = new QPushButton(QIcon("edit.jpg"), "Edit");

	QMenu *editMenu = new QMenu("&Edit");
	
	QAction *editAction = editMenu->addAction(QIcon("edit.jpg"), "Edit");
	QAction *deleteAction = editMenu->addAction(QIcon("delete.jpg"), "Delete");
	QAction *InsertChildAction = editMenu->addAction(QIcon("InsertChild.jpg"), "Insert a child");
	QAction *InsertParentAction = editMenu->addAction(QIcon("InsertSibling.jpg"), "Insert a parent");
	QAction *InsertSiblingAction = editMenu->addAction(QIcon("InsertParent.jpg"), "Insert a sibling");
	editAction->setEnabled(false);//選項無法按

	QMenu *aboutMenu = new QMenu("&About");
	aboutMenu->addAction("About");

	mainWindow->menuBar()->addMenu(fileMenu);
	mainWindow->menuBar()->addMenu(editMenu);
	mainWindow->menuBar()->addMenu(aboutMenu);

	// 工具列
	QToolBar *toolBar = new QToolBar("QToolBar");
	toolBar->addAction(QIcon("create.jpg"), "Create a new mind map", &model, SLOT(getCreateMindMap()));
	toolBar->addAction(QIcon("open.jpg"), "Open a mind map", &model, SLOT(openFile()));
	toolBar->addAction(QIcon("save.jpg"), "Save a mind map");
	toolBar->addSeparator();
	//toolBar->addAction(QIcon("edit.jpg"), "Edit");
	//toolBar->addAction(QIcon("delete.jpg"), "Delete");
	QAction *editAction_bar = toolBar->addAction(QIcon("edit.jpg"), "Edit");
	QAction *deleteAction_bar = toolBar->addAction(QIcon("delete.jpg"), "Delete");
	toolBar->addSeparator();
	//toolBar->addAction(QIcon("InsertChild.jpg"), "Insert a child");
	//toolBar->addAction(QIcon("InsertSibling.jpg"), "Insert a parent");
	//toolBar->addAction(QIcon("InsertParent.jpg"), "Insert a sibling");
	QAction *InsertChildAction_bar = toolBar->addAction(QIcon("InsertChild.jpg"), "Insert a child");
	QAction *InsertParentAction_bar = toolBar->addAction(QIcon("InsertSibling.jpg"), "Insert a parent");
	QAction *InsertSiblingAction_bar = toolBar->addAction(QIcon("InsertParent.jpg"), "Insert a sibling");
	toolBar->addSeparator();
	editAction_bar->setDisabled(true);

	mainWindow->addToolBar(toolBar);

	// 狀態列 
	QStatusBar *statusBar = mainWindow->statusBar();
	statusBar->showMessage("Status here...");

	mainWindow->show();

	app.exec();
}
