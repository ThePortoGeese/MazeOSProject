#ifndef INFORMATIONPAGE_H
#define INFORMATIONPAGE_H

#include <QWidget>

namespace Ui {
class informationPage;
}

class informationPage : public QWidget
{
    Q_OBJECT

public:
    explicit informationPage(QWidget *parent = nullptr);
    ~informationPage();

private:
    Ui::informationPage *ui;
};

#endif // INFORMATIONPAGE_H
