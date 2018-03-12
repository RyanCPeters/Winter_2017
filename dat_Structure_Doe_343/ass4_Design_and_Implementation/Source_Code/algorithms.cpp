//
// Created by R.Peters on 2/24/2018.
//

#include "movie.h"
#include "imovie.h"

using namespace std;

char discernMovieType(const Movie &target) {

}

/**
 * a function that, given the assignement's specified sorting, will preform
 * the following conditional comparison:
 *
 *  return a <= b
 *
 *  In the event that dissimilar movie types are compared, ie., comparing a
 *  'C'lassics movie against a 'D'rama movie or 'F'unny(comedy) movie, the
 *  comparison return a value according to the following order of precedense:
 *      Let 'C' = Classics
 *          'D' = Dramas
 *          'F' = Funny(Comedies)
 *
 *      Where the order of these values is:
 *          'C' < 'D' < 'F'
 *
 *      Such that:
 *          'C' < 'D' -> true
 *          'C' < 'F' -> true
 *          'D' < 'F' -> true
 *          'F' < 'C' -> false
 *          'F' < 'D' -> false
 *          'D' < 'C' -> false
 *
 * If 'a' and 'b' are of the same movie type, then the comparitor will
 * proceed to evalute their relative order based upon the primary and
 * secondary sorting criteria for their movie type as per assignment 4's
 * specifications, explained as follows:
 *      -------------------------------------------------------
 *      |Movie type | Primary criteria   | Secondary criteria |
 *      |-----------|--------------------|--------------------|
 *      |   ‘C’     | Release date       |  Major actor       |
 *      |   ‘D’     | Director           |  Title             |
 *      |   ‘F’     | Title              |  Year released     |
 *      -------------------------------------------------------
 *
 *      So, as an example consider the following 2 movies:
 *
 *          Movie a -> D, 10, Steven Spielberg, Schindler's List, 1993
 *          Movie b -> D, 10, Steven Spielberg, E.T. , 1982
 *
 *          Because they BOTH are marked as 'D' (drama),  we need to compare
 *          them based upon the primary and secondary criteria for Dramas.
 *
 *          The result will be:
 *              return a <= b; // true
 *
 *          The evaluation returns true because the primary criteria
 *          comparison of director name places them in a common ranking, but
 *          the year of release for E.T. comes before the release year for
 *          Schindler's List.
 *
 * @param a 'a' is a reference to a Movie object which will be compared
 * against movie object 'b'
 * @param b 'b' is a reference to a Movie object which will be compared
 * against movie object 'a'
 * @return The return value will be true if 'a' is less than or equal to 'b',
 *         else return false;
 */
bool movieSorter(const Movie &a, const Movie &b) {
  
  if (a.getMovieType() == b.getMovieType()) {
    return (a.getMovieType() < b.getMovieType());
  }
  // We now know that the two movies are of the same type, and compRec = 0;
//  switch (a.getMovieType()) {
//    case 'C':dynamic_cast<Classics>(a), dynamic_cast<Classics>(b);
//      break;
//    case 'D':dynamic_cast<Drama>(a), dynamic_cast<Drama>(b);
//      break;
//    case 'F':dynamic_cast<Comedy>(a), dynamic_cast<Comedy>(b);
//      break;
//    default: // it's possible we could end up here if the m_type of the
//      // movie object 'a' is TOTAL_MOVIE_TYPE
//      break;
//  }
  int compRec = a.comparePrimaryCriteria(b);
  compRec += (compRec == 0) ? a.compareSecondaryCriteria(b) : 0;
  return compRec <= 0;
}
