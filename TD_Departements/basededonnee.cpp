#include "basededonnee.h"
#include "ui_basededonnee.h"


BaseDeDonnee::BaseDeDonnee(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BaseDeDonnee)
{
    ui->setupUi(this);

    bd=QSqlDatabase::addDatabase("QMYSQL");
    bd.setHostName("172.18.58.7");
    bd.setDatabaseName("france2018");
    bd.setUserName("snir");
    bd.setPassword("snir");
    if (!bd.open())
    {
        qDebug()<<"pb acces bd "<<bd.lastError();
    }
    else
    {
        qDebug()<<"acces bd ok ";
    }
    QSqlQuery requete("select code, name from regions order by name;" );
    if (!requete.exec()){
        qDebug()<<"pb requete "<<requete.lastError();
    }
    QString nom;
    QString id;

    while(requete.next())
    {
        nom=requete.value("name").toString();
        id=requete.value("code").toString();
        ui->comboBoxRegions->addItem(nom,id);
    }
}

BaseDeDonnee::~BaseDeDonnee()
{
    delete ui;
}


void BaseDeDonnee::on_pushButtonAvoirNom_clicked()
{
    QSqlQuery requete;
    requete.prepare("Select name from departments where code = :idr;");
    requete.bindValue(":idr",ui->lineEditNumDepartements->text());
    if (!requete.exec())
    {
        qDebug()<<"pb requete "<<requete.lastError();
    }
    QString nomDepartement;
    while(requete.next()){
        nomDepartement=requete.value("name").toString();
        qDebug()<<nomDepartement;
    }
    ui->labelNomDepartement->setText(nomDepartement);

}

void BaseDeDonnee::on_comboBoxRegions_currentIndexChanged(int index)
{
    // recupere l'id de la region
        QString idRegion=ui->comboBoxRegions->itemData(index).toString();
        // vider la liste des departements
        ui->comboBoxDepartements->clear();
        ui->comboBoxDepartements->addItem("Choisissez un département");
        QSqlQuery requete("select code, name from Departments order by name "
                          "where region.code = dep;" );
        requete.bindValue(":dep",index);
            if (!requete.exec()){
                qDebug()<<"pb requete "<<requete.lastError();
            }
            QString nom;
            QString id;

            while(requete.next())
            {
                nom=requete.value("name").toString();
                id=requete.value("code").toString();
                ui->comboBoxDepartements->addItem(nom,id);
            }
}

void BaseDeDonnee::on_comboBoxDepartements_currentIndexChanged(int index)
{

}
