//
// Created by R.Peters on 2/25/2018.
//


#include "../movie.h"
#include "../drama.h"
#include "../classics.h"
#include "../comedy.h"
#include "../actor.h"

/*
 *    |-----------------------------------------------------------------------------------------------------------|
 *    | type     | stock | Director           | Title                           | (MajorActor-date)(D), else: year|
 *    |----------|-------|--------------------|---------------------------------|---------------------------------|
 * A  | C        | 10    | Michael Curtiz     | Casablanca                      | Ingrid Bergman 8 1942 |
 * B  | C        | 10    | Michael Curtiz     | Casablanca                      | Humphrey Bogart 8 1942 |
 * C  | F        | 10    | Nora Ephron        | Sleepless in Seattle            | 1993 |
 *    -------------------------------------------------------------------------------------------------------------
 */
Movie a;


/**
 *
 */
static bool test_MovieA_preceeds_MovieB(){
  Person personA = Actor("Ingrid", "Bergman", PersonType::ACTOR),
         personB = Actor("Humphrey", "Bogart", PersonType::ACTOR),
         personC = Director("Nora", "Ephron", PersonType::DIRECTOR);
  DDate dateA{}, dateB{}, dateC{};
  dateA.month = 8, dateA.year = 1942;
  dateB.month = 8, dateB.year = 1942;
  dateA.year = 1993;
  
  Movie a = Movie("Casablanca",MovieType::DRAMA,personA,10,dateA,DiskType::DVD);
  Movie b = Movie("Casablanca",MovieType::DRAMA,personB,10,dateB,DiskType::DVD);
  Movie c = Movie("Sleepless in Seattle",MovieType::COMEDY,personC,10,dateC,
                  DiskType::DVD);
  
  
  
}


/* data4movies.txt converted to a table for easy visual referencing
 * |-----------------------------------------------------------------------------------------------------------|
 * | category | stock | Director           | Title                           | (MajorActor-date)(D), else: year|
 * |----------|-------|--------------------|---------------------------------|---------------------------------|
 * | C        | 10    | Michael Curtiz     | Casablanca                      | Ingrid Bergman 8 1942 |
 * | C        | 10    | Michael Curtiz     | Casablanca                      | Humphrey Bogart 8 1942 |
 * | C        | 10    | Victor Fleming     | The Wizard of Oz                | Judy Garland 7 1939 |
 * | F        | 10    | Nora Ephron        | Sleepless in Seattle            | 1993 |
 * | D        | 10    | Barry Levinson     | Good Morning Vietnam            | 1988 |
 * | D        | 10    | Gus Van Sant       | Good Will Hunting               | 2000 |
 * | F        | 10    | Woody Allen        | Annie Hall                      | 1977 |
 * | F        | 10    | Rob Reiner         | When Harry Met Sally            | 1989 |
 * | D        | 10    | Phillippe De Broca | King of Hearts                  | 1967 |
 * | D        | 10    | Steven Spielberg   | Schindler's List                | 1993 |
 * | F        | 10    | Gore Verbinski     | Pirates of the Caribbean        | 2003 |
 * | F        | 10    | Joel Coen          | Fargo                           | 1996 |
 * | D        | 10    | Jonathan Demme     | Silence of the Lambs            | 1991 |
 * | D        | 10    | Clint Eastwood     | Unforgiven                      | 1992 |
 * | C        | 10    | Hal Ashby          | Harold and Maude                | Ruth Gordon 3 1971 |
 * | Z        | 10    | Hal Ashby          | Harold and Maude                | Bud Cort 3 1971 |
 * | C        | 10    | George Cukor       | Holiday                         | Katherine Hepburn 9 1938 |
 * | C        | 10    | George Cukor       | Holiday                         | Cary Grant 9 1938 |
 * | C        | 10    | Victor Fleming     | Gone With the Wind              | Vivien Leigh 2 1939 |
 * | C        | 10    | Victor Fleming     | Gone With the Wind              | Clark Gable 2 1939 |
 * | C        | 10    | George Cukor       | The Philadelphia Story          | Katherine Hepburn 5 1940 |
 * | C        | 10    | George Cukor       | The Philadelphia Story          | Cary Grant 5 1940 |
 * | C        | 10    | John Huston        | The Maltese Falcon              | Humphrey Bogart 10 1941 |
 * | Z        | 10    | Frank Capra        | It's a Wonderful Life           | James Steward 11 1946 |
 * | C        | 10    | Frank Capra        | It's a Wonderful Life           | James Steward 11 1946 |
 * | C        | 10    | Frank Capra        | It's a Wonderful Life           | Donna Reed 11 1946 |
 * | C        | 10    | Stanley Kubrick    | A Clockwork Orange              | Malcolm McDowell 2 1971 |
 * | F        | 10    | John Landis        | National Lampoon's Animal House | 1978 |
 * | D        | 10    | Nancy Savoca       | Dogfight                        | 1991 |
 * | F        | 10    | Nora Ephron        | You've Got Mail                 | 1998 |
 * -----------------------------------------------------------------------------------
 */
