#pragma once
#include <TGlobal>

class THttpRequest;
class TSession;


class T_MODEL_EXPORT T001UserService {
public:
    void index();
    void show(const QString &c001Email);
    QString create(THttpRequest &request);
    void edit(TSession &session, const QString &c001Email);
    int save(THttpRequest &request, TSession &session, const QString &c001Email);
    bool remove(const QString &c001Email);
};

