/*
 * qFM1000
 * Copyright (C) 2021  Luca Cireddu - IS0GVH
 * sardylan@gmail.com - is0gvh@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License.
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


#ifndef __QFM1000__QFM1000__WINDOWS__MAIN__H
#define __QFM1000__QFM1000__WINDOWS__MAIN__H

#include <QtCore/QList>

#include <QtWidgets/QMainWindow>

#include "eeprom.hpp"

namespace Ui {
    class Main;
}

namespace qfm1000::app::windows {

    class Main : public QMainWindow {
    Q_OBJECT

    public:

        explicit Main(QWidget *parent = nullptr);

        ~Main() override;

    private:

        Ui::Main *ui;
        QList<windows::EEPROM*> eepromWidgets;

        void connectSignals();

        void initUi();

        void updateWindowTitle();

    signals:

        void displayAbout();

    };

}

#endif
