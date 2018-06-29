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
<<<<<<< HEAD
    //void SetLoanTable(QVector<DataLoan>);
=======
    void SetLoanTable(QVector<DataRecord>);
>>>>>>> 916793ca42385bd503d2f3f507e81f63df1dd620
    void Adapt2User();
    void Adapt2Administer();
signals:
    void SearchLoan(QString search_info, QString search_type);
    void ExtendLoan(QString id);
    void FinishLoan(QString id);

private slots:
    void on_SearchButton_clicked();
    void on_FinishButton_clicked();
    void on_ProlongButton_clicked();

private:
    Ui::LoanStackedPage *ui;
};

#endif // LOANSTACKEDPAGE_H
