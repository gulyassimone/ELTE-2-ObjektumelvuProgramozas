#include "account.h"

bool Account::search(const std::string& cardNo) const
{
    for( Card* card : _cards ){
        if( card->_cardNo == cardNo ) return true;
    }
    return false;
}
