# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/mnt/hdd/iqbal/kuliah/TA/PA2/pa_deploy/client_program/resources/ui/HomeWidget.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_HomeWidget(object):
    def setupUi(self, HomeWidget):
        HomeWidget.setObjectName("HomeWidget")
        HomeWidget.resize(1006, 582)
        HomeWidget.setAutoFillBackground(True)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(HomeWidget)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label_time = QtWidgets.QLabel(HomeWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_time.sizePolicy().hasHeightForWidth())
        self.label_time.setSizePolicy(sizePolicy)
        self.label_time.setObjectName("label_time")
        self.verticalLayout_2.addWidget(self.label_time)
        self.horizontalWidget_2 = QtWidgets.QWidget(HomeWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.horizontalWidget_2.sizePolicy().hasHeightForWidth())
        self.horizontalWidget_2.setSizePolicy(sizePolicy)
        self.horizontalWidget_2.setMaximumSize(QtCore.QSize(16777215, 100))
        self.horizontalWidget_2.setObjectName("horizontalWidget_2")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.horizontalWidget_2)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_temp = QtWidgets.QLabel(self.horizontalWidget_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_temp.sizePolicy().hasHeightForWidth())
        self.label_temp.setSizePolicy(sizePolicy)
        self.label_temp.setObjectName("label_temp")
        self.horizontalLayout_3.addWidget(self.label_temp)
        self.label_status = QtWidgets.QLabel(self.horizontalWidget_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_status.sizePolicy().hasHeightForWidth())
        self.label_status.setSizePolicy(sizePolicy)
        self.label_status.setObjectName("label_status")
        self.horizontalLayout_3.addWidget(self.label_status)
        self.verticalLayout_2.addWidget(self.horizontalWidget_2)
        self.label_image = QtWidgets.QLabel(HomeWidget)
        self.label_image.setObjectName("label_image")
        self.verticalLayout_2.addWidget(self.label_image)
        self.horizontalLayout.addLayout(self.verticalLayout_2)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label = QtWidgets.QLabel(HomeWidget)
        self.label.setTextFormat(QtCore.Qt.MarkdownText)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.te_user_id = QtWidgets.QPlainTextEdit(HomeWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.te_user_id.sizePolicy().hasHeightForWidth())
        self.te_user_id.setSizePolicy(sizePolicy)
        self.te_user_id.setMinimumSize(QtCore.QSize(0, 10))
        self.te_user_id.setMaximumSize(QtCore.QSize(16777215, 100))
        self.te_user_id.setFrameShape(QtWidgets.QFrame.Box)
        self.te_user_id.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.te_user_id.setLineWidth(5)
        self.te_user_id.setObjectName("te_user_id")
        self.verticalLayout.addWidget(self.te_user_id)
        self.gridWidget = QtWidgets.QWidget(HomeWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.gridWidget.sizePolicy().hasHeightForWidth())
        self.gridWidget.setSizePolicy(sizePolicy)
        self.gridWidget.setObjectName("gridWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.gridWidget)
        self.gridLayout.setSizeConstraint(QtWidgets.QLayout.SetDefaultConstraint)
        self.gridLayout.setObjectName("gridLayout")
        self.pb_2 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_2.setObjectName("pb_2")
        self.gridLayout.addWidget(self.pb_2, 0, 1, 1, 1)
        self.pb_5 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_5.setObjectName("pb_5")
        self.gridLayout.addWidget(self.pb_5, 1, 1, 1, 1)
        self.pb_enter = QtWidgets.QPushButton(self.gridWidget)
        self.pb_enter.setAutoFillBackground(False)
        self.pb_enter.setStyleSheet("background-color: rgb(146, 255, 73);")
        self.pb_enter.setText("")
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/icons/checkbox-marked-circle-outline.svg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pb_enter.setIcon(icon)
        self.pb_enter.setObjectName("pb_enter")
        self.gridLayout.addWidget(self.pb_enter, 3, 2, 1, 1)
        self.pb_3 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_3.setObjectName("pb_3")
        self.gridLayout.addWidget(self.pb_3, 0, 2, 1, 1)
        self.pb_9 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_9.setObjectName("pb_9")
        self.gridLayout.addWidget(self.pb_9, 2, 2, 1, 1)
        self.pb_1 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_1.setObjectName("pb_1")
        self.gridLayout.addWidget(self.pb_1, 0, 0, 1, 1)
        self.pb_reset = QtWidgets.QPushButton(self.gridWidget)
        self.pb_reset.setStyleSheet("background-color: rgb(255, 0, 4);")
        self.pb_reset.setText("")
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(":/icons/close-circle-outline.svg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.pb_reset.setIcon(icon1)
        self.pb_reset.setObjectName("pb_reset")
        self.gridLayout.addWidget(self.pb_reset, 3, 0, 1, 1)
        self.pb_4 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_4.setObjectName("pb_4")
        self.gridLayout.addWidget(self.pb_4, 1, 0, 1, 1)
        self.pb_0 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_0.setObjectName("pb_0")
        self.gridLayout.addWidget(self.pb_0, 3, 1, 1, 1)
        self.pb_7 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_7.setObjectName("pb_7")
        self.gridLayout.addWidget(self.pb_7, 2, 0, 1, 1)
        self.pb_6 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_6.setObjectName("pb_6")
        self.gridLayout.addWidget(self.pb_6, 1, 2, 1, 1)
        self.pb_8 = QtWidgets.QPushButton(self.gridWidget)
        self.pb_8.setObjectName("pb_8")
        self.gridLayout.addWidget(self.pb_8, 2, 1, 1, 1)
        self.verticalLayout.addWidget(self.gridWidget)
        self.pb_admin = QtWidgets.QPushButton(HomeWidget)
        self.pb_admin.setObjectName("pb_admin")
        self.verticalLayout.addWidget(self.pb_admin)
        self.horizontalLayout.addLayout(self.verticalLayout)
        self.horizontalLayout_2.addLayout(self.horizontalLayout)

        self.retranslateUi(HomeWidget)
        self.pb_reset.clicked.connect(self.te_user_id.clear) # type: ignore
        QtCore.QMetaObject.connectSlotsByName(HomeWidget)

    def retranslateUi(self, HomeWidget):
        _translate = QtCore.QCoreApplication.translate
        HomeWidget.setWindowTitle(_translate("HomeWidget", "Form"))
        self.label_time.setText(_translate("HomeWidget", "<strong>07:30 AM</strong>"))
        self.label_temp.setText(_translate("HomeWidget", "Suhu : 30 C"))
        self.label_status.setText(_translate("HomeWidget", "Status : Normal"))
        self.label_image.setText(_translate("HomeWidget", "Preview Camera"))
        self.label.setText(_translate("HomeWidget", "<strong>Masukan Nomor Identitas</strong>"))
        self.pb_2.setText(_translate("HomeWidget", "2"))
        self.pb_5.setText(_translate("HomeWidget", "5"))
        self.pb_3.setText(_translate("HomeWidget", "3"))
        self.pb_9.setText(_translate("HomeWidget", "9"))
        self.pb_1.setText(_translate("HomeWidget", "1"))
        self.pb_4.setText(_translate("HomeWidget", "4"))
        self.pb_0.setText(_translate("HomeWidget", "0"))
        self.pb_7.setText(_translate("HomeWidget", "7"))
        self.pb_6.setText(_translate("HomeWidget", "6"))
        self.pb_8.setText(_translate("HomeWidget", "8"))
        self.pb_admin.setText(_translate("HomeWidget", "admin"))
from . import resources_rc
