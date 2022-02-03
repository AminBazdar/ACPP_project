#include <unistd.h>
#include "connection.h"
#include "include/hospital.hpp"

connection::connection()
{
}
// ------------------------------------------------------
int connection::totalCoin()
{
  return coin;
}

void connection::setTotalCoin(int val)
{
  coin = mainHospital->getCoin();
  emit totalCoinChanged();
}
// ------------------------------------------------------

int connection::totalPhysicians()
{
  return physician;
}

void connection::setTotalPhysicians(int val)
{
  physician = mainHospital->getPhysician();
  emit totalPhysiciansChanged();
}
// ------------------------------------------------------
int connection::totalSurgeons()
{
  return surgeon;
}

void connection::setTotalSurgeons(int val)
{
  surgeon = mainHospital->getSurgeon();
  emit totalSurgeonsChanged();
}
// ------------------------------------------------------

void connection::setPhysicianIncom(int val)
{
  physIncome = physician * 2;
  coin += physIncome;
  if(mainHospital->getDifficulty() == hospital::difficulty::EASY && coin >= 50)
    {
      coin = -1;
    }
  else if(mainHospital->getDifficulty() == hospital::difficulty::NORMAL && coin >= 80)
    {
      coin = -1;
    }
  else if(mainHospital->getDifficulty() == hospital::difficulty::HARD && coin >= 100)
    {
      coin = -1;
    }
  emit physicianIncomChanged();
}

int connection::physicianIncom()
{
  return physIncome;
}

void connection::addPhys()
{
  if(coin < 5)
    {
      emit fail();
      return;
    }
  coin -= 5;
  physician++;
  emit buyPhys();
}

void connection::addSurg()
{
  if(coin < 7)
    {
      emit fail();
      return;
    }
  coin -= 7;
  surgeon++;
  emit buySurg();
}

void connection::setSurgeonIncome()
{
  coin += surgeon * 3;
  if(mainHospital->getDifficulty() == hospital::difficulty::EASY && coin >= 50)
    {
      coin = -1;
    }
  else if(mainHospital->getDifficulty() == hospital::difficulty::NORMAL && coin >= 80)
    {
      coin = -1;
    }
  else if(mainHospital->getDifficulty() == hospital::difficulty::HARD && coin >= 100)
    {
      coin = -1;
    }
  emit surgeonIncome();
}

// ------------------------------------------------------

void connection::start(QString gameDiff)
{
      mainHospital = new hospital(gameDiff.toStdString());
      coin = mainHospital->getCoin();
      physician = mainHospital->getPhysician();
      surgeon = mainHospital->getSurgeon();
      emit gameStarted();
}

