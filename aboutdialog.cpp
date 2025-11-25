#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QDesktopServices>
#include <QUrl>

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    setWindowTitle("ℹ️ Sobre o Planejador Financeiro Pessoal/ About the Personal Finance Planner");
    ui->label->setText(
        "<h2>💵 Personal Finance Planner</h2>"
        "<p>Projeto desenvolvido por <b>Carlos Eduardo Mulinari</b><br>"
        "UPF — Engenharia da Computação — 2025</p>"
        "<p>Planejador financeiro inteligente com Arduino e Qt/ Intelligent Finance Planner with Arduino and Qt.</p>"
        );
    connect(ui->githubButton_2, &QPushButton::clicked, this, []() {
        QDesktopServices::openUrl(QUrl("https://github.com/carlosEmulinari"));
    });

    connect(ui->youtubeButton, &QPushButton::clicked, this, []() {
        QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=UjRCzryYscs%3D%3D"));
    });
    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

