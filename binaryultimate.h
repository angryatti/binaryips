#ifndef BINARYULTIMATE_H
#define BINARYULTIMATE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BinaryUltimate; }
QT_END_NAMESPACE

class BinaryUltimate : public QMainWindow
{
    Q_OBJECT

public:
    BinaryUltimate(QWidget *parent = nullptr);
    ~BinaryUltimate();

private slots:
    void on_ToBinaryBT1_clicked();
    bool ValidIP(QStringList vip);
    void on_ToDecimalBT2_clicked();
private:
    Ui::BinaryUltimate *ui;

};
#endif // BINARYULTIMATE_H
