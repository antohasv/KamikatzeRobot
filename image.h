#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QString>

using namespace std;

class Image
{
// Attributes
private:
    QImage img;
// Operations
public:
    void setImage (QString path);
    QImage getImage ();
};

#endif // IMAGE_H
