#ifndef LOANSTACKEDPAGE_H
#define LOANSTACKEDPAGE_H

#include <QWidget>
#include "configure.h"
#include "datarecord.h"
namespace Ui {
class LoanStackedPage;
}

class LoanStackedPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoanStackedPage(QWidget *parent = 0);
    ~LoanStackedPage();

    void SetLoanTable(QVector<DataRecord*> records);
    void ClearTable();
    void Adapt2User();
    void Adapt2Administer();
signals:
    void SearchLoan(QString search_info, QString search_type);
    void ExtendLoan(QString id);
    void FinishLoan(QString id);
    void AcceptReserveLoan(QString id);
private slots:
    void on_SearchButton_clicked();
    void on_FinishButton_clicked();
    void on_ProlongButton_clicked();
    void on_ReserveButton_clicked();

private:
    Ui::LoanStackedPage *ui;
};

#endif // LOANSTACKEDPAGE_H
