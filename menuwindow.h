#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <mazes.h>
#include <QMainWindow>
#include "QtMultimedia/QMediaPlayer"
#include "QtMultimedia/QAudioOutput"
#include <qmessagebox.h>
#include <informationpage.h>
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
private slots:
    void on_btnCredits_clicked();
    void endCreditsAbruptly(QMediaPlayer::PlaybackState state);
    void endCredits(QMediaPlayer::MediaStatus status);
    void updateSlideLbls();
    void on_btnResolve_clicked();

    void on_btnGenerate_clicked();

    void on_btnGenerateMaze_clicked();

    void on_btnSolveMaze_clicked();
    void on_btnSummary_clicked();

private:
    Ui::menuWindow *ui;
};

#endif // MENUWINDOW_H
