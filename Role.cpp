#include "Role.h"

Role::Role()
{

}

Role::Role(string role, string dom, string min, string max, string pc)
{
    this->pc=pc;
    this->dom=dom;
    this->max=max;
    this->min=min;
    this->role=role;
}
