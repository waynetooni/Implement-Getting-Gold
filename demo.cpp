#include <stdio.h>   // scanf
#include <iostream>  // cout , endl
#include <fstream>   // open, is_open, close, write, ignore
#include <string>    // string, find_last_of, substr, clear
#include <vector>    // vector, push_back
#include <cstdlib>   // atoi, system
#include <memory.h>

using namespace std;
int gold = 0 ; 
int row = 0 ;
int column = 0 ;


void visit(int y, int x, vector<vector<char> > & map ){
	    if(map[y][x] =='G')
            gold++;

	    if(!(map[y+1][x] == '#' && map[y][x+1] == '#' && map[y-1][x] == '#' && map[y][x-1] == '#') 
           && !(map[y+1][x] == 'T' || map[y][x+1] == 'T' || map[y-1][x] == 'T' || map[y][x-1] == 'T')
           && !(x >= row || y >= column || x < 0 || y < 0 )){    // if no wall around and any trap around and no out of range
	       

           map[y][x] ='#';
       	   if ( map[y][x+1] != '#')
       	      visit(y, x+1,map);	//	right
           if ( map[y-1][x] != '#')
       		  visit(y-1, x,map);	//	up 
       	   if (map[y][x-1] != '#')
       		  visit(y, x-1,map);	//	left 
		   if (map[y+1][x] != '#')	  
       		  visit(y+1, x ,map);	//	down 
       	
		}	// if
        else {
	      map[y][x] = '#' ;
        } // else
	
} // visit

int main(){
	int startX = 0 ;
    int startY = 0 ;
    bool found = false ;
    char temp ;
    
    scanf("%d",&row);
    scanf("%d",&column) ;
    while(row !=0 && column != 0){
	  vector<vector<char> > map ;
      row++;
      for(int i = 0 ; i < column ; i++){
	    vector<char> maptemp ;
	    for(int j = 0 ; j < row ; j++){
	      scanf( "%c", &temp );
          if( temp != '\n')
            maptemp.push_back(temp); 
          if( temp == 'P'){
	        startX = j - 1  ;
            startY = i ;
          }  // if
        } //for 
        map.push_back(maptemp);
      } // for

      cout << endl ;
/*
      for(int i = 0 ; i < column ; i++){
	    for(int j = 0 ; j < row - 1 ; j++){
	      cout << map[i][j] ;
        
        } //for 
        cout << endl ;
      } // for
*/
      //cout << startY <<  startX  <<map[startY][startX] << endl ;
      visit(startY, startX, map);
      cout << "Gold: " << gold << endl;
    
      scanf("%d",&row);
      scanf("%d",&column) ;
      gold = 0 ;
    }
    
} // main()
