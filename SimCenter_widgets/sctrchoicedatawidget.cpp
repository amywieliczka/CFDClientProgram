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

#include "sctrchoicedatawidget.h"

#include "cwe_globals.h"

SCtrChoiceDataWidget::SCtrChoiceDataWidget(QWidget *parent):
    SCtrMasterDataWidget(parent)
{

}

void SCtrChoiceDataWidget::setData(QJsonObject &obj)
{
    // set up the UI for the widget
    this->initUI();

    m_obj = obj;

    QHBoxLayout *layout = (QHBoxLayout *)this->layout();
    layout->setMargin(0);

    if (label_unit != NULL) {
        label_unit->setText(obj.value(QString("unit")).toString());
    }
    if (label_varName != NULL) {
        label_varName->setText(obj.value(QString("displayname")).toString());
    }

    QStandardItemModel *theModel = new QStandardItemModel(this);

    QJsonObject options = obj.value(QString("options")).toObject();
    QString theDefault = obj.value(QString("default")).toString();

    foreach (QString key, options.keys())
    {
        QList<QStandardItem *> newRow;
        // newRow.clear();
        newRow.append(new QStandardItem(key));
        newRow.append(new QStandardItem(options.value(key).toString()));

        theModel->appendRow(newRow);
    }

    theComboBox = new QComboBox(this);
    layout->insertWidget(1, theComboBox, 4);
    theComboBox->setModel(theModel);
    theComboBox->setModelColumn(1);
    theComboBox->setCurrentText(options.value(theDefault).toString());

    this->setLayout(layout);
}

QString SCtrChoiceDataWidget::toString()
{
    /* *** update the value ***
     *
     * the model contains two columns:
     *   col 0: the variable name
     *   col 1: the human readable variable description
     *
     * theComboBox displays col 1
     * the driver uses the associated value from col 0
     * thus, the return value is the associate QString from col 0
     */

    QStandardItemModel *model = (QStandardItemModel *)theComboBox->model();
    QStandardItem *item = model->item(theComboBox->currentIndex(), 0);

    return item->text();
}

void SCtrChoiceDataWidget::updateValue(QString s)
{
    /* *** update the value ***
     *
     * the model contains two columns:
     *   col 0: the variable name
     *   col 1: the human readable variable description
     *
     * theComboBox displays col 1
     * the driver uses the associated value from col 0
     */


    /* check if new information is an appropriate type */
    QStandardItemModel *theModel = (QStandardItemModel *)theComboBox->model();
    QList<QStandardItem *> itemList = theModel->findItems(s, Qt::MatchExactly, 0);

    if (itemList.isEmpty())
    {
        /* add an error message */
        QString name = m_obj["displayname"].toString();
        cwe_globals::displayPopup(QString("Variable %1 of unknown selection option \'%2\'.\nVariable ignored.").arg(name).arg(s), "Warning");
        return;
    }

    /* the following loop should never have more than one item in the itemList ...  */
    foreach (QStandardItem *item, itemList)
    {
        QModelIndex idx = theModel->indexFromItem(item);
        theComboBox->setCurrentIndex(idx.row());
    }

}

