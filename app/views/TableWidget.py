import imp
from select import select
from PyQt5.QtWidgets import QWidget

from ..ui.TableWidget_ui import Ui_TableWidget

class TableWidget(QWidget, Ui_TableWidget):
    """Table Widget"""

    def __init__(self, parent = None):
        super().__init__(parent)
        self.parent_window = parent
        self.setupUi(self)
        self.init_listener()
    
    def init_listener(self):
        self.pb_back.clicked.connect(self.go_back)

    def go_back(self):
        self.parent_window.change_page(0)

