#include "contest.h"

using namespace std;

void Contest::next()
{
    _curr.contestId=_tt.current().contestId;
    _curr.isCatfish=false;
    _curr.isNotCatfish=false;
    _end=_tt.end();
    while( !_tt.end() && _tt.current().contestId==_curr.contestId )
    {
        _curr.isCatfish=_curr.isCatfish || _tt.current().isCatfish;
        _curr.isNotCatfish=_curr.isNotCatfish||_tt.current().isNotCatfish;
        _tt.next();
    }
}
