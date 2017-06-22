#ifndef CIMAGEITEM_H
#define CIMAGEITEM_H

#include <QtQuick/QQuickPaintedItem>
#include <QImage>

#include "opencv2/opencv.hpp"
using namespace cv;

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
    Q_INVOKABLE void on_horizen_trigger( );
    QImage MatToQImage(const Mat& mat);
    Q_INVOKABLE void on_vertical_trigger( );
    Q_INVOKABLE void on_horizen_and_vertical_trigger( );
    Q_INVOKABLE void on_erosion_trigger( );
    Q_INVOKABLE void on_dilation_trigger( );
    Q_INVOKABLE void on_opening_trigger( );
    Q_INVOKABLE void on_closing_trigger( );
    Q_INVOKABLE void on_action_morphological_gradient_trigger( );
    Q_INVOKABLE void on_top_hat_trigger( );
    Q_INVOKABLE void on_black_hat_trigger( );
    Q_INVOKABLE void on_normalizefilter_trigger( );
    Q_INVOKABLE void on_gaussfilter_trigger( );
    Q_INVOKABLE void on_medianfilter_trigger( );
    Q_INVOKABLE void on_bilateralfilter_trigger( );
    Q_INVOKABLE void on_normalize_trigger( );
    Q_INVOKABLE void on_nonormalize_trigger( );
    Q_INVOKABLE void on_pyrup_action_trigger( );
    Q_INVOKABLE void on_pyrdown_action_trigger( );
    Q_INVOKABLE void on_resizeup_action_trigger( );
    Q_INVOKABLE void on_resizedown_action_trigger( );
    Q_INVOKABLE void on_cn_resize_triggered( );
    Q_INVOKABLE void on_c_resize_triggered( );
    Q_INVOKABLE void on_anticlockwise_triggered( );
    Q_INVOKABLE void on_nflip_resize_triggered( );
    Q_INVOKABLE bool get_file_exist_status( );

signals:

private:
    QString ms_ir_file_path;
    QString ms_vector_file_path;
    QImage m_ir_img;
};

#endif // CIMAGEITEM_H
