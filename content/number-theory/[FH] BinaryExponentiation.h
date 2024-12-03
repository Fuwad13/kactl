/**
 * Author: Noam527
 * Date: 2019-04-24
 * License: CC0
 * Source: folklore
 * Description:
 * Status: tested
 */
ll binexp(ll base, ll exp, ll M){
    if(exp==0)
        return 1;
    ll ret = binexp(base, exp/2, M);
    ret=(ret*ret)%M;
    if(exp&1)
        return ((ret%M)*(base%M))%M;
    return ret;
}