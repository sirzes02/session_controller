#include <TreeFrogModel>
#include "t001user.h"
#include "sqlobjects/t001userobject.h"


T001User::T001User() :
    TAbstractUser(),
    TAbstractModel(),
    d(new T001UserObject())
{
    // set the initial parameters
}

T001User::T001User(const T001User &other) :
    TAbstractUser(),
    TAbstractModel(),
    d(other.d)
{ }

T001User::T001User(const T001UserObject &object) :
    TAbstractUser(),
    TAbstractModel(),
    d(new T001UserObject(object))
{ }


T001User::~T001User()
{
    // If the reference count becomes 0,
    // the shared data object 'T001UserObject' is deleted.
}

QString T001User::c001Email() const
{
    return d->c001_email;
}

void T001User::setC001Email(const QString &c001Email)
{
    d->c001_email = c001Email;
}

QString T001User::c001Password() const
{
    return d->c001_password;
}

void T001User::setC001Password(const QString &c001Password)
{
    d->c001_password = c001Password;
}

T001User &T001User::operator=(const T001User &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

T001User T001User::authenticate(const QString &c001Email, const QString &c001Password)
{
    if (c001Email.isEmpty() || c001Password.isEmpty())
        return T001User();

    TSqlORMapper<T001UserObject> mapper;
    T001UserObject obj = mapper.findFirst(TCriteria(T001UserObject::C001Email, c001Email));
    if (obj.isNull() || obj.c001_password != c001Password) {
        obj.clear();
    }
    return T001User(obj);
}

T001User T001User::create(const QString &c001Email, const QString &c001Password)
{
    T001UserObject obj;
    obj.c001_email = c001Email;
    obj.c001_password = c001Password;
    if (!obj.create()) {
        return T001User();
    }
    return T001User(obj);
}

T001User T001User::create(const QVariantMap &values)
{
    T001User model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

T001User T001User::get(const QString &c001Email)
{
    TSqlORMapper<T001UserObject> mapper;
    return T001User(mapper.findByPrimaryKey(c001Email));
}

int T001User::count()
{
    TSqlORMapper<T001UserObject> mapper;
    return mapper.findCount();
}

QList<T001User> T001User::getAll()
{
    return tfGetModelListByCriteria<T001User, T001UserObject>();
}

QJsonArray T001User::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *T001User::modelData()
{
    return d.data();
}

const TModelObject *T001User::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const T001User &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, T001User &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(T001User)