/********************************************************************************
** Form generated from reading UI file 'informationpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONPAGE_H
#define UI_INFORMATIONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_informationPage
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *informationPage)
    {
        if (informationPage->objectName().isEmpty())
            informationPage->setObjectName("informationPage");
        informationPage->setWindowModality(Qt::WindowModality::ApplicationModal);
        informationPage->resize(649, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(2, 13, 26, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(3, 19, 39, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(2, 16, 32, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(1, 6, 13, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(1, 9, 17, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush9(QColor(1, 6, 13, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        QBrush brush10(QColor(1, 9, 18, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush10);
        informationPage->setPalette(palette);
        verticalLayout = new QVBoxLayout(informationPage);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 12);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        textBrowser = new QTextBrowser(informationPage);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setLineWrapColumnOrWidth(0);
        textBrowser->setOverwriteMode(false);
        textBrowser->setSource(QUrl(QString::fromUtf8("qrc:/others/resources/algorithmTxt.html")));

        verticalLayout_3->addWidget(textBrowser);


        verticalLayout->addLayout(verticalLayout_3);


        retranslateUi(informationPage);

        QMetaObject::connectSlotsByName(informationPage);
    } // setupUi

    void retranslateUi(QWidget *informationPage)
    {
        informationPage->setWindowTitle(QCoreApplication::translate("informationPage", "Form", nullptr));
        textBrowser->setDocumentTitle(QCoreApplication::translate("informationPage", "Relat\303\263rio sobre o Algoritmo de Gera\303\247\303\243o e Resolu\303\247\303\243o de Labirintos", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("informationPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><title>Relat\303\263rio sobre o Algoritmo de Gera\303\247\303\243o e Resolu\303\247\303\243o de Labirintos</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\" bgcolor=\"#020d1a\">\n"
"<h1 align=\"center\" style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:xx-large; font-weight:700; color:#1e90ff;\">Relat\303\263rio sobre o Algoritmo de Gera\303\247\303\243o e Resolu\303\247\303\243o de Labirintos</span><span style=\" font-family:'Arial','sans-"
                        "serif'; color:#ffffff;\"> </span></h1>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:x-large; font-weight:700; color:#1e90ff;\">Introdu\303\247\303\243o</span><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\"> </span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\">O presente relat\303\263rio descreve o funcionamento de um algoritmo respons\303\241vel pela gera\303\247\303\243o e resolu\303\247\303\243o de labirintos. O algoritmo est\303\241 estruturado de forma modular e utiliza conceitos de recursividade para gerar caminhos dentro do labirinto e encontrar a solu\303\247\303\243o. </span></p>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-"
                        "indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:x-large; font-weight:700; color:#1e90ff;\">Estrutura do Algoritmo</span><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\"> </span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\">O sistema baseia-se em tr\303\252s principais componentes: </span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:12px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Gera\303\247\303\243o do Labirinto:</span> Respons\303\241vel por construir uma estrutura de c\303\251lulas interligadas, criando caminhos e barreiras."
                        " </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Resolu\303\247\303\243o do Labirinto:</span> Utiliza um m\303\251todo recursivo para encontrar um caminho vi\303\241vel entre a entrada e a sa\303\255da do labirinto. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Estruturas de Dados:</span> Utiliza objetos para representar c\303\251lulas e conex\303\265es, armazenando o estado do labirinto. </li></ul>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:x-large; font-weight:700; color:#1e90ff;"
                        "\">Gera\303\247\303\243o do Labirinto</span><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\"> </span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\">A gera\303\247\303\243o do labirinto ocorre atrav\303\251s de uma abordagem baseada em escava\303\247\303\243o recursiva. Os principais passos incluem: </span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:12px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Cria\303\247\303\243o da grade de c\303\251lulas:</span> O labirinto \303\251 inicializado com uma matriz de c\303\251lulas interligadas, onde cada c\303\251lula pode conter "
                        "conex\303\265es para seus vizinhos. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Defini\303\247\303\243o da entrada e sa\303\255da:</span> A entrada e a sa\303\255da s\303\243o escolhidas aleatoriamente em uma das bordas do labirinto. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Escava\303\247\303\243o recursiva:</span> \n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-h"
                        "eight:160%;\">Come\303\247ando pela entrada, o algoritmo percorre recursivamente as c\303\251lulas vizinhas de forma aleat\303\263ria. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">Cada conex\303\243o entre c\303\251lulas pode ser marcada como livre (sem obst\303\241culo) ou bloqueada. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">Se uma c\303\251lula n\303\243o foi visitada, o caminho entre ela e a c\303\251lula anterior \303\251 aberto, e a escava\303\247\303\243o continua. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">O proc"
                        "esso se repete at\303\251 que o labirinto esteja completamente escavado. </li></ul></li></ul>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:x-large; font-weight:700; color:#1e90ff;\">Resolu\303\247\303\243o do Labirinto</span><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\"> </span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\">Para encontrar um caminho vi\303\241vel dentro do labirinto, o algoritmo segue uma abordagem recursiva: </span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:12px; margin-bottom:8px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Inicializa\303\247\303\243o:</span> Um mapa de c\303\251lulas visitadas \303\251 criado para evitar revisitar locais j\303\241 percorridos. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Busca Recursiva:</span> \n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">O algoritmo come\303\247a na entrada e tenta seguir pelos caminhos poss\303\255veis. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:"
                        "8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">Caso uma c\303\251lula leve diretamente \303\240 sa\303\255da, a solu\303\247\303\243o \303\251 encontrada. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">Se a c\303\251lula atual n\303\243o for a sa\303\255da, o algoritmo tenta mover-se para uma c\303\251lula adjacente que n\303\243o tenha obst\303\241culos. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">Caso todas as dire\303\247\303\265es sejam bloqueadas, o algoritmo retrocede e busca outra alternativa. </li></ul></li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#ffffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left"
                        ":0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700;\">Marca\303\247\303\243o do Caminho:</span> Ao encontrar a solu\303\247\303\243o, as c\303\251lulas percorridas s\303\243o marcadas, formando o caminho correto. </li></ul>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:x-large; font-weight:700; color:#1e90ff;\">Conclus\303\243o</span><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\"> </span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Arial','sans-serif'; color:#ffffff;\">O algoritmo implementa de maneira eficiente a gera\303\247\303\243o e resolu\303\247\303\243o de labirintos, utilizando recursividade tanto para a constru\303\247\303\243o quanto para a busca do c"
                        "aminho correto. Essa abordagem permite criar labirintos complexos e encontrar solu\303\247\303\265es de forma otimizada. A modulariza\303\247\303\243o do sistema facilita a manuten\303\247\303\243o e expans\303\243o do c\303\263digo, tornando-o aplic\303\241vel a diversas situa\303\247\303\265es de navega\303\247\303\243o e resolu\303\247\303\243o de problemas. </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class informationPage: public Ui_informationPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATIONPAGE_H
