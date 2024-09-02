#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H
#include <QListWidget>

class myListWidget : public QListWidget
{
    Q_OBJECT
public:
    myListWidget(QWidget* parent = nullptr);

private slots:
    bool deleteNode();
    bool addNode();

private:
};

#endif // MYLISTWIDGET_H
