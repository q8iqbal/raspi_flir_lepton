import imp
from select import select
from PyQt5.QtWidgets import QWidget

from ..ui.HomeWidget_ui import Ui_HomeWidget

class HomeWidget(QWidget, Ui_HomeWidget):
    """Home Widget"""

    def __init__(self, parent = None):
        super().__init__(parent)
        self.parent_window = parent
        self.setupUi(self)
        self.init_listener()
    
    def init_listener(self):
        self.pb_admin.clicked.connect(self.go_auth)

    def go_auth(self):
        self.parent_window.change_page(2)

