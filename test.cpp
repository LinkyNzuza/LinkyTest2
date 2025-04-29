#include <iostream>
#include <cassert>
#include <stdio>
using namespace std;
void runtests
{
 assert(ounces2pounds(16)==1);//Check 1 pound is equal to 16 ounces
 assert(ounces2pounds(0)==0);// default 0 ponds is 0 ounces
 printf("ounces2pounds passed");
 
assert(stones2pounds(1)==14);//Check 1 stone is equal to 14 pounds
assert(stones2pounds(0)==0);//default 0 stones is 0 pounds
printf("stones2pounds passed");
 
}
int main()
{
runtests();
printf("All tests passed");
return -1; 
}
