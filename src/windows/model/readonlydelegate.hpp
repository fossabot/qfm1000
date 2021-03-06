/*
 * qFM1000
 * Copyright (C) 2020  Luca Cireddu (sardylan@gmail.com)
 * https://www.lucacireddu.it/
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

#ifndef __QFM1000_WINDOWS_MODEL_READONLYDELEGATE_H
#define __QFM1000_WINDOWS_MODEL_READONLYDELEGATE_H

#include <QStyledItemDelegate>
#include <QComboBox>

namespace qfm1000::windows {

    class ReadOnlyDelegate : public QStyledItemDelegate {
    Q_OBJECT

    public:
        explicit ReadOnlyDelegate(QObject *parent = nullptr);

        QWidget *
        createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    protected:
        bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option,
                         const QModelIndex &index) override;

    };

}

#endif