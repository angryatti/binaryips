#include "binaryultimate.h"
#include "./ui_binaryultimate.h"
#include <QMessageBox>
#include <QRegularExpression>

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
    int a[10], n, i =0;
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
QStringList octList;
octList << ui->ipLE1->text().split('.');
QMessageBox msgBox;
QRegularExpression regEx("[0-9]");
QRegularExpressionMatch match;

for (int i =0;i<octList.length();i++)
{
  match =  regEx.match(octList[i]);

    if (!match.hasMatch())
    {
      msgBox.setText("Invalid ip or subnetmask it is containing alphabet");
      msgBox.exec();
      return;


    }
    if (octList[i].toInt()>255)
    {
    msgBox.setText("Invalid ip or subnetmask");
    msgBox.exec();
    return;


    }
}
int cnt = 0;
QString tempIP = ui->ipLE1->text();
for (int i=0;i<tempIP.length();i++)
         {
    if (tempIP[i]=='.')
  {
    cnt++;

    }
    if (cnt>3)
    {
    break;
    }

    }
if (cnt>3)
{
    msgBox.setText("Invalid ip or subnetmask");
    msgBox.exec();
    return;

}
QString outBinIp ="";
for (int i =0;i<=3;i++)
    {
    qDebug() << octList[i];
     outBinIp+= QStringLiteral("%1").arg(DecToBin(octList[i]),8,QLatin1Char('0')) +".";


}
outBinIp.removeAt(outBinIp.length()-1);
qDebug() << outBinIp;


ui->binaryIPLE2->setText(outBinIp);
 }
