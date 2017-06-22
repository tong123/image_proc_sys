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
#include <QFile>



CImageItem::CImageItem( QQuickItem * parent ) : QQuickPaintedItem( parent )
{

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
    QPointF point(0.0,0.0);
    if( m_ir_img.byteCount() != 0 ) {
        painter->drawImage( point, m_ir_img );
//        painter->drawImage( boundingRect().adjusted(1, 1, -1, -1), m_ir_img );
    }
    painter->setOpacity( 1 );

}

bool CImageItem::get_file_exist_status()
{
    if( QFile::exists(ms_ir_file_path) ) {
        return true;
    } else {
        return false;
    }
}

void CImageItem::on_vertical_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, 0 );
    m_ir_img = MatToQImage( des_image );
    update( );
}

void CImageItem::on_horizen_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, 1 );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_horizen_and_vertical_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, -1 );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_erosion_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, -1 );
    int erosion_type;
    erosion_type = MORPH_RECT;
    int erosion_size = 3;
    Mat element = getStructuringElement( erosion_type, Size(2*erosion_size+1, 2*erosion_size+1), Point(erosion_size, erosion_size) );
    erode(src_image, des_image, element );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_dilation_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, -1 );
    int dilation_type;
    dilation_type = MORPH_RECT;
    int dilation_size = 2;
    Mat element = getStructuringElement( dilation_type, Size(2*dilation_size+1, 2*dilation_size+1), Point(dilation_size, dilation_size) );
    dilate(src_image, des_image, element );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_opening_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, -1 );
    int morph_elem;
    morph_elem = MORPH_RECT;
    int morph_size = 2;
    Mat element = getStructuringElement( morph_elem, Size(2*morph_size+1, 2*morph_size+1), Point(morph_size, morph_size) );
    morphologyEx(src_image, des_image, MORPH_OPEN, element );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_closing_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, -1 );
    int morph_elem;
    morph_elem = MORPH_RECT;
    int morph_size = 2;
    Mat element = getStructuringElement( morph_elem, Size(2*morph_size+1, 2*morph_size+1), Point(morph_size, morph_size) );
    morphologyEx(src_image, des_image, MORPH_CLOSE, element );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_action_morphological_gradient_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, -1 );
    int morph_elem;
    morph_elem = MORPH_RECT;
    int morph_size = 2;
    Mat element = getStructuringElement( morph_elem, Size(2*morph_size+1, 2*morph_size+1), Point(morph_size, morph_size) );
    morphologyEx(src_image, des_image, MORPH_GRADIENT, element );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_top_hat_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, -1 );
    int morph_elem;
    morph_elem = MORPH_RECT;
    int morph_size = 2;
    Mat element = getStructuringElement( morph_elem, Size(2*morph_size+1, 2*morph_size+1), Point(morph_size, morph_size) );
    morphologyEx(src_image, des_image, MORPH_TOPHAT, element );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_black_hat_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    cv::flip( src_image, des_image, -1 );
    int morph_elem;
    morph_elem = MORPH_RECT;
    int morph_size = 2;
    Mat element = getStructuringElement( morph_elem, Size(2*morph_size+1, 2*morph_size+1), Point(morph_size, morph_size) );
    morphologyEx(src_image, des_image, MORPH_BLACKHAT, element );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_normalizefilter_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    blur( src_image, des_image, Size(7,7), Point(-1, -1) );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_gaussfilter_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    GaussianBlur( src_image, des_image, Size(7,7), 0, 0 );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_medianfilter_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    medianBlur( src_image, des_image, 7 );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_bilateralfilter_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    bilateralFilter( src_image, des_image, 31, 31*2, 31/2 );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_normalize_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    boxFilter( src_image, des_image, -1, Size(5,5) );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_nonormalize_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    boxFilter( src_image, des_image, -1, Size(3,3), Point(-1,-1), false );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_pyrup_action_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    pyrUp( src_image, des_image, Size(src_image.cols*2, src_image.rows*2) );
    m_ir_img = MatToQImage( des_image );
    update();
}


void CImageItem::on_pyrdown_action_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    pyrDown( src_image, des_image, Size(src_image.cols/2, src_image.rows/2) );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_resizeup_action_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    resize( src_image, des_image, Size(src_image.cols*2, src_image.rows*2) );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_resizedown_action_trigger( )
{
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );

    resize( src_image, des_image, Size(src_image.cols/2, src_image.rows/2) );
    m_ir_img = MatToQImage( des_image );
    update();
}

void CImageItem::on_cn_resize_triggered( )
{

    Mat rot_mat( 2, 3, CV_32FC1 );
    Mat warp_rotate_dst;
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );
    Point center = Point( src_image.cols/2, src_image.rows/2 );
    double angle = -50;
    double scale = 1;
    rot_mat = getRotationMatrix2D( center, angle, scale );
    warpAffine( src_image, warp_rotate_dst, rot_mat, src_image.size() );
    warp_rotate_dst.copyTo( des_image );
    m_ir_img = MatToQImage( des_image );
    m_ir_img = m_ir_img.scaled(640, 480 );
    update();
}

void CImageItem::on_c_resize_triggered( )
{
    Mat rot_mat( 2, 3, CV_32FC1 );
    Mat warp_rotate_dst;
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );
    Point center = Point( src_image.cols/2, src_image.rows/2 );
    double angle = -50;
    double scale = 0.5;
    rot_mat = getRotationMatrix2D( center, angle, scale );
    warpAffine( src_image, warp_rotate_dst, rot_mat, src_image.size() );
    warp_rotate_dst.copyTo( des_image );
    m_ir_img = MatToQImage( des_image );
    m_ir_img = m_ir_img.scaled(640, 480 );
    update();
}

void CImageItem::on_anticlockwise_triggered( )
{
    Mat rot_mat( 2, 3, CV_32FC1 );
    Mat warp_rotate_dst;
    Mat src_image = imread(ms_ir_file_path.toStdString());
    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );
    Point center = Point( src_image.cols/2, src_image.rows/2 );
    double angle = 50;
    double scale = 0.5;
    rot_mat = getRotationMatrix2D( center, angle, scale );
    warpAffine( src_image, warp_rotate_dst, rot_mat, src_image.size() );
    warp_rotate_dst.copyTo( des_image );
    m_ir_img = MatToQImage( des_image );
    m_ir_img = m_ir_img.scaled(640, 480 );
    update();
}

void CImageItem::on_nflip_resize_triggered( )
{
    Mat rot_mat( 2, 3, CV_32FC1 );
    Mat warp_rotate_dst;
    Mat src_image = imread(ms_ir_file_path.toStdString());

    Mat des_image;
    des_image.create( src_image.rows, src_image.cols, src_image.type() );
    Point center = Point( src_image.cols/2, src_image.rows/2 );
    double angle = 0;
    double scale = 0.5;
    rot_mat = getRotationMatrix2D( center, angle, scale );
    warpAffine( src_image, warp_rotate_dst, rot_mat, src_image.size() );
    warp_rotate_dst.copyTo( des_image );
    m_ir_img = MatToQImage( des_image );
    m_ir_img = m_ir_img.scaled(640, 480 );
    update();
}

QImage CImageItem::MatToQImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    qDebug()<<mat.type();
    if(mat.type() == CV_8UC1)
    {
        qDebug()<<"CV_8UC1";
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        qDebug()<<"CV_8UC3";

        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
