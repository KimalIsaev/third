#ifndef FILEINFORMATION_H
#define FILEINFORMATION_H
#include <QString>

class FileInformation
{
public:
    QString name;
    double relativeSize;

    FileInformation(QString givenName, double givenRelativeSize):name(givenName), relativeSize(givenRelativeSize){};
};

#endif // FILEINFORMATION_H
