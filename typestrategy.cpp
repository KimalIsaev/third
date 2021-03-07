#include "typestrategy.h"

void TypeStrategy::addSizeToMap(QMap<QString, unsigned long long> &map,
                                const QString &fileType,
                                unsigned long long size)
{
    if (map.contains(fileType)){
        map[fileType] += size;
    } else {
        map[fileType] = size;
    }
}

QList<QPair<QString, double>> TypeStrategy::calculate(const QString &path)
{
    QList<QPair<QString, double>> result;
    QMap<QString, unsigned long long> map;
    unsigned long long sizeOfAll = typeMap(QFileInfo(path), map);
    QMapIterator<QString, unsigned long long> i(map);
    if (sizeOfAll){
        while (i.hasNext()) {
            i.next();
            result.append(qMakePair(i.key(),
                                    double(i.value()) / double(sizeOfAll)));
        }
    } else {
        while (i.hasNext()) {
            i.next();
            result.append(qMakePair(i.key(), divisionByZero));
        }
    }
    return result;
}


unsigned long long TypeStrategy::typeMap(
        const QFileInfo &info, QMap<QString, unsigned long long> &map)
{
    bool exist = info.exists();
    if (!exist) return 0;

    bool isLink = info.isSymLink();
    if (isLink) {
        unsigned long long pathSize = symLinkSize(info);
        addSizeToMap(map, "SymLink", pathSize);
        return pathSize;
    }

    bool isDir = info.isDir();
    if (isDir) {
        unsigned long long dirSize = 0;
        QDir dir = info.absoluteFilePath();
        QFileInfoList dirEntries =
                dir.entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);
        for (const auto &entry : dirEntries)
            dirSize += typeMap(entry, map);
        return dirSize;
    }

    unsigned long long pathSize = info.size();
    addSizeToMap(map, info.suffix(), pathSize);
    return pathSize;
}
