/* 
        Segment_Tree 
        author: SHHHS
        2016-09-28 12:35:17 
*/ 
#include "bits/stdc++.h"

using namespace std ;
typedef long long QAQ ;
const int maxN = 100100 ;
struct SegTree { int l , r , sum ;};

SegTree tr[ maxN<<2 ] ;
int arr[ maxN ] ;
void Build_Tree ( int x , int y , int i ) {
         tr[ i ].l = x ; tr[ i ].r = y ;
         if ( x==y ) return ;
         else {
                  QAQ mid = ( tr[ i ].l + tr[ i ].r ) >> 1 ;
                 Build_Tree ( x , mid , i<<1 ) ;
                 Build_Tree ( mid +1 , y , i<<1|1 ) ;
         }
}

void Insert_Tree ( int q , int i ) {
         if ( q==tr[ i ].l && q==tr[ i ].r ) {
                   tr[ i ].sum ++ ;
                   return ;
         }
         else {
                   QAQ mid = ( tr[ i ].l + tr[ i ].r ) >> 1 ;
                   if ( q>mid ) Insert_Tree ( q , i<<1|1 ) ;
                   else if ( q<=mid ) Insert_Tree ( q , i<<1 ) ;
         }
         tr[ i ].sum = tr[ i<<1 ].sum + tr[ i<<1|1 ].sum ;
}

QAQ Query_Tree (  int q , int w , int i ){
         if ( q<=tr[i].l && w>=tr[i].r ) {
                  return tr[i].sum ;
         }
         else {
                  QAQ mid=(tr[i].l+tr[i].r)>>1;
                  if ( q>mid )return Query_Tree(q,w,i<<1|1);
                  else if ( w<=mid )return Query_Tree(q,w,i<<1);
                  else return Query_Tree(q,mid,i<<1) + Query_Tree(mid+1,w,i<<1|1);
        
         }
}

int main ( ) {
         int N ; 
         QAQ ans = 0;
         scanf ("%d",&N);
         for ( int i=1 ; i<=N ; ++i ) scanf ( "%d" , arr + i ) ;
         Build_Tree ( 1 , N , 1 ) ;
         for ( int i=1 ; i<=N ; ++i ) {
                  int temp = arr [ i ] ;
                  Insert_Tree ( temp , 1 ) ;
                  ans += i - Query_Tree ( 1 , temp , 1 ) ;
         }
         printf ( "%lld" , ans ) ;
         system("pause");
         return 0 ;
}