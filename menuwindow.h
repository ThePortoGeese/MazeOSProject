#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <qmazes.h>
#include <QMainWindow>
#include "algorithmselectionbox.h"
#include "qmediaplayer.h"
#include "QtMultimedia/QAudioOutput"
#include <qmessagebox.h>
#include <informationpage.h>
#include <QFileDialog>
#include <qmazesconversionmethods.h>
#include <iostream>
#include <QStandardItemModel>
namespace Ui {
class menuWindow;
}

class menuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = nullptr);
    ~menuWindow();
    void resizeEvent(QResizeEvent *event) override;

    bool areYouSureModal();
    void closeEvent(QCloseEvent *e) override;

    void resetMazeCreator();
    static void deleteMaze(QMazes* mazeToDelete);
private slots:
    void on_btnCredits_clicked();
    void endCreditsAbruptly(QMediaPlayer::PlaybackState state);
    void endCredits(QMediaPlayer::MediaStatus status);

    void on_btnResolve_clicked();

    void on_btnGenerate_clicked();

    void on_btnGenerateMaze_clicked();

    void on_btnSummary_clicked();
    void chartPathToCell(const int& tX,const int& tY);
    void updateStatusText();

    void on_btnNewUserMaze_clicked();

    void on_btnUserOpenMaze_clicked();

    void on_btnUserSave_clicked();
    void on_btnSolveMaze_clicked();

    void on_btnSelectFileForViewing_clicked();

    void on_btnSelectFileNext_clicked();

    void changeAlgorithmSelection(AlgorithmSelectionBox* box);

    void on_btnSelectAlgorithmNext_clicked();

    void setLeaderboard();
    void saveLeaderboard();

    void on_btnLeaderBoards_clicked();

    void on_btnRandomMaze_clicked();

    void updateLeaderboard(int score);

    void setMenuButtonsEnabled(bool enab);

    void on_btnAddWall_clicked();

    void on_btnRemoveWall_clicked();

    QString getHardnessRating(int score);
private:
    Ui::menuWindow *ui;
};

#endif // MENUWINDOW_H
