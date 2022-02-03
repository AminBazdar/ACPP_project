import QtQuick 2.0
import QtQuick.Controls 2.12
import QtMultimedia 5.9
import connect 1.0

Item {
    id: game
    anchors.fill: parent
    property int timerVal: 10
    property int tempVal: 0

    Image {
        id: playingbackground
        source: "assets/images/background1.jpg"
        anchors.fill: parent
    }

    Connections{
        target: connection
        onGameStarted:{
            coins.text = connection.totalCoin
            physicians.text = connection.totalPhysicians
            surgeons.text = connection.totalSurgeons
            physicianPatient.start()
            surgeonPatient.start()
            timerVal = 10
            timerr.start()
        }

        onPhysicianIncomChanged:{
                physicianDialog.open()
                tempVal = connection.totalCoin
                if(tempVal == -1)
                {
                    mainAudio.pause()
                    winningSound.play()
                    timerr.stop()
                    physicianPatient.stop()
                    surgeonPatient.stop()
                    view.push(winningPage)
                }
                else
                {
                    coins.text = connection.totalCoin
                }
        }
        onSurgeonIncome:{
            surgeonInc.open()
            tempVal = connection.totalCoin
            if(tempVal == -1)
            {
                mainAudio.pause()
                winningSound.play()
                timerr.stop()
                physicianPatient.stop()
                surgeonPatient.stop()
                view.push(winningPage)
            }
            else
            {
                coins.text = connection.totalCoin
            }
        }
        onBuyPhys:{
            coins.text = connection.totalCoin
            physicians.text = connection.totalPhysicians
            buyphysmessage.open()
        }
        onBuySurg:{
            coins.text = connection.totalCoin
            surgeons.text = connection.totalSurgeons
            buySurgmessage.open()
        }
        onFail:{
            fail.open()
        }
    }

    Button{
        id: buyingphysician
        x: 650
        y: 200
        width: 220
        height: 100
        focusPolicy: Qt.NoFocus
        text: "Buying physician"
        font.pixelSize: 20
        background: Rectangle{
            anchors.fill: parent
            color: parent.down ? "red":
                                 (parent.hovered? "orange": "white")
        }
        onClicked: {
            clicking.play()
            connection.addPhys()
        }
    }

    Button{
        id: buyingSurgeon
        anchors.left: buyingphysician.right
        anchors.leftMargin: 20
        y: 200
        width: 220
        height: 100
        focusPolicy: Qt.NoFocus
        text: "Buying surgeon"
        font.pixelSize: 20
        background: Rectangle{
            anchors.fill: parent
            color: parent.down ? "red":
                                 (parent.hovered? "orange": "white")
        }
        onClicked: {
            clicking.play()
            connection.addSurg()
        }
    }

    Dialog{
        id: fail
        anchors.centerIn: parent
        title: "Not enough coin"
    }

    Dialog{
        id: buyphysmessage
        anchors.centerIn: parent
        title: "physician successfully bought"
    }
    Dialog{
        id: buySurgmessage
        anchors.centerIn: parent
        title: "Surgeon successfully bought"
    }

    Image {
        id: coin
        x:10
        y:10
        source: "assets/images/coinIcon.png"
        width: 30
        height: 30
        Text {
            id: coins
            anchors.left: coin.right
            anchors.leftMargin: 5
            text: qsTr("none")
            color: "yellow"
            font.pointSize: 25
        }
    }

    Row{
        id: surgeonRow
        anchors.top: coin.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 7

        spacing: 5
        Text {
            id: physician
            color: "yellow"
            text: qsTr("Physicians: ")
            font.pointSize: 25
        }
        Text {
            id: physicians
            color: "yellow"
            text: qsTr("None")
            font.pointSize: 25
        }
    }

    Row{
        anchors.top: surgeonRow.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 7

        spacing: 5

        Text {
            id: surgeon
            color: "yellow"
            text: qsTr("surgeons: ")
            font.pointSize: 25
        }
        Text {
            id: surgeons
            color: "yellow"
            text: qsTr("None")
            font.pointSize: 25
        }
    }

    Image {
        id: clock
        source: "assets/images/clock.png"
        height: 130
        width: 130

        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
    }

    Timer{
        id: timerr
        interval: 1000
        running: false
        repeat: true
        onTriggered:{
            timerVal = timerVal - 1
            if(timerVal < 1)
            {
                mainAudio.pause()
                losingSound.play()
                timerVal = 0
                youLose.open()
            }
            time.text = timerVal.toString()
        }
    }

    Text {
        id: time
        color: "black"
        anchors.centerIn: clock
        text: qsTr("540")
        font.pointSize: 22
    }

    Dialog{
        anchors.centerIn: parent
        id: youLose
        Image {
            id: youLoseimg
            source: "assets/images/youLose.gif"
            anchors.centerIn: parent
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
                timerr.stop()
                physicianPatient.stop()
                youLose.close()
                view.pop()
            }
        }
    }

    Dialog{
        id: physicianDialog
        anchors.centerIn: parent
        title: "physician income added"
        Button{
            text: "Ok"
            anchors.centerIn: parent
            onClicked: {
                clicking.play()
                physicianDialog.close()
            }
        }
    }

    Timer{
        id: physicianPatient
        interval: 20000
        running: false
        repeat: true
        onTriggered: {
            connection.setPhysicianIncom(0)
        }
    }
    Timer{
        id: surgeonPatient
        interval: 35000
        running: false
        repeat: true
        onTriggered: {
                connection.setSurgeonIncome()
        }
    }

    Dialog{
        id: surgeonInc
        anchors.centerIn: parent
        title: "Surgeon income added"
        Button{
            text: "Ok"
            anchors.centerIn: parent
            onClicked: {
                clicking.play()
                surgeonInc.close()
            }
        }
    }

    Audio{
        id: clicking
        source: "assets/sounds/clicking.m4a"
    }
    Audio{
        id: winningSound
        source: "assets/sounds/winning sound.m4a"
        volume: 1.0
    }
    Audio{
        id: losingSound
        source: "assets/sounds/losing sound.m4a"
    }
}
