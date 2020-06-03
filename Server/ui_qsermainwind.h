/********************************************************************************
** Form generated from reading UI file 'qsermainwind.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSERMAINWIND_H
#define UI_QSERMAINWIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSerMainWind
{
public:
    QAction *actBeginListen;
    QAction *actStopListen;
    QAction *actCloseWindow;
    QAction *actClear;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ListenAddress;
    QComboBox *IPcomboBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *ListenPort;
    QSpinBox *PortspinBox;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *MessageBrowser;
    QHBoxLayout *horizontalLayout;
    QLabel *MessageLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *ClearMessageButton;
    QPushButton *SendMessageButton;
    QLineEdit *MessageEdit;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *StateText;
    QListView *MemberView;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QSerMainWind)
    {
        if (QSerMainWind->objectName().isEmpty())
            QSerMainWind->setObjectName(QStringLiteral("QSerMainWind"));
        QSerMainWind->resize(800, 610);
        actBeginListen = new QAction(QSerMainWind);
        actBeginListen->setObjectName(QStringLiteral("actBeginListen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon/kaishi.png"), QSize(), QIcon::Normal, QIcon::On);
        actBeginListen->setIcon(icon);
        actStopListen = new QAction(QSerMainWind);
        actStopListen->setObjectName(QStringLiteral("actStopListen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/icon/tingzhi.png"), QSize(), QIcon::Normal, QIcon::On);
        actStopListen->setIcon(icon1);
        actCloseWindow = new QAction(QSerMainWind);
        actCloseWindow->setObjectName(QStringLiteral("actCloseWindow"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icon/\351\200\200\345\207\272.png"), QSize(), QIcon::Normal, QIcon::On);
        actCloseWindow->setIcon(icon2);
        actClear = new QAction(QSerMainWind);
        actClear->setObjectName(QStringLiteral("actClear"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icon/\346\270\205\347\251\272.png"), QSize(), QIcon::Normal, QIcon::On);
        actClear->setIcon(icon3);
        centralWidget = new QWidget(QSerMainWind);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 781, 518));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        ListenAddress = new QLabel(layoutWidget);
        ListenAddress->setObjectName(QStringLiteral("ListenAddress"));

        horizontalLayout_3->addWidget(ListenAddress);

        IPcomboBox = new QComboBox(layoutWidget);
        IPcomboBox->setObjectName(QStringLiteral("IPcomboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IPcomboBox->sizePolicy().hasHeightForWidth());
        IPcomboBox->setSizePolicy(sizePolicy);
        IPcomboBox->setMinimumSize(QSize(160, 0));
        IPcomboBox->setMaximumSize(QSize(160, 16777215));
        IPcomboBox->setLayoutDirection(Qt::LeftToRight);
        IPcomboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_3->addWidget(IPcomboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ListenPort = new QLabel(layoutWidget);
        ListenPort->setObjectName(QStringLiteral("ListenPort"));

        horizontalLayout_3->addWidget(ListenPort);

        PortspinBox = new QSpinBox(layoutWidget);
        PortspinBox->setObjectName(QStringLiteral("PortspinBox"));
        PortspinBox->setMaximum(10000);
        PortspinBox->setSingleStep(10);
        PortspinBox->setValue(1200);

        horizontalLayout_3->addWidget(PortspinBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 5, -1, 3);
        MessageBrowser = new QPlainTextEdit(layoutWidget);
        MessageBrowser->setObjectName(QStringLiteral("MessageBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MessageBrowser->sizePolicy().hasHeightForWidth());
        MessageBrowser->setSizePolicy(sizePolicy1);
        MessageBrowser->setMinimumSize(QSize(490, 400));
        MessageBrowser->setMaximumSize(QSize(490, 400));

        verticalLayout_2->addWidget(MessageBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        MessageLabel = new QLabel(layoutWidget);
        MessageLabel->setObjectName(QStringLiteral("MessageLabel"));
        MessageLabel->setMinimumSize(QSize(0, 30));
        MessageLabel->setMaximumSize(QSize(16777215, 30));
        MessageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(MessageLabel);

        horizontalSpacer = new QSpacerItem(40, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ClearMessageButton = new QPushButton(layoutWidget);
        ClearMessageButton->setObjectName(QStringLiteral("ClearMessageButton"));
        ClearMessageButton->setMinimumSize(QSize(0, 30));
        ClearMessageButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(ClearMessageButton);

        SendMessageButton = new QPushButton(layoutWidget);
        SendMessageButton->setObjectName(QStringLiteral("SendMessageButton"));
        SendMessageButton->setMinimumSize(QSize(0, 30));
        SendMessageButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(SendMessageButton);


        verticalLayout_2->addLayout(horizontalLayout);

        MessageEdit = new QLineEdit(layoutWidget);
        MessageEdit->setObjectName(QStringLiteral("MessageEdit"));

        verticalLayout_2->addWidget(MessageEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, 5);
        StateText = new QPlainTextEdit(layoutWidget);
        StateText->setObjectName(QStringLiteral("StateText"));
        StateText->setMinimumSize(QSize(250, 0));
        StateText->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(StateText);

        MemberView = new QListView(layoutWidget);
        MemberView->setObjectName(QStringLiteral("MemberView"));
        MemberView->setMinimumSize(QSize(0, 250));
        MemberView->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(MemberView);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        QSerMainWind->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        statusBar = new QStatusBar(QSerMainWind);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QSerMainWind->setStatusBar(statusBar);
        toolBar = new QToolBar(QSerMainWind);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        QSerMainWind->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actBeginListen);
        toolBar->addAction(actStopListen);
        toolBar->addAction(actClear);
        toolBar->addSeparator();
        toolBar->addAction(actCloseWindow);

        retranslateUi(QSerMainWind);
        QObject::connect(actCloseWindow, SIGNAL(triggered()), QSerMainWind, SLOT(close()));
        QObject::connect(actClear, SIGNAL(triggered()), MessageBrowser, SLOT(clear()));
        QObject::connect(ClearMessageButton, SIGNAL(clicked()), MessageEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(QSerMainWind);
    } // setupUi

    void retranslateUi(QMainWindow *QSerMainWind)
    {
        QSerMainWind->setWindowTitle(QApplication::translate("QSerMainWind", "QSerMainWind", Q_NULLPTR));
        actBeginListen->setText(QApplication::translate("QSerMainWind", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actBeginListen->setToolTip(QApplication::translate("QSerMainWind", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStopListen->setText(QApplication::translate("QSerMainWind", "\345\201\234\346\255\242\347\233\221\345\220\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStopListen->setToolTip(QApplication::translate("QSerMainWind", "\345\201\234\346\255\242\347\233\221\345\220\254", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCloseWindow->setText(QApplication::translate("QSerMainWind", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCloseWindow->setToolTip(QApplication::translate("QSerMainWind", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("QSerMainWind", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("QSerMainWind", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ListenAddress->setText(QApplication::translate("QSerMainWind", "\347\233\221\345\220\254\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        ListenPort->setText(QApplication::translate("QSerMainWind", "\347\233\221\345\220\254\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        MessageLabel->setText(QApplication::translate("QSerMainWind", "Message:", Q_NULLPTR));
        ClearMessageButton->setText(QApplication::translate("QSerMainWind", "\346\270\205\347\251\272\346\266\210\346\201\257", Q_NULLPTR));
        SendMessageButton->setText(QApplication::translate("QSerMainWind", "\345\217\221\351\200\201\344\277\241\346\201\257", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        SendMessageButton->setShortcut(QApplication::translate("QSerMainWind", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        toolBar->setWindowTitle(QApplication::translate("QSerMainWind", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QSerMainWind: public Ui_QSerMainWind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSERMAINWIND_H
