import QtQuick 2.0
import QtQuick.Controls 2.12
import QtMultimedia 5.9
import connect 1.0

Item {
    id: welcome

    anchors.fill: parent
    Image {
        id: background
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "assets/images/background3.jpg"
    }

    Dialog{
        id: settingsDialog
        parent: welcome
        anchors.centerIn: welcome
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

    Dialog{
        id: difficultyDialog
        parent: welcome
        anchors.centerIn: welcome
        title: "Select Difficulty"

        Column{
            id: difficultyButtons
            spacing: 5

            Button{
                id: easy
                width: 150
                height: 50
                text: "Easy"
                focusPolicy: Qt.NoFocus
                font.pixelSize: 20
                onClicked: {
                    clicking.play()
                    difficultyDialog.close()
                    connection.start("easy")
                    easyDialog.open()
                    view.push(gamePage)
                }
            }

            Button{
                id: medium
                width: 150
                height: 50
                text: "Medium"
                focusPolicy: Qt.NoFocus
                font.pixelSize: 20
                onClicked: {
                    clicking.play()
                    difficultyDialog.close()
                    connection.start("medium")
                    mediumDialog.open()
                    view.push(gamePage)
                }
            }

            Button{
                id: hard
                width: 150
                height: 50
                text: "Hard"
                focusPolicy: Qt.NoFocus
                font.pixelSize: 20
                onClicked: {
                    clicking.play()
                    difficultyDialog.close()
                    connection.start("hard")
                    hardDialog.open()
                    view.push(gamePage)
                }
            }
        }
    }

    Dialog{
        id: easyDialog
        title: "you have 2 minutes to reach 50 coins... are you ready?"
        anchors.centerIn: parent
        Button{
            text: "let's go"
            width: 150
            height: 50
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            anchors.centerIn: parent
            onClicked: {
                clicking.play()
                easyDialog.close()
            }
        }
    }

    Dialog{
        id: mediumDialog
        title: "you have 2 minutes to reach 80 coins... are you ready?"
        anchors.centerIn: parent
        Button{
            text: "let's go"
            width: 150
            height: 50
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            anchors.centerIn: parent
            onClicked: {
                clicking.play()
                mediumDialog.close()
            }
        }
    }

    Dialog{
        id: hardDialog
        title: "you have 2 minutes to reach 100 coins... are you ready?"
        anchors.centerIn: parent
        Button{
            text: "let's go"
            width: 150
            height: 50
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            anchors.centerIn: parent
            onClicked: {
                clicking.play()
                hardDialog.close()
            }
        }
    }

    Column{
        id: buttons
        anchors.right: welcome.right
        anchors.rightMargin: 100
        y: 150
        spacing: 10

        Button{
            id: start
            width: 230
            height: 70
            text: "Start"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            onClicked: {
                clicking.play()
                difficultyDialog.open()
            }
        }

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
            id: exit
            width: 230
            height: 70
            text: "Exit"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            onClicked: {
                clicking.play()
                Qt.quit()
            }
        }
    }

    Audio{
        id: clicking
        source: "assets/sounds/clicking.m4a"
    }

}
