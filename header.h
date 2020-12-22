#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdint.h>
#include <appconst.h>

struct _share_{
           char name[NAME_LEN];
           int32_t price[] = {100,25,125,200,115} ;
           int32_t quantity


};
typedef struct _share_ Share;

struct _transaction_{
    int32_t buy;
    int32_t sell;
    char company_name[NAME_LEN];
    int32_t price;

};
typedef struct _transaction_ Transaction;

Share    share_buysell(int32_t price,int32_t n);



#endif // HEADER_H_INCLUDED
