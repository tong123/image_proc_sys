#ifndef CIMAGEITEM_H
#define CIMAGEITEM_H

#include <QtQuick/QQuickPaintedItem>
#include <QImage>


class CImageItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_ENUMS( DrawAnaType )
    Q_PROPERTY( QString irFilePath READ get_ir_file_path WRITE set_ir_file_path )
public:
    CImageItem( QQuickItem * parent = 0 );
    ~CImageItem();

    QString get_ir_file_path() const;
    void set_ir_file_path( const QString &s_ir_file_path );

    void paint( QPainter *painter );

signals:

private:
    QString ms_ir_file_path;
    QString ms_vector_file_path;
    QImage m_ir_img;
};

#endif // CIMAGEITEM_H
