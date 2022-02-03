import QtQuick 2.0
import QtQuick.Controls 2.12
import QtMultimedia 5.9

Item {
    anchors.fill: parent
    Rectangle{
        anchors.fill: parent
        color: "gray"
    }

    Image {
        id: goldenCup
        height: 500
        width: 500
        source: "assets/images/chickenDinner.png"
        anchors.centerIn: parent
    }
    Column{
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.right: parent.right
        anchors.rightMargin: 50
        spacing: 15
        Button{
            id: settings
            width: 230
            height: 70
            text: "Settings"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            onClicked: {
                clicking.play()
                settingsDialog.open()
            }
        }
        Button{
            id: quit
            width: 230
            height: 70
            text: "Quit"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            onClicked: {
                clicking.play()
                mainAudio.play()
                view.pop()
                view.pop()
            }
        }
    }

    Dialog{
        id: settingsDialog
        anchors.centerIn: parent
        title: "Settings"
        modal: true
        CheckBox{
            checked: true
            text: qsTr("music")
            onCheckStateChanged: {
                if(checked === false)
                {
                    mainAudio.stop();
                }
                if(checked === true)
                {
                    mainAudio.play();
                }
            }
        }
    }

    Audio{
        id: clicking
        source: "assets/sounds/clicking.m4a"
    }
}
