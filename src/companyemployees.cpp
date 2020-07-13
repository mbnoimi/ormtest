#include "companyemployees.h"

CompanyEmployees::CompanyEmployees() : Database(),
    m_users(new TableSet<User>(this))
{

}
