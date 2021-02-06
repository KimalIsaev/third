#include "typestrategy.h"

QList<FileInformation> TypeStrategy::Explore(const QString &path)
{
    QFileInfo pathInfo(path);
    QList<FileInformation> result;

    bool pathExist = pathInfo.exists();
    if (!pathExist) return result;
}
