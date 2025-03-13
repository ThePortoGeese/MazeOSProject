#include "leaderboardtablemodel.h"

LeaderboardTableModel::LeaderboardTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    QFile file(":/others/resources/leaderboardData.txt");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){

        QTextStream in(&file);

        for(int i=0;i<rowCount();i++){



            for(int j=0;j<columnCount();j++){
                QModelIndex idx = this->index(i,j);
                this->setData(idx,)
            }
        }
    }
}
