#include "mainwindow.h"

#include "./ui_mainwindow.h"

extern "C" {
#include "../controller/controller.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  MainWindow::makePlot();

  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_20, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_21, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_22, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_23, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_25, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_26, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_27, SIGNAL(clicked()), this, SLOT(add_char()));
  connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(add_char()));

  connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(set_pi()));
  connect(ui->pushButton_e, SIGNAL(clicked()), this, SLOT(set_e()));

  connect(ui->pushButton_pow_2, SIGNAL(clicked()), this, SLOT(set_pow()));
  connect(ui->pushButton_pow_3, SIGNAL(clicked()), this, SLOT(set_pow()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(set_pow()));

  connect(ui->pushButton_c, SIGNAL(clicked()), this, SLOT(clearLine()));
  connect(ui->pushButton_ce, SIGNAL(clicked()), this, SLOT(clearAll()));
  connect(ui->pushButton_back, SIGNAL(clicked()), this, SLOT(backspaceFunc()));

  connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(controller()));
  connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(controller()));

  connect(ui->pushButton_graphic, SIGNAL(clicked()), this, SLOT(makePlot()));
  connect(ui->BuildGraphicButton, SIGNAL(clicked()), this,
          SLOT(calculate_plot()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::add_char() {
  QPushButton *button = (QPushButton *)sender();

  ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void MainWindow::clear_lineEdit() {}

void MainWindow::clearLine() { ui->lineEdit->clear(); }
void MainWindow::clearAll() {
  ui->lineEdit->clear();
  ui->result->clear();
}
void MainWindow::backspaceFunc() {
  QString tmp = ui->lineEdit->text();
  tmp.chop(1);
  ui->lineEdit->setText(tmp);
}
void MainWindow::set_pi() {
  ui->lineEdit->setText(ui->lineEdit->text() + "3.1415926");
}
void MainWindow::set_e() {
  ui->lineEdit->setText(ui->lineEdit->text() + "2.7182818");
}

void MainWindow::controller() {
  auto line = ui->lineEdit->text();
  std::string str = line.toStdString();
  char *p = (char *)str.c_str();
  if (is_valid(p)) {
    ui->result->setText("expression error");
  } else {
    auto out = QString::number((double)get_result(p, NAN, false), 'g', 7);
    if (out == "nan") {
      out = "<p style=\"color: red;\">" + out + "</p>";
    }
    ui->result->setText(out);
  }
}

void MainWindow::set_pow() {
  QPushButton *button = (QPushButton *)sender();
  auto text = button->text();

  if (text == "x^2") {
    ui->lineEdit->setText(ui->lineEdit->text() + "^2");
  } else if (text == "x^3") {
    ui->lineEdit->setText(ui->lineEdit->text() + "^3");
  } else {
    ui->lineEdit->setText(ui->lineEdit->text() + "^");
  }
}

void MainWindow::makePlot() {
  // create graph and assign data to it:
  if (!ui->customPlot->graphCount()) {
    this->resize(1150, 550);
    ui->customPlot->setVisible(true);
    ui->customPlot->addGraph();
    this->show();
  } else if (ui->customPlot->isVisible()) {
    ui->customPlot->setVisible(false);
    this->resize(730, 550);

    this->show();
  } else {
    ui->customPlot->setVisible(true);
    this->resize(1150, 550);
    this->show();
  }
}

void MainWindow::calculate_plot() {
  QString text = ui->x_min_line->text();
  bool min_is_number = (!text.isEmpty() && text.toDouble()) || text == "0";

  text = ui->x_max_line->text();
  bool max_is_number = (!text.isEmpty() && text.toDouble()) || text == "0";

  text = ui->y_min_line->text();
  bool min_y_is_number = (!text.isEmpty() && text.toDouble()) || text == "0";

  text = ui->y_max_line->text();
  bool max_y_is_number = (!text.isEmpty() && text.toDouble()) || text == "0";

  auto line = ui->lineEdit->text();
  std::string str = line.toStdString();
  char *p = (char *)str.c_str();

  if (is_valid(p) || !min_is_number || !max_is_number || !max_y_is_number ||
      !min_y_is_number) {
    ui->result->setText(" fail build plot, check you expression or rav x-y ");
    return;
  } else if (ui->x_min_line->text().toDouble() >=
                 ui->x_max_line->text().toDouble() ||
             ui->y_min_line->text().toDouble() >=
                 ui->y_max_line->text().toDouble()) {
    ui->result->setText(" fail build plot, check you expression or rav x ");
    return;
  } else {
    double min = ui->x_min_line->text().toDouble();
    double max = ui->x_max_line->text().toDouble();
    double min_y = ui->y_min_line->text().toDouble();
    double max_y = ui->y_max_line->text().toDouble();
    int count_elem = static_cast<int>(std::abs(min) + std::abs(max)) * 50;
    QVector<double> x(count_elem),
        y(count_elem);  // initialize with entries 0..100

    for (int i = 0; i < count_elem; ++i) {
      x[i] = (static_cast<double>(i) / 50.0) * (max - min) +
             min;  // x goes from min to max
      y[i] = static_cast<double>(
          get_result(p, x[i], true));  // let's plot a quadratic function
    }

    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(min, max);
    ui->customPlot->yAxis->setRange(min_y, max_y);
    ui->customPlot->replot();

    ui->result->setText(
        "<p style=\"color: green;\">equation graph successfully completed</p>");
  }
}
