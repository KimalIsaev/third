#include "filedirectorystrategy.h"

QFileInfoList FileDirectoryStrategy::dirFileInfoToEntries(
        const QFileInfo &dirInfo)
{
    QDir dir(dirInfo.absoluteFilePath());
    QFileInfoList dirEntries =
            dir.entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);
    return dirEntries;
}

unsigned long long FileDirectoryStrategy::directorySize(
        const QFileInfo &dirInfo)
{
    unsigned long long dirSize = 0;
    QFileInfoList dirEntries = dirFileInfoToEntries(dirInfo);
    for(const auto &entry : dirEntries) dirSize += sizeFromFileInfo(entry);
    return dirSize;
}

unsigned long long FileDirectoryStrategy::sizeFromFileInfo(
        const QFileInfo &info)
{
    bool exist = info.exists();
    if (!exist) return 0;

    bool isLink = info.isSymLink();
    if (isLink) return symLinkSize(info);

    bool isDir = info.isDir();
    if (isDir) return directorySize(info);

    unsigned long long pathSize = info.size();
    return pathSize;
}

QList<QPair<QString, double> > FileDirectoryStrategy::calculate(
        const QString &path)
{
    QList<QPair<QString, unsigned long long>> temp;
    QFileInfoList dirEntries = dirFileInfoToEntries(QFileInfo(path));
    unsigned long long sizeOfEntry, sizeOfAll=0;
    QString entryName;
    for(const auto &entry : dirEntries) {
        entryName = entry.fileName();
        sizeOfEntry = sizeFromFileInfo(entry);
        sizeOfAll += sizeOfEntry;
        temp.append(qMakePair(entryName, sizeOfEntry));
    }
    QList<QPair<QString, double>> result;
    if (sizeOfAll) {
        for(const auto &p : temp)
            result.append(qMakePair(p.first,
                                    double(p.second)/double(sizeOfAll)));
    } else {
        for(const auto &p : temp)
            result.append(qMakePair(p.first, divisionByZero));
    }
    return result;
}
