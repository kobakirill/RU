/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include <QtWidgets>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QFile>

namespace Ui {
  class DownloadDialog;
}

class DownloadDialog : public QDialog
{
  Q_OBJECT

  public:
    explicit DownloadDialog(QWidget *parent = 0, QString src = "", QString tgt = "", QString contentType = "", QString title = "");

    ~DownloadDialog();

  public slots:
    virtual void reject() override;

  private slots:
    void fileError();
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);

  private:
    Ui::DownloadDialog *ui;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    QFile *file;
    bool aborted;
    QNetworkRequest request;
    QUrl url;
};
