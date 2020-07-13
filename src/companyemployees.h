#ifndef COMPANYEMPLOYEES_H
#define COMPANYEMPLOYEES_H

#include "database.h"
#include "user.h"

#ifdef NUT_NAMESPACE
using namespace NUT_NAMESPACE;
#endif

class CompanyEmployees : public Database
{
    Q_OBJECT

    NUT_DB_VERSION(1)
    NUT_DECLARE_TABLE(User, users)

public:
    CompanyEmployees();
};

#endif // COMPANYEMPLOYEES_H
