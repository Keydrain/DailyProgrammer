#!/bin/usr/python3

import sys
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtWidgets import QToolTip #ToolTip import
from PyQt5.QtWidgets import QPushButton #Button import
from PyQt5.QtGui import QIcon #Icon import
from PyQt5.QtGui import QFont #Font import
from PyQt5.QtCore import QCoreApplication # Core functions

screenx = 1920
screeny = 1200
width = 500
height = 500

class Thing(QWidget):
	def __init__(self):
		super().__init__()
		self.initUI()

	def initUI(self):

		# Code for Icons on Windows Etc
		self.setGeometry((screenx-width)/2, (screeny-height)/2, width, height)
		self.setWindowTitle('Icon')
		self.setWindowIcon(QIcon('web.png'))
		# -----

		# Code for Tool Tips
		QToolTip.setFont(QFont('SansSerif', 10))
		self.setToolTip('This is a <b>QWidget</b> widget')
		# -----

		# Code for buttons
		btn = QPushButton('Button', self)
		btn.setToolTip('This is a <b>QPushButton</b> widget')
		btn.resize(btn.sizeHint())
		btn.move(100, 100)

		# Code for quit buttons
		qbtn = QPushButton('Quit', self)
		qbtn.setToolTip('Press this to quit.')
		qbtn.clicked.connect(QCoreApplication.instance().quit)
		qbtn.resize(qbtn.sizeHint())
		qbtn.move((width - qbtn.width())/2, height - 2*qbtn.height()) # Place the button on the bottom and center it

		self.show()

	def center(self):
		qr = self.frameGeometry()
		cp = QDesktopWidget().availableGeometry().center()
		qr.move.Center(cp)
		self.move(qr.topLeft())

if __name__ == '__main__':

	app = QApplication(sys.argv)

	w = Thing()
	#w.resize(width, height)
	#w.move((screenx-width)/2, (screeny-height)/2)
	w.setWindowTitle('Derpy')
	w.show()

	sys.exit(app.exec_())

