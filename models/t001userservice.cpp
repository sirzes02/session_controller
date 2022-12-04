#include "t001userservice.h"
#include "objects/t001user.h"
#include <TreeFrogModel>


void T001UserService::index()
{
    auto items = T001User::getAllJson();
    texport(items);
}

void T001UserService::show(const QString &c001Email)
{
    auto item = T001User::get(c001Email).toJsonObject();
    texport(item);
}

QString T001UserService::create(THttpRequest &request)
{
    auto item = request.formItems("t001User");
    auto model = T001User::create(item);

    if (model.isNull()) {
        QString error = "Failed to create.";
        texport(error);
        texport(item);
        return QString();
    }

    QString notice = "Created successfully.";
    tflash(notice);
    return model.c001Email();
}

void T001UserService::edit(TSession& session, const QString &c001Email)
{
    auto model = T001User::get(c001Email);
    if (!model.isNull()) {
        auto item = model.toJsonObject();
        texport(item);
    }
}

int T001UserService::save(THttpRequest &request, TSession &session, const QString &c001Email)
{
    auto model = T001User::get(c001Email);
    
    if (model.isNull()) {
        QString error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        return 0;
    }

    auto item = request.formItems("t001User");
    model.setProperties(item);
    if (!model.save()) {
        texport(item);
        QString error = "Failed to update.";
        texport(error);
        return -1;
    }

    QString notice = "Updated successfully.";
    tflash(notice);
    return 1;
}

bool T001UserService::remove(const QString &c001Email)
{
    auto t001User = T001User::get(c001Email);
    return t001User.remove();
}

