#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Calculator");
  w.setMaximumSize(1150, 550);
  w.setFixedSize(w.size());
  w.setBaseSize(730, 550);
  w.setMinimumSize(730, 550);
  w.resize(730, 550);

  w.show();

  return a.exec();
}
