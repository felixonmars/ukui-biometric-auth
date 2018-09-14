/*
 * Copyright (C) 2018 Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 * 
**/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "biometric.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(const QString &userName, QDialog *parent = 0);
    ~MainWindow();

private:
    enum Mode{UNDEFINED, PASSWORD, BIOMETRIC, DEVICES};
    void switchWidget(Mode mode);

private:
    Ui::MainWindow *ui;
    BioAuthWidget *widgetBioAuth;
    BioDevicesWidget *widgetBioDevices;
    BioDevices bioDevices;

    QString userName;
};

#endif // MAINWINDOW_H
