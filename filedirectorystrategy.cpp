#include "filedirectorystrategy.h"

unsigned long long FileDirectoryStrategy::directorySize(
        const QFileInfo &dirInfo)
{
    unsigned long long dirSize = 0;
    QDirIterator dir(dirInfo.absoluteFilePath());
    while (dir.hasNext()) dirSize += sizeFromPath(dir.next());
    return dirSize;
}

unsigned long long FileDirectoryStrategy::sizeFromPath(
        const QString &path)
{
    QFileInfo pathInfo(path);

    bool pathExist = pathInfo.exists();
    if (!pathExist) return 0;

    bool isPathLink = pathInfo.isSymLink();
    if (isPathLink) return symLinkSize(pathInfo);

    bool isPathDir = pathInfo.isDir();
    if (isPathDir) return directorySize(pathInfo);

    unsigned long long pathSize = pathInfo.size();
    return pathSize;
}

QList<QPair<QString, double> > FileDirectoryStrategy::calculate(
        const QString &path)
{
    QList<QPair<QString, unsigned long long>> temp;
    QDirIterator dir(path);
    unsigned long long sizeOfAll=0, sizeOfElement;
    QString elementPath, elementName;
    while (dir.hasNext()) {
        elementPath = dir.next();
        elementName = QFileInfo(elementPath).fileName();
        sizeOfElement = sizeFromPath(elementPath);
        sizeOfAll += sizeOfElement;
        temp.append(qMakePair(elementName, sizeOfElement));
    }
    QList<QPair<QString, double>> result;
    if (sizeOfAll) {
        std::transform(temp.begin(), temp.end(), result.begin(),
                       [sizeOfAll]
                       (QPair<QString, unsigned long long> p)
                       {return qMakePair(p.first, p.second/sizeOfAll);});
    } else {
        double tempDouble = divisionByZero;
        std::transform(temp.begin(), temp.end(), result.begin(),
                       [tempDouble]
                       (QPair<QString, unsigned long long> p)
                       {return qMakePair(p.first, tempDouble);});
    }
    return result;
}
