import java.util.*;
import java.io.*;
class Movie{
    int movieId;
    String director;
    int rating;
    int budget;
    Movie(int movieId, String director, int rating, int budget){
        this.movieId = movieId;
        this.director = director;
        this.rating = rating;
        this.budget = budget;
    }

}

class Solution{
    static int findAvgBudgetByDirector(Movie[] movies, String director){
        int count=0, cnt=0;
        for(int i=0; i<movies.length; i++){
            if(director.toLowerCase().equals(movies[i].director.toLowerCase())){
                count += movies[i].budget;
                cnt++;
            }
        }
        if(cnt==0) return 0;
        else return count/cnt;
    }

    static Movie getMovieByRatingBudget(int rating, int budget, Movie[] movies){
        for(int i=0; i<movies.length; i++){
            if(movies[i].rating==rating && movies[i].budget==budget && budget%rating==0)
                return movies[i];
        }
        return null;

    }
    public static void main(String args[]) throws IOException{
         BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
         Movie[] movies = new Movie[5];
         for(int t=0; t<5; t++){
            int id = Integer.parseInt(br.readLine());
            String dir = br.readLine();
            int rating = Integer.parseInt(br.readLine());
            int budget = Integer.parseInt(br.readLine());
            movies[t] = new Movie(id, dir, rating, budget);
         }
         
    }

}