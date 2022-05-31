#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <array>

#include<json.hpp>

#include <QMainWindow>
#include <QLineEdit>
#include <QLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QVector>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool energyinput=false;
    QString energyunit{};
    nlohmann::json J;
    std::vector<std::vector<double>> x_vec;
    std::vector<double> times;
    std::vector<QLineEdit*> reactions;
    std::vector<QLineEdit*> forward_rates;
    std::vector<QLineEdit*> backward_rates;
    std::vector<QLineEdit*> species_names;
    std::vector<QLineEdit*> init_conc;

public slots:
    void my_slot();
    void set_energyinput();
    void set_energyunit();
    void do_calculation();
    void set_xlog();
    void set_ylog();
    void safeFile();
    void loadFile();
    void export_raw();
    void export_png();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
