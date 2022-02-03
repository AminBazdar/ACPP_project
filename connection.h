#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include "include/hospital.hpp"

class connection : public QObject
{
  Q_OBJECT
  Q_PROPERTY(int totalCoin READ totalCoin WRITE setTotalCoin NOTIFY totalCoinChanged)
  Q_PROPERTY(int totalPhysicians READ totalPhysicians WRITE setTotalPhysicians NOTIFY totalPhysiciansChanged)
  Q_PROPERTY(int totalSurgeons READ totalSurgeons WRITE setTotalSurgeons NOTIFY totalSurgeonsChanged)
  Q_PROPERTY(int physicianIncom READ physicianIncom WRITE setPhysicianIncom NOTIFY physicianIncomChanged)

public:
  connection();

signals:
  void totalCoinChanged();
  void totalPhysiciansChanged();
  void totalSurgeonsChanged();
  void physicianIncomChanged();
  void surgeonIncome();
  void buyPhys();
  void buySurg();
  void fail();
  void gameStarted();

public slots:
  int totalCoin();
  void setTotalCoin(int);

  int totalPhysicians();
  void setTotalPhysicians(int);

  int totalSurgeons();
  void setTotalSurgeons(int);

  void setPhysicianIncom(int);
  int physicianIncom();

  void addPhys();
  void addSurg();

  void setSurgeonIncome();
  void start(QString);

private:
  hospital* mainHospital = nullptr;
  int coin = 0;
  int physician = 0;
  int surgeon = 0;
  int counter = 540;
  int physIncome = 0;

};

#endif // CONNECTION_H
