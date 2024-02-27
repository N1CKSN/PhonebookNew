#include "include/AdminWindow.h"

AdminWindow::AdminWindow(DataTable *&table, int x, int y, const char *l)
    : OFLWindow(x, y, 350, 150, l), table(table) {
  begin();
  password = new Fl_Secret_Input(115, button_h, 120, button_h, "Пароль:");

  conf_but = new ConfirmButton(this, 110 + spacing_x * 2, 100, 90, button_h,
                               "Подтвердить");
  conf_but->labelsize(12);
  set_modal();
  show();
  end();
}

AdminWindow::~AdminWindow() {
  delete password;
  delete conf_but;
}

void AdminWindow::insertInpValues() {
  std::string pass = password->value();
  if (this->PASSWORD != pass) {
    err_win = new ErrorOkWindow(0, 0, "Неверный пароль!", "Окно ошибок");
    return;
  } else {
    table->setAdmin();
    table->undoTable();
  }
}
void AdminWindow::Interaction() {
  hide();
  if (Fl::event() == FL_CLOSE) {
    Fl::delete_widget(this);
  } else {
    insertInpValues();
  }
}
