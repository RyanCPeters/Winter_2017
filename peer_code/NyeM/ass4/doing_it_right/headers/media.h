
#ifndef DOING_IT_RIGHT_MEDIA_H
#define DOING_IT_RIGHT_MEDIA_H

enum media_t {DVD = 0, DEFAULT = -1};
class Media {
public:

  /** Empty Constructor will default initialize the local member vaiable
   * media_type to be media_t::DEFAULT
   *
   */
  Media():media_type(media_t::DEFAULT){};

  /** takes in an argument for the media type and assignes it to the local
  * variable media_type.
   *
   * @param this media objects assigned media_t state.
   */
  Media(media_t medt):media_type(medt){};


private:
  media_t media_type;

};


#endif //DOING_IT_RIGHT_MEDIA_H
