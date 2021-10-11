#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signalAndSlots();
    //length
    QMap<QString,double> lengthUnit;
    lengthUnit["千米"] = 1000;
    lengthUnit["米"] = 1;
    lengthUnit["分米"] = 0.1;
    lengthUnit["厘米"] = 0.01;
    lengthUnit["毫米"]=0.001;
    lengthUnit["微米"] = 0.000001;
    lengthUnit["纳米"] = 0.000000001;
    lengthUnit["英里"] = 1609.344;
    lengthUnit["英尺"] = 0.3048;
    lengthUnit["英寸"] = 0.0254;
    lengthUnit["海里"] = 1852;
    m_mapUnit["长度"] = lengthUnit;

    QMap<QString,double> radUnit;
    radUnit["度"] = 1;
    radUnit["弧度(rad)"]=57.29578;
    radUnit["分(′)"] = 0.01666667;
    radUnit["秒(′′)"] = 0.0002778;
    m_mapUnit["角度"] = radUnit;

   QMap<QString,double> areaUnit;
    areaUnit["平方米(m²)"] = 1;
    areaUnit["平方千米(km²)"] = 1000000;
    areaUnit["公亩"] = 100;
    areaUnit["公顷(ha)"] = 10000;
    areaUnit["平方英里(sq.mi)"] = 2589988.110336;
    m_mapUnit["面积"] = radUnit;

    QMap<QString,double> speedUnit;
    speedUnit["米/秒(m/s)"] = 3.6;
    speedUnit["千米/时(km/h)"] = 1;
    speedUnit["海里/时"] = 1.852;
    speedUnit["马赫(mach)"] = 1225.08;
    m_mapUnit["速度"] = speedUnit;

    QMap<QString,double> tempUnit;
    tempUnit["摄氏度(℃)"] = 1;
    tempUnit["华氏度(℉)"] = -17.2222222;
    tempUnit["开氏度(K)"] = -272.15;
    tempUnit["兰氏度(°R)"] = -272.5944444;
    tempUnit["列氏度(°Re)"] = 1.25;
    m_mapUnit["温度"] = tempUnit;

    QMap<QString,double> pressUnit;
    pressUnit["帕斯卡(Pa)"] = 1;
    pressUnit["兆帕(Mpa)"] = 1000000;
    pressUnit["千帕(kpa)"] = 1000;
    pressUnit["百帕(hpa)"] = 100;
    pressUnit["标准大气压(atm)"] = 101325;
    pressUnit["毫米汞柱(mmHg)"] = 133.3223684;
    pressUnit["毫米水柱"] = 9.80661358;
    m_mapUnit["压强"] = pressUnit;

    QMap<QString,double> volumeUnit;
    volumeUnit["立方米(m³)"] = 1;
    volumeUnit["立方分米(dm³)"] = 0.001;
    volumeUnit["立方厘米(cm³)"] = 0.000001;
    volumeUnit["升(l)"] = 0.001;
    volumeUnit["美制液体盎司(oz)"] = 0.0000293;
    volumeUnit["英制液体盎司(oz)"] = 0.0000284;
    volumeUnit["亩英尺"] = 1233.4818375;
    volumeUnit["美制加仑(usgal)"] = 0.0037854;
    volumeUnit["英制加仑(ukgal)"] = 0.0045461;
    volumeUnit["公石(hl)"] = 0.1;
    m_mapUnit["体积"] = volumeUnit;

    QMap<QString,double> timeUnit;
    timeUnit["年"] = 365;
    timeUnit["周"] = 7;
    timeUnit["天"] = 1;
    timeUnit["时"] = 0.0416667;
    timeUnit["分"] = 0.0006944;
    timeUnit["秒"] = 0.0000116;
    m_mapUnit["时间"] = timeUnit;



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{

}

void MainWindow::signalAndSlots()
{
    connect(ui->comboBox_unit,&QComboBox::currentTextChanged,[this](QString txt){
           QMap<QString,double> lUnit = m_mapUnit[txt];
           ui->comboBox_input->clear();
           ui->comboBox_outPut->clear();
           for(auto iter= lUnit.begin();iter!=lUnit.end();++iter)
           {
                ui->comboBox_input->addItem(iter.key(),iter.value());
                ui->comboBox_outPut->addItem(iter.key(),iter.value());
           }
    });

    connect(ui->comboBox_input,&QComboBox::currentTextChanged,[this]{
        calReslut();
    });
    connect(ui->comboBox_outPut,&QComboBox::currentTextChanged,[this]{
        calReslut();
    });
    connect(ui->lineEdit_input,&QLineEdit::textChanged,[this]{
        calReslut();
    });
}

void MainWindow::calReslut()
{
    double input = ui->lineEdit_input->text().toDouble();
    double inputUnitData = ui->comboBox_input->currentData().toDouble();
    double outputUnitData = ui->comboBox_outPut->currentData().toDouble();
    double reslut = input*inputUnitData/outputUnitData;
    ui->lineEdit_outPut->setText(QString::number(reslut));
}
