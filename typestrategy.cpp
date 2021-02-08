#include "typestrategy.h"

void TypeStrategy::addSizeToMap(QMap<QString, unsigned long long> &map,
                                const QString &fileType, unsigned long long size)
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
    unsigned long long sizeOfAll = typeMap(path, map);
    QMapIterator<QString, unsigned long long> i(map);
    while (i.hasNext()) {
        i.next();
        result.append(qMakePair(i.key(),
                                double(i.value()) / double(sizeOfAll)));
    }
    return result;
}

unsigned long long TypeStrategy::typeMap(const QString &path, QMap<QString,
                                         unsigned long long> &map)
{
    QFileInfo pathInfo(path);

    bool pathExist = pathInfo.exists();
    if (!pathExist) return 0;

    bool isPathLink = pathInfo.isSymLink();
    if (isPathLink) {
        unsigned long long pathSize = symLinkSize(pathInfo);
        addSizeToMap(map, "SymLink", pathSize);
        return pathSize;
    }

    bool isPathDir = pathInfo.isDir();
    if (isPathDir) {
        unsigned long long dirSize = 0;
        QDirIterator dir(pathInfo.absoluteFilePath());
        while (dir.hasNext()) dirSize += typeMap(dir.next(), map);
        return dirSize;
    }

    return pathInfo.size();
}
