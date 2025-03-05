#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <qmazes.h>
#include <QMainWindow>
#include "qmediaplayer.h"
#include "QtMultimedia/QAudioOutput"
#include <qmessagebox.h>
#include <informationpage.h>
#include <QFileDialog>
#include <qmazesconversionmethods.h>
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

private slots:
    void on_btnCredits_clicked();
    void endCreditsAbruptly(QMediaPlayer::PlaybackState state);
    void endCredits(QMediaPlayer::MediaStatus status);
    void updateSlideLbls();
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

private:
    Ui::menuWindow *ui;
};

#endif // MENUWINDOW_H
