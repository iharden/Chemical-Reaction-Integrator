#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "functions.hpp"
#include "integrator.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //----------------------------------------------------------------------//
    //                                                                      //
    //                  MainWindow constructor                              //
    // Set default values, hide certain elements etc.                       //
    // ui is the only private member of the MainWindow instance             //
    // setupUi(QMainWindow*) is  defined in ui_mainwindow.h and creates     //
    //                all the widgets, connects SIGNALS with SLOTS etc.     //
    //----------------------------------------------------------------------//

    ui->setupUi(this);
    ui->kcal->setVisible(false);
    ui->ev->setVisible(false);
    ui->Hartree->setVisible(false);
    ui->scrollArea_2->setVisible(false);
    ui->lineEdit_31->setVisible(false);
    ui->lineEdit_32->setVisible(false);
    ui->lineEdit_34->setVisible(false);
    ui->lineEdit_33->setText("293.15");
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_13->setVisible(false);
    ui->label_14->setVisible(false);
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->label_12->setVisible(false);
    ui->label_15->setVisible(false);
    ui->label_16->setVisible(false);
    ui->lineEdit_35->setVisible(false);
    ui->lineEdit_36->setVisible(false);
    ui->calculateButton->setVisible(false);
    ui->customPlot->setVisible(false);
    ui->xlog->setVisible(false);
    ui->ylog->setVisible(false);
    ui->pushRawdata->setVisible(false);
    ui->pushPng->setVisible(false);

    //vector<QLineEdit*> reactions;
    reactions.push_back(ui->line1_2); reactions.push_back(ui->line2_2);
    reactions.push_back(ui->line3_2); reactions.push_back(ui->line4_2);
    reactions.push_back(ui->line5_2); reactions.push_back(ui->line6_2);
    reactions.push_back(ui->line7_2); reactions.push_back(ui->line8_2);
    reactions.push_back(ui->line9_2); reactions.push_back(ui->line10_2);
    reactions.push_back(ui->line11_2); reactions.push_back(ui->line12_2);
    reactions.push_back(ui->line13_2); reactions.push_back(ui->line14_2);
    reactions.push_back(ui->line15_2);

    //vector<QLineEdit*> forward_rates;
    forward_rates.push_back(ui->line1); forward_rates.push_back(ui->line2);
    forward_rates.push_back(ui->line3); forward_rates.push_back(ui->line4);
    forward_rates.push_back(ui->line5); forward_rates.push_back(ui->line6);
    forward_rates.push_back(ui->line7); forward_rates.push_back(ui->line8);
    forward_rates.push_back(ui->line9); forward_rates.push_back(ui->line10);
    forward_rates.push_back(ui->line11); forward_rates.push_back(ui->line12);
    forward_rates.push_back(ui->line13); forward_rates.push_back(ui->line14);
    forward_rates.push_back(ui->line15);

    //vector<QLineEdit*> backward_rates;
    backward_rates.push_back(ui->lineEdit_37); backward_rates.push_back(ui->lineEdit_38);
    backward_rates.push_back(ui->lineEdit_39); backward_rates.push_back(ui->lineEdit_40);
    backward_rates.push_back(ui->lineEdit_41); backward_rates.push_back(ui->lineEdit_42);
    backward_rates.push_back(ui->lineEdit_43); backward_rates.push_back(ui->lineEdit_44);
    backward_rates.push_back(ui->lineEdit_45); backward_rates.push_back(ui->lineEdit_46);
    backward_rates.push_back(ui->lineEdit_47); backward_rates.push_back(ui->lineEdit_48);
    backward_rates.push_back(ui->lineEdit_49); backward_rates.push_back(ui->lineEdit_50);
    backward_rates.push_back(ui->lineEdit_51);

    //vector<QLineEdit*> species_names;
    species_names.push_back(ui->lineEdit_6);  species_names.push_back(ui->lineEdit_5);
    species_names.push_back(ui->lineEdit_23); species_names.push_back(ui->lineEdit_22);
    species_names.push_back(ui->lineEdit_21); species_names.push_back(ui->lineEdit_20);
    species_names.push_back(ui->lineEdit_19); species_names.push_back(ui->lineEdit_18);
    species_names.push_back(ui->lineEdit_17); species_names.push_back(ui->lineEdit_11);
    species_names.push_back(ui->lineEdit_3);  species_names.push_back(ui->lineEdit_10);
    species_names.push_back(ui->lineEdit_4);  species_names.push_back(ui->lineEdit_2);
    species_names.push_back(ui->lineEdit);

    //vector<QLineEdit*> init_conc;
    init_conc.push_back(ui->lineEdit_8);  init_conc.push_back(ui->lineEdit_27);
    init_conc.push_back(ui->lineEdit_30); init_conc.push_back(ui->lineEdit_29);
    init_conc.push_back(ui->lineEdit_28); init_conc.push_back(ui->lineEdit_26);
    init_conc.push_back(ui->lineEdit_25); init_conc.push_back(ui->lineEdit_24);
    init_conc.push_back(ui->lineEdit_14); init_conc.push_back(ui->lineEdit_16);
    init_conc.push_back(ui->lineEdit_15); init_conc.push_back(ui->lineEdit_13);
    init_conc.push_back(ui->lineEdit_12); init_conc.push_back(ui->lineEdit_9);
    init_conc.push_back(ui->lineEdit_7);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_energyinput() {

    //----------------------------------------------------------------------//
    //                  Read in barriers or rates?                          //
    //----------------------------------------------------------------------//

    if(ui->boolactivation->isChecked()) {
        energyinput=true;

        ui->kcal->setVisible(true);
        ui->ev->setVisible(true);
        ui->Hartree->setVisible(true);
    }
    else {
        energyinput=false;

        ui->kcal->setVisible(false);
        ui->ev->setVisible(false);
        ui->Hartree->setVisible(false);
    }
}

void MainWindow::set_energyunit() {

    //----------------------------------------------------------------------//
    //                 kcal, eV or Hartree?                                 //
    //----------------------------------------------------------------------//

    if(ui->kcal->isChecked()) {

       energyunit="kcal";
       ui->Hartree->setEnabled(false);
       ui->ev->setEnabled(false);
    }

    if(ui->ev->isChecked()) {

       energyunit="ev";
       ui->Hartree->setEnabled(false);
       ui->kcal->setEnabled(false);
    }

    if(ui->Hartree->isChecked()) {

       energyunit="hartree";
       ui->kcal->setEnabled(false);
       ui->ev->setEnabled(false);
    }

    if(!ui->Hartree->isChecked() && !ui->ev->isChecked() && !ui->kcal->isChecked()) {

        ui->kcal->setEnabled(true);
        ui->ev->setEnabled(true);
        ui->Hartree->setEnabled(true);
    }
}

void MainWindow::my_slot() {

    //----------------------------------------------------------------------//
    //                                                                      //
    //                  Read in reaction equations                          //
    // ON OUTPUT: vector<std::string> with all equations                    //
    //----------------------------------------------------------------------//

    vector<QString> lines;
    for(auto ptr:reactions) {
        if(ptr->text()!= "")
            lines.push_back(ptr->text());
    }

    vector<string> stdlines=functions::get_stdstring(lines);


    //----------------------------------------------------------------------//
    //                                                                      //
    //                  Read in forward rates or barriers                   //
    // ON OUTPUT: vector<double> with reaction rates at temperate T         //
    //----------------------------------------------------------------------//

    vector<double> fr;
    for(auto ptr:forward_rates) {
        if(ptr->text() != "")
            fr.push_back(ptr->text().toDouble());
    }
    double T=ui->lineEdit_33->text().toDouble();
    fr = functions::convert_rates(fr, T, energyinput, energyunit);

    //----------------------------------------------------------------------//
    //                                                                      //
    //                  Read in optional backward rates or barriers         //
    // ON OUTPUT: vector<double> with reaction rates at temperate T         //
    //----------------------------------------------------------------------//

    vector<double> br;
    for(auto ptr:backward_rates) {
        if(ptr->text()=="")
            br.push_back(-1.0);
        else
            br.push_back(ptr->text().toDouble());
    }
    br = functions::convert_rates(br, T, energyinput, energyunit);

    //----------------------------------------------------------------------//
    //                                                                      //
    //             Most important step: Set up json object                  //
    // ON OUTPUT: nlohmann::json J (J is member of MainWindow class         //
    //                              which is why we don't initiate it)      //
    //----------------------------------------------------------------------//

    try {
        J=functions::setup_json(stdlines,fr, br);
    }
    catch(runtime_error& e) {

        QString err=e.what();
        QMessageBox::information(this, tr("An error occured!"),err);
        return;
    }

    //----------------------------------------------------------------------//
    //                                                                      //
    //                  Get ready to read initial concentrations            //
    // Enable the lineedits and put the right lables there                  //
    //----------------------------------------------------------------------//

    vector<string> labels;
    int numreact=J["reactions"].size();
    for(int i=0;i<numreact;++i) {
        for(int j=0;j<J["reactions"][i]["reactands"]["Labels"].size();++j)
            labels.push_back(J["reactions"][i]["reactands"]["Labels"][j]);
        for(int j=0;j<J["reactions"][i]["products"]["Labels"].size();++j)
            labels.push_back(J["reactions"][i]["products"]["Labels"][j]);
    }

    sort(labels.begin(),labels.end());
    labels.erase(unique(labels.begin(),labels.end()),labels.end());

    vector<QString> qlabels = functions::get_qstring(labels);
    ui->scrollArea_2->setVisible(true);
    ui->label_10->setVisible(true);
    ui->label_11->setVisible(true);
    ui->label_12->setVisible(true);


    for(int i=0;i<qlabels.size();++i)
        species_names[i]->setText(qlabels[i]);

    for(int i=0;i<species_names.size();++i) {
        if(i<qlabels.size())
            species_names[i]->setEnabled(true);
        else
            species_names[i]->setEnabled(false);
    }

    for(int i=0;i<init_conc.size();++i) {
        if(i<qlabels.size())
            init_conc[i]->setEnabled(true);
        else
            init_conc[i]->setEnabled(false);
    }

    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label_7->setVisible(true);
    ui->label_13->setVisible(true);
    ui->label_14->setVisible(true);
    ui->label_15->setVisible(true);
    ui->label_16->setVisible(true);
    ui->lineEdit_35->setVisible(true);
    ui->lineEdit_36->setVisible(true);
    ui->lineEdit_35->setText("1.0e-06");
    ui->lineEdit_36->setText("1.0e-06");

    ui->lineEdit_31->setVisible(true);
    ui->lineEdit_31->setText("0");

    ui->lineEdit_32->setVisible(true);
    ui->lineEdit_32->setText("100000");

    ui->lineEdit_34->setVisible(true);
    ui->lineEdit_34->setText("0.0001");

    ui->calculateButton->setVisible(true);
}

void MainWindow::do_calculation() {

    //----------------------------------------------------------------------
    //
    //                  Read initial concentrations
    // some redundant stuff from the previously called slot
    //----------------------------------------------------------------------

    vector<string> labels;
    int numreact=J["reactions"].size();
    for(int i=0;i<numreact;++i) {
        for(int j=0;j<J["reactions"][i]["reactands"]["Labels"].size();++j)
            labels.push_back(J["reactions"][i]["reactands"]["Labels"][j]);
        for(int j=0;j<J["reactions"][i]["products"]["Labels"].size();++j)
            labels.push_back(J["reactions"][i]["products"]["Labels"][j]);
    }

    sort(labels.begin(),labels.end());
    labels.erase(unique(labels.begin(),labels.end()),labels.end());

    vector<QString> qlabels = functions::get_qstring(labels);

    state_type init(qlabels.size());
    for(int i=0;i<qlabels.size();++i) {
        init[i]=init_conc[i]->text().toDouble();
    }

    //------------------------------------------------------------------------
    //
    // Get integration setup and call the integrator
    // ON OUTPUT: All concentrations (vector<vector<double>>
    //            and time points (vector<double>)
    //------------------------------------------------------------------------

    double t_start = ui->lineEdit_31->text().toDouble();
    double t_end = ui->lineEdit_32->text().toDouble();
    double step_init = ui->lineEdit_34->text().toDouble();

    double abs_err = ui->lineEdit_35->text().toDouble();
    double rel_err = ui->lineEdit_36->text().toDouble();

    // x_vec and times must be members of mainwindow so that we can export them via a PushButton
    // Therefore no structured binding but rather std::tie()
    tie(x_vec, times) = integrator::do_integration(J, init, t_start, t_end, step_init, abs_err, rel_err);

    //------------------------------------------------------------------------
    //
    // Now we have to do the plotting
    // Prepare QVectors, colors, get ranges for axes etc.
    //------------------------------------------------------------------------

    QVector<double> qtimes = QVector<double>(times.begin(),times.end());
    vector<QVector<double>> qx(x_vec.size());
    for(int i=0;i<qx.size();++i)
        qx[i]=QVector<double>(x_vec[i].begin(),x_vec[i].end());

    array<QColor,16> colors{Qt::black, Qt::red, Qt::blue, Qt::green,
                         Qt::yellow, Qt::cyan, Qt::magenta, Qt::gray,
                         Qt::darkRed, Qt::darkGreen, Qt::darkBlue, Qt::darkCyan, Qt::darkMagenta,
                         Qt::darkYellow, Qt::darkGray, Qt::lightGray};

    double miny=1e7, maxy=0.0;
    double tmp;
    for(auto& v:x_vec) {
        tmp=*min_element(v.begin(), v.end());
        if(tmp<miny)
            miny=tmp;
        tmp= *max_element(v.begin(), v.end());
        if(tmp>maxy)
            maxy=tmp;
    }

    ui->customPlot->setVisible(true);
    ui->xlog->setVisible(true);
    ui->ylog->setVisible(true);
    ui->pushRawdata->setVisible(true);
    ui->pushPng->setVisible(true);
    ui->customPlot->clearGraphs();      // important for replotting

    for(int i=0;i<x_vec.size();++i) {
        ui->customPlot->addGraph();
        ui->customPlot->graph(i)->setData(qtimes, qx[i]);
        ui->customPlot->graph(i)->setName(qlabels[i]);
        if(x_vec.size()>16) {
            int n=i/16;
            ui->customPlot->graph(i)->setPen(QPen(colors[i-n*16]));
        }
        else
            ui->customPlot->graph(i)->setPen(QPen(colors[i]));
    }

    ui->customPlot->xAxis->setLabel("time [s]");
    ui->customPlot->yAxis->setLabel("c [mol/L]");
    ui->customPlot->xAxis->setRange(t_start, t_end);
    ui->customPlot->yAxis->setRange(miny, maxy);
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->replot();
}

void MainWindow::set_xlog() {

    //--------------------------------------------------------------------------------//
    //                                                                                //
    // The idea is actually simple:                                                   //
    // We need two ticker (one log, one linear). The linear one has to be             //
    // the default base class Ticker                                                  //
    // One could consider to create the pointers only once and just to                //
    // pass it to the functions (but then they are class members... )                 //
    //                                                                                //
    // Does this code leak memory? I do not think so...                               //
    // setTicker() takes a shared_ptr, the first shared_ptr is destroyed when we leave the function     //
    // When we pass a new shared_ptr to setTicker() the old one is deleted            //
    // Since it was the last instance, the object gets destroyed as well              //
    //--------------------------------------------------------------------------------//

    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
    QSharedPointer<QCPAxisTicker> linTicker(new QCPAxisTicker);

    if(ui->xlog->isChecked()) {
        ui->customPlot->xAxis->setScaleType(QCPAxis::stLogarithmic);
        ui->customPlot->xAxis->setTicker(logTicker);
        ui->customPlot->replot();
    }

    else {
        ui->customPlot->xAxis->setScaleType(QCPAxis::stLinear);
        ui->customPlot->xAxis->setTicker(linTicker);
        ui->customPlot->replot();
    }
}

void MainWindow::set_ylog() {

    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
    QSharedPointer<QCPAxisTicker> linTicker(new QCPAxisTicker);

    if(ui->ylog->isChecked()) {
        ui->customPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
        ui->customPlot->yAxis->setTicker(logTicker);
        ui->customPlot->replot();
    }

    else {
        ui->customPlot->yAxis->setScaleType(QCPAxis::stLinear);
        ui->customPlot->yAxis->setTicker(linTicker);
        ui->customPlot->replot();
    }
}

void MainWindow::safeFile() {

    QString filename=QFileDialog::getSaveFileName(this, tr("Save current project"), "", tr("Reaction system (*.chemsys);;All Files (*)"));

    if(filename.isEmpty()) {
        return;
    }
    else {

        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
        QTextStream out(&file);


        out << "Reactions \n";
        for(auto ptr:reactions) {
            if(ptr->text()!="")
                out << ptr->text() << " \n";
        }

        out << "Forward rates \n";
        for(int i=0;i<forward_rates.size();++i) {
            if(forward_rates[i]->text() != "" && reactions[i]->text()!="")
                out << forward_rates[i]->text() << " \n";
        }

        out << "Backward rates \n";
        for(auto ptr:backward_rates) {
            if(ptr->text() == "")
                out << "-1 \n";
            else
                out << ptr->text() << " \n";
        }

        if(energyinput) {
            out << "energyinput true \n";
            out << "energyunit \n";
            out << energyunit << " \n";
        }
        else {
            out << "energyinput false";
            out << "energyunit false";
        }


        out << "Unique species labels \n";
        for(auto ptr:species_names) {
            if(ptr->text()!="")
                out << ptr->text() << " \n";
        }

        out << "Initial concentrations \n";
        for(auto ptr:init_conc) {
            if(ptr->text()!="")
                out << ptr->text() << " \n";
        }

        out << "Temperature \n";
        out << ui->lineEdit_33->text() << " \n";

        out << "Error controls \n";
        out << ui->lineEdit_35->text() << " \n";
        out << ui->lineEdit_36->text() << " \n";

        out << "Simulation controls \n";
        out << ui->lineEdit_31->text() << " \n";
        out << ui->lineEdit_32->text() << " \n";
        out << ui->lineEdit_34->text() << " \n";
    }
}

void MainWindow::loadFile() {
    QString filename = QFileDialog::getOpenFileName(this,tr("Open project"), "", tr("Reaction system (*.chemsys);;All Files (*)"));

    if(filename.isEmpty())
        return;
    else {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
        QTextStream in(&file);
        vector<QString> input;
        while(in.atEnd()==false)
            input.push_back(in.readLine());

        QString startstring="Reactions";
        QString endstring="Forward rates";

        int idx1, idx2;
        for(int i=0;i<input.size();++i) {
           if(input[i].contains(startstring))
               idx1=i;
           if(input[i].contains(endstring)) {
               idx2=i;
               break;
           }
        }

        int idx=0;
        for(int i=idx1+1;i<idx2;++i) {
           reactions.at(idx)->setText(input[i]);
           ++idx;
        }

        // clear all other lines
        for(int i=idx;i<reactions.size();++i)
            reactions[i]->setText("");

        startstring=endstring;
        endstring="Backward rates";

        for(int i=0;i<input.size();++i) {
          if(input[i].contains(startstring))
              idx1=i;
          if(input[i].contains(endstring)) {
              idx2=i;
              break;
          }
        }

       idx=0;
        for(int i=idx1+1;i<idx2;++i) {
          forward_rates.at(idx)->setText(input[i]);
          ++idx;
        }

        // clear all other lines
        for(int i=idx;i<reactions.size();++i)
            forward_rates[i]->setText("");

        startstring=endstring;
        endstring="energyinput";

        for(int i=0;i<input.size();++i) {
            if(input[i].contains(startstring))
             idx1=i;
            if(input[i].contains(endstring)) {
             idx2=i;
             break;
            }
        }

        idx=0;
        for(int i=idx1+1;i<idx2;++i) {
            if(input[i].contains("-1"))
                backward_rates.at(idx)->setText("");
            else
                backward_rates.at(idx)->setText(input[i]);
            ++idx;
        }

        // clear all other lines
        for(int i=idx;i<reactions.size();++i)
            backward_rates[i]->setText("");

     // Now we need the temperature in order to call my_slot() which will take care of the layout
        for(int i=0;i<input.size();++i) {
            if(input[i].contains("Temperature")) {
                ui->lineEdit_33->setText(input[i+1]);
                break;

            }
        }

     // we actually need also the effect of the two energyslots
        for(int i=0;i<input.size();++i) {

            if(input[i].contains("energyinput true")) {

             ui->boolactivation->setChecked(true);
             energyinput=true;

             ui->kcal->setVisible(true);
             ui->ev->setVisible(true);
             ui->Hartree->setVisible(true);

             // Enable all buttons, makes it easier if we load a file with different settings
             ui->kcal->setEnabled(true);
             ui->ev->setEnabled(true);
             ui->Hartree->setEnabled(true);

             ui->kcal->setChecked(false);
             ui->ev->setChecked(false);
             ui->Hartree->setChecked(false);
             break;
            }

            if(input[i].contains("energyinput false")) {
             energyinput=false;

             ui->kcal->setVisible(false);
             ui->ev->setVisible(false);
             ui->Hartree->setVisible(false);
             break;
            }
        }

        for(int i=0;i<input.size();++i) {
            if(input[i].contains("energyinput true")) {
                 energyunit=input[i+2];
                 energyunit=energyunit.trimmed();

                 if(energyunit=="kcal") {
                     ui->kcal->setChecked(true);
                     ui->ev->setEnabled(false);
                     ui->Hartree->setEnabled(false);
                     break;
                 }

                 if(energyunit=="ev") {
                     ui->kcal->setEnabled(false);
                     ui->ev->setChecked(true);
                     ui->Hartree->setEnabled(false);
                     break;
                 }
                 if(energyunit=="hartree") {
                     ui->kcal->setEnabled(false);
                     ui->ev->setEnabled(false);
                     ui->Hartree->setChecked(true);
                 }
            }
            if(input[i].contains("energyinput false")) {
                break;
            }
        }

        // clear unique spcies labels and initial concentrations
        for(int i=0;i<species_names.size();++i) {

            species_names[i]->setText("");
            init_conc[i]->setText("");
        }

        my_slot(); // creates JSON object and takes care of the layout for the initial concentrations

        startstring="Initial concentrations";
        endstring="Temperature";

        for(int i=0;i<input.size();++i) {
          if(input[i].contains(startstring))
              idx1=i;
          if(input[i].contains(endstring)) {
              idx2=i;
              break;
          }
        }

       idx=0;
        for(int i=idx1+1;i<idx2;++i) {
          init_conc.at(idx)->setText(input[i]);
          ++idx;
        }

        for(int i=0;i<input.size();++i) {
            if(input[i].contains("Error controls")) {
                ui->lineEdit_35->setText(input[i+1]);
                ui->lineEdit_36->setText(input[i+2]);
            }
        }

        for(int i=0;i<input.size();++i) {
            if(input[i].contains("Simulation controls")) {
                ui->lineEdit_31->setText(input[i+1]);
                ui->lineEdit_32->setText(input[i+2]);
                ui->lineEdit_34->setText(input[i+3]);
            }
        }
    }
}

void MainWindow::export_raw() {

    QString filename=QFileDialog::getSaveFileName(this, tr("Export raw data"), "", tr("dat files (*.dat);;All Files (*)"));

    if(filename.isEmpty()) {
        return;
    }

    else {
        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
        QTextStream out(&file);

        for(int i=0;i<times.size();++i) {
            out << times[i] << "  ";
            for(int j=0;j<x_vec.size();++j) {
                out << x_vec[j][i] << "  ";             // Looks suspecious! Cache misses! For every access we need to jump to a different vector. Very bad!
            }
            out << "\n";
        }
    }
}

void MainWindow::export_png() {

    QString filename=QFileDialog::getSaveFileName(this, tr("Export png image"), "", tr("png files (*.png);;All Files (*)"));

    if(filename.isEmpty()) {
        return;
    }
    else {
        ui->customPlot->savePng(filename, 0,0,1.0,100);
    }
}

