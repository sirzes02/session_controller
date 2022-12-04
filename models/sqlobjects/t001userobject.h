#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT T001UserObject : public TSqlObject, public QSharedData {
public:
    QString c001_email;
    QString c001_password;

    enum PropertyIndex {
        C001Email = 0,
        C001Password,
    };

    int primaryKeyIndex() const override { return C001Email; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QStringLiteral("t001_user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString c001_email READ getc001_email WRITE setc001_email)
    T_DEFINE_PROPERTY(QString, c001_email)
    Q_PROPERTY(QString c001_password READ getc001_password WRITE setc001_password)
    T_DEFINE_PROPERTY(QString, c001_password)
};

