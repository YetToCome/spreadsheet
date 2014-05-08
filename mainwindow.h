#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
protected:
    void closeEvent(QCloseEvent* event);
private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void about();

    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRencentFileActions();
    QString strippedName(const QString &fullFileName);

    Spreadsheet *spreadsheet;
    FindDialog *findDialog;
    QLabel *locationLabel;
    QLabel *formulabel;
    QStringList recentFiles;
    QString curFile;

    enum { MaxRecentFiles = 5};
    QAction *recentFileActions[MaxRecentFiles];
    QAction *separatorAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *selectSubMenu;
    QMenu *toolsMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;
    //
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAction;
    QAction *openAction;
    QAction *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *selectAllAction;
    QAction *showGridAction;
    QAction *recalculateAction;
    QAction *autoRecalcAction;
    QAction *sortAction;
    QAction *selectRowAction;
    QAction *selectColumnAction;
    QAction *findAction;
    QAction *goToCellAction;
    QAction *aboutAction;
    //
    QAction *aboutQtAction;
};

#endif // MAINWINDOW_H
