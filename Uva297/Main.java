import java.util.*;

public class Main{
    public static void main( String []args ) {
        Scanner in = new Scanner( System.in );
        int T;
        T = in.nextInt();
        in.nextLine(); // the "\r\n" string
        while( T != 0 ) {
            T --;
            String str1, str2;
            Init();
            str1 = in.nextLine();
            str2 = in.nextLine();
            strPos = 0;
            draw( str1, 0, 0, 32 );
            strPos = 0;
            draw( str2, 0, 0, 32 );
            System.out.println( "There are " + counter + " black pixels." );
        }
    }

    public static final int MAXN = 32 + 5;
    public static int counter;
    public static int square[][] = new int[ MAXN ][ MAXN ];
    public static int strPos;

    public static void Init() {
        for( int i = 0; i < MAXN; i ++ ) {
            for( int j = 0; j < MAXN; j ++ ) {
                square[i][j] = 0;
            }
        }
        counter = 0;
    }

    public static void draw( String str, int row, int col, int width ) {
        int ch = str.charAt( strPos ++ );
        if( ch == 'p' ) {
            draw( str, row, col + width/2, width/2 );
            draw( str, row, col, width/2 );
            draw( str, row + width/2, col, width/2 );
            draw( str, row + width/2, col + width/2, width/2 );
        } else if ( ch == 'f' ) {
            for( int i = row; i < row + width; i ++ ) {
                for( int j = col; j < col + width; j ++ ) {
                    if( square[i][j] == 0 ) {
                        square[i][j] = 1;
                        counter ++;
                    }
                }
            }
        }
    }
}