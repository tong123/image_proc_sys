#include "image-item.h"
#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include <QImage>
#include <QImageReader>
#include <QCursor>
#include <QtMath>
#include <QFileInfo>
#include <QDir>

#define ImageW 640
#define ImageH 480
#define AnchorW 4

CImageItem::CImageItem( QQuickItem * parent ) : QQuickPaintedItem( parent )
{
//    set_ir_file_path( "D:/qtpace_5/image_proc_sys/position.irp.jpg" );
}

CImageItem::~CImageItem()
{
}

QString CImageItem::get_ir_file_path() const
{
    return ms_ir_file_path;
}

void CImageItem::set_ir_file_path( const QString &s_ir_file_path )
{
    ms_ir_file_path = s_ir_file_path;

    m_ir_img = QImage( 640, 480, QImage::Format_RGB32 );
    m_ir_img.load( ms_ir_file_path );
    update();
}

void CImageItem::paint( QPainter *painter )
{
    painter->setOpacity( 1 );
    if( m_ir_img.byteCount() != 0 ) {
        painter->drawImage( boundingRect().adjusted(1, 1, -1, -1), m_ir_img.scaled( 640, 480 ) );
    }
    painter->setOpacity( 1 );

}
