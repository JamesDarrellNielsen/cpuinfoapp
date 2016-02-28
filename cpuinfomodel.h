#ifndef CPUINFOMODEL_H
#define CPUINFOMODEL_H

#include <QAbstractListModel>
#include <QQuickItem>
#include <QFile>
#include <QTextStream>
#include <QColor>

class CpuInfoModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CpuInfoModel(QObject *parent = 0);

public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

private:
    QStringList m_cpudata;
};

#endif // CPUINFOMODEL_H
