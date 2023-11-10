#include "binaryultimate.h"
#include "./ui_binaryultimate.h"

BinaryUltimate::BinaryUltimate(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BinaryUltimate)
{
    ui->setupUi(this);
}

BinaryUltimate::~BinaryUltimate()
{
    delete ui;
}

int BinToDec(int binNumber) {

    int decimalValue = 0;
    int base1 = 1;

    while (binNumber > 0)
    {
        int reminder = binNumber % 10;
        binNumber = binNumber / 10;
        decimalValue += reminder * base1;
        base1 = base1 * 2;
    }
    return decimalValue;
}

QString DecToBin(QString decNumber)
    {
    int a[10], n, i;
    QString fDecN="";
    n = decNumber.toInt();
for(i=0; n>0; i++)
{
    a[i]=n%2;
    n= n/2;
}
for(i=i-1 ;i>=0 ;i--)
{
    fDecN+=QString::number(a[i]);
}

return fDecN;

 }


void BinaryUltimate::on_ToBinaryBT1_clicked()
{

ui->outBinL2->setText(DecToBin(ui->ipLE1->text()));
}

