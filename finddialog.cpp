#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "finddialog.h"

FindDialog::FindDialog(QWidget* parent) : QDialog(parent) {
    label = new QLabel(tr("Find &What: "));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwordCheckBox = new QCheckBox(tr("Search &backword"));

    findButon = new QPushButton(tr("&Find"));
    findButon->setDefault(true);
    findButon->setEnabled(false);

    closeButton = new QPushButton(tr("Closse"));

    connect(lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableFindButton(const QString&)));
    connect(findButon, SIGNAL(clicked()), this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwordCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButon);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked() {
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    if (backwordCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void FindDialog::enableFindButton(const QString &text) {
    findButon->setEnabled(!text.isEmpty());
}
