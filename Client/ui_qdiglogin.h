/********************************************************************************
** Form generated from reading UI file 'qdiglogin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIGLOGIN_H
#define UI_QDIGLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDigLogin
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *UserNameLabel;
    QLineEdit *UserNameEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *LogInButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *QuitButton;

    void setupUi(QDialog *QDigLogin)
    {
        if (QDigLogin->objectName().isEmpty())
            QDigLogin->setObjectName(QStringLiteral("QDigLogin"));
        QDigLogin->resize(400, 300);
        widget = new QWidget(QDigLogin);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 130, 244, 91));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        UserNameLabel = new QLabel(widget);
        UserNameLabel->setObjectName(QStringLiteral("UserNameLabel"));
        UserNameLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(UserNameLabel);

        UserNameEdit = new QLineEdit(widget);
        UserNameEdit->setObjectName(QStringLiteral("UserNameEdit"));

        horizontalLayout->addWidget(UserNameEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LogInButton = new QPushButton(widget);
        LogInButton->setObjectName(QStringLiteral("LogInButton"));

        horizontalLayout_2->addWidget(LogInButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        QuitButton = new QPushButton(widget);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        horizontalLayout_2->addWidget(QuitButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(QDigLogin);
        QObject::connect(QuitButton, SIGNAL(clicked()), QDigLogin, SLOT(close()));

        QMetaObject::connectSlotsByName(QDigLogin);
    } // setupUi

    void retranslateUi(QDialog *QDigLogin)
    {
        QDigLogin->setWindowTitle(QApplication::translate("QDigLogin", "Dialog", Q_NULLPTR));
        UserNameLabel->setText(QApplication::translate("QDigLogin", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        UserNameEdit->setText(QApplication::translate("QDigLogin", "Samoking", Q_NULLPTR));
        LogInButton->setText(QApplication::translate("QDigLogin", "\347\231\273\345\275\225", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        LogInButton->setShortcut(QApplication::translate("QDigLogin", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        QuitButton->setText(QApplication::translate("QDigLogin", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QDigLogin: public Ui_QDigLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIGLOGIN_H
