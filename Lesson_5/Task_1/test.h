#ifndef TEST_H
#define TEST_H

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

signals:
};

#endif // TEST_H
