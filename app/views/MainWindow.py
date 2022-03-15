from select import select
from unicodedata import numeric
from PyQt5.QtWidgets import QMainWindow, QStackedWidget
from app.views.AuthWidget import AuthWidget
from app.views.HomeWidget import HomeWidget
from app.views.TableWidget import TableWidget

from ..ui.MainWindow_ui import Ui_MainWindow

class MainWindow(QMainWindow, Ui_MainWindow):
    """Main Window."""
    HOME_PAGE = 0
    TABLE_PAGE = 1
    AUTH_PAGE = 2

    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)
        self.init_widget()


    def init_widget(self):
        self.page  = []
        self.home_page = HomeWidget(self)
        self.page.append(self.home_page)
        self.stackedWidget.addWidget(self.home_page)
        
        self.table_page = TableWidget(self)
        self.page.append(self.table_page )
        self.stackedWidget.addWidget(self.table_page)

        self.auth_page = AuthWidget(self)
        self.page.append(self.auth_page)
        self.stackedWidget.addWidget(self.auth_page)
        self.stackedWidget.setCurrentWidget(self.page[0])

    def change_page(self, page_index : numeric):
        self.stackedWidget.setCurrentWidget(self.page[page_index])

        
