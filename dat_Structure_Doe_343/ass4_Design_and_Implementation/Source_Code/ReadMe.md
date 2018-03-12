ReadMe.md


343-Ass4-P2
===

### Document Purpose:

I am not particularly happy with the assig4 design from part 1; it seemed to have come about more by accident than intention. 

Thus, I intend to fix that by applying the **Model-View-Controller (MVC)** -- according to how I understand it -- design template to the specifications of the project.

---
Step 1: Establish the model
---

First, I will need to make note of what state elements the model will need to hold. Then I will use that information to determine how best to set up the hash table used for tracking those state members.

The model needs to store both sensitive customer information, and non-sensitive store inventory information.

- Customer info to be stored:
  + data4cusomters.txt format:
    * `1111 Mouse Mickey` 
    * `1000 Mouse Minnie`
    * where: 
      - the first 4 integer digits are a unique user ID pin
      - The following 2 strings represent the first, then last, names.
  + `int c_pin; // the 4 digit int value unique to this customer, used to identify them in inventory manipulation.`
  + `std::string c_name; // just a string containing the user's first and last name. No need to split them as far as I can see.`


- Store inventory will be manipulated via commands as demonstrated in the data4commands.txt file.
  + data4commands.txt format:
    * `B 2000 D F Sleepless in Seattle, 1993`
      - The **first token** in the line, the char `B`, denotes the action performed:
        + Borrow (denoted as ‘B’): (stock – 1) for each item borrowed
        + Return (denoted as ‘R’): (stock + 1) for each item returned
        + Inventory (denoted as ‘I’): outputs the inventory of all the items in the store
        + History (denoted as ‘H’): outputs all the transactions of a customer
      - The **second token** in the line, the int `2000`, denotes the unique customer id performing the action.
      - The **third token** in the line, the char `D`, denotes the media type of the movie being acted upon.
        + In this case, it shall always be `D` for "DVD", as this project is a simple demonstration of inheritance, and not actually a project to be implemented IRL.
      - The **fourth token** in the line, the char `F`, denotes the movie's genre.
        + The movies will need to be sorted according to genre before being sorted according to genre specific criteria.
        + The order of the expected genre sorting shall be the same order as what's shown in the following explanation of genre labels:
          * `F` labels are for Comedies, because F for Funny :P
          * `D` labels are for Dramas.
          * `C` labels are for Classics.
      - The **fifth token** in the line, the std::string literal `Sleepless in Seattle`, denotes the primary sorting criteria reference according to the genre indicated by the **fourth token**, which directly precedes this one.
      - The **sixth token** in the line, the int `1993`, denotes the secondary sorting reference according to the genre indicated by the fourth token.


- Store inventory will be built via inputs contained in the data4movies.txt file.
  + data4movies.txt format:
    * `C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939`
    * `F, 10, Nora Ephron, Sleepless in Seattle, 1993`
    * `D, 10, Barry Levinson, Good Morning Vietnam, 1988`
      - where:
        + the **first token**, the char `C || F || D`, denote the genre of the movie.
        + the **second token**, the int `10`, denotes the initial inventory stock to be added for this movie. 
          * ***NOTE*** movies can have stock inventory added multiple times, so the **second token** should not be interpreted as being the absolute stock in our inventory for the given movie title.
        + the **third token**, the std::string literal, denotes the movie director's name.
        + the **fourth token**, the std::string literal, denotes the movie's title.
        + the **fifth token**, has variable input which is dependent upon the movie's genre from the first token.
          * for `Comedies` and `Dramas`, the **fifth token** is simply the year of release as an int value.
          * for `Classics`, the **fifth token** is a combination of a std::string literal denoting the starring actor's name followed by the month and year of the movies release.
  + Movie info to be stored:
    * Because there are 5 tokens on each line of our movie input data file, we should maintain state members in our model for each of those data items.
      - the items we will store are:
        + `GenreEnum m_genre;        // the movie's genre as denoted by the chars 'F', 'D', and 'C'`
          * Assuming that we will want to define an enum inside our base model class for `GenreEnum`.
        + `int m_stock;         // the number of copies the store has in inventory for this specific`
        + `std::string m_dir;   // the director of this specific movie title`
        + `std::string m_title; // this specific movie's title`
        + `int* m_date;         // this int pointer allows us to conveniently store a movies year of release, followed by the conditionally needed month of release.`
        + `std::string* m_majorActor; // the major actor(s). This member variable is a string pointer for the sake of making it easier to handle situations where a movie has multiple major actors attributed to it. Each index of the pointer contains an individual actor's full name.`

### In short:      
- The model will need to maintain inventory objects which represent each unique movie title that the store owns. 
  + These objects may be publicly observable with no consequence; however, they should not be publicly mutable.
  + Within each of those inventory objects, the model will maintain the following state members:
    * information acquired from data4movies.txt file:
      - `GenreEnum m_genre;`
      - `int m_stock;`
      - `std::string m_dir;`
      - `std::string m_title;`
      - `int* m_date;`
      - `std::string* m_majorActor;`
    * information we must implicitly append to each inventory object for the time being:
      - media type for the movie, which is implicitly a DVD at this time.
      - first we need to define an enum tool for MediaEnum
        + `enum class MediaEnum : char {DVD = 'd'}`
        + now we can save media types for each inventory object's stock count;
      - `MediaEnum m_media;`
        + Factors to consider for the future:
          * We will probably want to create a struct or inner class as a means to track media types and their associated stock counts.
          * This means that both `int m_stock` and `MediaEnum m_media` will both be affected by this change, and as a result we will want a way to manage multiple distinct stock counts per inventory object.

### This concludes the abstract definition of assig4's model component.

---
step 2: define the view and controller components
---

      
         


