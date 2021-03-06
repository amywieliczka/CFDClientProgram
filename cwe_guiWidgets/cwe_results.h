/*********************************************************************************
**
** Copyright (c) 2018 The University of Notre Dame
** Copyright (c) 2018 The Regents of the University of California
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** 1. Redistributions of source code must retain the above copyright notice, this
** list of conditions and the following disclaimer.
**
** 2. Redistributions in binary form must reproduce the above copyright notice, this
** list of conditions and the following disclaimer in the documentation and/or other
** materials provided with the distribution.
**
** 3. Neither the name of the copyright holder nor the names of its contributors may
** be used to endorse or promote products derived from this software without specific
** prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
** EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
** SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
** TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
** BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
** IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
** SUCH DAMAGE.
**
***********************************************************************************/

// Contributors:

#ifndef CWE_RESULTS_H
#define CWE_RESULTS_H

#include "cwe_super.h"

#include <QStandardItemModel>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>

enum class CaseState;
class ResultProcureBase;

namespace Ui {
class CWE_Results;
}

class CWE_Results : public CWE_Super
{
    Q_OBJECT

public:
    explicit CWE_Results(QWidget *parent = 0);
    ~CWE_Results();

    virtual void linkDriver(CWE_InterfaceDriver * newDriver);
    void resetViewInfo();

private slots:
    void on_downloadEntireCaseButton_clicked();
    void resultViewClicked(QModelIndex);

    void newCaseGiven();
    void newCaseState(CaseState newState);

private:
    QMap<QString, QString> getResultObjectFromName(QString name);
    void populateResultsScreen();
    void performSingleFileDownload(QString filePathToDownload, QString stage);

    Ui::CWE_Results    *ui;
    QStandardItemModel *model;

    bool viewIsValid = false;
    int showCol;
    int downloadCol;

    void addResult(QString name, bool showeye, bool download, QString type);
};

#endif // CWE_RESULTS_H
