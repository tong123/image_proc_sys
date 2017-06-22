import QtQuick 2.0
import QtQuick.Controls 1.4

MenuBar {
    Menu {
        title: "文件"
        MenuItem{
            text: "打开测试文件"
            onTriggered: {
                fileDialog.open()
            }
        }
//        MenuItem{
//            text: "打开自定义文件"
//        }
//        MenuItem{
//            text: "复原"
//        }
//        MenuItem{
//            text: "清除"
//        }
        MenuItem{
            text: "退出"
            onTriggered: {
                Qt.quit()
            }
        }

    }
    Menu {
        title: "翻转"
        MenuItem{
            text: "水平"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }

                image_item.on_horizen_trigger()
            }
        }
        MenuItem{
            text: "垂直"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_vertical_trigger()
            }
        }
        MenuItem{
            text: "水平垂直"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_horizen_and_vertical_trigger()
            }
        }
    }
    Menu {
        title: "形态"
        MenuItem{
            text: "腐蚀"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_erosion_trigger()
            }
        }
        MenuItem{
            text: "膨胀"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_dilation_trigger()
            }
        }
        MenuItem{
            text: "开运算"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_opening_trigger()
            }
        }
        MenuItem{
            text: "闭运算"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_closing_trigger()
            }
        }
        MenuItem{
            text: "形态学梯度"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_action_morphological_gradient_trigger()
            }
        }
        MenuItem{
            text: "顶帽"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_top_hat_trigger()
            }
        }
        MenuItem{
            text: "黑帽"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_black_hat_trigger()
            }
        }
    }
    Menu {
        title: "滤波"
        MenuItem{
            text: "均值"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_normalizefilter_trigger()
            }
        }
        Menu{
            title: "方框"
            MenuItem {
                text: "归一化"
                onTriggered: {
                    if( !image_item.get_file_exist_status() ) {
                        return
                    }
                    image_item.on_normalize_trigger()
                }
            }
            MenuItem {
                text: "非归一化"
                onTriggered: {
                    if( !image_item.get_file_exist_status() ) {
                        return
                    }
                    image_item.on_nonormalize_trigger()
                }
            }

        }
        MenuItem{
            text: "高斯"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_gaussfilter_trigger()
            }
        }
        MenuItem{
            text: "中值"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_medianfilter_trigger()
            }
        }
        MenuItem{
            text: "双边"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_bilateralfilter_trigger()
            }
        }
    }
    Menu {
        title: "缩放"
        MenuItem{
            text: "放大(PyUp)"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_pyrup_action_trigger()
            }
        }
        MenuItem{
            text: "缩小(PyDown)"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_pyrdown_action_trigger()
            }
        }
        MenuItem{
            text: "放大(Resize)"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_resizeup_action_trigger()
            }
        }
        MenuItem{
            text: "缩小(Resize)"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_resizedown_action_trigger()
            }
        }
    }
    Menu {
        title: "旋转"
        MenuItem{
            text: "顺时针无缩放"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_cn_resize_triggered( )
            }
        }
        MenuItem{
            text: "顺时针缩放"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_c_resize_triggered()
            }
        }
        MenuItem{
            text: "逆时针"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_anticlockwise_triggered()
            }
        }
        MenuItem{
            text: "零旋转缩放"
            onTriggered: {
                if( !image_item.get_file_exist_status() ) {
                    return
                }
                image_item.on_nflip_resize_triggered()
            }
        }
    }
    Menu {
        title: "帮助"
        MenuItem{
            text: "版权"
        }
        MenuItem{
            text: "关于"
        }
    }
}

