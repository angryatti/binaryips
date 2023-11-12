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


QString HexToBin(std::string hexdec)
 {
size_t i = (hexdec[1] == 'x' || hexdec[1] == 'X')? 2 : 0;
QString hexMain ="";
while (hexdec[i]) {

    switch (hexdec[i]) {
    case '0':
        hexMain+= "0000";
        break;
    case '1':
        hexMain+= "0001";
        break;
    case '2':
        hexMain+= "0010";
        break;
    case '3':
        hexMain+= "0011";
        break;
    case '4':
        hexMain+= "0100";
        break;
    case '5':
        hexMain+= "0101";
        break;
    case '6':
        hexMain+= "0110";
        break;
    case '7':
        hexMain+= "0111";
        break;
    case '8':
        hexMain+= "1000";
        break;
    case '9':
        hexMain+= "1001";
        break;
    case 'A':
    case 'a':
        hexMain+= "1010";
        break;
    case 'B':
    case 'b':
        hexMain+= "1011";
        break;
    case 'C':
    case 'c':
        hexMain+= "1100";
        break;
    case 'D':
    case 'd':
        hexMain+="1101";
        break;
    case 'E':
    case 'e':
        hexMain+="1110";
        break;
    case 'F':
    case 'f':
        hexMain+="1111";
        break;
    case ':':
       hexMain+= ".";
        break;
    default:
        hexMain= "Invalid hexadecimal digit" + QString(hexdec[i]);break;
    }
    i++;
}

    return hexMain;

 }
 //this too https://www.geeksforgeeks.org
 void createMap(std::unordered_map<std::string, char> *um)
 {
    (*um)["0000"] = '0';
    (*um)["0001"] = '1';
    (*um)["0010"] = '2';
    (*um)["0011"] = '3';
    (*um)["0100"] = '4';
    (*um)["0101"] = '5';
    (*um)["0110"] = '6';
    (*um)["0111"] = '7';
    (*um)["1000"] = '8';
    (*um)["1001"] = '9';
    (*um)["1010"] = 'A';
    (*um)["1011"] = 'B';
    (*um)["1100"] = 'C';
    (*um)["1101"] = 'D';
    (*um)["1110"] = 'E';
    (*um)["1111"] = 'F';
 }
 // It's more then I know https://www.geeksforgeeks.org
 QString BinaryUltimate::BinToHex(std::string bin)
 {
    int l = bin.size();
    int t = bin.find_first_of('.');

    int len_left = t != -1 ? t : l;

    for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
    bin = '0' + bin;


    if (t != -1)
    {
    int len_right = l - len_left - 1;

    for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
        bin = bin + '0';
    }

    std::unordered_map<std::string, char> bin_hex_map;
    createMap(&bin_hex_map);

    int i = 0;
    QString hex = "";

    while (1)
    {
    hex += bin_hex_map[bin.substr(i, 4)];
    i += 4;
    if (i == bin.size())
        break;

    if (bin.at(i) == '.')
    {
        hex += ':';
        i++;
    }
    }

    return hex;
 }



 bool BinaryUltimate::ValidIP(QStringList strIP)
  {
QMessageBox msgBox;
QRegularExpression regEx("[0-9]");
QRegularExpressionMatch match;

for (int i =0;i<strIP.length();i++)
{

    match =  regEx.match(strIP[i]);

    if (!match.hasMatch())
    {
        msgBox.setText("Invalid ip or subnetmask it is containing alphabet");
        msgBox.exec();
        return 0;


    }
    if ((strIP[i].length()>8))
    {

        msgBox.setText("Invalid ip or subnetmask too long or too much");
        msgBox.exec();
        return 0;


    }
}
int cnt = 0;
QString tempIP;
tempIP=ui->ipLE1->text();
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
    return 0;

}

return 1;

 }

 void BinaryUltimate::on_ToBinaryBT1_clicked()
 {
QStringList octList;
octList << ui->ipLE1->text().split('.');

if (ValidIP(octList))
{


QString outBinIp ="";
for (int i =0;i<=3;i++)
    {

     outBinIp+= QStringLiteral("%1").arg(DecToBin(octList[i]),8,QLatin1Char('0')) +".";

}
outBinIp.removeAt(outBinIp.length()-1);
qDebug() << outBinIp;
ui->OutputConvTE1->setText(outBinIp);
 }
 }

void BinaryUltimate::on_ToDecimalBT2_clicked()
{
 QStringList octList;
 octList << ui->ipLE1->text().split('.');

 if (ValidIP(octList))
 {


QString outDecIp ="";
for (int i =0;i<=3;i++)
{

     outDecIp+= QString::number(BinToDec(octList[i].toInt()))+".";

}
outDecIp.removeAt(outDecIp.length()-1);
qDebug() << outDecIp;
ui->OutputConvTE1->setText(outDecIp);

 }



}


void BinaryUltimate::on_ToHEXABT3_clicked()
{
 ui->OutputConvTE1->setText(HexToBin(ui->ipLE1->text().toStdString()));
}


void BinaryUltimate::on_switchValueBT4_clicked()
{
 QString temp;
 temp = ui->ipLE1->text();
 ui->ipLE1->setText(ui->OutputConvTE1->toPlainText());
 ui->OutputConvTE1->setText(temp);

}


void BinaryUltimate::on_BinToHexBT5_clicked()
{
 QStringList octList;
 octList << ui->ipLE1->text().split('.');


QString outHexIp ="";
for (int i =0;i<octList.length();i++)
{

    outHexIp+= BinToHex(octList[i].toStdString())+":";

}
qDebug() << outHexIp;
outHexIp.removeAt(outHexIp.length()-1);
qDebug() << outHexIp;
ui->OutputConvTE1->setText(outHexIp);





// ui->OutputConvTE1->setText(BinToHex(ui->ipLE1->text().toStdString()));
}

