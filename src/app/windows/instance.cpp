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


#include <QtCore/QDebug>

#include <QtGui/QFont>
#include <QtGui/QFontDatabase>

#include "instance.hpp"
#include "ui_instance.h"

using namespace qfm1000::app::windows;

Instance::Instance(QWidget *parent) : QWidget(parent), ui(new Ui::Instance) {
    ui->setupUi(this);

    connectSignals();
    initUi();
}

Instance::~Instance() {
    delete ui;
}

void Instance::connectSignals() {
    qInfo() << "Connecting signals";

}

void Instance::initUi() {
    qInfo() << "Initalizing UI";
}

void Instance::updateFileName(const QString &filename) {
    if (filename.size() == 0) {
        setWindowTitle("<not saved>");
        return;
    }

    setWindowTitle(filename);
}
