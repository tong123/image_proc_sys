import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import ImageItem 1.0
ApplicationWindow {
    visible: true
    width: 850
    height: 480

    menuBar:CustomMenuBar{

    }
    Row {
        anchors.centerIn: parent
        spacing: 20
        Column {
            width: 400
            height: 450
            spacing: 10
            Rectangle {
                width: 400
                height: 400
                border.width: 1
                border.color: "black"
                Image{
                    id: src_img
                    anchors.fill: parent
                    source: "position.irp.jpg"
                }
            }
            Text {
                id: src_txt
                text: qsTr("源图像")
            }
        }
        Column {
            width: 400
            height: 450
            spacing: 10
            Rectangle {
                width: 400
                height: 400
                border.width: 1
                border.color: "black"
                ImageItem {
                    id: image_item
                    anchors.fill: parent
                }

            }
            Text {
                id: des_txt
                text: qsTr("处理结果")
            }
        }
    }
    FileDialog {
        id: fileDialog
        title: "请选择一张图片文件"
        onAccepted: {
            src_img.source = fileDialog.fileUrl
            var s_ir_file = fileDialog.fileUrl.toString()
            image_item.irFilePath = s_ir_file.slice(8)
        }
        onRejected: {
        }
        Component.onCompleted: visible = false
    }
}

