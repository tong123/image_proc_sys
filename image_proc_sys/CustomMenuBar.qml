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
        MenuItem{
            text: "打开自定义文件"
        }
        MenuItem{
            text: "复原"
        }
        MenuItem{
            text: "清除"
        }
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
        }
        MenuItem{
            text: "垂直"
        }
        MenuItem{
            text: "水平垂直"
        }
    }
    Menu {
        title: "形态"
        MenuItem{
            text: "腐蚀"
        }
        MenuItem{
            text: "膨胀"
        }
        MenuItem{
            text: "开运算"
        }
        MenuItem{
            text: "闭运算"
        }
        MenuItem{
            text: "形态学梯度"
        }
        MenuItem{
            text: "顶帽"
        }
        MenuItem{
            text: "黑帽"
        }
    }
    Menu {
        title: "滤波"
        MenuItem{
            text: "均值"
        }
        MenuItem{
            text: "高斯"
        }
        MenuItem{
            text: "中值"
        }
        MenuItem{
            text: "双边"
        }
    }
    Menu {
        title: "缩放"
        MenuItem{
            text: "放大(PyUp)"
        }
        MenuItem{
            text: "高斯(PyUp)"
        }
        MenuItem{
            text: "中值(PyUp)"
        }
        MenuItem{
            text: "双边(PyUp)"
        }
    }
    Menu {
        title: "旋转"
        MenuItem{
            text: "顺时针无缩放"
        }
        MenuItem{
            text: "顺时针缩放"
        }
        MenuItem{
            text: "逆时针"
        }
        MenuItem{
            text: "零旋转缩放"
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

