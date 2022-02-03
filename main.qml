import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.3
import QtMultimedia 5.9
import connect 1.0

ApplicationWindow {
    id: root
    visible: true
    minimumWidth: 700
    minimumHeight: 500
    width: Screen.width
    height: Screen.height
    title: qsTr("my Hospital")
    Material.theme: Material.Light
    Material.accent: Material.Purple
    Material.background: "#EEEEEE"

    StackView{
        id: view
        initialItem: welcomePage
        width: root.width
        height: root.height
    }

    Welcome{
        id: welcomePage
        visible: false
    }

    GamePage{
        id: gamePage
        visible: false
    }
    Winning{
        id: winningPage
        visible: false
    }

    Audio{
        id:mainAudio
        source: "assets/sounds/mainSound.m4a"
        autoPlay: true
        loops: -1
    }

    Connect{
        id: connection
    }
}
