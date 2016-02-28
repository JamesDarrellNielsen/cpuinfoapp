import QtQuick 2.5
import CPUInfo 1.0
import QtQuick.Window 2.2

Rectangle {
    id: rect
    anchors.fill: parent

    ListView {
        id: view
        anchors.fill: parent
        model: CpuInfoModel {}
        delegate: Text {
            text: model.display
        }
    }
}

