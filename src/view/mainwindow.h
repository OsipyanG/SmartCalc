#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
 private slots:
  void makePlot();
  void add_char();
  void clear_lineEdit();
  void controller();
  void calculate_plot();
  void clearLine();
  void clearAll();
  void backspaceFunc();
  void set_pi();
  void set_e();
  void set_pow();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
