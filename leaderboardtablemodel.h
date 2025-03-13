#ifndef LEADERBOARDTABLEMODEL_H
#define LEADERBOARDTABLEMODEL_H

#include <QAbstractTableModel>
#include <QFile>
class LeaderboardTableModel : public QAbstractTableModel
{
public:
    explicit LeaderboardTableModel(QObject *parent = nullptr);

    int columnCount(const QModelIndex &parent = QModelIndex()) const override{
        Q_UNUSED(parent);
        return 4;
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override{
        Q_UNUSED(parent);
        return 10;
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override{
        index.value;
    }
};

#endif // LEADERBOARDTABLEMODEL_H
