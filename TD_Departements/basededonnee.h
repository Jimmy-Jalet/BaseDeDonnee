#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class BaseDeDonnee; }
QT_END_NAMESPACE

class BaseDeDonnee : public QWidget
{
    Q_OBJECT

public:
    BaseDeDonnee(QWidget *parent = nullptr);
    ~BaseDeDonnee();

private slots:
    void on_pushButtonAvoirNom_clicked();

    void on_comboBoxRegions_currentIndexChanged(int index);

    void on_comboBoxDepartements_currentIndexChanged(int index);

private:
    Ui::BaseDeDonnee *ui;
    QSqlDatabase bd;
};
#endif // BASEDEDONNEE_H
