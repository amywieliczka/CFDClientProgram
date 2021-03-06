/*********************************************************************************
**
** Copyright (c) 2017 The University of Notre Dame
** Copyright (c) 2017 The Regents of the University of California
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
// Peter Mackenzie-Helnwein, UW Seattle

#include "cwe_welcome_screen.h"
#include "ui_cwe_welcome_screen.h"

CWE_welcome_screen::CWE_welcome_screen(QWidget *parent) :
    CWE_Super(parent),
    ui(new Ui::CWE_welcome_screen)
{
    ui->setupUi(this);
//    ui->WelcomeStackedWidget->setCurrentIndex(0);

    /* set page 1 of help screen */

//    ui->text_label_1->setBackgroundRole(QPalette::Base);
//    ui->text_label_1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//    ui->text_label_1->setScaledContents(true);

//    ui->text_label_2->setBackgroundRole(QPalette::Base);
//    ui->text_label_2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//    ui->text_label_2->setScaledContents(true);

    /*
    ui->text_label_3->setBackgroundRole(QPalette::Base);
    ui->text_label_3->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->text_label_3->setScaledContents(true);

    ui->text_label_4->setBackgroundRole(QPalette::Base);
    ui->text_label_4->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->text_label_4->setScaledContents(true);

    ui->text_label_5->setBackgroundRole(QPalette::Base);
    ui->text_label_5->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->text_label_5->setScaledContents(true);
    */

//    ui->text_label_1->setPixmap(QPixmap(":/images/Overview/CWEFlow1.png"));
//    ui->text_label_1->setPixmap(QPixmap(":/images/Overview/CWEFlow1.png").scaled(600,600,Qt::KeepAspectRatio));
//    ui->text_label_2->setPixmap(QPixmap(":/images/Overview/CWEFlow2.png"));
    /*
    ui->text_label_3->setPixmap(QPixmap(":/images/Overview/CWEFlow3.png"));
    ui->text_label_4->setPixmap(QPixmap(":/images/Overview/CWEFlow4.png"));
    ui->text_label_5->setPixmap(QPixmap(":/images/Overview/CWEFlow5.png"));
    */

}

CWE_welcome_screen::~CWE_welcome_screen()
{
    delete ui;
}

void CWE_welcome_screen::on_commandLinkButton_2_clicked()
{
    /* previous page on welcome screen */

//    int index = ui->WelcomeStackedWidget->currentIndex();
//    index--;
    //if (index<0) { index += 5; }
//    if (index<0) { index += 2; }
//    ui->WelcomeStackedWidget->setCurrentIndex(index);
}

void CWE_welcome_screen::on_commandLinkButton_clicked()
{
    /* next page on welcome screen */

//    int index = ui->WelcomeStackedWidget->currentIndex();
//    index++;
    //if (index>4) { index -= 5; }
//    if (index>1) { index -= 2; }
//    ui->WelcomeStackedWidget->setCurrentIndex(index);
}
