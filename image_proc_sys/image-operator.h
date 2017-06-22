#ifndef IMAGEOPERATOR_H
#define IMAGEOPERATOR_H

#include <QObject>
#include "opencv2/opencv.hpp"
class ImageOperator : public QObject
{
    Q_OBJECT
public:
    explicit ImageOperator(QObject *parent = 0);

signals:

public slots:
};

#endif // IMAGEOPERATOR_H
