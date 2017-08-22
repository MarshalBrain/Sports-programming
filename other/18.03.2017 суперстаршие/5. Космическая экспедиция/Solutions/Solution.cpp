#include <stdio.h>
#include <algorithm>
using namespace std;

int complexLength;
int complexWidth;
int complexHeight;

int sectionNumbers [ 100 ] [ 100 ] [ 100 ] = {0};

int sectionsCount;

int startLength [ 20000 ] = {0};
int finishLength [ 20000 ] = {0};

int startWidth [ 20000 ] = {0};
int finishWidth [ 20000 ] = {0};

int startHeight [ 20000 ] = {0};
int finishHeight [ 20000 ] = {0};

int p[ 1000000 ] = { 0 };
int rank[ 1000000 ] = { 0 };

void Make_set( int x ) {
	p [ x ] = x;
	rank [ x ] = 0;
}

void Link( int x, int y ) {
 if ( rank [ x ] < rank [ y ] ) {
	 p [ x ] = p [ y ];
 }
 else {
	 if ( rank [ x ] == rank [ y ]) {
		 rank [ y ] ++; 
	 }
	 p [ y ] = p [ x ];
 }
}

int Find_set( int x ) {
	if ( x != p [ x ] ) {
		p [ x ] = Find_set ( p [ x ] );
	}
	return p [ x ];
}

void Union( int x, int y ) {
 Link ( Find_set( x ), Find_set( y ) );
}

void input() {
	FILE* f = fopen ( "input.txt", "r" );
	fscanf(f, "%d %d %d", &complexLength, &complexWidth, &complexHeight);
	
	fscanf(f, "%d", &sectionsCount);
	for (int sectionIndex = 0; sectionIndex < sectionsCount; sectionIndex ++) {
		fscanf (f, "%d %d %d", &startLength [ sectionIndex ], &startWidth [ sectionIndex ], &startHeight [ sectionIndex ] );
		fscanf (f, "%d %d %d", &finishLength [ sectionIndex ], &finishWidth [ sectionIndex ], &finishHeight [ sectionIndex ] );
	}

	int currentSectionNumber = 0;

	for (int lengthIndex = 0; lengthIndex < complexLength; lengthIndex ++ ) {
		for (int widthIndex = 0; widthIndex < complexWidth; widthIndex ++ ) {
			for (int heightIndex = 0; heightIndex < complexHeight; heightIndex ++) {
				Make_set( currentSectionNumber ) ;
				sectionNumbers [ lengthIndex ] [ widthIndex ] [ heightIndex ] = currentSectionNumber;
				currentSectionNumber ++;
			}
		}
	}

}

FILE* f = fopen( "output.txt", "w");

void solve () {

	for (int sectionIndex = 0; sectionIndex < sectionsCount; sectionIndex ++) {
		
		if ( startLength [ sectionIndex ] - finishLength [ sectionIndex ] != 0) {
			
			if ( startLength [ sectionIndex ] < finishLength [ sectionIndex ] ) {
				for (int lengthIndex = startLength [ sectionIndex ]; 
					lengthIndex < finishLength [ sectionIndex ];
					lengthIndex ++ ) {

						int firstSectionIndex = sectionNumbers [ lengthIndex - 1 ] 
						[ startWidth [ sectionIndex ] - 1 ] 
						[ startHeight [ sectionIndex ] - 1 ];

						int secondSectionIndex = sectionNumbers [lengthIndex ] 
						[ startWidth [ sectionIndex ] - 1 ]
						[ startHeight [ sectionIndex ] - 1 ];

						if ( Find_set( firstSectionIndex ) != Find_set ( secondSectionIndex ) ) {
							Union (firstSectionIndex, secondSectionIndex);
						}
						else {
							fprintf ( f, "%d %d %d ", 
								lengthIndex, 
								startWidth [ sectionIndex ], 
								startHeight [ sectionIndex ] );
							fprintf ( f, "%d %d %d\n", 
								lengthIndex + 1, 
								startWidth [ sectionIndex ], 
								startHeight [ sectionIndex ] );
						}
				}
				
			}
			else {
				for (int lengthIndex = startLength [ sectionIndex ]; 
					lengthIndex > finishLength [ sectionIndex ];
					lengthIndex -- ) {

						int firstSectionIndex = sectionNumbers [ lengthIndex - 1 ] 
						[ startWidth [ sectionIndex ] - 1 ] 
						[ startHeight [ sectionIndex ] - 1 ];

						int secondSectionIndex = sectionNumbers [lengthIndex - 2 ] 
						[ startWidth [ sectionIndex ] - 1 ]
						[ startHeight [ sectionIndex ] - 1 ];

						if ( Find_set( firstSectionIndex ) != Find_set ( secondSectionIndex ) ) {
							Union (firstSectionIndex, secondSectionIndex);
						}
						else {
							fprintf ( f, "%d %d %d ", 
								lengthIndex, 
								startWidth [ sectionIndex ], 
								startHeight [ sectionIndex ] );
							fprintf ( f, "%d %d %d\n", 
								lengthIndex - 1, 
								startWidth [ sectionIndex ], 
								startHeight [ sectionIndex ] );
						}
				}
			}

			

		}

		if ( startWidth [ sectionIndex ] - finishWidth [ sectionIndex ] != 0) {

			if ( startWidth [ sectionIndex ] < finishWidth [ sectionIndex ] ) {
				for (int widthIndex = startWidth [ sectionIndex ]; 
					widthIndex < finishWidth [ sectionIndex ];
					widthIndex ++ ) {
						int firstSectionIndex = sectionNumbers [ startLength [ sectionIndex ] - 1 ]
						[ widthIndex - 1 ]
						[ startHeight [ sectionIndex ] - 1 ];
						int secondSectionIndex = sectionNumbers [ startLength [ sectionIndex ] - 1 ]
						[ widthIndex ]
						[ startHeight [ sectionIndex ] - 1 ];
						if ( Find_set( firstSectionIndex ) != Find_set ( secondSectionIndex ) ) {
							Union (firstSectionIndex, secondSectionIndex);
						}
						else {
							fprintf ( f, "%d %d %d ", 
								startLength [ sectionIndex ], 
								widthIndex, 
								startHeight [ sectionIndex ] );
							fprintf ( f, "%d %d %d\n", 
								startLength [ sectionIndex ], 
								widthIndex + 1, 
								startHeight [ sectionIndex ] );
						}
				}
			}
			else {
				for (int widthIndex = startWidth [ sectionIndex ]; 
					widthIndex > finishWidth [ sectionIndex ];
					widthIndex -- ) {
						int firstSectionIndex = sectionNumbers [ startLength [ sectionIndex ] - 1 ]
						[ widthIndex - 1 ]
						[ startHeight [ sectionIndex ] - 1 ];
						int secondSectionIndex = sectionNumbers [ startLength [ sectionIndex ] - 1 ]
						[ widthIndex - 2 ]
						[ startHeight [ sectionIndex ] - 1 ];
						if ( Find_set( firstSectionIndex ) != Find_set ( secondSectionIndex ) ) {
							Union (firstSectionIndex, secondSectionIndex);
						}
						else {
							fprintf ( f, "%d %d %d ", 
								startLength [ sectionIndex ], 
								widthIndex, 
								startHeight [ sectionIndex ] );
							fprintf ( f, "%d %d %d\n", 
								startLength [ sectionIndex ], 
								widthIndex - 1, 
								startHeight [ sectionIndex ] );
						}
				}
			}

			

		}

		if ( startHeight [ sectionIndex ] - finishHeight [ sectionIndex ] != 0) {
	
			if ( startHeight [ sectionIndex ] < finishHeight [ sectionIndex ] ) {
				for (int heightIndex = startHeight [ sectionIndex ]; 
					heightIndex < finishHeight [ sectionIndex ];
					heightIndex ++ ) {
						int firstSectionIndex = sectionNumbers [ startLength [ sectionIndex ] - 1 ]
						[ startWidth [ sectionIndex ] - 1 ]
						[ heightIndex - 1 ];
						int secondSectionIndex = sectionNumbers [ startLength [ sectionIndex ] - 1 ]
						[ startWidth [ sectionIndex ] - 1 ] 
						[ heightIndex ];
						if ( Find_set( firstSectionIndex ) != Find_set ( secondSectionIndex ) ) {
							Union (firstSectionIndex, secondSectionIndex);
						}
						else {
							fprintf ( f, "%d %d %d ", 
								startLength [ sectionIndex ], 
								startWidth [ sectionIndex ], 
								heightIndex );
							fprintf ( f, "%d %d %d\n", 
								startLength [ sectionIndex ], 
								startWidth [ sectionIndex ], 
								heightIndex + 1 );
						}
				}
			}
			else {
				for (int heightIndex = startHeight [ sectionIndex ]; 
					heightIndex > finishHeight [ sectionIndex ];
					heightIndex -- ) {
						int firstSectionIndex = sectionNumbers [ startLength [ sectionIndex ] - 1 ]
						[ startWidth [ sectionIndex ] - 1 ]
						[ heightIndex - 1 ];
						int secondSectionIndex = sectionNumbers [ startLength [ sectionIndex ] - 1 ]
						[ startWidth [ sectionIndex ] - 1 ] 
						[ heightIndex - 2 ];
						if ( Find_set( firstSectionIndex ) != Find_set ( secondSectionIndex ) ) {
							Union (firstSectionIndex, secondSectionIndex);
						}
						else {
							fprintf ( f, "%d %d %d ", 
								startLength [ sectionIndex ], 
								startWidth [ sectionIndex ], 
								heightIndex );
							fprintf ( f, "%d %d %d\n", 
								startLength [ sectionIndex ], 
								startWidth [ sectionIndex ], 
								heightIndex - 1 );
						}
				}
			}

			

		}
	}

	fclose(f);

}

int main() {

	input();
	solve();

	return 0;
}

