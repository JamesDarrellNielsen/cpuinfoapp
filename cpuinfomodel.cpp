#include "cpuinfomodel.h"

CpuInfoModel::CpuInfoModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // load the cpuinfo file contents into QStringList member m_cpudata
    QFile file("/proc/cpuinfo");
    QString filestr;
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        filestr = in.readAll();
        file.close();
        m_cpudata = filestr.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    }
}

// virtual overrides

int CpuInfoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_cpudata.count();
}


QVariant CpuInfoModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if(row < 0 || row >= m_cpudata.count()) {
        return QVariant();
    }

    // A model can return data for different roles.
    // The default role is the display role.
    // it can be accesses in QML with "model.display"
    switch(role) {
        case Qt::DisplayRole:
            // Return  a line from the cpuinfo file for the row
            // Qt automatically converts it to the QVariant type
            return m_cpudata.value(row);
    }

    // The view asked for other data, just return an empty QVariant
    return QVariant();
}
