#ifndef DISK_H
#define DISK_H

#include <iostream>
#include <string>

// forward declearation
class Drama;

class Comedy;

class Classics;

class Movie;

// release date
struct DDate {
  uint8_t      day{0};
  uint8_t      month{0};
  unsigned int year{0};
};
enum DiskType {
  DVD
};
// movie music or game
enum MediaType {
  MOVIE, TOTAL_MEDIA_TYPE
};

// base class for disk
class Disk {
  // disk type is DVD or CD or BLUEBRAY
  Disk(const DiskType &diskType, const MediaType &mediaType,
       const std::string &title, const unsigned int &stock,
       const DDate &releaseDate);
  
  // firstName and lastName for director for movie or artist,
  // firstName1 and lastName1 for classics movie (optional)
  static Disk *createDisk(const DiskType &diskType, const MediaType &mediaType,
                          const short &genre, const std::string &title,
                          const unsigned int &stock, const DDate &releaseDate,
                          const std::string &firstName,
                          const std::string &lastName,
                          const std::string &fistName1 = " ",
                          const std::string &lastName1 = " ");
  
  const std::string getDiskType() const;
  
  const std::string &getTitle() const;
  
  const std::string getMediaType() const;
  
  void checkOut();
  
  void checkIn();
  
  const unsigned int &getStock() const;
  
  // set stock
  void setStock();
  
  // get release date
  const DDate &getReleaseDate() const;
  
  friend std::ostream &operator<<(std::ostream &sout, const Disk &);
  
  // assign operator
  virtual Disk &operator=(const Disk &);
  
  // compare opeartor for sorting
  virtual bool operator==(const Disk &) const = 0;
  
  virtual bool operator!=(const Disk &) const = 0;
  
  virtual bool operator<(const Disk &) const = 0;
  
  virtual bool operator>(const Disk &) const = 0;
  
  virtual ~Disk();
  

protected:
  virtual void print(std::ostream &sout) const;

private:
  DiskType     m_type;
  std::string  m_title;
  MediaType    m_mediaType;
  DDate        m_releaseDate;
  unsigned int m_stock;
};

#endif
