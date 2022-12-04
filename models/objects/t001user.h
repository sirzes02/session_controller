#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractUser>
#include <TAbstractModel>

class TModelObject;
class T001UserObject;
class QJsonArray;


class T_MODEL_EXPORT T001User : public TAbstractUser, public TAbstractModel {
public:
    T001User();
    T001User(const T001User &other);
    T001User(const T001UserObject &object);
    ~T001User();

    QString c001Email() const;
    void setC001Email(const QString &c001Email);
    QString c001Password() const;
    void setC001Password(const QString &c001Password);
    QString identityKey() const { return c001Email(); }
    T001User &operator=(const T001User &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static T001User authenticate(const QString &c001Email, const QString &c001Password);
    static T001User create(const QString &c001Email, const QString &c001Password);
    static T001User create(const QVariantMap &values);
    static T001User get(const QString &c001Email);
    static int count();
    static QList<T001User> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<T001UserObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
    friend QDataStream &operator<<(QDataStream &ds, const T001User &model);
    friend QDataStream &operator>>(QDataStream &ds, T001User &model);
};

Q_DECLARE_METATYPE(T001User)
Q_DECLARE_METATYPE(QList<T001User>)

