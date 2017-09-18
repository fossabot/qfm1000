/*
 * qFM1000
 * Copyright (C) 2017  Luca Cireddu
 * sardylan@gmail.com
 * http://www.lucacireddu.it
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __QFM1000_EEPROM_PROGRAMMER_TEST_H
#define __QFM1000_EEPROM_PROGRAMMER_TEST_H

#include <QtCore/QObject>
#include <QtSerialPort/QSerialPort>
#include <QtTest>

#include "programmer.hpp"

class ArduinoProgrammerTest : public QObject {

Q_OBJECT

private:
    ArduinoProgrammer *programmer;

    static void generateRandomData(QByteArray *data, size_t len);

private slots:

    void initTestCase();

    void cleanupTestCase();

    void init();

    void cleanup();

//    void testSinglePage();
};

#endif