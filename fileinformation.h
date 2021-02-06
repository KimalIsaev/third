#ifndef FILEINFORMATION_H
#define FILEINFORMATION_H
#include <QString>

class FileInformation
{
public:
    QString name;
    quint64 absoluteSize;
    double relativeSize;

    FileInformation(QString givenName, quint64 givenAbsoluteSize, double givenRelativeSize):name(givenName), absoluteSize(givenAbsoluteSize), relativeSize(givenRelativeSize){};
};

#endif // FILEINFORMATION_H
