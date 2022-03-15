import imp
from PyQt5.QtWidgets import QWidget


from ..ui.AuthWidget_ui import Ui_AuthWidget

class AuthWidget(QWidget, Ui_AuthWidget):
    """Auth Widget"""

    def __init__(self, parent=None):
        super().__init__(parent)
        self.parent_window = parent
        self.setupUi(self)
        self.init_listener()

    def init_listener(self):
        self.pb_cancel.clicked.connect(self.go_back)
        self.pb_login.clicked.connect(self.go_table)

    def go_back(self):
        self.parent_window.change_page(0)

    def go_table(self):
        self.parent_window.change_page(1)
