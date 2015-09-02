import java.util.*;

public class Main{

    public static void main(String[] args) {
        Scanner in = new Scanner( System.in );
        while( true ) {
            int rows, cols;
            rows = in.nextInt(); // read the rows
            cols = in.nextInt(); // read the cols
            if( rows == 0 && cols == 0 ) { // the input end
                break;
            }
            OilDeposits od = new OilDeposits( rows, cols );
            od.readGrids( in ); // read the strings
            System.out.println( od.getPocketsAmount() );
        }
    }
}

class OilDeposits{
    private int rows, cols;
    private char grids[][];
    private boolean vis[][];
    private final int dir[][] = { // the eight directions
            {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}
        };

    private final char EMPTY = '*';
    private final char EXIST = '@';
    
    public OilDeposits( int rows, int cols ) {
        this.rows = rows;
        this.cols = cols;
        this.grids = new char[ rows + 5 ][ cols + 5 ];
        this.vis = new boolean[ rows ][ cols ];
        for( int i=0; i<rows; i++ ) {
            for( int j=0; j<cols; j++ ) {
                this.vis[i][j] = false;
            }
        }
    }

    private boolean isValid( int row, int col ) { // whether it can visit this position
        if( row < 0 || row >= this.rows || col < 0 || col >= this.cols || vis[row][col] || this.grids[row][col] == EMPTY ) {
            return false;
        }
        return true;
    }

    public void readGrids( Scanner in ) {
        String str;
        for( int i=0; i<rows; i++ ) {
            this.grids[i] = in.next().toCharArray();
        }
    }

    public void Search( int row, int col ) { // search this grid and its adjacent grids
        if( !this.isValid( row, col ) ) {
            return ;
        }
        this.vis[row][col] = true;
        for( int i=0; i<8; i ++ ) {
            Search( row+dir[i][0], col+dir[i][1] );
        }
    }

    public int getPocketsAmount() {
        int counter = 0;
        for( int i=0; i<this.rows; i++ ) {
            for( int j=0; j<this.cols; j++ ) {
                if( this.grids[i][j] == '@' && !this.vis[i][j] ) {
                    counter ++;
                    this.Search( i, j );
                }
            }
        }
        return counter;
    }

}